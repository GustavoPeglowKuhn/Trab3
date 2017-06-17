#pragma once
ref class Equipamento{
public:
	int id;
	System::String^ nome;
	float peso;
	int quantidade, usando;

	Equipamento(int, System::String^, float, int, int);
};

