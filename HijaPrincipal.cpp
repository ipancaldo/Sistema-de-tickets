#include "HijaPrincipal.h"
#include "HijaAgregarC.h"
#include "HijaAdmClientes.h"
#include <ctime>
#include <wx/icon.h>
#include "HijaAdmProductos.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

///Constructor
HijaPrincipal::HijaPrincipal(Financiero *financiero) : ///Recibe puntero agenda
	BasePrincipal(nullptr)/*no tiene padre*/, m_financiero(financiero)/*iniciamos el puntero con lo que le acabamos de pasar*/
{
	this->SetIcon(wxIcon("icono.ico"));
	//	RefrescarGrilla();
	//	m_financiero->Cantidad
	
	
	// Para ingresar la fecha de hoy
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );	
	wxString year = wxString::Format(wxT("%i"),now->tm_year + 1900);
	wxString month = wxString::Format(wxT("%i"),now->tm_mon + 1);
	wxString day = wxString::Format(wxT("%i"),now->tm_mday);
	
	DiaHoy->SetLabelText(day+"/"+month+"/"+year);
}



void HijaPrincipal::ClickBotonAdministrarCliente(wxCommandEvent& event)  {
	HijaAdmClientes *win = new HijaAdmClientes(this, m_financiero);
	/*if(*/win->ShowModal();/*==1)*////En caso de clickear agregar, devuelve 1 y refresca
	//		RefrescarGrilla(); 
	///Cuando creemos la grilla, se descomentan las dos lineas previas
}

void HijaPrincipal::ClickBotonAdministrarProducto( wxCommandEvent& event )  {
	HijaAdmProductos *win = new HijaAdmProductos(this, m_financiero);
	win->ShowModal();
}

void HijaPrincipal::ImprimirTicket( wxCommandEvent& event )  {
	event.Skip();
}

void HijaPrincipal::Salir( wxCommandEvent& event )  {
	///Debería preguntar si queremos salir
	Close();
}

void HijaPrincipal::OnCambiarTamanioPrinc( wxSizeEvent& event )  {
	event.Skip();
}


void HijaPrincipal::clickBotonIniciarDia( wxCommandEvent& event )  {
	event.Skip();
}

void HijaPrincipal::clickBotonCerrarDia( wxCommandEvent& event )  {
	event.Skip();
}

void HijaPrincipal::agregarProductoGrilla( wxCommandEvent& event )  {
	int posProducto = m_financiero->BuscarCodProd(wx_to_std(m_codigoProducto->GetValue())); //Tomamos el valor del código del producto y lo buscamos en la BD
	if(posProducto != -1){
		Producto producto = m_financiero->SeleccionarProducto(posProducto);
		
		/// Creamos un ticket para ir almacenando----------------------------------------VER
		Ticket ticket;
		
		/// ACA DEBEMOS PONER QUE SI ESTA VACÍA SIGUIENTE, INGRESAR
		// Cuatro datos del Producto
		m_grilla->SetCellValue(0,0,producto.prod_VerNombre());
		m_grilla->SetCellValue(0,1,producto.prod_VerMarca());
		m_grilla->SetCellValue(0,2,producto.prod_VerDescr());
		///Transformamos el float en un wxstring para que se pueda mostrar
		///%.2f hace que se vean sólo 2 decimales
		wxString mystring = wxString::Format(wxT("%.2f"), producto.prod_VerValor());
		m_grilla->SetCellValue(0,3,"$" + mystring);
		
		// Tomamos el valor de la cantidad que quieren comprar
//		p1.prod_EditarNombre(wx_to_std(m_p_producto->GetValue()));
		///DESCOMENTAR ESTA!
//		m_grilla->SetCellValue(0,4,m_cantidadProducto->GetValue()); 
		
		// Subtotal entre la multiplicación del valor unitario del producto y la cantidad ingresada
		// Debemos realizar el traspaso a int del valor ingresado, multiplicar por el precio y 
		//transformar el resultado nuevamente a wx
		///DESCOMENTAR TODO PARA ABAJO!
//		float subtotal;
//		float cantidadItems = wxAtof(m_cantidadProducto->GetValue());
//		subtotal = cantidadItems * producto.prod_VerValor();
//		
//		wxString subtotalString = wxString::Format(wxT("%.2f"), subtotal);
//		m_grilla->SetCellValue(0,5,"$" + subtotalString);
	}else{
		wxMessageBox("El codigo no se encuentra en el sistema","error",wxOK|wxICON_ERROR);
	}
}

