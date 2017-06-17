#pragma once

enum habilidadeTipo{ acao=0, reacao=1, suporte=2 };

ref class Habilidade{
public:
	int id;
	habilidadeTipo tipo;
	System::String^ nome;
	System::String^ bonus;
	//int forca, agilidade, intelligencia, vontade;
	//int req_nivel;

	Habilidade(int, habilidadeTipo, System::String^, System::String^);
};

