#include "HijaPrincipal.h"
#include "HijaAgregarC.h"
#include "HijaAdmClientes.h"
#include "HijaAdmTickets.h"
#include <ctime>
#include <wx/icon.h>
#include "HijaAdmProductos.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

struct grillaTicket{
	std::string pNombre, pMarca, pDescr;
	int pCant;
	float pUnit, pSubTotal;
};

///Vector para ir cargando los productos. Al terminar de utilizarse, se limpia
std::vector<Ticket> ticketCargando;

///Auxiliar para utilizar el mismo codigo de tickets para una compra
std::string codTicket;

///Auxiliar para mostrar costo total de la compra
float costoTotal;

///Día de hoy. Luego servirá para los tickets.
time_t t = time(0);   // get time now
struct tm * now = localtime( & t );	
wxString year = wxString::Format(wxT("%i"),now->tm_year + 1900);
wxString month = wxString::Format(wxT("%i"),now->tm_mon + 1);
wxString day = wxString::Format(wxT("%i"),now->tm_mday);
std::string anio = wx_to_std(year);
std::string mes = wx_to_std(month);
std::string dia = wx_to_std(day);


///Constructor
HijaPrincipal::HijaPrincipal(Financiero *financiero) : ///Recibe puntero agenda
	BasePrincipal(nullptr)/*no tiene padre*/, m_financiero(financiero)/*iniciamos el puntero con lo que le acabamos de pasar*/
{
	this->SetIcon(wxIcon("icono.ico"));
	
	///Mostramos el día de hoy a partir de los datos tomados en líneas 19 a 23
	DiaHoy->SetLabelText(day+"/"+month+"/"+year);
	
	precioTotal->SetLabelText("0");
}


void HijaPrincipal::ImprimirTicket( wxCommandEvent& event )  {
	HijaPrincipal::Guardar(event);
	
	///Genera el .txt
	m_financiero->ImprimirTicket(codTicket);
	
	///Con esto limpiamos la grilla para usarla de 0
	if(m_grilla->GetNumberRows()!=0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	
	///Limpiamos el valor total de la Compras
	precioTotal->SetLabelText("0");
	
	///Vaciamos el ticket donde se iban almacenando
	ticketCargando.erase(ticketCargando.begin(), ticketCargando.end());
	ticketCargando.resize(0);
	
	
}

void HijaPrincipal::Salir( wxCommandEvent& event )  {
	///Debería preguntar si queremos salir
	Close();
}

void HijaPrincipal::OnCambiarTamanioPrinc( wxSizeEvent& event )  {
	event.Skip();
}



void HijaPrincipal::agregarProductoGrilla( wxCommandEvent& event )  {
	std::string codProd = wx_to_std(m_codigoProducto->GetValue()); //Almacenamos el cod prod
	//Buscamos el producto en nuestra base de datos, nos devuelve la POS
	int posProducto = m_financiero->BuscarCodProd(codProd);
	
	//Si el producto existe:
	if(posProducto != -1){
		//Buscamos el prod y lo tomamos
		Producto producto = m_financiero->SeleccionarProducto(posProducto);
		
		
		// Si no hay grillas generadas, generamos nuevo ID de ticket. Se almacena en la
		//variable global
		if(m_grilla->GetNumberRows()==0){
			codTicket = m_financiero->ticket_GenerarId();
			numeroTicket->SetLabelText(std_to_wx(codTicket));
		}
		
		/// Tomamos el valor del wxSpinCtrl, lo guardamos en un float (no int
		///ya que vamos a multiplicar por un precio float más adelante).
		int cantidadItems = m_cantidadProducto->GetValue();
		
		//Datos para el struct
		std::string pNombre, pMarca, pDescr;
		float pCant, pUnit, pSubTotal;
		
		//Para guardar el precio unitario del producto
		int codigoProd = m_financiero->BuscarCodProd(producto.prod_VerCodigo());
		pUnit = m_financiero->SeleccionarProducto(codigoProd).prod_VerValor();
		
		//Guardamos en struct para luego mostrar en pantalla los datos del producto
		grillaTicket prod = {producto.prod_VerNombre(), producto.prod_VerMarca(), producto.prod_VerDescr(),
			cantidadItems, producto.prod_VerValor(), cantidadItems*producto.prod_VerValor()};
		
		m_codigoProducto->SetValue(""); //Restauramos el valor de codigoProducto
		m_cantidadProducto->SetValue("1"); //Restauramos el valor de cantidadProducto
		refrescarGrilla(prod); //Agregamos el producto a la grilla
		
//		///Pasamos la cantidad de items deseados a int para el constructor del ticket
//		int cantidadInt = static_cast<int>(pCant);
		
		/// Creamos un ticket para ir almacenandolo en el vector de la línea 11
		///(después habría que limpiar memoria)
		///Para saber si es el primer producto de la grilla.
		///Debemos saber para generar un código único para el ticket.
		Ticket ticket = {dia, mes, anio, codTicket,
			/*Acá deberíamos buscar el índice del cliente y guardar el DNI abajo
			t_dni = Financiero->SeleccionarCliente(comprador-1).VerDNI(),*/
			"34563466", ///Después debería ir el DNI del cliente seleccionado
			codProd,
			producto.prod_VerValor(),
			cantidadItems
		};
		
		/// Cargamos en pantalla el valor de la compra total hasta el momento
		costoTotal += cantidadItems*producto.prod_VerValor();
		wxString costo = wxString::Format(wxT("%.2f"), costoTotal); 
		precioTotal->SetLabelText(costo);
		
		
		ticketCargando.push_back(ticket);
		
	}else{
		wxMessageBox("El codigo no se encuentra en el sistema","error",wxOK|wxICON_ERROR);
	}
}



///Además de refresacr, pasa todos los campos a wxString
void HijaPrincipal::refrescarGrilla(struct grillaTicket prod){ 
	int ultimaFila = m_grilla->GetNumberRows();
	m_grilla->AppendRows(); //Crea una nueva fila
	// Cuatro datos del Producto
	m_grilla->SetCellValue(ultimaFila,0,prod.pNombre);
	m_grilla->SetCellValue(ultimaFila,1,prod.pMarca);
	m_grilla->SetCellValue(ultimaFila,2,prod.pDescr);
	///Transformamos el float en un wxstring para que se pueda mostrar
	///%.2f hace que se vean sólo 2 decimales
	wxString mystring = wxString::Format(wxT("%.2f"), prod.pUnit); //De float a wxString
	m_grilla->SetCellValue(ultimaFila,3,"$" + mystring);
	///Transformamos la cantidad del wxSpinCtrl a float	
	wxString cantItem = wxString::Format(wxT("%i"),prod.pCant); //De int a wxString
	m_grilla->SetCellValue(ultimaFila,4,cantItem);
	///Subtotal
	wxString subtotalString = wxString::Format(wxT("%.2f"), prod.pSubTotal); //Transformamos float a wxString
	m_grilla->SetCellValue(ultimaFila,5,"$" + subtotalString);
}

///BORRAR FILA!! m_grilla->DeleteRows(0,m_grilla->GetNumberRows()); REEMPLAZAR GetNumberRow por la actual que nos encontremos

void HijaPrincipal::ClickBotonHistorialTickets( wxCommandEvent& event )  {
	HijaAdmTickets *win = new HijaAdmTickets(this, m_financiero);
	win->ShowModal();
}

void HijaPrincipal::ClickBotonAdministrarCliente(wxCommandEvent& event)  {
	HijaAdmClientes *win = new HijaAdmClientes(this, m_financiero);
	win->ShowModal();///En caso de clickear agregar, devuelve 1 y refresca
	///Cuando creemos la grilla, se descomentan las dos lineas previas
}

void HijaPrincipal::ClickBotonAdministrarProducto( wxCommandEvent& event )  {
	HijaAdmProductos *win = new HijaAdmProductos(this, m_financiero);
	win->ShowModal();
}



///Guardamos los tickets almacenados en el vector global en la BD
void HijaPrincipal::Guardar( wxCommandEvent& event )  {
	if(ticketCargando.size() != 0){
		for(size_t i=0;i<ticketCargando.size();i++) { 
			m_financiero->AgregarTicket(ticketCargando[i]);
		}
		wxString nada = "";
		costoTotal = 0;
		numeroTicket->SetLabelText(nada);
		///Con esto limpiamos la grilla para usarla de 0
		if(m_grilla->GetNumberRows()!=0)
			m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	}else{
		wxMessageBox("No hay ticket para guardar","error",wxOK|wxICON_ERROR);
	}
}

void HijaPrincipal::OnClickEliminarProducto( wxCommandEvent& event )  {
	if(m_grilla->GetNumberRows()==0){
		wxMessageBox("No hay productos para borrar","error",wxOK|wxICON_ERROR);
	}else{
		int f = m_grilla-> GetGridCursorRow();///Para tomar la grilla seleccionada
		/// Mensaje de alerta, en caso de aceptar, se guardan los cambios (eliminar)
		int x = wxMessageBox("Esta seguro de eliminar?","Advertencia", wxYES_NO|wxICON_QUESTION);
		
		if(x==wxYES){
			///Creamos un producto por referencia para seleccionarlo y luego deshabilitarlo
			ticketCargando.erase(ticketCargando.begin()+f);
			actualizarGrilla();
		}
	}
}

void HijaPrincipal::actualizarGrilla(){
	///Si la grilla no está vacía, hace esto
	if(m_grilla->GetNumberRows()!=0)
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	
	for(size_t i=0 ; i<ticketCargando.size(); i++){
		m_grilla->AppendRows(); //Agrega grillas a medida que metemos datosp
		
		Ticket t = ticketCargando[i];
		Producto p = m_financiero->SeleccionarProducto(m_financiero->BuscarCodProd(t.ticket_VerCodigoProd()));
		
		
		///SetCellValue = setear valor de la celda, que va a ir adentro. i fila 0 columna
		m_grilla->SetCellValue(i,0,p.prod_VerNombre());
		m_grilla->SetCellValue(i,1,p.prod_VerMarca());
		m_grilla->SetCellValue(i,2,p.prod_VerDescr());
		///Transformamos el float en un wxstring para que se pueda mostrar
		///%.2f hace que se vean sólo 2 decimales
		wxString mystring = wxString::Format(wxT("%.2f"), t.ticket_VerPrecio());
		m_grilla->SetCellValue(i,3,"$" + mystring);
		m_grilla->SetCellValue(i,4,p.prod_VerDescr());
		wxString subtotalString = wxString::Format(wxT("%.2f"), t.ticket_VerTotal());
		m_grilla->SetCellValue(i,5,"$" + subtotalString);
	}
}

HijaPrincipal::~HijaPrincipal() {
	
}

