#include "HijaEditarC.h"
#include "Cliente.h"
#include "Cliente.h"
#include "string_conv.h"



HijaEditarC::HijaEditarC(wxWindow *parent, Financiero *financiero, int cual) 
	: VentanaEditarCliente(parent), m_financiero(financiero)
	{
	
		std::string nom = wx_to_std(m_c_nombre->GetValue());
		std::string ape = wx_to_std(m_c_apellido->GetValue().c_str());
		std::string dni = wx_to_std(m_c_dni->GetValue());
		std::string alias = wx_to_std(m_c_alias->GetValue().c_str());
		std::string dir = wx_to_std(m_c_direccion->GetValue().c_str());
		std::string tel = wx_to_std(m_c_telefono->GetValue().c_str());
		std::string mail = wx_to_std(m_c_mail->GetValue().c_str());
		
		Cliente &c = m_financiero->SeleccionarCliente(cual);
		m_c_nombre->SetValue( std_to_wx(c.VerNombre()) );
		m_c_apellido->SetValue( std_to_wx(c.VerApellido()) );
		m_c_dni->SetValue( std_to_wx(c.VerDNI()) );
		m_c_alias->SetValue( std_to_wx(c.VerAlias()) );
		m_c_direccion->SetValue( std_to_wx(c.VerDireccion()) );
		m_c_telefono->SetValue( std_to_wx(c.VerTelefono()) );
		m_c_mail->SetValue( std_to_wx(c.VerMail()) );
//		if (p.VerAnioNac()!=0) m_anio->SetValue( wxString()<<p.VerAnioNac() );
//		if (p.VerMesNac()!=0) m_mes->SetValue( wxString()<<p.VerMesNac() );
//		if (p.VerDiaNac()!=0) m_dia->SetValue( wxString()<<p.VerDiaNac() );
		///Modifico el nombre de los botones asi puede utilizarse en otra apertura como editar
		m_c_agregar->SetLabel("Editar");
		m_c_cancelar->SetLabel("Aceptar");
		SetTitle("Editar Persona");
}
	


void HijaEditarC::ClickEditarCliente( wxCommandEvent& event )  {
	event.Skip();
}


void HijaEditarC::ClickCancelarCliente( wxCommandEvent& event )  {
	event.Skip();
}

