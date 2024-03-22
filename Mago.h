#pragma once
using namespace std;
#include <iostream>
class Mago
{
private:
	string Nombre ="";
	string TipodeMago="";
	int Poder=0;
	int Velocidad=0;
	int Resistencia=0;
	int Ataque=0;
	int vida=0;
public:
	Mago(string Nombre, string TipodeMago, int Poder, int Velocidad, int Resistencia, int Ataque, int vida); 
	Mago(); 
	~Mago(); 
	string getNombre() const ;
	void setNombre(string Nombre); 
	string getTipodeMago();
	void setTipodeMago(string TipodeMago);
	int getPoder();
	void setNPoder(int Poder);
	int getVelocidad();
	void setVelocidad(int Velocidad);
	int getResistencia() ;
	void setResistencia(int Resistencia);
	int getAtaque() ;
	void setAtaque(int Ataque);
	int getvida();
	void setvida(int vida);
	string Tostring(); 
};