#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaPrincipal : public BasePrincipal {
	
private:
	
protected:
	void ClickBotonAdministrarCliente( wxCommandEvent& event)  override;
	void ImprimirTicket( wxCommandEvent& event )  override;
	///Como lo usamos varias veces, guardamos ese puntero
	///Para usar en los metodos de buscar, eliminar, ordenar, etc
	Financiero *m_financiero;
	
public:
	HijaPrincipal(Financiero *financiero);
};

#endif

