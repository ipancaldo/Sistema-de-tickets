#include "HijaPrincipal.h"
#include "HijaAgregarC.h"
#include "HijaAdmClientes.h"

///Constructor
HijaPrincipal::HijaPrincipal(Financiero *financiero) : ///Recibe puntero agenda
	BasePrincipal(nullptr)/*no tiene padre*/, m_financiero(financiero)/*iniciamos el puntero con lo que le acabamos de pasar*/
{
//	RefrescarGrilla();
//	m_financiero->Cantidad
}



void HijaPrincipal::ClickBotonAdministrarCliente(wxCommandEvent& event)  {
	HijaAdmClientes *win = new HijaAdmClientes(this, m_financiero);
	/*if(*/win->ShowModal();/*==1)*////En caso de clickear agregar, devuelve 1 y refresca
//		RefrescarGrilla(); 
		///Cuando creemos la grilla, se descomentan las dos lineas previas
}

void HijaPrincipal::ImprimirTicket( wxCommandEvent& event )  {
	event.Skip();
}
