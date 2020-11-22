#ifndef HIJAADMCLIENTES_H
#define HIJAADMCLIENTES_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaAdmClientes : public VentanaAdministrarClientes {
	
private:
	///Guardamos el "negocio"
	Financiero *m_financiero;
	void cargar_datos_fila(int fila); ///!!!!POR AHORA NO LO USO Y CREO QUE NO LO VOY A USAR, ES DEL PROFE!!!
protected:
	void OnClickGCliente( wxGridEvent& event )  override; ///Sirve para ordenar las columnas por criterio
	void OnDobleClickGCliente( wxGridEvent& event )  override; ///En doble click, habilita editar cliente
	
	void ClickBotonEditarCliente( wxCommandEvent& event )  override; ///Para editar cliente
	void ClickBotonEliminarCliente( wxCommandEvent& event )  override; ///!!Para eliminar, DEBERÍA SE DESHABILITAR!!
	void ClickBotonAgregarCliente( wxCommandEvent& event )  override; ///Nueva ventana para agregar cliente
	
	void ClickCancelarAdmCliente( wxCommandEvent& event )  override; ///Click CANCELAR
	void ClickAceptarAdmCliente( wxCommandEvent& event )  override; ///Click ACEPTAR
	
	//EL ERROR VIENE DE ESTE CREO!
	void EnterBuscar( wxCommandEvent& event )  override;
	void OnClickBuscar( wxCommandEvent& event )  override;	
public:
	///Al constructor de la hija, además del padre recibe el "negocio"
	HijaAdmClientes(wxWindow *parent, Financiero *financiero);
	void RefrescarGrilla(); ///Refresca la grilla, esto depende de varios factores (cuando abre/ordenando/etc)
};

#endif

