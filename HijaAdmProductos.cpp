#include "HijaAdmProductos.h"
#include <wx/msgdlg.h>
#include "string_conv.h"
#include <cstring>
#include "HijaAgregarP.h"
#include "HijaEditarP.h"
using namespace std;

HijaAdmProductos::HijaAdmProductos(wxWindow *parent, Financiero *financiero) : 
	VentanaAdministrarProductos(parent), m_financiero(financiero) 
{
	RefrescarGrilla();	///Funcion que refresca lo que vemos (se visualiza abajo como lo hace)
}

void HijaAdmProductos::RefrescarGrilla(){
	//Grilla de PRODUCTOS, AL PRINCIPIO VOY A HACER QUE CARGUE TODO!!!
	///Si la grilla no está vacía, hace esto
	if(m_p_grilla->GetNumberRows()!=0)
		m_p_grilla->DeleteRows(0,m_p_grilla->GetNumberRows());
	
	///SI DESCOMENTO ES PARA PROBAR CON DESHABILITAR Y NO CON ELIMINAR
	/// Guardamos los clientes en un vector asi cuando queremos mostrar los productos
	///habilitados y hay alguno que no existe entre medio, no da error de no mostrar nada.
//	for(int i=0 ; i<m_financiero->CantidadProductos(); i++){
//		Producto &p = m_financiero->SeleccionarProducto(i);

//		std::vector<Producto> mostrarHabilitados;
//		if(p.prod_VerEstado() == true){
//			mostrarHabilitados.push_back(p);
//		}
		
		/// Para mostrar productos HABILITADOS (cuando se "elimina" se deshabilita)
//		for(size_t i=0;i<mostrarHabilitados.size();i++) {
		for(int i=0 ; i<m_financiero->CantidadProductos(); i++){
			m_p_grilla->AppendRows(); //Agrega grillas a medida que metemos datosp
			
			Producto &p = m_financiero->SeleccionarProducto(i);
			
			///SetCellValue = setear valor de la celda, que va a ir adentro. i fila 0 columna
			m_p_grilla->SetCellValue(i,0,p.prod_VerCodigo());
			m_p_grilla->SetCellValue(i,1,p.prod_VerNombre());
			m_p_grilla->SetCellValue(i,2,p.prod_VerMarca());
			/*m_p_grilla->SetColFormatFloat(i,3,p.prod_VerValor());*/
			///Transformamos el float en un wxstring para que se pueda mostrar
			///%.2f hace que se vean sólo 2 decimales
			wxString mystring = wxString::Format(wxT("%.2f"), p.prod_VerValor());
			m_p_grilla->SetCellValue(i,3,"$" + mystring);
			m_p_grilla->SetCellValue(i,4,p.prod_VerDescr());
		}
	}



void HijaAdmProductos::ClickBotonAgregarProducto( wxCommandEvent& event )  {
	///Abrimos una nueva ventana de AgregarC
	HijaAgregarP *win = new HijaAgregarP(this, m_financiero);
	if(win->ShowModal()==1)
		RefrescarGrilla();
}

void HijaAdmProductos::ClickBotonEditarProducto( wxCommandEvent& event )  {
	int fila = m_p_grilla-> GetGridCursorRow();
	HijaEditarP nueva_ventana(this, m_financiero, fila);
	if(nueva_ventana.ShowModal()==1)
		RefrescarGrilla();
}




void HijaAdmProductos::ClickBotonEliminarProducto( wxCommandEvent& event )  {
	int f = m_p_grilla-> GetGridCursorRow(); ///Para tomar la grilla seleccionada
	/// Mensaje de alerta, en caso de aceptar, se guardan los cambios (eliminar)
	int x = wxMessageBox("Esta seguro de eliminar?","Advertencia", wxYES_NO|wxICON_QUESTION);
	
	
	/// Esto es para deshabilitar
//	if(x==wxYES){
//		///Creamos un producto por referencia para seleccionarlo y luego deshabilitarlo
//		Producto &p = m_financiero->SeleccionarProducto(f);
//		
//		m_financiero->SeleccionarProducto(m_financiero->BuscarCodProd(p.prod_VerCodigo())).DeshabilitarProducto();
//		m_financiero->GuardarProductos();
//		RefrescarGrilla();
//	}	
	
	if(x==wxYES){
		///Creamos un producto por referencia para seleccionarlo y luego deshabilitarlo
		m_financiero->EliminarProducto(f);
		m_financiero->GuardarProductos();
		RefrescarGrilla();
	}	
}

void HijaAdmProductos::OnClickCargarProductos( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::EnterBuscar( wxCommandEvent& event )  {
	OnClickBuscarProd(event);
}

void HijaAdmProductos::OnClickBuscarProd( wxCommandEvent& event )  {
	/// Esto sirve para guardar en una variable el str del recuadro, pero primero
	///se debe pasar del formato wx a std::string con .ToStdString()
	std::string buscar = m_prod_buscar->GetValue().ToStdString();
	int encontrado;
	
	for(size_t i = 0; i<m_financiero->CantidadProductos(); i++){
		encontrado = m_financiero->BuscarCodProd(buscar);
		if(encontrado != -1){
			m_p_grilla->SetGridCursor(encontrado,0); // seleccionar
			m_p_grilla->SelectRow(encontrado); // seleccionar
		}else{
			encontrado = m_financiero->BuscarNombreProd(buscar);
			if(encontrado != -1){
				m_p_grilla->SetGridCursor(encontrado,0); // seleccionar
				m_p_grilla->SelectRow(encontrado); // seleccionar
			}else{
				encontrado = m_financiero->BuscarMarcaProd(buscar);
				if(encontrado != -1){
					m_p_grilla->SetGridCursor(encontrado,0); // seleccionar
					m_p_grilla->SelectRow(encontrado); // seleccionar
				}else{
					wxMessageBox("No se encontró resultado"); ///Sería -1
					break;
				}
			}
		}
	}
}


//Al realizar doble click, abre el editor sobre el Producto
void HijaAdmProductos::OnDobleClickGProducto( wxGridEvent& event )  {
	int fila = m_p_grilla-> GetGridCursorRow();
	HijaEditarP nueva_ventana(this, m_financiero, fila);
	if(nueva_ventana.ShowModal()==1)
		RefrescarGrilla();	
}

//Ordena columnas por criterio
void HijaAdmProductos::OnClickGProducto( wxGridEvent& event )  {
	int columna=event.GetCol();
	int cant_productos = m_financiero->CantidadProductos(); ///MUESTRA LOS HABILITADOS
	switch(columna) { /// ordena la lista de clientes por:
		case 0: m_financiero->Ordenar(por_pcodigo); break;
		case 1: m_financiero->Ordenar(por_pnombre); break;
		case 2: m_financiero->Ordenar(por_pmarca); break;
		case 3: m_financiero->Ordenar(por_pvalor); break;
		case 4: m_financiero->Ordenar(por_pdescripcion); break;
	}
	RefrescarGrilla();
}

void HijaAdmProductos::ClickAceptarAdmProducto( wxCommandEvent& event )  {
	EndModal(1);
}

void HijaAdmProductos::ClickCancelarAdmProducto( wxCommandEvent& event )  {
	EndModal(0);
}

//HijaAdmProductos::~HijaAdmProductos() {
//	
//}

