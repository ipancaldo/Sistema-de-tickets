#ifndef HIJAEDITARC_H
#define HIJAEDITARC_H
#include "wxfb_project.h"
#include "Financiero.h"
//#include "Cliente.h"

class HijaEditarC : public VentanaCliente{
	
private:
	Financiero *m_financiero;
	int QueCliente; ///almacena el índice del cliente
protected:
	void ClickCancelarCliente( wxCommandEvent& event )  override;
	void ClickAceptarCliente( wxCommandEvent& event )  override;
	
public:
	HijaEditarC(wxWindow *parent, Financiero *financiero, int quien);
	//	~HijaEditarC();
};

#endif
