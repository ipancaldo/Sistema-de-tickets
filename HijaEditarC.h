#ifndef HIJAEDITARC_H
#define HIJAEDITARC_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaEditarC : public VentanaEditarCliente {
	
private:
	Cliente *m_financiero;
	int m_indice_persona; ///< guarda el indice de la persona por si hay que modificarla
protected:
	void ClickCancelarCliente( wxCommandEvent& event )  override;
	void ClickEditarCliente( wxCommandEvent& event )  override;
	
public:
	HijaEditarC(wxWindow *parent, Financiero *financiero, int cual);

};

#endif
