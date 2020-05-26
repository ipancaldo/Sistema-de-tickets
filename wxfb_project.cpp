///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

BasePrincipal::BasePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Cliente:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer3->Add( m_staticText2, 0, wxALL, 5 );

	wxArrayString m_choice1Choices;
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer3->Add( m_choice1, 1, wxALL, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Administrar clientes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button3, 0, wxALL, 5 );


	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Producto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_textCtrl1, 1, wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer4->Add( m_staticText6, 0, wxALL, 5 );

	m_spinCtrl1 = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer4->Add( m_spinCtrl1, 0, wxALL, 5 );

	m_button8 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button8, 0, wxALL, 5 );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Administrar productos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Ticket:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer5->Add( m_staticText4, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, wxEXPAND, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 6 );
	m_grilla->EnableEditing( true );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 148 );
	m_grilla->SetColSize( 1, 110 );
	m_grilla->SetColSize( 2, 181 );
	m_grilla->SetColSize( 3, 80 );
	m_grilla->SetColSize( 4, 80 );
	m_grilla->SetColSize( 5, 80 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelSize( 30 );
	m_grilla->SetColLabelValue( 0, wxT("Nombre") );
	m_grilla->SetColLabelValue( 1, wxT("Marca") );
	m_grilla->SetColLabelValue( 2, wxT("Descripción") );
	m_grilla->SetColLabelValue( 3, wxT("Precio un.") );
	m_grilla->SetColLabelValue( 4, wxT("Cantidad") );
	m_grilla->SetColLabelValue( 5, wxT("Subtotal") );
	m_grilla->SetColLabelValue( 6, wxEmptyString );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( m_grilla, 1, wxALL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer7->Add( m_staticText5, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("precio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer7->Add( m_staticText7, 0, wxALL, 5 );


	bSizer2->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_cancelar, 0, wxALL, 5 );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_button6, 0, wxALL, 5 );

	m_imprimir = new wxButton( this, wxID_ANY, wxT("Imprimir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_imprimir, 0, wxALL, 5 );


	bSizer2->Add( bSizer6, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAdministrarCliente ), NULL, this );
	m_imprimir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ImprimirTicket ), NULL, this );
}

BasePrincipal::~BasePrincipal()
{
	// Disconnect Events
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAdministrarCliente ), NULL, this );
	m_imprimir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ImprimirTicket ), NULL, this );

}

VentanaAdministrarClientes::VentanaAdministrarClientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Administrar clientes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer23->Add( m_staticText15, 0, wxALL, 5 );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );

	m_c_a_vent_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_c_a_vent_agregar, 0, wxALL, 5 );

	m_c_e_cliente = new wxButton( this, wxID_ANY, wxT("Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_c_e_cliente, 0, wxALL, 5 );

	m_c_eliminar = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_c_eliminar, 0, wxALL, 5 );


	bSizer24->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer24->Add( m_staticText16, 0, wxALL, 5 );

	m_textCtrl10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_textCtrl10, 0, wxALL, 5 );


	bSizer23->Add( bSizer24, 0, wxEXPAND, 5 );

	m_c_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_c_grilla->CreateGrid( 0, 6 );
	m_c_grilla->EnableEditing( true );
	m_c_grilla->EnableGridLines( true );
	m_c_grilla->EnableDragGridSize( false );
	m_c_grilla->SetMargins( 0, 0 );

	// Columns
	m_c_grilla->SetColSize( 0, 144 );
	m_c_grilla->SetColSize( 1, 84 );
	m_c_grilla->SetColSize( 2, 114 );
	m_c_grilla->SetColSize( 3, 128 );
	m_c_grilla->SetColSize( 4, 80 );
	m_c_grilla->SetColSize( 5, 105 );
	m_c_grilla->EnableDragColMove( false );
	m_c_grilla->EnableDragColSize( true );
	m_c_grilla->SetColLabelSize( 30 );
	m_c_grilla->SetColLabelValue( 0, wxT("Nombre y Apellido") );
	m_c_grilla->SetColLabelValue( 1, wxT("DNI") );
	m_c_grilla->SetColLabelValue( 2, wxT("Alias") );
	m_c_grilla->SetColLabelValue( 3, wxT("Dirección") );
	m_c_grilla->SetColLabelValue( 4, wxT("Teléfono") );
	m_c_grilla->SetColLabelValue( 5, wxT("Mail") );
	m_c_grilla->SetColLabelValue( 6, wxEmptyString );
	m_c_grilla->SetColLabelValue( 7, wxEmptyString );
	m_c_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_c_grilla->EnableDragRowSize( true );
	m_c_grilla->SetRowLabelSize( 0 );
	m_c_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_c_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer23->Add( m_c_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );

	m_button13 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button13, 0, wxALL, 5 );

	m_button14 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button14, 0, wxALL, 5 );


	bSizer23->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer23 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_c_a_vent_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonAgregarCliente ), NULL, this );
	m_c_e_cliente->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEditarCliente ), NULL, this );
	m_c_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEliminarCliente ), NULL, this );
}

VentanaAdministrarClientes::~VentanaAdministrarClientes()
{
	// Disconnect Events
	m_c_a_vent_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonAgregarCliente ), NULL, this );
	m_c_e_cliente->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEditarCliente ), NULL, this );
	m_c_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEliminarCliente ), NULL, this );

}

VentanaAgregarCliente::VentanaAgregarCliente( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Agregando nuevo cliente:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer7->Add( m_staticText7, 0, wxALL, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer9->Add( m_staticText8, 0, wxALL, 5 );

	m_c_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_c_nombre, 1, wxALL, 5 );


	bSizer7->Add( bSizer9, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer91->Add( m_staticText9, 0, wxALL, 5 );

	m_c_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer91->Add( m_c_apellido, 1, wxALL, 5 );


	bSizer7->Add( bSizer91, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer92->Add( m_staticText10, 0, wxALL, 5 );

	m_c_dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( m_c_dni, 1, wxALL, 5 );


	bSizer7->Add( bSizer92, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Nombre del local:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer93->Add( m_staticText11, 0, wxALL, 5 );

	m_c_alias = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer93->Add( m_c_alias, 1, wxALL, 5 );


	bSizer7->Add( bSizer93, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Direccción:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer94->Add( m_staticText12, 0, wxALL, 5 );

	m_c_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer94->Add( m_c_direccion, 1, wxALL, 5 );


	bSizer7->Add( bSizer94, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Teléfono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer95->Add( m_staticText13, 0, wxALL, 5 );

	m_c_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_c_telefono, 1, wxALL, 5 );


	bSizer7->Add( bSizer95, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer21->Add( m_staticText14, 0, wxALL, 5 );

	m_c_mail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_c_mail, 1, wxALL, 5 );


	bSizer7->Add( bSizer21, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_c_agregar = new wxButton( this, wxID_ANY, wxT("BotonA"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_c_agregar, 0, wxALL, 5 );

	m_c_cancelar = new wxButton( this, wxID_ANY, wxT("BotonB"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_c_cancelar, 0, wxALL, 5 );


	bSizer7->Add( bSizer22, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_c_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarCliente::ClickAgregarCliente ), NULL, this );
	m_c_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarCliente::ClickCancelarAgrCliente ), NULL, this );
}

VentanaAgregarCliente::~VentanaAgregarCliente()
{
	// Disconnect Events
	m_c_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarCliente::ClickAgregarCliente ), NULL, this );
	m_c_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarCliente::ClickCancelarAgrCliente ), NULL, this );

}

VentanaEditarCliente::VentanaEditarCliente( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Agregando nuevo cliente:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer7->Add( m_staticText7, 0, wxALL, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer9->Add( m_staticText8, 0, wxALL, 5 );

	m_c_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_c_nombre, 1, wxALL, 5 );


	bSizer7->Add( bSizer9, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer91->Add( m_staticText9, 0, wxALL, 5 );

	m_c_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer91->Add( m_c_apellido, 1, wxALL, 5 );


	bSizer7->Add( bSizer91, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer92->Add( m_staticText10, 0, wxALL, 5 );

	m_c_dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( m_c_dni, 1, wxALL, 5 );


	bSizer7->Add( bSizer92, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Nombre del local:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer93->Add( m_staticText11, 0, wxALL, 5 );

	m_c_alias = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer93->Add( m_c_alias, 1, wxALL, 5 );


	bSizer7->Add( bSizer93, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer94;
	bSizer94 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Direccción:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer94->Add( m_staticText12, 0, wxALL, 5 );

	m_c_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer94->Add( m_c_direccion, 1, wxALL, 5 );


	bSizer7->Add( bSizer94, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Teléfono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer95->Add( m_staticText13, 0, wxALL, 5 );

	m_c_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_c_telefono, 1, wxALL, 5 );


	bSizer7->Add( bSizer95, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer21->Add( m_staticText14, 0, wxALL, 5 );

	m_c_mail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_c_mail, 1, wxALL, 5 );


	bSizer7->Add( bSizer21, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_c_agregar = new wxButton( this, wxID_ANY, wxT("BotonA"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_c_agregar, 0, wxALL, 5 );

	m_c_cancelar = new wxButton( this, wxID_ANY, wxT("BotonB"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_c_cancelar, 0, wxALL, 5 );


	bSizer7->Add( bSizer22, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_c_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarCliente::ClickEditarCliente ), NULL, this );
	m_c_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarCliente::ClickCancelarCliente ), NULL, this );
}

VentanaEditarCliente::~VentanaEditarCliente()
{
	// Disconnect Events
	m_c_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarCliente::ClickEditarCliente ), NULL, this );
	m_c_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEditarCliente::ClickCancelarCliente ), NULL, this );

}
