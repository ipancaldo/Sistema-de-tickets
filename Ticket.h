#ifndef TICKET_H
#define TICKET_H
//#include "Financiero.h"
#include <string>
#include <fstream>
#include <iostream>

class Ticket {
private:
	std::string m_dia;
	std::string m_mes;
	std::string m_anio;
	std::string m_id; ///ID del ticket
	std::string m_dni; ///DNI de quién compra, para tomar los datos posteriormente
	std::string m_cod_prod; ///Código del producto comprado
	int m_cantidad; ///Cantidad de ítems del mismo producto
	float m_precio; ///Precio unitario al momento de comprar
	float m_total; ///Total de la compra realizada en el ticket (para un sólo producto)
	bool m_activo;
public:
	Ticket();
	Ticket(std::string, std::string, std::string, std::string, std::string, std::string, float, int);
	
	std::string ticket_VerDia() const;
	std::string ticket_VerMes() const;
	std::string ticket_VerAnio() const;
	std::string ticket_VerId() const;
	std::string ticket_VerDNI() const;
	std::string ticket_VerCodigoProd() const;
	int ticket_VerCantidadItems() const;
	float ticket_VerPrecio() const;
	float ticket_VerTotal() const;
	
	float ticket_ValorProducto(std::string) const; ///Para buscar el valor del producto
	void ticket_AgregarComprador(std::string); ///Sólo utilizable si no pasamos los datos directamente al constructor
	/*void ticket_Imprimir();*/ ///Función que imprime datos personales del comprador y todo lo que compra
	
	void DeshabilitarTicket();
	void HabilitarTicket();
};

bool criterio_de_comparacion_id(const Ticket &p1, const Ticket &p2);
bool criterio_de_comparacion_fecha(const Ticket &p1, const Ticket &p2);
bool criterio_de_comparacion_dni_t(const Ticket &p1, const Ticket &p2);
bool criterio_de_comparacion_cod_prod(const Ticket &p1, const Ticket &p2);

#endif

