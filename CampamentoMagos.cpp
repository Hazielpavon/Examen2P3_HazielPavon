#include "CampamentoMagos.h"
#include "Mago.h"
#include <string>
#include <iostream>
#include <fstream>
CampamentoMagos::CampamentoMagos()
{
}
// liberando memoria
CampamentoMagos::~CampamentoMagos()
{
	for (auto magos : Magos) {
		delete[] magos;
	}
}
// getters y setters
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
	// metodo sencillo de agregar
	Magos.push_back(mago);
	cout << "Mago agregado exitosamente!" << endl;
}
void CampamentoMagos::EliminarMago(int pos)
{
	//metodo aun mas sencillo de eiliminar
	if (!Magos.empty()) {
		Magos.erase(Magos.begin() + pos);
		cout << "Mago eliminado exitosamente!" << endl;
	}
	else {
		cout << "No hay Magos" << endl;
	}
}
void CampamentoMagos::ListarMagos()
{
	if (!Magos.empty()) {
		for (int i = 0; i < Magos.size(); i++)
		{
			cout << Magos[i]->Tostring();
		}
	}
	else {
		cout << "No hay Magos" << endl;
	}
}
void CampamentoMagos::GuardarMagos() {
	ofstream archivo("Magos.xyz", ios::binary | ios::app); // Igual que el lab pasado el app me resuelve 
	if (!archivo) {
		cout << "Error, si te falla aca ahi si no se" << endl;
	}
	for (const auto& mago : Magos) {
		archivo.write(reinterpret_cast<const char*>(mago), sizeof(Mago));
	}
	archivo.close();
}
void CampamentoMagos::CargarMagos() {
	ifstream archivo("Magos.xyz", ios::binary);
	if (!archivo) {
		cout << "Error, cual? Primero crea el archivo papiii" << endl;
	}
	// End Of File, igualito a java  
	while (archivo.peek() != EOF) {
		Mago* mago = new Mago();
		archivo.read(reinterpret_cast<char*>(mago), sizeof(Mago));
		Magos.push_back(mago);
	}
	archivo.close();
}
void CampamentoMagos::SimularBatalla()
{
	if (!Magos.empty()) {
		cout << "Seleccione dos magos para simular la batalla:" << endl;
		ListarMagos();
		// agarro dos magos pa que pelien 
		int indiceMago1, indiceMago2;
		cout << "Indice del primer mago: ";
		cin >> indiceMago1;
		cout << "Indice del segundo mago: ";
		cin >> indiceMago2;
		if (indiceMago1 < 0 || indiceMago1 >= Magos.size() || indiceMago2 < 0 || indiceMago2 >= Magos.size()) {
			cout << "Indice de mago inválido." << endl;
		}
		Mago* mago1 = Magos[indiceMago1];
		Mago* mago2 = Magos[indiceMago2];
		// aqui decido que mago va primero 
		Mago* atacante = new Mago();
		Mago* defensor = new Mago();
		if (mago1->getVelocidad() > mago2->getVelocidad()) {
			atacante = mago1;
			defensor = mago2;
		}
		else {
			atacante = mago2;
			defensor = mago1;
		}
		int contador = 0;
		while (atacante->getvida() > 0 && defensor->getvida() > 0) {
			// calculando el damage 
			int damage = (atacante->getAtaque() - (defensor->getResistencia() / 2)); // el calculo completo me causaba un ciclo infinito, lo reduci y funciono 
			int aumentoAtaque = rand() % 6 + 5;
			atacante->setAtaque(atacante->getAtaque() + aumentoAtaque);
			cout << "Turno: " << contador << endl;
			cout << atacante->getNombre() << " ataca a " << defensor->getNombre() << " Causando: " << damage << +", Dano" << endl;
			int x = defensor->getvida() - damage;
			defensor->setvida(x);
			cout << "Vida de " << defensor->getNombre() << ": " << defensor->getvida() << endl;
			swap(atacante, defensor);

			contador++;
		}
		if (atacante->getvida() <= 0) {
			cout << atacante->getNombre() << " ha sido derrotado." << endl;
			Magos.erase(Magos.begin() + indiceMago1);
		}
		else if (defensor->getvida() <= 0) {
			cout << defensor->getNombre() << " ha sido derrotado." << endl;
			Magos.erase(Magos.begin() + indiceMago2);

		}
		delete mago1;
		delete atacante;
		delete mago2;
		delete defensor;
	}
	else {
		cout << "No hay magos rey" << endl;
	}


}