#include "stdafx.h"
#include "Equipamento.h"

Equipamento::Equipamento(int id, System::String^ nome, float peso, int quantidade, int usando){
	this->id = id;
	this->nome = nome;
	this->peso = peso;
	this->quantidade = quantidade;
	this->usando = usando;
}
