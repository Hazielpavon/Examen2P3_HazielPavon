#include "CampamentoMagos.h"
#include "Mago.h"
#include <string>
#include <iostream>
#include <fstream>
CampamentoMagos::CampamentoMagos()
{
}
CampamentoMagos::~CampamentoMagos()
{
	for (auto magos : Magos) {
		delete[] magos;
	}
}
vector<Mago*> CampamentoMagos::getMagos()
{
	return Magos;
}
void CampamentoMagos::setMagos(vector<Mago*> Magos)
{
	this->Magos = Magos;
}
void CampamentoMagos::AgregarMago(Mago* mago)
{
	Magos.push_back(mago);
	cout << "Mago agregado exitosamente!" << endl;
}
void CampamentoMagos::EliminarMago(int pos)
{
	Magos.erase(Magos.begin() + pos);
	cout << "Mago eliminado exitosamente!" << endl;
}
void CampamentoMagos::ListarMagos()
{
	for (int i = 0; i < Magos.size(); i++)
	{
		Magos[i]->Tostring();
	}
}
void CampamentoMagos::GuardarMagos()
{
	ofstream archivo("Magos.xyz", ios::binary | ios::app);
	if (archivo.is_open()) {
		archivo.write(reinterpret_cast<char*>(&Magos), sizeof(Magos));
		archivo.close();
		cout << "Datos guardados en Magos.xyz" << endl;
	}
	else {
		cout << "Error al abrir el archivo." << endl;
	}
}
void CampamentoMagos::CargarMagos()
{
	ifstream archivoRecuperado("Magos.xyz", ios::binary | ios::app);
	if (archivoRecuperado.is_open()) {
		archivoRecuperado.read(reinterpret_cast<char*>(&Magos), sizeof(Magos));
		archivoRecuperado.close();
	}
	else {
		cout << "Error al abrir el archivo para recuperar los datos." << endl;
	}
}
void CampamentoMagos::SimularBatalla()
{

}