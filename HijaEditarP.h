#ifndef HIJAEDITARP_H
#define HIJAEDITARP_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaEditarP : public VentanaAgrEditProductos {
	
private:
	Financiero *m_financiero;
	int QueProducto; ///almacena el índice del cliente
protected:
	void OnClickButtonNuevaMarca( wxCommandEvent& event )  override;
	void OnClickButtonAceptarA( wxCommandEvent& event )  override;
	void OnClickButtonCancelarB( wxCommandEvent& event )  override;
	
public:
	HijaEditarP(wxWindow *parent, Financiero *financiero, int quien);
	~HijaEditarP();
};

#endif

