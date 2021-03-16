#ifndef HIJAADMPRODUCTOS_H
#define HIJAADMPRODUCTOS_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaAdmProductos : public VentanaAdministrarProductos {
	
private:
	Financiero *m_financiero;
protected:	
	void ClickBotonAgregarProducto( wxCommandEvent& event )  override;
	void ClickBotonEditarProducto( wxCommandEvent& event )  override;
	void ClickBotonEliminarProducto( wxCommandEvent& event )  override; //Deshabilita, no elimina
	
	void EnterBuscar( wxCommandEvent& event )  override;
	void OnClickBuscarProd( wxCommandEvent& event )  override;
	
	void OnDobleClickGProducto( wxGridEvent& event )  override;
	void OnClickGProducto( wxGridEvent& event )  override;
	
	void ClickAceptarAdmProducto( wxCommandEvent& event )  override;
	void ClickCancelarAdmProducto( wxCommandEvent& event )  override;
	
public:
	HijaAdmProductos(wxWindow *parent, Financiero *financiero);
	void RefrescarGrilla();
	~HijaAdmProductos();
};

#endif

