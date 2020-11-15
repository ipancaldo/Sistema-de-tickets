#include "HijaEditarC.h"
#include "Cliente.h"
#include "Financiero.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

HijaEditarC::HijaEditarC(wxWindow *parent, Financiero *financiero, int quien) ///Pasamos a quién modificamos
	: VentanaCliente(parent), m_financiero(financiero), QueCliente(quien)
{
	Cliente &c = m_financiero->SeleccionarCliente(quien);
	///Transforma de STRING a WX_STR para que la GUI puede leer
	m_c_nombre->SetValue( std_to_wx(c.VerNombre()) );
	m_c_apellido->SetValue( std_to_wx(c.VerApellido()) );
	m_c_dni->SetValue( std_to_wx(c.VerDNI()) );
	m_c_alias->SetValue( std_to_wx(c.VerAlias()) );
	m_c_direccion->SetValue( std_to_wx(c.VerDireccion()) );
	m_c_telefono->SetValue( std_to_wx(c.VerTelefono()) );
	m_c_mail->SetValue( std_to_wx(c.VerMail()) );
	///Modifico el nombre de los botones asi puede utilizarse en otra apertura como editar
	m_c_agregar->SetLabel("Editar");
	m_c_cancelar->SetLabel("Cancelar");
	///Modifico lo que dice el titulo de la ventana (para este caso, editar)
	m_c_tituloventana->SetLabel("Editar cliente:");
	///Titulo de la barra de la ventana
	SetTitle("Editar cliente");
}



void HijaEditarC::ClickAceptarCliente( wxCommandEvent& event )  {
	
	// Creamos un cliente para ver si los datos son correctos
	//(no por referencia para no guardar)
	Cliente c2(
			   wx_to_std(m_c_nombre->GetValue()),
			   wx_to_std(m_c_apellido->GetValue()),
			   wx_to_std(m_c_alias->GetValue()),
			   wx_to_std(m_c_mail->GetValue()),
			   wx_to_std(m_c_direccion->GetValue()),
			   wx_to_std(m_c_telefono->GetValue()),
			   wx_to_std(m_c_dni->GetValue()),
			   true
			   );
	
	// Siguiente paso, es verificar que no haya errores (campos vacíos, etc)
	string errores = c2.ValidarDatos();
	if(errores.empty()){	///En caso de no haber ninguno, guarda y acepta
		// Tomamos el cliente por referencia
		Cliente &c1 = m_financiero->SeleccionarCliente(QueCliente);
		// Guardamos la info con cada una de las funciones propias
		/// Tomamos los valores visualizados en pantalla (modificados por nosotros)
		///y lo transformamos a STRING para poder guardarlo
		c1.EditarNombre(wx_to_std(m_c_nombre->GetValue()));
		c1.EditarApellido(wx_to_std(m_c_apellido->GetValue()));
		c1.EditarAlias(wx_to_std(m_c_alias->GetValue()));
		c1.EditarMail(wx_to_std(m_c_mail->GetValue()));
		c1.EditarDireccion(wx_to_std(m_c_direccion->GetValue()));
		c1.EditarTelefono(wx_to_std(m_c_telefono->GetValue()));
		c1.EditarDNI(wx_to_std(m_c_dni->GetValue()));
		
		// Guardamos por las dudas además
		m_financiero->GuardarClientes();
		EndModal(1);
	}else{
		///Con esto me tira el iconito de error y el mensajito de error!
		wxMessageBox(errores,"error",wxOK|wxICON_ERROR);
	}
	
}


void HijaEditarC::ClickCancelarCliente( wxCommandEvent& event )  {
	EndModal(0);
}

