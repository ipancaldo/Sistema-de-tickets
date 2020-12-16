#include "HijaAdmTickets.h"

HijaAdmTickets::HijaAdmTickets(wxWindow *parent, Financiero *financiero) : 
	VentanaTickets(parent), m_financiero(financiero) 
{
	
}

void HijaAdmTickets::ClickBotonBuscarTodosTickets( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmTickets::EnterBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmTickets::OnClickBuscarTicket( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmTickets::ClickAceptarAdmProducto( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAdmTickets::ClickCancelarAdmProducto( wxCommandEvent& event )  {
	event.Skip();
}

HijaAdmTickets::~HijaAdmTickets() {
	
}

