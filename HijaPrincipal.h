#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "Financiero.h"

class HijaPrincipal : public BasePrincipal {
	
private:
	
protected:
	void OnClickEliminarProducto( wxCommandEvent& event )  override;
	void Guardar( wxCommandEvent& event )  override; ///Guardamos todos los tickets en la DB
	void ClickBotonHistorialTickets( wxCommandEvent& event )  override;
	void agregarProductoGrilla( wxCommandEvent& event )  override;
	void OnCambiarTamanioPrinc( wxSizeEvent& event )  override;
	void Salir( wxCommandEvent& event )  override; ///Debería preguntar si queremos salir
	void ClickBotonAdministrarCliente( wxCommandEvent& event)  override;
	void ClickBotonAdministrarProducto( wxCommandEvent& event )  override;
	void ImprimirTicket( wxCommandEvent& event )  override;
	
	void refrescarGrilla(struct grillaTicket);
	void actualizarGrilla();
	
	void cargar_datos_fila(int fila);
	///Como lo usamos varias veces, guardamos ese puntero
	///Para usar en los metodos de buscar, eliminar, ordenar, etc	
	Financiero *m_financiero;
	
public:
	HijaPrincipal(Financiero *financiero);
	~HijaPrincipal();
};

#endif

