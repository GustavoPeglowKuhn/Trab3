#pragma once

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
	/// Summary for FormNovo
	/// </summary>
	public ref class FormNovo : public System::Windows::Forms::Form {
	private:
		List<int> ^racasId, ^classesId;		//ids
		//List<String^> ^racas, ^classes;		//nomes		//não  necessario
		PgSqlConnection^ pgc;
		//Form^ formMain;

	public:
		FormNovo(PgSqlConnection^ _pgc) {		//Form^ _formMain,	//formMain = _formMain;
			InitializeComponent();
			pgc = _pgc;
			loadRacas();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormNovo(){
			if (components){
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::TextBox^  txt_jogador;
		System::Windows::Forms::TextBox^  txt_personagem;
		System::Windows::Forms::TextBox^  txt_motiv;
		System::Windows::Forms::Label^  label5;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::ComboBox^  cb_raca;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::ComboBox^  cb_classe;
		System::Windows::Forms::Button^  btn_ok;
		System::Windows::Forms::Button^  btn_cancel;

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
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormNovo::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_jogador = (gcnew System::Windows::Forms::TextBox());
			this->txt_personagem = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cb_raca = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cb_classe = (gcnew System::Windows::Forms::ComboBox());
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->txt_motiv = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Jogador: ";
			// 
			// txt_jogador
			// 
			this->txt_jogador->Location = System::Drawing::Point(90, 6);
			this->txt_jogador->Name = L"txt_jogador";
			this->txt_jogador->Size = System::Drawing::Size(121, 20);
			this->txt_jogador->TabIndex = 1;
			// 
			// txt_personagem
			// 
			this->txt_personagem->Location = System::Drawing::Point(90, 41);
			this->txt_personagem->Name = L"txt_personagem";
			this->txt_personagem->Size = System::Drawing::Size(121, 20);
			this->txt_personagem->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Personagem: ";
			// 
			// cb_raca
			// 
			this->cb_raca->FormattingEnabled = true;
			this->cb_raca->Location = System::Drawing::Point(289, 6);
			this->cb_raca->Name = L"cb_raca";
			this->cb_raca->Size = System::Drawing::Size(121, 21);
			this->cb_raca->TabIndex = 4;
			this->cb_raca->SelectedIndexChanged += gcnew System::EventHandler(this, &FormNovo::cb_raca_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(239, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Raça: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(239, 45);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Classe: ";
			// 
			// cb_classe
			// 
			this->cb_classe->Enabled = false;
			this->cb_classe->FormattingEnabled = true;
			this->cb_classe->Location = System::Drawing::Point(289, 42);
			this->cb_classe->Name = L"cb_classe";
			this->cb_classe->Size = System::Drawing::Size(121, 21);
			this->cb_classe->TabIndex = 6;
			this->cb_classe->SelectedIndexChanged += gcnew System::EventHandler(this, &FormNovo::cb_classe_SelectedIndexChanged);
			// 
			// btn_ok
			// 
			this->btn_ok->Enabled = false;
			this->btn_ok->Location = System::Drawing::Point(112, 120);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(75, 23);
			this->btn_ok->TabIndex = 8;
			this->btn_ok->Text = L"Criar";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &FormNovo::btn_ok_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_cancel->Location = System::Drawing::Point(246, 120);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 9;
			this->btn_cancel->Text = L"Cancelar";
			this->btn_cancel->UseVisualStyleBackColor = true;
			// 
			// txt_motiv
			// 
			this->txt_motiv->Location = System::Drawing::Point(90, 80);
			this->txt_motiv->Name = L"txt_motiv";
			this->txt_motiv->Size = System::Drawing::Size(320, 20);
			this->txt_motiv->TabIndex = 11;
			this->txt_motiv->TextChanged += gcnew System::EventHandler(this, &FormNovo::textBox1_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Motivação: ";
			// 
			// FormNovo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(422, 155);
			this->Controls->Add(this->txt_motiv);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->btn_ok);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->cb_classe);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cb_raca);
			this->Controls->Add(this->txt_personagem);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_jogador);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"FormNovo";
			this->Text = L"Novo Personagem";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void loadRacas(){
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, nome FROM raca", pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				
				
				racasId = gcnew List<int>();
				cb_raca->Items->Clear();
				while(pgReader->Read()){
					racasId->Add(pgReader->GetInt32(0));
					cb_raca->Items->Add(pgReader->GetString(1));
				}
			} catch(Exception^){}
		}

		void loadClasses(){
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, nome FROM classe, rac_classes WHERE"
					+ " classe.id = rac_classes.c_id AND rac_classes.r_id = " + racasId[cb_raca->SelectedIndex], pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				
				classesId = gcnew List<int>();
				cb_classe->Items->Clear();
				while(pgReader->Read()){
					classesId->Add(pgReader->GetInt32(0));
					cb_classe->Items->Add(pgReader->GetString(1));
				}
			} catch(Exception^){}
		}

		System::Void cb_raca_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			btn_ok->Enabled = false;
			cb_classe->Enabled = true;
			cb_classe->SelectedIndex = -1;	//testar
			cb_classe->ResetText();
			loadClasses();
		}
		System::Void cb_classe_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			btn_ok->Enabled = true;
		}

		System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e){
			if(txt_jogador->Text->Length == 0){
				MessageBox::Show("O campo deve ser preenchido", "Jogador invalido");
				return;
			}
			if(txt_personagem->Text->Length == 0){
				MessageBox::Show("O campo deve ser preenchido", "Personagem invalido");
				return;
			}
			if(txt_motiv->Text->Length == 0){
				MessageBox::Show("Falta de motivação pode causar serios problemas, em batlhas ou em dificuldade de se levantar do banco de uma taverna\r\n"
					, "Falta de motivação");
				return;
			}
			try{
				int rid = racasId[cb_raca->SelectedIndex], cid = classesId[cb_classe->SelectedIndex];
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("INSERT INTO personagem "
					+ "(personagem, jogador, motivacao, "
					+ "experiencia, nivel, mana_max, mana, vida_max, vida, "
					+ "raca, classe, "
					+ "atributos, defesa, carga) "
					+ "VALUES ('" + txt_personagem->Text + "', '" + txt_jogador->Text + "', '" + txt_motiv->Text + "', "
					+ " 0, 1, 60, 60, 60, 60, "
					+ racasId[cb_raca->SelectedIndex] + ", "+ classesId[cb_classe->SelectedIndex]
					+ ", '{0,0,0,0}', '{0,0,0}', '{0,0,0}')", pgc);
				pgc->Open();
				pgCommand->ExecuteNonQuery();
			} catch(Exception^){}
			this->Close();	//retorna para o menu depois de criar o personagem
							//trocar para enviar para o FromFicha
		}
		System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e){}
	};
}
