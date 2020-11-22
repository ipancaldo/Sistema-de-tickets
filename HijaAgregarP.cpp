#include "HijaAgregarP.h"
#include "Cliente.h"
#include "Producto.h"
#include "Financiero.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>

HijaAgregarP::HijaAgregarP(wxWindow *parent, Financiero *financiero)
	: VentanaAgrEditProductos(parent), m_financiero(financiero) {
	///Modifico el nombre de los botones asi puede utilizarse en otra apertura como editar
	m_p_aceptarA->SetLabel("Agregar");
	m_p_cancelarB->SetLabel("Cancelar");
	///Modifico lo que dice el titulo de la ventana (para este caso, agregar)
	m_p_titulo->SetLabel("Agregar producto:");
	///Titulo de la barra de la ventana
	SetTitle("Agregar producto");
}

void HijaAgregarP::OnClickButtonNuevaMarca( wxCommandEvent& event )  {
	event.Skip();
}

void HijaAgregarP::OnClickButtonAceptarA( wxCommandEvent& event )  {
	// Creamos un producto para verificar errores (no por referencia para no guardar en este paso)
	///Transformamos el wxString del precio a float para poder pasarselo al constructor
	float decimalNumber = wxAtof(m_p_precio->GetValue());
	Producto p2(
				wx_to_std(m_p_producto->GetValue()),
				wx_to_std(m_p_marca->GetValue()),
				wx_to_std(m_p_codigo->GetValue()),
				///Ac� se debe pasar el wxString mystring a float;
				decimalNumber,
				wx_to_std(m_p_descripcion->GetValue())
	);
	
	//Verificamos si el c�digo ya se encuentra en uso
	std::string erroresExistenciaCodigo = p2.validarExistenciaCodigo();
	
	if(erroresExistenciaCodigo.empty()){ //Si no est� en el sistema el c�digo, se prosigue
		// Siguiente paso, es verificar que no haya errores (campos vac�os, etc)
		std::string errores = p2.ValidarDatos();
		if(errores.empty()){	///En caso de no haber ninguno, guarda y acepta
			m_financiero->AgregarProducto(p2);
			EndModal(1);
		}else{
			///Con esto me tira el iconito de error y el mensajito de error!
			wxMessageBox(errores,"error",wxOK|wxICON_ERROR);
		}
	}else{
		wxMessageBox(erroresExistenciaCodigo,"error",wxOK|wxICON_ERROR);
	}
}

void HijaAgregarP::OnClickButtonCancelarB( wxCommandEvent& event )  {
	EndModal(0);
}

HijaAgregarP::~HijaAgregarP() {
	
}

