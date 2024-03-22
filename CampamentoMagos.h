#pragma once
#include "Mago.h"
#include <vector>
#include "memory.h"
class CampamentoMagos
{
private: 
	vector <Mago*> Magos; 
public: 
	CampamentoMagos(); 
	~CampamentoMagos(); 
	vector <Mago*> getMagos(); 
	void setMagos(vector <Mago*> Magos); 
	void AgregarMago(Mago* mago);
	void EliminarMago(int pos); 
	void ListarMagos(); 
	void GuardarMagos(); 
	void CargarMagos(); 
	void SimularBatalla(); 
};