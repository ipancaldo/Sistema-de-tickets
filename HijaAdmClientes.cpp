#include "HijaAdmClientes.h"
#include "HijaAgregarC.h"
#include "HijaEditarC.h"
#include <wx/msgdlg.h>
#include "string_conv.h"

HijaAdmClientes::HijaAdmClientes(wxWindow *parent, Financiero *financiero) : 
	VentanaAdministrarClientes(parent), m_financiero(financiero) 
{
	RefrescarGrilla(); ///Funcion que refresca lo que vemos (se visualiza abajo como lo hace)
}


void HijaAdmClientes::RefrescarGrilla(){
	//Grilla de CLIENTES
	///Si la grilla no está vacía, hace esto
	if(m_c_grilla->GetNumberRows()!=0)
		m_c_grilla->DeleteRows(0,m_c_grilla->GetNumberRows());
	
	///SI DESCOMENTO ES PARA PROBAR CON DESHABILITAR Y NO CON ELIMINAR		
	//	std::vector<int> v = m_financiero->MostrarClientesHabilitados(true);
	//	for(size_t i=0 ; i<v.size(); i++){
	for(int i=0 ; i<m_financiero->CantidadClientes(); i++){
		//		Cliente &c = m_financiero->SeleccionarCliente(v[i]);
		Cliente &c = m_financiero->SeleccionarCliente(i);
		///Para mostrar clientes HABILITADOS (cuando se "elimina" se deshabilita)
		if(c.VerEstado() == true){
			m_c_grilla->AppendRows(); //Agrega grillas a medida que metemos datos
			///SetCellValue = setear valor de la celda, que va a ir adentro. i fila 0 columna
			m_c_grilla->SetCellValue(i,0,c.VerApellido()+", "+c.VerNombre());
			m_c_grilla->SetCellValue(i,1,c.VerDNI());
			m_c_grilla->SetCellValue(i,2,c.VerAlias());
			m_c_grilla->SetCellValue(i,3,c.VerDireccion());
			m_c_grilla->SetCellValue(i,4,c.VerTelefono());
			m_c_grilla->SetCellValue(i,5,c.VerMail());
		}
	}
	
}


void HijaAdmClientes::ClickBotonAgregarCliente( wxCommandEvent& event )  {
	///Esto estoy haciendo (copiando 23:42)
	///Abrimos una nueva ventana de AgregarC
	HijaAgregarC *win = new HijaAgregarC(this, m_financiero);
	///El ShowModal es para ventanas del tipo DIALOG. Puede almacenar un dato
	///En este caso 1= Aceptar 2=Cancelar
	if(win->ShowModal()==1)
		RefrescarGrilla();
}

/// NUEVO-------------------------------------------24/08/2020


void HijaAdmClientes::ClickBotonEliminarCliente( wxCommandEvent& event )  {
	int f = m_c_grilla-> GetGridCursorRow(); ///Para tomar la grilla seleccionada
	///Creamos un cliente por referencia para seleccionarlo y luego deshabilitarlo
	//	Cliente &c = m_financiero->SeleccionarCliente(f);
	///Mensaje de alerta, en caso de aceptar, se guardan los cambios (eliminar)
	int x = wxMessageBox("Esta seguro de eliminar?","Advertencia", wxYES_NO|wxICON_QUESTION);
	if(x==wxYES){
		///Descomentar para DESHABILITAR y comentar ELIMINAR
		//		c.DeshabilitarCliente(); ///No lo eliminarmos, para más seguridad
		m_financiero->EliminarCliente(f);
		m_financiero->GuardarClientes();
		RefrescarGrilla();
	}	
}

void HijaAdmClientes::ClickBotonEditarCliente( wxCommandEvent& event )  {
	int fila = m_c_grilla-> GetGridCursorRow(); ///Para tomar la grilla seleccionada (indice)
	///Creamos un cliente por referencia para seleccionarlo y poder modificarlo
	HijaEditarC nueva_ventana(this, m_financiero, fila);
	///El ShowModal es para ventanas del tipo DIALOG. Puede almacenar un dato
	///En este caso 1= Aceptar 2=Cancelar
	if(nueva_ventana.ShowModal()==1)
		RefrescarGrilla();
}


/// NUEVO-------------------------------------------24/10/2020


//Al realizar doble click, abre el editor sobre el Cliente
void HijaAdmClientes::OnDobleClickGCliente( wxGridEvent& event )  {
	int fila = m_c_grilla-> GetGridCursorRow();
	HijaEditarC nueva_ventana(this, m_financiero, fila);
	if(nueva_ventana.ShowModal()==1)
		RefrescarGrilla();	
}

//Ordena columnas por criterio
void HijaAdmClientes::OnClickGCliente( wxGridEvent& event )  {
	int columna=event.GetCol();
	int cant_clientes=m_financiero->CantidadClientes();
	switch(columna) { /// ordena la lista de clientes por:
	case 0: m_financiero->Ordenar(por_apellido); break;
	case 1: m_financiero->Ordenar(por_dni); break;
	case 2: m_financiero->Ordenar(por_alias); break;
	case 3: m_financiero->Ordenar(por_direccion); break;
	case 4: m_financiero->Ordenar(por_telefono); break;
	case 5: m_financiero->Ordenar(por_mail); break;
	}
	RefrescarGrilla();
}



void HijaAdmClientes::EnterBuscar( wxCommandEvent& event )  {
	OnClickBuscar(event);
}


/// Tengo que arreglar el problema por el cual me sale el error!
/// Supuestamente viene por acá el problema de que al entrar a ADMINISTRAR CLIENTE
///salte una advertencia/error
void HijaAdmClientes::OnClickBuscar( wxCommandEvent& event )  {
	/// Esto sirve para guardar en una variable el str del recuadro, pero primero
	///se debe pasar del formato wx a std::string con .ToStdString()
	std::string Buscar = m_cli_buscar->GetValue().ToStdString();
	int Encontrado;
	
	for(size_t i = 0; i<m_financiero->CantidadClientes(); i++){
		Encontrado = m_financiero->BuscarNombre(Buscar);
		if(Encontrado != -1){
			m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
			m_c_grilla->SelectRow(Encontrado); // seleccionar
		}else{
			Encontrado = m_financiero->BuscarApellido(Buscar);
			if(Encontrado != -1){
				m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
				m_c_grilla->SelectRow(Encontrado); // seleccionar
			}else{
				Encontrado = m_financiero->BuscarAlias(Buscar);
				if(Encontrado != -1){
					m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
					m_c_grilla->SelectRow(Encontrado); // seleccionar
				}else{
					Encontrado = m_financiero->BuscarMail(Buscar);
					if(Encontrado != -1){
						m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
						m_c_grilla->SelectRow(Encontrado); // seleccionar
					}else{
						Encontrado = m_financiero->BuscarDireccion(Buscar);
						if(Encontrado != -1){
							m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
							m_c_grilla->SelectRow(Encontrado); // seleccionar
						}else{
							Encontrado = m_financiero->BuscarTelefono(Buscar);
							if(Encontrado != -1){
								m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
								m_c_grilla->SelectRow(Encontrado); // seleccionar
							}else{
								Encontrado = m_financiero->BuscarDni(Buscar);{
									if(Encontrado != -1){
										m_c_grilla->SetGridCursor(Encontrado,0); // seleccionar
										m_c_grilla->SelectRow(Encontrado); // seleccionar
									}else{
										wxMessageBox("No se encontró resultado"); ///Sería -1
										break;
									}
								};
							}
						}
					}
				}
			}
		}
		
	}
	
}



//Al clickear cancelar
void HijaAdmClientes::ClickCancelarAdmCliente( wxCommandEvent& event )  {
	EndModal(0);
}

//Al clickear aceptar
void HijaAdmClientes::ClickAceptarAdmCliente( wxCommandEvent& event )  {
	EndModal(1);
}

///Esto creo que no es necesario, es para ir cargando las filas en la cuadrícula
///a medida que va haciendo algo el sistema
void HijaAdmClientes::cargar_datos_fila(int fila){
	//	Cliente &c = m_financiero->SeleccionarCliente(fila);
	//	
	//	m_c_grilla->SetCellValue(fila, 0, std_to_wx(c.VerApellido())+", "+std_to_wx(c.VerNombre());
	//	m_c_grilla->SetCellValue(fila, 1, std_to_wx(c.VerDNI()) );
	//	m_c_grilla->SetCellValue(fila, 2, std_to_wx(c.VerAlias()) );
	//	m_c_grilla->SetCellValue(fila, 3, std_to_wx(c.VerDireccion()) );
	//	m_c_grilla->SetCellValue(fila, 4, std_to_wx(c.VerTelefono()) );
	//	m_c_grilla->SetCellValue(fila, 5, std_to_wx(c.VerMail()) );
}
