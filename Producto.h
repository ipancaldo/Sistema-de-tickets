#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto{
private:
	std::string m_prod_nom;
	std::string m_prod_marca;
	std::string m_prod_cod;
	float m_prod_valor;
	std::string m_prod_descr;
	bool m_activo;
public:
	Producto();
	Producto(std::string, std::string, std::string, float, std::string);
	
	std::string prod_VerNombre() const;
	std::string prod_VerMarca() const;
	std::string prod_VerCodigo() const;
	float prod_VerValor() const;
	std::string prod_VerDescr() const;
	bool prod_VerEstado() const;
	
	void prod_EditarNombre(std::string);
	void prod_EditarMarca(std::string);
	void prod_EditarValor(float);
	void prod_EditarDescr(std::string);
	
	void DeshabilitarProducto();
	void HabilitarProducto();
	
	std::string ValidarDatos();
};

bool criterio_de_comparacion_pnombre(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pmarca(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pcodigo(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pvalor(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pdescripcion(const Producto &p1, const Producto &p2);


#endif
