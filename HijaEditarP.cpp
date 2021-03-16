#include "HijaEditarP.h"
#include "Cliente.h"
#include "Financiero.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>

// Ante todo, guardamos el código actual al inicio de editar (código original),
//a fin de verificar si se modificó. Si no se modificó, no busca si ese código ya 
//existe en la BD. Si se modificó, debería salir una alerta que se modificó (porque
//es muy importante) y preguntar si deseamos continuar. En caso que si: se busca en
//la BD si se encuentra ya en uso.
std::string verificadorCodigoInicial;

HijaEditarP::HijaEditarP(wxWindow *parent, Financiero *financiero, int cual) ///Pasamos a quién modificamos
	: VentanaAgrEditProductos(parent), m_financiero(financiero), QueProducto(cual)
{
	Producto &p = m_financiero->SeleccionarProducto(cual);
	m_p_codigo->SetValue( std_to_wx(p.prod_VerCodigo()));
	m_p_producto->SetValue( std_to_wx(p.prod_VerNombre()));
	m_p_marca->SetValue( std_to_wx(p.prod_VerMarca()));
	///Transformamos el float en un wxstring para que se pueda mostrar
	///%.2f hace que se vean sólo 2 decimales
	wxString mystring = wxString::Format(wxT("%.2f"), p.prod_VerValor());
	m_p_precio->SetValue(mystring);
	m_p_descripcion->SetValue( std_to_wx(p.prod_VerDescr()));
	///Modifico el nombre de los botones asi puede utilizarse en otra apertura como editar
	m_p_aceptarA->SetLabel("Editar");
	m_p_cancelarB->SetLabel("Cancelar");
	///Modifico lo que dice el titulo de la ventana (para este caso, agregar)
	m_p_titulo->SetLabel("Editar producto:");
	///Titulo de la barra de la ventana
	SetTitle("Editar producto");
	
	verificadorCodigoInicial = p.prod_VerCodigo();
}

void HijaEditarP::OnClickButtonAceptarA( wxCommandEvent& event )  {
	// Creamos un producto para ver si los datos son correctos
	//(no por referencia para no guardar en este paso)
	///Transformamos el wxString del precio a float para poder pasarselo al constructor
	float decimalNumber = wxAtof(m_p_precio->GetValue());
	Producto p2(
		wx_to_std(m_p_producto->GetValue()),
		wx_to_std(m_p_marca->GetValue()),
		wx_to_std(m_p_codigo->GetValue()),
		///Acá se debe pasar el wxString mystring a float;
		decimalNumber,
		wx_to_std(m_p_descripcion->GetValue())
	);
	
	// Guardamos un bool para ver si el código se mantuvo o se modificó
	std::string verificadorCodigoActual = wx_to_std(m_p_codigo->GetValue());
	bool codigoModificado = (verificadorCodigoInicial == verificadorCodigoActual);
	// Siguiente paso, es verificar que no haya errores (campos vacíos, etc)
	std::string errores = p2.ValidarDatos();
	std::string erroresExistenciaCodigo = p2.validarExistenciaCodigo();
	
	if(errores.empty()){	///En caso de no haber ninguno, guarda y acepta
		if(codigoModificado == false){
			if(erroresExistenciaCodigo.empty()){
				int respuesta = wxMessageBox("Esta seguro de editar el codigo?","Advertencia!", wxYES_NO|wxICON_EXCLAMATION);
			
				if(respuesta==wxYES){
					// Tomamos el producto por referencia
					Producto &p1 = m_financiero->SeleccionarProducto(QueProducto);
					// Guardamos la info con cada una de las funciones propias
					/// Tomamos los valores visualizados en pantalla (modificados por nosotros)
					///y lo transformamos a STRING para poder guardarlo
					p1.prod_EditarCodigo(wx_to_std(m_p_codigo->GetValue()));
					p1.prod_EditarNombre(wx_to_std(m_p_producto->GetValue()));
					p1.prod_EditarMarca(wx_to_std(m_p_marca->GetValue()));
					///p1.prod_EditarValor(wx_to_std(m_p_precio->GetValue()));
					//
					float decimalNumber = wxAtof(m_p_precio->GetValue());
					p1.prod_EditarValor(decimalNumber);
					p1.prod_EditarDescr(wx_to_std(m_p_descripcion->GetValue()));
					
					// Guardamos por las dudas además
					m_financiero->GuardarProductos();
					EndModal(1);
				}
				else{
					wxMessageBox(erroresExistenciaCodigo,"error",wxOK|wxICON_ERROR);
				}
			}
		} else{
			///ACA GUARDA SIN EDITAR CÓDIGO
			// Tomamos el producto por referencia
			Producto &p1 = m_financiero->SeleccionarProducto(QueProducto);
			// Guardamos la info con cada una de las funciones propias
			/// Tomamos los valores visualizados en pantalla (modificados por nosotros)
			///y lo transformamos a STRING para poder guardarlo
			p1.prod_EditarNombre(wx_to_std(m_p_producto->GetValue()));
			p1.prod_EditarMarca(wx_to_std(m_p_marca->GetValue()));
			///p1.prod_EditarValor(wx_to_std(m_p_precio->GetValue()));
			float decimalNumber = wxAtof(m_p_precio->GetValue());
			p1.prod_EditarValor(decimalNumber);
			p1.prod_EditarDescr(wx_to_std(m_p_descripcion->GetValue()));
			
			// Guardamos por las dudas además
			m_financiero->GuardarProductos();
			EndModal(1);
		}
	}else{
		///Con esto me tira el iconito de error y el mensajito de error!
		wxMessageBox(errores,"error",wxOK|wxICON_ERROR);
	}
	
}

void HijaEditarP::OnClickButtonCancelarB( wxCommandEvent& event )  {
	EndModal(0);
}

HijaEditarP::~HijaEditarP() {
	
}

