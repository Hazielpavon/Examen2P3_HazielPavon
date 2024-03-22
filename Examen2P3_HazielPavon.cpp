#include <iostream>
#include <string>
#include "Mago.h"
#include "CampamentoMagos.h"
using namespace std;
void ejercicio1() {
	bool seguir = true;
	Mago* mago = new Mago();
	CampamentoMagos* Campamento = new CampamentoMagos();
	while (seguir) {
		cout << "---- Bienvenido Al FREE ROYALE ----" << endl;
		cout << "1. Crear un Mago" << endl;
		cout << "2. Eliminar un Mago" << endl;
		cout << "3. Listar los Magos" << endl;
		cout << "4. Guardar Magos" << endl;
		cout << "5. Cargar Magos" << endl;
		cout << "6. Simular Batalla" << endl;
		cout << "7. Salir" << endl;
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			string Nombre, TipodeMago;
			int Poder, Velocidad, Resistencia, Ataque, vida, tipodemagoint;
			bool vali = true, vali2 = true, vali3 = true, vali4 = true, vali5 = true;
			cout << "Ingrese el nombre del mago: ";
			cin.ignore();
			getline(cin, Nombre);
			while (vali) {
				cout << "Ingrese el tipo de mago (1. Fuego, 2.Electrico, 3.Hielo): ";
				cin >> tipodemagoint;
				if (tipodemagoint > 4 || tipodemagoint < 0) {
					cout << "El tipo de mago va desde 1 hasta 3" << endl;
				}
				else {
					vali = false;
				}
			}
			if (tipodemagoint == 1) {
				TipodeMago = "Fuego";
				while (vali2) {
					cout << "Ingrese el poder (70-100): ";
					cin >> Poder;
					if (Poder > 99 || Poder < 69) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali2 = false;
					}
				}
				while (vali3) {
					cout << "Ingrese La velocidad (40-70): ";
					cin >> Velocidad;
					if (Poder > 69 || Poder < 39) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali3 = false;
					}
				}
				while (vali4) {
					cout << "Ingrese la Resistenca (30-60): ";
					cin >> Resistencia;
					if (Resistencia > 59 || Resistencia < 29) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali4 = false;
					}
				}
				while (vali5) {
					cout << "Ingrese el ataque (60-90): ";
					cin >> Resistencia;
					if (Resistencia > 89 || Resistencia < 59) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali5 = false;
					}
				}
				mago = new Mago(Nombre, TipodeMago, Poder, Velocidad, Resistencia, Ataque, vida);
				Campamento->AgregarMago(mago);
			}
			else if (tipodemagoint == 2) {
				TipodeMago = "Electrico";
				while (vali2) {
					cout << "Ingrese el poder (50-80): ";
					cin >> Poder;
					if (Poder > 79 || Poder < 49) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali2 = false;
					}
				}
				while (vali3) {
					cout << "Ingrese La velocidad (60-100): ";
					cin >> Velocidad;
					if (Poder > 99 || Poder < 59) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali3 = false;
					}
				}
				while (vali4) {
					cout << "Ingrese la Resistenca (40-70): ";
					cin >> Resistencia;
					if (Resistencia > 69 || Resistencia < 39) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali4 = false;
					}
				}
				while (vali5) {
					cout << "Ingrese el ataque (50-80): ";
					cin >> Resistencia;
					if (Resistencia > 79 || Resistencia < 49) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali5 = false;
					}
				}
				mago = new Mago(Nombre, TipodeMago, Poder, Velocidad, Resistencia, Ataque, vida);
				Campamento->AgregarMago(mago);
			}
			else {
				TipodeMago = "Hielo";
				while (vali2) {
					cout << "Ingrese el poder (60-90): ";
					cin >> Poder;
					if (Poder > 89 || Poder < 59) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali2 = false;
					}
				}
				while (vali3) {
					cout << "Ingrese La velocidad (30-60): ";
					cin >> Velocidad;
					if (Poder > 59 || Poder < 29) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali3 = false;
					}
				}
				while (vali4) {
					cout << "Ingrese la Resistenca (50-80): ";
					cin >> Resistencia;
					if (Resistencia > 79 || Resistencia < 49) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali4 = false;
					}
				}
				while (vali5) {
					cout << "Ingrese el ataque (40-70): ";
					cin >> Resistencia;
					if (Resistencia > 69 || Resistencia < 39) {
						cout << "Ingrese correctamente los datos" << endl;
					}
					else {
						vali5 = false;
					}
				}
				mago = new Mago(Nombre, TipodeMago, Poder, Velocidad, Resistencia, Ataque, vida);
				Campamento->AgregarMago(mago);
			}
			break;
		}
		case 2: {
			cout << "Lista de los Magos" << endl; 
			Campamento->ListarMagos();
			cout << "Ingrese el indice para eliminar un mago: "; 
			int index; 
			cin >> index; 
			if (index >= 0 && index <= Campamento->getMagos().size()) {
				Campamento->EliminarMago(index-1); 
			}
			else {
				cout << "Indice Incorrecto" << endl; 
			}

			break;
		}
		case 3: {
			Campamento->ListarMagos();
			break;
		}
		case 4: {
			Campamento->GuardarMagos();
			break;
		}
		case 5: {
			Campamento->CargarMagos();
			break;
		}
		case 6: {
			Campamento->SimularBatalla();
			break;
		}
		case 7: {
			cout << "Saliendo..." << endl;
			seguir = false;
			break;
		}
		default: {
			cout << "Ingrese una opcion Valida" << endl;
			break;
		}
		}
	}
	delete mago;
}
int main()
{
	ejercicio1();
}