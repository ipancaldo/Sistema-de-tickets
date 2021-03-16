#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto{
private:
	std::string m_prod_nom; ///Nombre del producto
	std::string m_prod_marca; ///Marca del producto
	std::string m_prod_cod; ///C�digo de barras del producto
	float m_prod_valor; ///Valor unitario del producto
	std::string m_prod_descr; ///Descripci�n del producto
	bool m_activo; ///Si el producto se encuentra comercializando
public:
	Producto();
	Producto(std::string, std::string, std::string, float, std::string);
	
	std::string prod_VerNombre() const; ///Retorna el nombre del producto
	std::string prod_VerMarca() const; ///Retorna la marca del producto
	std::string prod_VerCodigo() const; ///Retorna el c�digo de barras del producto
	float prod_VerValor() const; ///Retorna el valor del producto
	std::string prod_VerDescr() const; ///Retorna la descripci�n del producto
	bool prod_VerEstado() const; ///Retorna el estado (ACTIVO / DESACTIVO)
	
	void prod_EditarCodigo(std::string); ///Edita el c�digo del producto
	void prod_EditarNombre(std::string); ///Edita el nombre del producto
	void prod_EditarMarca(std::string); ///Edita la marca del producto
	void prod_EditarValor(float); ///Edita el valor del producto
	void prod_EditarDescr(std::string); ///Edita la descripci�n del producto
	
	void DeshabilitarProducto(); ///Deshabilitar un producto
	void HabilitarProducto(); ///Habilitar un producto
	
	std::string ValidarDatos(); ///Valida que los campos ingresados sean correctos para guardar bien el producto
	std::string validarExistenciaCodigo(); //S�lo para verificar si el c�digo ya existe y no sobreescribir
};

bool criterio_de_comparacion_pnombre(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pmarca(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pcodigo(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pvalor(const Producto &p1, const Producto &p2);
bool criterio_de_comparacion_pdescripcion(const Producto &p1, const Producto &p2);


#endif
