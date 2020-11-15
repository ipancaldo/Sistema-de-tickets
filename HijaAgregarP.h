#ifndef HIJAAGREGARP_H
#define HIJAAGREGARP_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaAgregarP : public VentanaAgrEditProductos {
	
private:
	Financiero *m_financiero;
protected:
	void OnClickButtonNuevaMarca( wxCommandEvent& event )  override;
	void OnClickButtonAceptarA( wxCommandEvent& event )  override;
	void OnClickButtonCancelarB( wxCommandEvent& event )  override;
	
public:
	HijaAgregarP(wxWindow *parent, Financiero *financiero);
	~HijaAgregarP();
};

#endif

