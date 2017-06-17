#include "stdafx.h"
#include "Habilidade.h"

//Habilidade::Habilidade(){
Habilidade::Habilidade(int id, habilidadeTipo tipo, System::String^ nome, System::String^ bonus){
	this->id = id;
	this->tipo = tipo;
	this->nome = nome;
	this->bonus = bonus;
}
