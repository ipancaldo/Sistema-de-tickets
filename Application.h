#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Financiero.h"

class Application : public wxApp {
	Financiero *m_financiero;
public:
	virtual bool OnInit();
};

#endif
