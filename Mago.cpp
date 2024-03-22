#include "Mago.h"
#include <string>
Mago::Mago(string Nombre, string TipodeMago, int Poder, int Velocidad, int Resistencia, int Ataque, int vida) :
	Nombre(Nombre), TipodeMago(TipodeMago), Poder(Poder), Velocidad(Velocidad), Resistencia(Resistencia), Ataque(Ataque), vida(vida)
{}
Mago::Mago()
{
}
Mago::~Mago()
{
	Nombre = " ";
	TipodeMago = " ";
	Poder = 0;
	Velocidad = 0;
	Resistencia = 0;
	Ataque = 0;
	vida = 0;
}
string Mago::getNombre() const
{
	return Nombre; 
}
void Mago::setNombre(string Nombre)
{
	this->Nombre = Nombre; 
}
string Mago::getTipodeMago()
{
	return TipodeMago;
}
void Mago::setTipodeMago(string TipodeMago)
{
	this->TipodeMago = TipodeMago; 
}
int Mago::getPoder()
{
	return Poder;
}
void Mago::setNPoder(int Poder)
{
	this->Poder = Poder; 
}
int Mago::getVelocidad()
{
	return Velocidad;
}
void Mago::setVelocidad(int Velocidad)
{
	this->Velocidad = Velocidad; 
}
int Mago::getResistencia()
{
	return Resistencia;
}
void Mago::setResistencia(int Resistencia)
{
	this->Resistencia = Resistencia; 
}
int Mago::getAtaque()
{
	return Ataque;
}
void Mago::setAtaque(int Ataque)
{
	this->Ataque = Ataque; 
}
int Mago::getvida()
{
	return vida;
}
void Mago::setvida(int vida)
{
	this->vida = vida; 
}
string Mago::Tostring()
{
	return "Mago{ " + Nombre + "\nTipo De Mago: " + TipodeMago + "\nPoder: " + to_string(Poder) + "\nVelocidad: " + to_string(Velocidad) + "\nResistencia: " + to_string(Resistencia) + "\nAtaque: " + to_string(Ataque)+ "\n Vida: " + to_string(vida);
}