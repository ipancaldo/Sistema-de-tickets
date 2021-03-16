#ifndef HIJAADMTICKETS_H
#define HIJAADMTICKETS_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaAdmTickets : public VentanaTickets {
	
private:
	Financiero *m_financiero;
protected:
	void OnClickBuscarTicket( wxCommandEvent& event )  override;
	void EnterBuscar( wxCommandEvent& event )  override;
	void ClickAceptarAdmProducto( wxCommandEvent& event )  override;
	void ClickCancelarAdmProducto( wxCommandEvent& event )  override;
	
public:
	HijaAdmTickets(wxWindow *parent, Financiero *financiero);
	void RefrescarGrilla();
	~HijaAdmTickets();
};

#endif

