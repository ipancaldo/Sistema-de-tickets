#include "HijaAdmProductos.h"
#include <wx/msgdlg.h>
#include "string_conv.h"
#include <cstring>
#include "HijaAgregarP.h"
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
	for(int i=0 ; i<m_financiero->CantidadProductos(); i++){
		Producto &p = m_financiero->SeleccionarProducto(i);
		///Para mostrar clientes HABILITADOS (cuando se "elimina" se deshabilita)
		if(p.prod_VerEstado() == true){
			m_p_grilla->AppendRows(); //Agrega grillas a medida que metemos datosp
			///SetCellValue = setear valor de la celda, que va a ir adentro. i fila 0 columna
			
			///ESTO LO SAQUE DE UN FORO PARA DEMOSTRAR COMO SE MUESTRAN LOS INT TRANSFORMADOS CREO
//			grid->SetColFormatFloat(7, 6, 2);
//			grid->SetCellValue(0, 7, "Width 6\nprecision 2");
//			grid->SetCellValue(1, 7, wxString::Format(wxT("%g"), 3.1415));
//			grid->SetCellValue(2, 7, wxString::Format(wxT("%g"), 1415.0));
//			grid->SetCellValue(3, 7, wxString::Format(wxT("%g"), 12345.67890));
			
//			wxString string = wxString::FromAscii(codigoProducto); //Transformamos el string en wxString para mostrar
			m_p_grilla->SetCellValue(i,0,p.prod_VerCodigo());
			m_p_grilla->SetCellValue(i,1,p.prod_VerNombre());
			m_p_grilla->SetCellValue(i,2,p.prod_VerMarca());
			m_p_grilla->SetColFormatFloat(i,3,p.prod_VerValor());
			m_p_grilla->SetCellValue(i,4,p.prod_VerDescr());
		}
	}
}


void HijaAdmProductos::ClickBotonAgregarProducto( wxCommandEvent& event )  {
	///Esto estoy haciendo (copiando 23:42)
	///Abrimos una nueva ventana de AgregarC
	HijaAgregarP *win = new HijaAgregarP(this, m_financiero);
	if(win->ShowModal()==1)
		RefrescarGrilla();
}

void HijaAdmProductos::ClickBotonEditarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::ClickBotonEliminarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::OnClickCargarProductos( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::EnterBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::OnClickBuscarProd( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::OnDobleClickGProducto( wxGridEvent& event )  {
	event.Skip();
}

void HijaAdmProductos::OnClickGProducto( wxGridEvent& event )  {
	event.Skip();
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

