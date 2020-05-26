///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BasePrincipal
///////////////////////////////////////////////////////////////////////////////
class BasePrincipal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxChoice* m_choice1;
		wxButton* m_button3;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText6;
		wxSpinCtrl* m_spinCtrl1;
		wxButton* m_button8;
		wxButton* m_button4;
		wxStaticText* m_staticText4;
		wxGrid* m_grilla;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText7;
		wxButton* m_cancelar;
		wxButton* m_button6;
		wxButton* m_imprimir;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonAdministrarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ImprimirTicket( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,523 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BasePrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAdministrarClientes
///////////////////////////////////////////////////////////////////////////////
class VentanaAdministrarClientes : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText15;
		wxButton* m_c_a_vent_agregar;
		wxButton* m_c_e_cliente;
		wxButton* m_c_eliminar;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_textCtrl10;
		wxGrid* m_c_grilla;
		wxButton* m_button13;
		wxButton* m_button14;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonAgregarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEditarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminarCliente( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAdministrarClientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 678,576 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaAdministrarClientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarCliente
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarCliente : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_c_nombre;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_c_apellido;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_c_dni;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_c_alias;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_c_direccion;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_c_telefono;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_c_mail;
		wxButton* m_c_agregar;
		wxButton* m_c_cancelar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickAgregarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarAgrCliente( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAgregarCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 506,329 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaAgregarCliente();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaEditarCliente
///////////////////////////////////////////////////////////////////////////////
class VentanaEditarCliente : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_c_nombre;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_c_apellido;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_c_dni;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_c_alias;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_c_direccion;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_c_telefono;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_c_mail;
		wxButton* m_c_agregar;
		wxButton* m_c_cancelar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickEditarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarCliente( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaEditarCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 506,329 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaEditarCliente();

};

