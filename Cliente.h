#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Cliente{
private:
	std::string m_nom;
	std::string m_ape;
	std::string m_ali;
	std::string m_mail;
	std::string m_dir;
	std::string m_tel;
	std::string m_dni;
	bool m_activo;
public:
	Cliente();
	Cliente(std::string, std::string, std::string, std::string, std::string, std::string, std::string, bool);
	
	std::string VerNombre() const;
	std::string VerApellido() const;
	std::string VerAlias() const;
	std::string VerMail() const;
	std::string VerDireccion() const;
	std::string VerTelefono() const;
	std::string VerDNI() const;
	bool VerEstado() const; //Verifica si esta habilitado o deshabilitado
	
	
	void EditarNombre(std::string);
	void EditarApellido(std::string);
	void EditarAlias(std::string);
	void EditarMail(std::string);
	void EditarDireccion(std::string);
	void EditarTelefono(std::string);
	void EditarDNI(std::string);
	
	void DeshabilitarCliente();
	void HabilitarCliente();
	
	std::string ValidarDatos();
	
};


bool criterio_de_comparacion_nombre(const Cliente &p1, const Cliente &p2);
bool criterio_de_comparacion_apellido(const Cliente &p1, const Cliente &p2);
bool criterio_de_comparacion_alias(const Cliente &p1, const Cliente &p2);
bool criterio_de_comparacion_mail(const Cliente &p1, const Cliente &p2);
bool criterio_de_comparacion_direccion(const Cliente &p1, const Cliente &p2);
bool criterio_de_comparacion_telefono(const Cliente &p1, const Cliente &p2);
bool criterio_de_comparacion_dni(const Cliente &p1, const Cliente &p2);

#endif
