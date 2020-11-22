#include "Producto.h"
#include "Ayuda.h"
#include "Financiero.h"

Producto::Producto() {
	
}

Producto::Producto(std::string nom, std::string marca, std::string cod, float valor_venta, std::string descr){
	nom = CorregirPalabra(nom);
	this-> m_prod_nom = nom;
	marca = CorregirPalabra(marca);
	this-> m_prod_marca = marca;
	this-> m_prod_cod = cod;
	this-> m_prod_valor = valor_venta;
	this-> m_prod_descr = descr;
	this-> m_activo = true;
}

std::string Producto::prod_VerNombre() const{
	return m_prod_nom;
}

std::string Producto::prod_VerMarca() const{
	return m_prod_marca;
}

std::string Producto::prod_VerCodigo() const{
	return m_prod_cod;
}

float Producto::prod_VerValor() const{
	return m_prod_valor;
}

std::string Producto::prod_VerDescr() const{
	return m_prod_descr;
}

bool Producto::prod_VerEstado() const{
	return m_activo;
}


void Producto::prod_EditarCodigo(std::string cod){
	m_prod_cod = cod;
}
void Producto::prod_EditarNombre(std::string nom){
	m_prod_nom = nom;
}
void Producto::prod_EditarMarca(std::string marca){
	m_prod_marca = marca;
}
void Producto::prod_EditarValor(float valor){
	m_prod_valor = valor;
}
void Producto::prod_EditarDescr(std::string descr){
	m_prod_descr = descr;
}

//Deshabilita un producto para su uso
void Producto::DeshabilitarProducto(){
	m_activo = false;
}
//Vuelve a habilitar un producto
void Producto::HabilitarProducto(){
	m_activo = true;
}



std::string Producto::ValidarDatos() {
	std::string errores;
	if (m_prod_cod.size()==0) errores+="El código no puede estar vacío\n";
	if (m_prod_cod.size()>13) errores+="El código no puede tener más de 13 caracteres\n";
	
//	if (f.BuscarCodProd(m_prod_cod)!=-1)
//		errores+="El código ya se encuentra cargado\n";
	if (m_prod_nom.size()==0) errores+="El nombre no puede estar vacio\n";
	if (m_prod_nom.size()>30) errores+="El nombre es demasiado largo\n";
	if (m_prod_marca.size()==0) errores+="La marca no puede estar vacia\n";
	if (m_prod_marca.size()>30) errores+="La marca es demasiada larga\n";
	if (m_prod_valor==-1) errores+="El precio no puede ser negativo\n";
	if (m_prod_valor==0) errores+="El precio no puede estar vacío\n";
	if (m_prod_descr.size()>500) errores+="La descripción es demasiado larga\n";
	return errores;
}

std::string Producto::validarExistenciaCodigo() {
	std::string error;
	Financiero f;
	if (f.BuscarCodProd(m_prod_cod)!=-1)
		error="El código ya se encuentra cargado\n";
	return error;
}

bool criterio_de_comparacion_pnombre(const Producto &p1, const Producto &p2) {
	std::string s1 = p1.prod_VerNombre();
	std::string s2 = p2.prod_VerNombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_pmarca(const Producto &p1, const Producto &p2) {
	std::string s1 = p1.prod_VerMarca();
	std::string s2 = p2.prod_VerMarca();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_pcodigo(const Producto &p1, const Producto &p2) {
	std::string s1 = p1.prod_VerCodigo();
	std::string s2 = p2.prod_VerCodigo();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool criterio_de_comparacion_pvalor(const Producto &p1, const Producto &p2) {
	float s1 = p1.prod_VerValor();
	float s2 = p2.prod_VerValor();
	return s1<s2;
}
bool criterio_de_comparacion_pdescripcion(const Producto &p1, const Producto &p2) {
	std::string s1 = p1.prod_VerDescr();
	std::string s2 = p2.prod_VerDescr();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}

