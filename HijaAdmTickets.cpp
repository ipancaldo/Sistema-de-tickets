#include "HijaAdmTickets.h"
#include <wx/msgdlg.h>

HijaAdmTickets::HijaAdmTickets(wxWindow *parent, Financiero *financiero) : 
	VentanaTickets(parent), m_financiero(financiero) 
{
	RefrescarGrilla();
}

///Lo que va dentro del vector dentro de struct Cl_Pr_Tk
struct ticket_muestra{
	std::string p_nombre;
	std::string p_marca;
	std::string p_descr;
	int items;
	float total;
};
///Struct para devolver todas las cosas del ticket
struct Cl_Pr_Tk{
	std::string id;
	std::string cliente;
	std::string cliente_dni;
	std::string cliente_alias;
	float total_final; ///Monto final de la suma de todos los productos
	std::vector<ticket_muestra> v;
};


void HijaAdmTickets::RefrescarGrilla(){
	///Si la grilla no está vacía, hace esto
	if(m_grilla_tickets->GetNumberRows()!=0)
		m_grilla_tickets->DeleteRows(0,m_grilla_tickets->GetNumberRows());
	
	/// Struct auxiliar para ir guardando los datos relevantes a mostrar del ticket
	Cl_Pr_Tk aux;
	
	///Sólo seleccionamos los códigos ID únicos
	std::vector<std::string> tickets = m_financiero->IdTicketsNoRepetidos();
	
	for(size_t i=0 ; i<tickets.size();i++){
		m_grilla_tickets->AppendRows();
		
		///Primero, buscamos el ticket a partir del código
		int buscarTicket = m_financiero->BuscarIdTicket(tickets[i]);
		Ticket t = m_financiero->SeleccionarTicket(buscarTicket);
		
		///Luego buscamos el cliente a mostrar
		int posicionCliente = m_financiero->BuscarDni(t.ticket_VerDNI());
		Cliente c = m_financiero->SeleccionarCliente(posicionCliente);
		
		std::string fecha = t.ticket_VerDia()+"/"+t.ticket_VerMes()+"/"+t.ticket_VerAnio();
		
		///SetCellValue = setear valor de la celda, que va a ir adentro. i fila 0 columna
		m_grilla_tickets->SetCellValue(i,0,tickets[i]);
		m_grilla_tickets->SetCellValue(i,1,fecha);
		m_grilla_tickets->SetCellValue(i,2,c.VerApellido()+", "+c.VerNombre());
		wxString mystring = wxString::Format(wxT("%.2f"), m_financiero->TotalTicket(t.ticket_VerId()));
		m_grilla_tickets->SetCellValue(i,3,"$" + mystring);
	}
}


void HijaAdmTickets::EnterBuscar( wxCommandEvent& event )  {
	OnClickBuscarTicket(event);
}

void HijaAdmTickets::OnClickBuscarTicket( wxCommandEvent& event )  {
	/// Esto sirve para guardar en una variable el str del recuadro, pero primero
	///se debe pasar del formato wx a std::string con .ToStdString()
	std::string buscar = m_cajaticket_buscar->GetValue().ToStdString();
	int encontrado = -1;
	
	///Sólo seleccionamos los códigos ID únicos
	std::vector<std::string> tickets = m_financiero->IdTicketsNoRepetidos();
	for(size_t i=0;i<tickets.size();i++) {
		if(buscar == tickets[i]){
			encontrado = i;
			break;
		}
	}
	if(encontrado != -1){
		m_grilla_tickets->SetGridCursor(encontrado,0); // seleccionar
		m_grilla_tickets->SelectRow(encontrado); // seleccionar
	}else{
		wxMessageBox("No se encontró resultado"); ///Sería -1
	}
}

void HijaAdmTickets::ClickAceptarAdmProducto( wxCommandEvent& event )  {
	EndModal(1);
}

void HijaAdmTickets::ClickCancelarAdmProducto( wxCommandEvent& event )  {
	EndModal(0);
}

HijaAdmTickets::~HijaAdmTickets() {
	
}

