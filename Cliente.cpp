#include "Cliente.h"
#include "Ayuda.h"



Cliente::Cliente() {
}

//Creación del cliente con los datos básicos
Cliente::Cliente(std::string nom, std::string ape, std::string DNI, 
				 std::string ali, std::string dir, std::string tel,
				 std::string mail, bool activo) {
	//Al crear el Cliente, se corrigen los datos de 
	//forma que se guarden con la primera letra mayúscula 
	//y demás en minúsculas
	nom = CorregirPalabra(nom);
	this->m_nom = nom;
	ape = CorregirPalabra(ape);
	this->m_ape = ape;
	ali = CorregirPalabra(ali);
	this->m_ali = ali;
	this->m_mail = mail;
	dir = CorregirPalabra(dir);
	this->m_dir = dir;
	this->m_tel = tel;
	this->m_dni = DNI;
	this->m_activo = activo;
}

//Verificar nombre del cliente
std::string Cliente::VerNombre() const{
	return m_nom;
}
//Verificar apellido del cliente
std::string Cliente::VerApellido() const{
	return m_ape;
}
//Verificar alias (puede ser nombre del negocio) del cliente
std::string Cliente::VerAlias() const{
	return m_ali;
}
//Verificar e-mail del cliente
std::string Cliente::VerMail() const{
	return m_mail;
}
//Verificar dirección del cliente o del local
std::string Cliente::VerDireccion() const{
	return m_dir;
}
//Verificar número de teléfono
std::string Cliente::VerTelefono() const{
	return m_tel;
}
//Verificar número de DNI
std::string Cliente::VerDNI() const{
	return m_dni;
}
bool Cliente::VerEstado() const{
	return m_activo;
}


void Cliente::EditarNombre(std::string nom){
	m_nom = nom;
}
void Cliente::EditarApellido(std::string ape){
	m_ape = ape;
}
void Cliente::EditarAlias(std::string ali){
	m_ali = ali;
}
void Cliente::EditarMail(std::string mail){
	m_mail = mail;
}
void Cliente::EditarDireccion(std::string dir){
	m_dir = dir;
}
void Cliente::EditarTelefono(std::string tel){
	m_tel = tel;
}
void Cliente::EditarDNI(std::string dni){
	m_dni = dni;
}


//Deshabilita un cliente para su uso
void Cliente::DeshabilitarCliente(){
	m_activo = false;
}
//Vuelve a habilitar un cliente
void Cliente::HabilitarCliente(){
	m_activo = true;
}


std::string Cliente::ValidarDatos() {
	std::string errores;
	if (m_nom.size()==0) errores+="El nombre no puede estar vacio\n";
	if (m_nom.size()>30) errores+="El nombre es demasiado largo\n";
	if (m_ape.size()==0) errores+="El apellido no puede estar vacio\n";
	if (m_ape.size()>30) errores+="El apellido es demasiado largo\n";
	if (m_ali.size()>30) errores+="El alias es demasiado largo\n";
	if (m_dni.size()==0) errores+="El DNI no puede estar vacio\n";
	if (m_dni.size()>30) errores+="El DNI es demasiado largo\n";
	if (m_tel.size()>30) errores+="El telefono es demasiado largo\n";
	if (m_dir.size()>30) errores+="La direccion es demasiado largo\n";
	if (m_mail.size()>30) errores+="El e-mail es demasiado largo\n";
	return errores;
}


bool criterio_de_comparacion_nombre(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerNombre();
	std::string s2 = p2.VerNombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_apellido(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerApellido();
	std::string s2 = p2.VerApellido();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_alias(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerAlias();
	std::string s2 = p2.VerAlias();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_mail(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerMail();
	std::string s2 = p2.VerMail();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_direccion(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerDireccion();
	std::string s2 = p2.VerDireccion();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_telefono(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerTelefono();
	std::string s2 = p2.VerTelefono();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_dni(const Cliente &p1, const Cliente &p2) {
	std::string s1 = p1.VerDNI();
	std::string s2 = p2.VerDNI();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
