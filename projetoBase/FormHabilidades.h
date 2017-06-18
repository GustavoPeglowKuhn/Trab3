#pragma once

//#include "FormMain.h"

namespace projetoBase {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;		//List<...>
	using namespace Devart::Data::PostgreSql;

	/// <summary>
	/// Summary for FormHabilidades
	/// </summary>
	public ref class FormHabilidades : public System::Windows::Forms::Form {
	private:
		List<int>^ habilidades;
		int id, n_hab = 0;
		PgSqlConnection^ pgc;

	public:
		FormHabilidades(PgSqlConnection^ _pgc, int _id){
			InitializeComponent();

			pgc = _pgc;
			id = _id;
			loadHabilidades();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormHabilidades(){
			if (components){
				delete components;
			}
		}
	private: 
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::ComboBox^  cb_hab;
		System::Windows::Forms::TextBox^  txt_bonus;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  lbl_n_hab;
		System::Windows::Forms::Button^  btn_add;
		System::Windows::Forms::Button^  btn_voltar;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormHabilidades::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cb_hab = (gcnew System::Windows::Forms::ComboBox());
			this->btn_add = (gcnew System::Windows::Forms::Button());
			this->btn_voltar = (gcnew System::Windows::Forms::Button());
			this->txt_bonus = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_n_hab = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Habilidade:";
			// 
			// cb_hab
			// 
			this->cb_hab->FormattingEnabled = true;
			this->cb_hab->Location = System::Drawing::Point(78, 30);
			this->cb_hab->Name = L"cb_hab";
			this->cb_hab->Size = System::Drawing::Size(209, 21);
			this->cb_hab->TabIndex = 1;
			this->cb_hab->SelectedIndexChanged += gcnew System::EventHandler(this, &FormHabilidades::cb_hab_SelectedIndexChanged);
			// 
			// btn_add
			// 
			this->btn_add->Location = System::Drawing::Point(15, 149);
			this->btn_add->Name = L"btn_add";
			this->btn_add->Size = System::Drawing::Size(101, 23);
			this->btn_add->TabIndex = 2;
			this->btn_add->Text = L"Adicionar";
			this->btn_add->UseVisualStyleBackColor = true;
			this->btn_add->Click += gcnew System::EventHandler(this, &FormHabilidades::btn_add_Click);
			// 
			// btn_voltar
			// 
			this->btn_voltar->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn_voltar->Location = System::Drawing::Point(186, 149);
			this->btn_voltar->Name = L"btn_voltar";
			this->btn_voltar->Size = System::Drawing::Size(101, 23);
			this->btn_voltar->TabIndex = 3;
			this->btn_voltar->Text = L"Voltar";
			this->btn_voltar->UseVisualStyleBackColor = true;
			// 
			// txt_bonus
			// 
			this->txt_bonus->Location = System::Drawing::Point(12, 57);
			this->txt_bonus->Multiline = true;
			this->txt_bonus->Name = L"txt_bonus";
			this->txt_bonus->ReadOnly = true;
			this->txt_bonus->Size = System::Drawing::Size(275, 86);
			this->txt_bonus->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 189);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Habilidades adicionadas:";
			// 
			// lbl_n_hab
			// 
			this->lbl_n_hab->AutoSize = true;
			this->lbl_n_hab->Location = System::Drawing::Point(143, 189);
			this->lbl_n_hab->Name = L"lbl_n_hab";
			this->lbl_n_hab->Size = System::Drawing::Size(13, 13);
			this->lbl_n_hab->TabIndex = 6;
			this->lbl_n_hab->Text = L"0";
			// 
			// FormHabilidades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(310, 211);
			this->Controls->Add(this->lbl_n_hab);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_bonus);
			this->Controls->Add(this->btn_voltar);
			this->Controls->Add(this->btn_add);
			this->Controls->Add(this->cb_hab);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormHabilidades";
			this->Text = L"FormHabilidades";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		void loadHabilidades(){
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand(
					"SELECT distinct(habilidade.id), nome FROM habilidade, hab_gerais, rac_habilidades, cla_habilidades WHERE ("
					+"	habilidade.id = hab_gerais.h_id OR"
					+"	(rac_habilidades.r_id = (SELECT raca FROM personagem WHERE personagem.id = "+id+")"
					+"		AND habilidade.id = rac_habilidades.h_id) OR"
					+"		(cla_habilidades.c_id = (SELECT classe FROM personagem WHERE personagem.id = " + id + ")"
					+"			AND habilidade.id = cla_habilidades.h_id)"
					+"	) AND(habilidade.id NOT IN(SELECT h_id FROM m_hab WHERE p_id = " + id + "))", pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				habilidades = gcnew List<int>();
				cb_hab->Items->Clear();
				while(pgReader->Read()){
					habilidades->Add(pgReader->GetInt32(0));
					cb_hab->Items->Add(pgReader->GetString(1));
				}
			} catch(Exception^){}
		}
		void loadBonus(){
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand(
					"SELECT bonus FROM habilidade WHERE id = " + habilidades[cb_hab->SelectedIndex], pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				if(pgReader->Read())		//só uma linha
					txt_bonus->Text = pgReader->GetString(0);
			} catch(Exception^){}
		}

		System::Void cb_hab_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			btn_add->Enabled = true;
			loadBonus();
		}
		System::Void btn_add_Click(System::Object^  sender, System::EventArgs^  e){
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("INSERT INTO m_hab (p_id, h_id) VALUES ("
					+ id + ", " + habilidades[cb_hab->SelectedIndex] + ")", pgc);
				pgc->Open();
				pgCommand->ExecuteNonQuery();

				cb_hab->ResetText();
				cb_hab->SelectedIndex = -1;
				btn_add->Enabled = false;
				txt_bonus->Text = "";
				loadHabilidades();
				lbl_n_hab->Text = "" +(++n_hab);
			} catch(Exception^){}
		}
	};
}
