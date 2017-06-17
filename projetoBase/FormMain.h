#pragma once
#include "FormFicha.h"

namespace projetoBase{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//using namespace System::Collections::Generic;		//List<...>
	using namespace Devart::Data::PostgreSql;

	/// <summary>
	/// Summary for SelectForm
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form{
	private:
		int id;
		FormFicha^ formFicha;
		//Form^ formNew;

	public:
		FormMain(void){
			InitializeComponent();
//			this->SetStyle(static_cast<ControlStyles>(
//				ControlStyles::AllPaintingInWmPaint |
//				ControlStyles::DoubleBuffer |
//				ControlStyles::UserPaint), true);
//			this->UpdateStyles();

			get_cb_jogador_items();		//pega a lista de todos os jogadores no banco de daddos
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormMain(){
			if(components){
				delete components;
			}
		}

	private:
		Devart::Data::PostgreSql::PgSqlConnection^  pgSqlConnection1;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  lbl_raca;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::ComboBox^  cb_jogador;
		System::Windows::Forms::ComboBox^  cb_personagem;
		System::Windows::Forms::Label^  lbl1;
		System::Windows::Forms::Label^  lbl2;
		System::Windows::Forms::Label^  lbl_classe;
		System::Windows::Forms::Label^  lbl_nivel;
		System::Windows::Forms::Button^  btn_select;
		System::Windows::Forms::Button^  btn_new;
	
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void){
			this->btn_select = (gcnew System::Windows::Forms::Button());
			this->cb_jogador = (gcnew System::Windows::Forms::ComboBox());
			this->cb_personagem = (gcnew System::Windows::Forms::ComboBox());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->pgSqlConnection1 = (gcnew Devart::Data::PostgreSql::PgSqlConnection());
			this->btn_new = (gcnew System::Windows::Forms::Button());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			this->lbl_classe = (gcnew System::Windows::Forms::Label());
			this->lbl_nivel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_raca = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_select
			// 
			this->btn_select->Enabled = false;
			this->btn_select->Location = System::Drawing::Point(11, 173);
			this->btn_select->Name = L"btn_select";
			this->btn_select->Size = System::Drawing::Size(133, 23);
			this->btn_select->TabIndex = 0;
			this->btn_select->Text = L"Seleciona";
			this->btn_select->UseVisualStyleBackColor = true;
			this->btn_select->Click += gcnew System::EventHandler(this, &FormMain::btn_select_Click);
			// 
			// cb_jogador
			// 
			this->cb_jogador->FormattingEnabled = true;
			this->cb_jogador->Location = System::Drawing::Point(106, 12);
			this->cb_jogador->Name = L"cb_jogador";
			this->cb_jogador->Size = System::Drawing::Size(175, 21);
			this->cb_jogador->TabIndex = 1;
			this->cb_jogador->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::cb_jogador_SelectedIndexChanged);
			// 
			// cb_personagem
			// 
			this->cb_personagem->Enabled = false;
			this->cb_personagem->FormattingEnabled = true;
			this->cb_personagem->Location = System::Drawing::Point(106, 39);
			this->cb_personagem->Name = L"cb_personagem";
			this->cb_personagem->Size = System::Drawing::Size(175, 21);
			this->cb_personagem->TabIndex = 2;
			this->cb_personagem->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::cb_personagem_SelectedIndexChanged);
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lbl1->Location = System::Drawing::Point(12, 101);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(58, 17);
			this->lbl1->TabIndex = 3;
			this->lbl1->Text = L"Classe: ";
			// 
			// pgSqlConnection1
			// 
			this->pgSqlConnection1->CommitTimeout = 0;
			this->pgSqlConnection1->ConnectionString = L"User Id=postgres;Host=localhost;Database=rpg3;Unicode=True;Initial Schema=public;"
				L"";
			this->pgSqlConnection1->Name = L"pgSqlConnection1";
			this->pgSqlConnection1->Unicode = true;
			// 
			// btn_new
			// 
			this->btn_new->Location = System::Drawing::Point(151, 173);
			this->btn_new->Name = L"btn_new";
			this->btn_new->Size = System::Drawing::Size(130, 23);
			this->btn_new->TabIndex = 4;
			this->btn_new->Text = L"Novo";
			this->btn_new->UseVisualStyleBackColor = true;
			this->btn_new->Click += gcnew System::EventHandler(this, &FormMain::btn_new_Click);
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lbl2->Location = System::Drawing::Point(12, 131);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(51, 17);
			this->lbl2->TabIndex = 5;
			this->lbl2->Text = L"Nivel:  ";
			// 
			// lbl_classe
			// 
			this->lbl_classe->AutoSize = true;
			this->lbl_classe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lbl_classe->Location = System::Drawing::Point(76, 101);
			this->lbl_classe->Name = L"lbl_classe";
			this->lbl_classe->Size = System::Drawing::Size(12, 17);
			this->lbl_classe->TabIndex = 6;
			this->lbl_classe->Text = L".";
			// 
			// lbl_nivel
			// 
			this->lbl_nivel->AutoSize = true;
			this->lbl_nivel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lbl_nivel->Location = System::Drawing::Point(76, 131);
			this->lbl_nivel->Name = L"lbl_nivel";
			this->lbl_nivel->Size = System::Drawing::Size(12, 17);
			this->lbl_nivel->TabIndex = 7;
			this->lbl_nivel->Text = L".";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Jogador:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(12, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Personagem:";
			// 
			// lbl_raca
			// 
			this->lbl_raca->AutoSize = true;
			this->lbl_raca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lbl_raca->Location = System::Drawing::Point(76, 70);
			this->lbl_raca->Name = L"lbl_raca";
			this->lbl_raca->Size = System::Drawing::Size(12, 17);
			this->lbl_raca->TabIndex = 11;
			this->lbl_raca->Text = L".";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(12, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Ra�a:   ";
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(294, 204);
			this->Controls->Add(this->lbl_raca);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_nivel);
			this->Controls->Add(this->lbl_classe);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->btn_new);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->cb_personagem);
			this->Controls->Add(this->cb_jogador);
			this->Controls->Add(this->btn_select);
			this->Name = L"FormMain";
			this->Text = L"SelectForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void get_cb_jogador_items(){
			PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT jogador FROM personagem", pgSqlConnection1);
			cb_jogador->Items->Clear();
			try{
				pgSqlConnection1->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				while(pgReader->Read()){
					cb_jogador->Items->Add(pgReader->GetString(0));
				}
			} catch(Exception^){}
		}

		System::Void cb_jogador_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT personagem FROM personagem WHERE jogador = '" +
				cb_jogador->SelectedItem + "'", pgSqlConnection1);
			cb_personagem->Items->Clear();
			cb_personagem->Enabled = true;
			try{
				pgSqlConnection1->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				while(pgReader->Read()){
					cb_personagem->Items->Add(pgReader->GetString(0));
				}
			} catch(Exception^){}
		}
		System::Void cb_personagem_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			//SELECT personagem.id, raca.nome, personagem.nivel FROM personagem, raca WHERE raca.id = personagem.raca
			PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT personagem.id, raca.nome, classe.nome, personagem.nivel " +
				"FROM personagem, raca, classe WHERE raca.id = personagem.raca AND classe.id = personagem.classe AND "+
				"jogador = '" + cb_jogador->SelectedItem + "' AND personagem = '" + cb_personagem->SelectedItem + "'",
				pgSqlConnection1);
			//cb_personagem->Items->Clear();
			try{
				pgSqlConnection1->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				if(pgReader->Read()){	//s� vai ler uma linha
					btn_select->Enabled = true;
					id = pgReader->GetInt32(0);
					lbl_raca->Text = pgReader->GetString(1);
					lbl_classe->Text = pgReader->GetString(2);
					lbl_nivel->Text = pgReader->GetString(3);
				}
			} catch(Exception^){}
		}

		System::Void btn_select_Click(System::Object^  sender, System::EventArgs^  e){
			ShowFormFicha(id);
		}
		System::Void btn_new_Click(System::Object^  sender, System::EventArgs^  e){
			ShowFormNovo();
		}
		//System::Void FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e){
		//	this->Show();		////formFicha->OnClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormMain::FormFicha_FormClosed);
		//}

	public:			//O formulario da ficha pode chamar o formulario de novo formulario e vice versa
		void ShowFormFicha(int personagemId){
			this->formFicha = gcnew FormFicha(this, pgSqlConnection1, id);
			//this->formFicha->ShowDialog();
			this->formFicha->Show();
			this->Hide();
		}

		void ShowFormNovo(){
			//this->formNew = gcnew projetoBase::Form1(this);
			//this->formNew->Show();
			//this->Hide();
		}
	};
}
