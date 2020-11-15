#ifndef HIJAAGREGARC_H
#define HIJAAGREGARC_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaAgregarC : public VentanaCliente{
	
private:
	///VER SI ESTO ESTA BIEN!
	///Guardamos el "negocio"
	Financiero *m_financiero;
protected:
	void ClickAceptarCliente( wxCommandEvent& event )  override;
	void ClickCancelarCliente( wxCommandEvent& event )  override;
	
public:
	///Al constructor de la hija, además del padre recibe el "negocio"
	HijaAgregarC(wxWindow *parent, Financiero *financiero);
	~HijaAgregarC();
};

#endif

