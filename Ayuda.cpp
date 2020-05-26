#include "Ayuda.h"


void pasar_a_minusculas(std::string &palabra){
	int t = palabra.size();
	for(int i = 0; i<t; i++){
		palabra[i]=std::tolower(palabra[i]);
	}
}

std::string CorregirPalabra(std::string Palabra){
	if(!Palabra.empty()){//Si palabra no está vacío
		Palabra[0] = toupper(Palabra[0]);
		for(size_t i = 1; i<Palabra.size(); ++i){
			Palabra[i] = tolower(Palabra[i]);
		}
	}
	return Palabra;
}
