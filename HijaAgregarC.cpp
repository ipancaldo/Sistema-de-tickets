#include "HijaAgregarC.h"
#include "Cliente.h"
#include "Financiero.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

///Esto lo da en 1:41:40
HijaAgregarC::HijaAgregarC(wxWindow *parent, Financiero *financiero) 
	: VentanaAgregarCliente(parent), m_financiero(financiero) {
	///Modifico el nombre de los botones asi puede utilizarse en otra apertura como editar
	m_c_agregar->SetLabel("Agregar");
	m_c_cancelar->SetLabel("Cancelar");
}


void HijaAgregarC::ClickAgregarCliente( wxCommandEvent& event )  {
	string nom = wx_to_std(m_c_nombre->GetValue());
	string ape = wx_to_std(m_c_apellido->GetValue().c_str());
	string dni = wx_to_std(m_c_dni->GetValue());
	string alias = wx_to_std(m_c_alias->GetValue().c_str());
	string dir = wx_to_std(m_c_direccion->GetValue().c_str());
	string tel = wx_to_std(m_c_telefono->GetValue().c_str());
	string mail = wx_to_std(m_c_mail->GetValue().c_str());
	
	Cliente c(nom,ape,dni,alias,dir,tel,mail,true);
	
	///Validamos si los datos ingresados son correctos
	string errores = c.ValidarDatos();
	if(errores.empty()){///En caso de no haber ninguno, guarda y acepta
		m_financiero->AgregarCliente(c);
		EndModal(1);
	}else{
		///Con esto me tira el iconito de error y el mensajito de error!
		wxMessageBox(errores,"error",wxOK|wxICON_ERROR);
	}
}

void HijaAgregarC::ClickCancelarAgrCliente( wxCommandEvent& event )  {
	EndModal(0);
}


HijaAgregarC::~HijaAgregarC() {
	
}
