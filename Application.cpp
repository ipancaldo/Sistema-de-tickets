#include <wx/image.h>
#include "Application.h"
#include "HijaPrincipal.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	///el "negocio" en el cual vamos a trabajar
	///La verdadera instancia
	m_financiero = new Financiero();
	///A la ventana, le pasamos el puntero "negocio" (para que lo tenga) en cual vamos a trabajar
	HijaPrincipal *win = new HijaPrincipal(m_financiero);
	win->Show();
	return true;
}

