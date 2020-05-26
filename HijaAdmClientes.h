#ifndef HIJAADMCLIENTES_H
#define HIJAADMCLIENTES_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaAdmClientes : public VentanaAdministrarClientes {
	
private:
	///Guardamos el "negocio"
	Financiero *m_financiero;
protected:
	void ClickBotonEditarCliente( wxCommandEvent& event )  override;
	void ClickBotonEliminarCliente( wxCommandEvent& event )  override;
	void ClickBotonAgregarCliente( wxCommandEvent& event )  override;
	
public:
	///Al constructor de la hija, además del padre recibe el "negocio"
	HijaAdmClientes(wxWindow *parent, Financiero *financiero);
	void RefrescarGrilla();
};

#endif

