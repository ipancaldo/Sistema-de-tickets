#include "Ticket.h"

using namespace std;

Ticket::Ticket() {
}

Ticket::Ticket(std::string dia, std::string mes, std::string anio, std::string id, std::string dni, std::string cod_prod, float precio, int cant){
	this-> m_dia = dia;
	this-> m_mes = mes;
	this-> m_anio = anio;
	this-> m_id = id;
	this-> m_dni = dni;
	this-> m_cod_prod = cod_prod;
	this-> m_cantidad = cant;
	this-> m_precio = precio;
	this-> m_total = cant * precio;
	this-> m_activo = true;
}

void Ticket::ticket_AgregarComprador(std::string dni){
	this-> m_dni = dni;
}


std::string Ticket::ticket_VerDia() const{
	return m_dia;
}
std::string Ticket::ticket_VerMes() const{
	return m_mes;
}
std::string Ticket::ticket_VerAnio() const{
	return m_anio;
}
std::string Ticket::ticket_VerId() const{
	return m_id;
}
std::string Ticket::ticket_VerDNI() const{
	return m_dni;
}
std::string Ticket::ticket_VerCodigoProd() const{
	return m_cod_prod;
}
int Ticket::ticket_VerCantidadItems() const{
	return m_cantidad;
}
float Ticket::ticket_VerPrecio() const{
	return m_precio;
}
float Ticket::ticket_VerTotal() const{
	return m_total;
}

//Deshabilita un ticket
void Ticket::DeshabilitarTicket(){
	m_activo = false;
}
//Vuelve a habilitar un ticket
void Ticket::HabilitarTicket(){
	m_activo = true;
}


bool criterio_de_comparacion_id(const Ticket &p1, const Ticket &p2) {
	std::string s1 = p1.ticket_VerId();
	std::string s2 = p2.ticket_VerId();
	return s1<s2;
}
bool criterio_de_comparacion_fecha(const Ticket &p1, const Ticket &p2) {
	std::string s1 = p1.ticket_VerDia()+"/"+p1.ticket_VerMes()+"/"+p1.ticket_VerAnio();
	std::string s2 = p2.ticket_VerDia()+"/"+p2.ticket_VerMes()+"/"+p2.ticket_VerAnio();
	return s1<s2;
}
bool criterio_de_comparacion_dni_t(const Ticket &p1, const Ticket &p2) {
	std::string s1 = p1.ticket_VerDNI();
	std::string s2 = p2.ticket_VerDNI();
	return s1<s2;
}
bool criterio_de_comparacion_cod_prod(const Ticket &p1, const Ticket &p2) {
	std::string s1 = p1.ticket_VerCodigoProd();
	std::string s2 = p2.ticket_VerCodigoProd();
	return s1<s2;
}
