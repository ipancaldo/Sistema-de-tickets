#include "HijaAdmClientes.h"
#include "HijaAgregarC.h"
#include <wx/msgdlg.h>

HijaAdmClientes::HijaAdmClientes(wxWindow *parent, Financiero *financiero) : 
	VentanaAdministrarClientes(parent), m_financiero(financiero) 
{
	RefrescarGrilla(); ///Funcion que refresca lo que vemos (se visualiza abajo como lo hace)
}


void HijaAdmClientes::RefrescarGrilla(){
//	///Grilla de CLIENTES
	///Si la grilla no tiene 0 grillas, hace eso
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

void HijaAdmClientes::ClickBotonEliminarCliente( wxCommandEvent& event )  {
	int f = m_c_grilla-> GetGridCursorRow(); ///Para tomar la grilla seleccionada
	///Creamos un cliente por referencia para seleccionarlo y luego deshabilitarlo
	Cliente &c = m_financiero->SeleccionarCliente(f);
	///Mensaje de alerta, en caso de aceptar, se guardan los cambios (eliminar)
	int x = wxMessageBox("Esta seguro de eliminar?","Advertencia", wxYES_NO|wxICON_QUESTION);
	if(x==wxYES){
		///Descomentar para DESHABILITAR y comentar ELIMINAR
//		c.DeshabilitarCliente(); ///No lo eliminarmos, para más seguridad
		m_financiero->EliminarCliente(f);
		m_financiero->GuardarClientes();
		RefrescarGrilla();
	}	
	RefrescarGrilla();
}

void HijaAdmClientes::ClickBotonEditarCliente( wxCommandEvent& event )  {
	
}

