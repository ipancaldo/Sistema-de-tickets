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

	wxArrayString m_clientesChoices;
	m_clientes = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_clientesChoices, 0 );
	m_clientes->SetSelection( 0 );
	bSizer3->Add( m_clientes, 1, wxALL, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	DiaHoy = new wxStaticText( this, wxID_ANY, wxT("HoyDia"), wxDefaultPosition, wxDefaultSize, 0 );
	DiaHoy->Wrap( -1 );
	bSizer3->Add( DiaHoy, 0, wxALL, 5 );

	m_iniciardia = new wxButton( this, wxID_ANY, wxT("Iniciar Día"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_iniciardia, 1, wxALL, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Administrar clientes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button3, 0, wxALL, 5 );


	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Producto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALL, 5 );

	m_codigoProducto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_codigoProducto, 1, wxALL, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer4->Add( m_staticText6, 0, wxALL, 5 );

	m_cantidadProducto = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
	bSizer4->Add( m_cantidadProducto, 0, wxALL, 5 );

	m_agregarProducto = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_agregarProducto, 0, wxALL, 5 );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Administrar productos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Ticket:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer5->Add( m_staticText4, 0, wxALL, 5 );

	numeroTicket = new wxStaticText( this, wxID_ANY, wxT("Ticket numero"), wxDefaultPosition, wxDefaultSize, 0 );
	numeroTicket->Wrap( -1 );
	bSizer5->Add( numeroTicket, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, wxEXPAND, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 6 );
	m_grilla->EnableEditing( false );
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
	bSizer2->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer7->Add( m_staticText5, 0, wxALL, 5 );

	precioTotal = new wxStaticText( this, wxID_ANY, wxT("precio"), wxDefaultPosition, wxDefaultSize, 0 );
	precioTotal->Wrap( -1 );
	bSizer7->Add( precioTotal, 0, wxALL, 5 );


	bSizer2->Add( bSizer7, 0, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_cerrardia = new wxButton( this, wxID_ANY, wxT("Cerrar día"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_cerrardia, 0, wxALL, 5 );


	bSizer6->Add( 0, 0, 1, 0, 5 );

	m_cancelar = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
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
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( BasePrincipal::OnCambiarTamanioPrinc ) );
	m_iniciardia->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickBotonIniciarDia ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAdministrarCliente ), NULL, this );
	m_agregarProducto->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::agregarProductoGrilla ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAdministrarProducto ), NULL, this );
	m_cerrardia->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickBotonCerrarDia ), NULL, this );
	m_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::Salir ), NULL, this );
	m_imprimir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ImprimirTicket ), NULL, this );
}

BasePrincipal::~BasePrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( BasePrincipal::OnCambiarTamanioPrinc ) );
	m_iniciardia->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickBotonIniciarDia ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAdministrarCliente ), NULL, this );
	m_agregarProducto->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::agregarProductoGrilla ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAdministrarProducto ), NULL, this );
	m_cerrardia->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickBotonCerrarDia ), NULL, this );
	m_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::Salir ), NULL, this );
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

	m_cli_buscar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer24->Add( m_cli_buscar, 0, wxALL, 5 );

	m_c_buscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( m_c_buscar, 0, wxALL, 5 );


	bSizer23->Add( bSizer24, 0, wxEXPAND, 5 );

	m_c_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_c_grilla->CreateGrid( 0, 6 );
	m_c_grilla->EnableEditing( false );
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

	m_c_aceptar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_c_aceptar, 0, wxALL, 5 );

	m_c_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_c_cancelar, 0, wxALL, 5 );


	bSizer23->Add( bSizer26, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer23 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_c_a_vent_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonAgregarCliente ), NULL, this );
	m_c_e_cliente->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEditarCliente ), NULL, this );
	m_c_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEliminarCliente ), NULL, this );
	m_cli_buscar->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaAdministrarClientes::EnterBuscar ), NULL, this );
	m_c_buscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::OnClickBuscar ), NULL, this );
	m_c_grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaAdministrarClientes::OnDobleClickGCliente ), NULL, this );
	m_c_grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaAdministrarClientes::OnClickGCliente ), NULL, this );
	m_c_aceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickAceptarAdmCliente ), NULL, this );
	m_c_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickCancelarAdmCliente ), NULL, this );
}

VentanaAdministrarClientes::~VentanaAdministrarClientes()
{
	// Disconnect Events
	m_c_a_vent_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonAgregarCliente ), NULL, this );
	m_c_e_cliente->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEditarCliente ), NULL, this );
	m_c_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickBotonEliminarCliente ), NULL, this );
	m_cli_buscar->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaAdministrarClientes::EnterBuscar ), NULL, this );
	m_c_buscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::OnClickBuscar ), NULL, this );
	m_c_grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaAdministrarClientes::OnDobleClickGCliente ), NULL, this );
	m_c_grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaAdministrarClientes::OnClickGCliente ), NULL, this );
	m_c_aceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickAceptarAdmCliente ), NULL, this );
	m_c_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarClientes::ClickCancelarAdmCliente ), NULL, this );

}

VentanaCliente::VentanaCliente( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_c_tituloventana = new wxStaticText( this, wxID_ANY, wxT("TituloVentana"), wxDefaultPosition, wxDefaultSize, 0 );
	m_c_tituloventana->Wrap( -1 );
	bSizer7->Add( m_c_tituloventana, 0, wxALL, 5 );

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
	m_c_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaCliente::ClickAceptarCliente ), NULL, this );
	m_c_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaCliente::ClickCancelarCliente ), NULL, this );
}

VentanaCliente::~VentanaCliente()
{
	// Disconnect Events
	m_c_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaCliente::ClickAceptarCliente ), NULL, this );
	m_c_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaCliente::ClickCancelarCliente ), NULL, this );

}

VentanaAdministrarProductos::VentanaAdministrarProductos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Administrar productos:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer19->Add( m_staticText17, 0, wxALL, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_p_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_p_agregar, 0, wxALL, 5 );

	m_p_editar = new wxButton( this, wxID_ANY, wxT("Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_p_editar, 0, wxALL, 5 );

	m_p_eliminar = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_p_eliminar, 0, wxALL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	m_p_cargar = new wxButton( this, wxID_ANY, wxT("Cargar productos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_p_cargar, 0, wxALL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Buscar:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer20->Add( m_staticText18, 0, wxALL, 5 );

	m_prod_buscar = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer20->Add( m_prod_buscar, 0, wxALL, 5 );

	m_p_buscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_p_buscar, 0, wxALL, 5 );


	bSizer19->Add( bSizer20, 0, wxEXPAND, 5 );

	m_p_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_p_grilla->CreateGrid( 0, 5 );
	m_p_grilla->EnableEditing( false );
	m_p_grilla->EnableGridLines( true );
	m_p_grilla->EnableDragGridSize( false );
	m_p_grilla->SetMargins( 0, 0 );

	// Columns
	m_p_grilla->SetColSize( 0, 85 );
	m_p_grilla->SetColSize( 1, 143 );
	m_p_grilla->SetColSize( 2, 142 );
	m_p_grilla->SetColSize( 3, 83 );
	m_p_grilla->SetColSize( 4, 268 );
	m_p_grilla->EnableDragColMove( false );
	m_p_grilla->EnableDragColSize( true );
	m_p_grilla->SetColLabelSize( 30 );
	m_p_grilla->SetColLabelValue( 0, wxT("Código") );
	m_p_grilla->SetColLabelValue( 1, wxT("Producto") );
	m_p_grilla->SetColLabelValue( 2, wxT("Marca") );
	m_p_grilla->SetColLabelValue( 3, wxT("Precio") );
	m_p_grilla->SetColLabelValue( 4, wxT("Descripción") );
	m_p_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_p_grilla->EnableDragRowSize( true );
	m_p_grilla->SetRowLabelSize( 0 );
	m_p_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_p_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer19->Add( m_p_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_p_aceptar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_p_aceptar, 0, wxALL, 5 );

	m_p_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_p_cancelar, 0, wxALL, 5 );


	bSizer19->Add( bSizer22, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer19 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_p_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickBotonAgregarProducto ), NULL, this );
	m_p_editar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickBotonEditarProducto ), NULL, this );
	m_p_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickBotonEliminarProducto ), NULL, this );
	m_p_cargar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::OnClickCargarProductos ), NULL, this );
	m_prod_buscar->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaAdministrarProductos::EnterBuscar ), NULL, this );
	m_p_buscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::OnClickBuscarProd ), NULL, this );
	m_p_grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaAdministrarProductos::OnDobleClickGProducto ), NULL, this );
	m_p_grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaAdministrarProductos::OnClickGProducto ), NULL, this );
	m_p_aceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickAceptarAdmProducto ), NULL, this );
	m_p_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickCancelarAdmProducto ), NULL, this );
}

VentanaAdministrarProductos::~VentanaAdministrarProductos()
{
	// Disconnect Events
	m_p_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickBotonAgregarProducto ), NULL, this );
	m_p_editar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickBotonEditarProducto ), NULL, this );
	m_p_eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickBotonEliminarProducto ), NULL, this );
	m_p_cargar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::OnClickCargarProductos ), NULL, this );
	m_prod_buscar->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaAdministrarProductos::EnterBuscar ), NULL, this );
	m_p_buscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::OnClickBuscarProd ), NULL, this );
	m_p_grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaAdministrarProductos::OnDobleClickGProducto ), NULL, this );
	m_p_grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaAdministrarProductos::OnClickGProducto ), NULL, this );
	m_p_aceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickAceptarAdmProducto ), NULL, this );
	m_p_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAdministrarProductos::ClickCancelarAdmProducto ), NULL, this );

}

VentanaAgrEditProductos::VentanaAgrEditProductos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	m_p_titulo = new wxStaticText( this, wxID_ANY, wxT("Ventana titulo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_p_titulo->Wrap( -1 );
	bSizer22->Add( m_p_titulo, 0, wxALL, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Código de barras:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer28->Add( m_staticText25, 0, wxALL, 5 );

	m_p_codigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_p_codigo, 0, wxALL, 5 );


	bSizer22->Add( bSizer28, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText37 = new wxStaticText( this, wxID_ANY, wxT("Marca:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	bSizer80->Add( m_staticText37, 0, wxALL, 5 );

	m_p_marca = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer80->Add( m_p_marca, 0, wxALL, 5 );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_p_buscarMarcaLista = new wxBitmapComboBox( this, wxID_ANY, wxT("Productos"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer80->Add( m_p_buscarMarcaLista, 0, wxALL, 5 );


	bSizer80->Add( 0, 0, 1, wxEXPAND, 5 );

	m_p_nuevaMarca = new wxButton( this, wxID_ANY, wxT("Nueva marca"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer80->Add( m_p_nuevaMarca, 0, wxALL, 5 );


	bSizer22->Add( bSizer80, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText38 = new wxStaticText( this, wxID_ANY, wxT("Producto: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	bSizer81->Add( m_staticText38, 0, wxALL, 5 );

	m_p_producto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_p_producto, 1, wxALL, 5 );


	bSizer22->Add( bSizer81, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText40 = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	bSizer82->Add( m_staticText40, 0, wxALL, 5 );

	m_p_precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_p_precio, 0, wxALL, 5 );


	bSizer82->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Stock:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer82->Add( m_staticText42, 0, wxALL, 5 );

	m_p_stock = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( m_p_stock, 1, wxALL, 5 );


	bSizer22->Add( bSizer82, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxVERTICAL );

	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Descripción:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer84->Add( m_staticText43, 0, wxALL, 5 );

	m_p_descripcion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer84->Add( m_p_descripcion, 1, wxALL|wxEXPAND, 5 );


	bSizer22->Add( bSizer84, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxHORIZONTAL );

	m_p_aceptarA = new wxButton( this, wxID_ANY, wxT("BotonA"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer86->Add( m_p_aceptarA, 0, wxALL, 5 );

	m_p_cancelarB = new wxButton( this, wxID_ANY, wxT("BotonB"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer86->Add( m_p_cancelarB, 0, wxALL, 5 );


	bSizer22->Add( bSizer86, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer22 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_p_nuevaMarca->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgrEditProductos::OnClickButtonNuevaMarca ), NULL, this );
	m_p_aceptarA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgrEditProductos::OnClickButtonAceptarA ), NULL, this );
	m_p_cancelarB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgrEditProductos::OnClickButtonCancelarB ), NULL, this );
}

VentanaAgrEditProductos::~VentanaAgrEditProductos()
{
	// Disconnect Events
	m_p_nuevaMarca->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgrEditProductos::OnClickButtonNuevaMarca ), NULL, this );
	m_p_aceptarA->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgrEditProductos::OnClickButtonAceptarA ), NULL, this );
	m_p_cancelarB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgrEditProductos::OnClickButtonCancelarB ), NULL, this );

}
