#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaPrincipal : public BasePrincipal {
	
private:
	
protected:
	void clickBotonIniciarDia( wxCommandEvent& event )  override;
	void clickBotonCerrarDia( wxCommandEvent& event )  override;
	void OnCambiarTamanioPrinc( wxSizeEvent& event )  override;
	void Salir( wxCommandEvent& event )  override; ///Debería preguntar si queremos salir
	void ClickBotonAdministrarCliente( wxCommandEvent& event)  override;
	void ClickBotonAdministrarProducto( wxCommandEvent& event )  override;
	void ImprimirTicket( wxCommandEvent& event )  override;
	
	
	///Como lo usamos varias veces, guardamos ese puntero
	///Para usar en los metodos de buscar, eliminar, ordenar, etc	
	Financiero *m_financiero;
	
public:
	HijaPrincipal(Financiero *financiero);
};

#endif

