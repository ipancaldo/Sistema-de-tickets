#include "HijaAgregarP.h"
#include "Cliente.h"
#include "Financiero.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>

HijaAgregarP::HijaAgregarP(wxWindow *parent, Financiero *financiero)
	: VentanaAgrEditProductos(parent), m_financiero(financiero) {
	///Modifico el nombre de los botones asi puede utilizarse en otra apertura como editar
	m_p_aceptarA->SetLabel("Agregar");
	m_p_cancelarB->SetLabel("Cancelar");
	///Modifico lo que dice el titulo de la ventana (para este caso, agregar)
	m_p_titulo->SetLabel("Agregar producto:");
	///Titulo de la barra de la ventana
	SetTitle("Agregar producto");
}

void HijaAgregarP::OnClickButtonNuevaMarca( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAgregarP::OnClickButtonAceptarA( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAgregarP::OnClickButtonCancelarB( wxCommandEvent& event )  {
	event.Skip();
}

HijaAgregarP::~HijaAgregarP() {
	
}

