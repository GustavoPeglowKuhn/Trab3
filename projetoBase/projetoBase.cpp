// projetoBase.cpp : main project file.

#include "stdafx.h"
#include "FormMain.h"
#include "FormFicha.h"

using namespace projetoBase;

[STAThreadAttribute]
int main(array<System::String ^> ^args){
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	//Application::Run(gcnew Form1());
	Application::Run(gcnew FormMain());
	return 0;
}
