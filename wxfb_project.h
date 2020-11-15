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
#include <wx/bmpcbox.h>

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
		wxButton* m_iniciardia;
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
		wxButton* m_cerrardia;
		wxButton* m_cancelar;
		wxButton* m_button6;
		wxButton* m_imprimir;

		// Virtual event handlers, overide them in your derived class
		virtual void OnCambiarTamanioPrinc( wxSizeEvent& event ) { event.Skip(); }
		virtual void clickBotonIniciarDia( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAdministrarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAdministrarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickBotonCerrarDia( wxCommandEvent& event ) { event.Skip(); }
		virtual void Salir( wxCommandEvent& event ) { event.Skip(); }
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
		wxTextCtrl* m_cli_buscar;
		wxButton* m_c_buscar;
		wxGrid* m_c_grilla;
		wxButton* m_c_aceptar;
		wxButton* m_c_cancelar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonAgregarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEditarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGCliente( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGCliente( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAceptarAdmCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarAdmCliente( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAdministrarClientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 678,576 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaAdministrarClientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaCliente
///////////////////////////////////////////////////////////////////////////////
class VentanaCliente : public wxDialog
{
	private:

	protected:
		wxStaticText* m_c_tituloventana;
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
		virtual void ClickAceptarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarCliente( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 506,329 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaCliente();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAdministrarProductos
///////////////////////////////////////////////////////////////////////////////
class VentanaAdministrarProductos : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText17;
		wxButton* m_p_agregar;
		wxButton* m_p_editar;
		wxButton* m_p_eliminar;
		wxButton* m_p_cargar;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_prod_buscar;
		wxButton* m_p_buscar;
		wxGrid* m_p_grilla;
		wxButton* m_p_aceptar;
		wxButton* m_p_cancelar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickBotonAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEditarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonEliminarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCargarProductos( wxCommandEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscarProd( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGProducto( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGProducto( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAceptarAdmProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarAdmProducto( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAdministrarProductos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 744,543 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaAdministrarProductos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgrEditProductos
///////////////////////////////////////////////////////////////////////////////
class VentanaAgrEditProductos : public wxDialog
{
	private:

	protected:
		wxStaticText* m_p_titulo;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_p_codigo;
		wxStaticText* m_staticText37;
		wxTextCtrl* m_p_marca;
		wxBitmapComboBox* m_p_buscarMarcaLista;
		wxButton* m_p_nuevaMarca;
		wxStaticText* m_staticText38;
		wxTextCtrl* m_p_producto;
		wxStaticText* m_staticText40;
		wxTextCtrl* m_p_precio;
		wxStaticText* m_staticText42;
		wxTextCtrl* m_p_stock;
		wxStaticText* m_staticText43;
		wxTextCtrl* m_p_descripcion;
		wxButton* m_p_aceptarA;
		wxButton* m_p_cancelarB;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClickButtonNuevaMarca( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickButtonAceptarA( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickButtonCancelarB( wxCommandEvent& event ) { event.Skip(); }


	public:

		VentanaAgrEditProductos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 451,344 ), long style = wxDEFAULT_DIALOG_STYLE );
		~VentanaAgrEditProductos();

};

