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
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form{
	private:
		//propriedades do personagem atual
		int id, raca, classe;
		int experiencia, nivel, mana_max, mana, vida_max, vida;
		int forca, agilidade, inteligencia, vontade;
		int bloqueio, esquiva, determinacao;
		int basica, pesada, maxima;
		//!propriedades do personagem atual

		DateTime open;	//o memento de criacao do form, usado para compor o numero aleatorio do dado

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			open = DateTime::Now;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  lbl_personagem;
		System::Windows::Forms::Label^  lbl_raca;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  lbl_jogador;
		System::Windows::Forms::Label^  label6;
		System::Windows::Forms::Panel^  pnl_desc;
		System::Windows::Forms::Label^  label10;
		System::Windows::Forms::Label^  lbl_nivel;
		System::Windows::Forms::Label^  label8;
		System::Windows::Forms::Label^  lbl_classe;
		System::Windows::Forms::Label^  label5;
		System::Windows::Forms::Label^  label7;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  lbl_experiencia;
		System::Windows::Forms::ToolStrip^  toolStrip1;
		System::Windows::Forms::Label^  lbl_motivacao;
		System::Windows::Forms::TextBox^  txt_vida;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  lbl_mana_max;

	private: System::Windows::Forms::Label^  lbl_vida_max;

		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Label^  label9;
		System::Windows::Forms::TextBox^  txt_mana;
		System::Windows::Forms::Panel^  panel2;
		System::Windows::Forms::TextBox^  txt_vontade;
		System::Windows::Forms::Label^  label14;
		System::Windows::Forms::TextBox^  txt_inteligencia;
		System::Windows::Forms::Label^  label13;
		System::Windows::Forms::TextBox^  txt_agilidade;
		System::Windows::Forms::Label^  label12;
		System::Windows::Forms::TextBox^  txt_forca;
		System::Windows::Forms::Label^  label11;
		System::Windows::Forms::Panel^  panel3;
		System::Windows::Forms::Label^  label18;
		System::Windows::Forms::Label^  label17;
		System::Windows::Forms::Label^  label16;
		System::Windows::Forms::TextBox^  txt_carga_maxima;
		System::Windows::Forms::TextBox^  txt_carga_pesada;
		System::Windows::Forms::TextBox^  txt_carga_basica;
		System::Windows::Forms::Label^  label15;
		System::Windows::Forms::Panel^  panel4;
		System::Windows::Forms::Label^  label19;
		System::Windows::Forms::Label^  label20;
		System::Windows::Forms::Label^  label21;
		System::Windows::Forms::TextBox^  txt_defesa_determinacao;
		System::Windows::Forms::TextBox^  txt_defesa_esquiva;
		System::Windows::Forms::TextBox^  txt_defesa_bloqueio;
		System::Windows::Forms::Label^  label22;
		System::Windows::Forms::ToolStripDropDownButton^  dd_file;
		System::Windows::Forms::ToolStripMenuItem^  dd_file_new;
		System::Windows::Forms::ToolStripMenuItem^  dd_file_save;
		System::Windows::Forms::ToolStripMenuItem^  dd_file_export;
		System::Windows::Forms::ToolStripMenuItem^  dd_file_import;
		System::Windows::Forms::Timer^  tmr_backup;
		System::Windows::Forms::Panel^  panel5;
		System::Windows::Forms::Label^  label26;
		System::Windows::Forms::Label^  label25;
		System::Windows::Forms::Label^  label24;
		System::Windows::Forms::Label^  label23;
		System::Windows::Forms::Button^  btn_ataque_add;
		System::Windows::Forms::TextBox^  txt_ataque;
		System::Windows::Forms::Label^  label30;
		System::Windows::Forms::Label^  label29;
		System::Windows::Forms::Label^  label28;
		System::Windows::Forms::Label^  label27;
		System::Windows::Forms::Panel^  panel6;
		System::Windows::Forms::TextBox^  txt_habilidade;
		System::Windows::Forms::Panel^  panel7;
		System::Windows::Forms::TextBox^  txt_equipamentos;
		System::Windows::Forms::Button^  btn_equip_add;
		System::Windows::Forms::Label^  label31;
		System::Windows::Forms::Label^  label32;
		System::Windows::Forms::Label^  label33;
		System::Windows::Forms::Label^  label34;
		System::Windows::Forms::ToolStripButton^  btn_d6;
		System::Windows::Forms::ToolStripMenuItem^  dd_file_save_as;
		System::Windows::Forms::ToolStripMenuItem^  dd_file_load;
		Devart::Data::PostgreSql::PgSqlConnection^  pgSqlConnection1;
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void){
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_personagem = (gcnew System::Windows::Forms::Label());
			this->lbl_raca = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lbl_jogador = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pnl_desc = (gcnew System::Windows::Forms::Panel());
			this->lbl_motivacao = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->lbl_nivel = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbl_classe = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_experiencia = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->dd_file = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->dd_file_new = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_file_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_file_save_as = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_file_load = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_file_export = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_file_import = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btn_d6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->txt_vida = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_mana_max = (gcnew System::Windows::Forms::Label());
			this->lbl_vida_max = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txt_mana = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txt_vontade = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txt_inteligencia = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txt_agilidade = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txt_forca = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->txt_carga_maxima = (gcnew System::Windows::Forms::TextBox());
			this->txt_carga_pesada = (gcnew System::Windows::Forms::TextBox());
			this->txt_carga_basica = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->txt_defesa_determinacao = (gcnew System::Windows::Forms::TextBox());
			this->txt_defesa_esquiva = (gcnew System::Windows::Forms::TextBox());
			this->txt_defesa_bloqueio = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->tmr_backup = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txt_ataque = (gcnew System::Windows::Forms::TextBox());
			this->btn_ataque_add = (gcnew System::Windows::Forms::Button());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->txt_habilidade = (gcnew System::Windows::Forms::TextBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->txt_equipamentos = (gcnew System::Windows::Forms::TextBox());
			this->btn_equip_add = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->pgSqlConnection1 = (gcnew Devart::Data::PostgreSql::PgSqlConnection());
			this->pnl_desc->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Personagem:";
			// 
			// lbl_personagem
			// 
			this->lbl_personagem->AutoSize = true;
			this->lbl_personagem->Location = System::Drawing::Point(75, 0);
			this->lbl_personagem->Name = L"lbl_personagem";
			this->lbl_personagem->Size = System::Drawing::Size(16, 13);
			this->lbl_personagem->TabIndex = 1;
			this->lbl_personagem->Text = L"...";
			// 
			// lbl_raca
			// 
			this->lbl_raca->AutoSize = true;
			this->lbl_raca->Location = System::Drawing::Point(42, 36);
			this->lbl_raca->Name = L"lbl_raca";
			this->lbl_raca->Size = System::Drawing::Size(16, 13);
			this->lbl_raca->TabIndex = 3;
			this->lbl_raca->Text = L"...";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(0, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Raça:";
			// 
			// lbl_jogador
			// 
			this->lbl_jogador->AutoSize = true;
			this->lbl_jogador->Location = System::Drawing::Point(54, 18);
			this->lbl_jogador->Name = L"lbl_jogador";
			this->lbl_jogador->Size = System::Drawing::Size(16, 13);
			this->lbl_jogador->TabIndex = 5;
			this->lbl_jogador->Text = L"...";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(0, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Jogador:";
			// 
			// pnl_desc
			// 
			this->pnl_desc->Controls->Add(this->lbl_motivacao);
			this->pnl_desc->Controls->Add(this->label10);
			this->pnl_desc->Controls->Add(this->lbl_nivel);
			this->pnl_desc->Controls->Add(this->label8);
			this->pnl_desc->Controls->Add(this->lbl_classe);
			this->pnl_desc->Controls->Add(this->label5);
			this->pnl_desc->Controls->Add(this->label7);
			this->pnl_desc->Controls->Add(this->label2);
			this->pnl_desc->Controls->Add(this->lbl_experiencia);
			this->pnl_desc->Controls->Add(this->label1);
			this->pnl_desc->Controls->Add(this->lbl_jogador);
			this->pnl_desc->Controls->Add(this->lbl_personagem);
			this->pnl_desc->Controls->Add(this->label6);
			this->pnl_desc->Controls->Add(this->label4);
			this->pnl_desc->Controls->Add(this->lbl_raca);
			this->pnl_desc->Location = System::Drawing::Point(5, 28);
			this->pnl_desc->Name = L"pnl_desc";
			this->pnl_desc->Size = System::Drawing::Size(411, 96);
			this->pnl_desc->TabIndex = 6;
			// 
			// lbl_motivacao
			// 
			this->lbl_motivacao->AutoSize = true;
			this->lbl_motivacao->Location = System::Drawing::Point(66, 72);
			this->lbl_motivacao->Name = L"lbl_motivacao";
			this->lbl_motivacao->Size = System::Drawing::Size(16, 13);
			this->lbl_motivacao->TabIndex = 14;
			this->lbl_motivacao->Text = L"...";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(192, 54);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(34, 13);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Nivel:";
			// 
			// lbl_nivel
			// 
			this->lbl_nivel->AutoSize = true;
			this->lbl_nivel->Location = System::Drawing::Point(239, 54);
			this->lbl_nivel->Name = L"lbl_nivel";
			this->lbl_nivel->Size = System::Drawing::Size(30, 13);
			this->lbl_nivel->TabIndex = 13;
			this->lbl_nivel->Text = L"0/10";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(192, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Classe:";
			// 
			// lbl_classe
			// 
			this->lbl_classe->AutoSize = true;
			this->lbl_classe->Location = System::Drawing::Point(239, 36);
			this->lbl_classe->Name = L"lbl_classe";
			this->lbl_classe->Size = System::Drawing::Size(16, 13);
			this->lbl_classe->TabIndex = 11;
			this->lbl_classe->Text = L"...";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(0, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Motivação:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(47, 72);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"...";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(0, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Experiencia:";
			// 
			// lbl_experiencia
			// 
			this->lbl_experiencia->AutoSize = true;
			this->lbl_experiencia->Location = System::Drawing::Point(71, 54);
			this->lbl_experiencia->Name = L"lbl_experiencia";
			this->lbl_experiencia->Size = System::Drawing::Size(30, 13);
			this->lbl_experiencia->TabIndex = 7;
			this->lbl_experiencia->Text = L"0/10";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2){ this->dd_file, this->btn_d6 });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(787, 25);
			this->toolStrip1->TabIndex = 7;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// dd_file
			// 
			this->dd_file->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->dd_file->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->dd_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6){
				this->dd_file_new,
					this->dd_file_save, this->dd_file_save_as, this->dd_file_load, this->dd_file_export, this->dd_file_import
			});
			this->dd_file->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dd_file->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->dd_file->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->dd_file->Name = L"dd_file";
			this->dd_file->Padding = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->dd_file->Size = System::Drawing::Size(50, 22);
			this->dd_file->Tag = L"1";
			this->dd_file->Text = L"File";
			this->dd_file->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->dd_file->TextDirection = System::Windows::Forms::ToolStripTextDirection::Horizontal;
			this->dd_file->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			// 
			// dd_file_new
			// 
			this->dd_file_new->Name = L"dd_file_new";
			this->dd_file_new->Size = System::Drawing::Size(150, 22);
			this->dd_file_new->Text = L"Novo";
			// 
			// dd_file_save
			// 
			this->dd_file_save->Enabled = false;
			this->dd_file_save->Name = L"dd_file_save";
			this->dd_file_save->Size = System::Drawing::Size(150, 22);
			this->dd_file_save->Text = L"Salvar";
			// 
			// dd_file_save_as
			// 
			this->dd_file_save_as->Enabled = false;
			this->dd_file_save_as->Name = L"dd_file_save_as";
			this->dd_file_save_as->Size = System::Drawing::Size(150, 22);
			this->dd_file_save_as->Text = L"Salvar Como";
			// 
			// dd_file_load
			// 
			this->dd_file_load->Name = L"dd_file_load";
			this->dd_file_load->Size = System::Drawing::Size(150, 22);
			this->dd_file_load->Text = L"Carregar";
			this->dd_file_load->Click += gcnew System::EventHandler(this, &Form1::load_click);
			// 
			// dd_file_export
			// 
			this->dd_file_export->Name = L"dd_file_export";
			this->dd_file_export->Size = System::Drawing::Size(150, 22);
			this->dd_file_export->Text = L"Exportar";
			// 
			// dd_file_import
			// 
			this->dd_file_import->Name = L"dd_file_import";
			this->dd_file_import->Size = System::Drawing::Size(150, 22);
			this->dd_file_import->Text = L"Importar";
			// 
			// btn_d6
			// 
			this->btn_d6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->btn_d6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_d6->Name = L"btn_d6";
			this->btn_d6->Size = System::Drawing::Size(24, 22);
			this->btn_d6->Text = L"d6";
			// 
			// txt_vida
			// 
			this->txt_vida->Location = System::Drawing::Point(6, 16);
			this->txt_vida->Name = L"txt_vida";
			this->txt_vida->ReadOnly = true;
			this->txt_vida->Size = System::Drawing::Size(33, 20);
			this->txt_vida->TabIndex = 8;
			this->txt_vida->Text = L"60";
			this->txt_vida->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Vida:";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lbl_mana_max);
			this->panel1->Controls->Add(this->lbl_vida_max);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->txt_mana);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txt_vida);
			this->panel1->Location = System::Drawing::Point(5, 130);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(97, 84);
			this->panel1->TabIndex = 16;
			// 
			// lbl_mana_max
			// 
			this->lbl_mana_max->AutoSize = true;
			this->lbl_mana_max->Location = System::Drawing::Point(63, 39);
			this->lbl_mana_max->Name = L"lbl_mana_max";
			this->lbl_mana_max->Size = System::Drawing::Size(24, 13);
			this->lbl_mana_max->TabIndex = 21;
			this->lbl_mana_max->Text = L"/60";
			// 
			// lbl_vida_max
			// 
			this->lbl_vida_max->AutoSize = true;
			this->lbl_vida_max->Location = System::Drawing::Point(15, 39);
			this->lbl_vida_max->Name = L"lbl_vida_max";
			this->lbl_vida_max->Size = System::Drawing::Size(24, 13);
			this->lbl_vida_max->TabIndex = 20;
			this->lbl_vida_max->Text = L"/60";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(55, 55);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 23);
			this->button2->TabIndex = 19;
			this->button2->Text = L"+/-";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 55);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(33, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"+/-";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(52, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(37, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Mana:";
			// 
			// txt_mana
			// 
			this->txt_mana->Location = System::Drawing::Point(55, 16);
			this->txt_mana->Name = L"txt_mana";
			this->txt_mana->ReadOnly = true;
			this->txt_mana->Size = System::Drawing::Size(33, 20);
			this->txt_mana->TabIndex = 16;
			this->txt_mana->Text = L"60";
			this->txt_mana->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->txt_vontade);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->txt_inteligencia);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->txt_agilidade);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->txt_forca);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Location = System::Drawing::Point(108, 130);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(95, 100);
			this->panel2->TabIndex = 17;
			// 
			// txt_vontade
			// 
			this->txt_vontade->Location = System::Drawing::Point(3, 81);
			this->txt_vontade->Name = L"txt_vontade";
			this->txt_vontade->ReadOnly = true;
			this->txt_vontade->Size = System::Drawing::Size(20, 20);
			this->txt_vontade->TabIndex = 25;
			this->txt_vontade->Text = L"3";
			this->txt_vontade->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(32, 84);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(47, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"Vontade";
			// 
			// txt_inteligencia
			// 
			this->txt_inteligencia->Location = System::Drawing::Point(3, 55);
			this->txt_inteligencia->Name = L"txt_inteligencia";
			this->txt_inteligencia->ReadOnly = true;
			this->txt_inteligencia->Size = System::Drawing::Size(20, 20);
			this->txt_inteligencia->TabIndex = 23;
			this->txt_inteligencia->Text = L"3";
			this->txt_inteligencia->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(29, 58);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 13);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Inteligencia";
			// 
			// txt_agilidade
			// 
			this->txt_agilidade->Location = System::Drawing::Point(3, 29);
			this->txt_agilidade->Name = L"txt_agilidade";
			this->txt_agilidade->ReadOnly = true;
			this->txt_agilidade->Size = System::Drawing::Size(20, 20);
			this->txt_agilidade->TabIndex = 21;
			this->txt_agilidade->Text = L"3";
			this->txt_agilidade->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(29, 32);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(50, 13);
			this->label12->TabIndex = 22;
			this->label12->Text = L"Agilidade";
			// 
			// txt_forca
			// 
			this->txt_forca->Location = System::Drawing::Point(3, 3);
			this->txt_forca->Name = L"txt_forca";
			this->txt_forca->ReadOnly = true;
			this->txt_forca->Size = System::Drawing::Size(20, 20);
			this->txt_forca->TabIndex = 20;
			this->txt_forca->Text = L"3";
			this->txt_forca->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(29, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(34, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Força";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label18);
			this->panel3->Controls->Add(this->label17);
			this->panel3->Controls->Add(this->label16);
			this->panel3->Controls->Add(this->txt_carga_maxima);
			this->panel3->Controls->Add(this->txt_carga_pesada);
			this->panel3->Controls->Add(this->txt_carga_basica);
			this->panel3->Controls->Add(this->label15);
			this->panel3->Location = System::Drawing::Point(209, 130);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(88, 100);
			this->panel3->TabIndex = 18;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(39, 71);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(43, 13);
			this->label18->TabIndex = 29;
			this->label18->Text = L"Máxima";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(39, 48);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(43, 13);
			this->label17->TabIndex = 28;
			this->label17->Text = L"Pesada";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(39, 23);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(39, 13);
			this->label16->TabIndex = 27;
			this->label16->Text = L"Básica";
			// 
			// txt_carga_maxima
			// 
			this->txt_carga_maxima->Location = System::Drawing::Point(0, 68);
			this->txt_carga_maxima->Name = L"txt_carga_maxima";
			this->txt_carga_maxima->ReadOnly = true;
			this->txt_carga_maxima->Size = System::Drawing::Size(33, 20);
			this->txt_carga_maxima->TabIndex = 22;
			this->txt_carga_maxima->Text = L"1";
			this->txt_carga_maxima->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txt_carga_pesada
			// 
			this->txt_carga_pesada->Location = System::Drawing::Point(0, 45);
			this->txt_carga_pesada->Name = L"txt_carga_pesada";
			this->txt_carga_pesada->ReadOnly = true;
			this->txt_carga_pesada->Size = System::Drawing::Size(33, 20);
			this->txt_carga_pesada->TabIndex = 21;
			this->txt_carga_pesada->Text = L"1";
			this->txt_carga_pesada->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txt_carga_basica
			// 
			this->txt_carga_basica->Location = System::Drawing::Point(0, 20);
			this->txt_carga_basica->Name = L"txt_carga_basica";
			this->txt_carga_basica->ReadOnly = true;
			this->txt_carga_basica->Size = System::Drawing::Size(33, 20);
			this->txt_carga_basica->TabIndex = 20;
			this->txt_carga_basica->Text = L"1";
			this->txt_carga_basica->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(16, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(50, 17);
			this->label15->TabIndex = 0;
			this->label15->Text = L"Carga:";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label19);
			this->panel4->Controls->Add(this->label20);
			this->panel4->Controls->Add(this->label21);
			this->panel4->Controls->Add(this->txt_defesa_determinacao);
			this->panel4->Controls->Add(this->txt_defesa_esquiva);
			this->panel4->Controls->Add(this->txt_defesa_bloqueio);
			this->panel4->Controls->Add(this->label22);
			this->panel4->Location = System::Drawing::Point(303, 130);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(113, 100);
			this->panel4->TabIndex = 30;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(39, 71);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(73, 13);
			this->label19->TabIndex = 29;
			this->label19->Text = L"Determinação";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(39, 48);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(45, 13);
			this->label20->TabIndex = 28;
			this->label20->Text = L"Esquiva";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(39, 23);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(48, 13);
			this->label21->TabIndex = 27;
			this->label21->Text = L"Bloqueio";
			// 
			// txt_defesa_determinacao
			// 
			this->txt_defesa_determinacao->Location = System::Drawing::Point(0, 68);
			this->txt_defesa_determinacao->Name = L"txt_defesa_determinacao";
			this->txt_defesa_determinacao->ReadOnly = true;
			this->txt_defesa_determinacao->Size = System::Drawing::Size(33, 20);
			this->txt_defesa_determinacao->TabIndex = 22;
			this->txt_defesa_determinacao->Text = L"1";
			this->txt_defesa_determinacao->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txt_defesa_esquiva
			// 
			this->txt_defesa_esquiva->Location = System::Drawing::Point(0, 45);
			this->txt_defesa_esquiva->Name = L"txt_defesa_esquiva";
			this->txt_defesa_esquiva->ReadOnly = true;
			this->txt_defesa_esquiva->Size = System::Drawing::Size(33, 20);
			this->txt_defesa_esquiva->TabIndex = 21;
			this->txt_defesa_esquiva->Text = L"1";
			this->txt_defesa_esquiva->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txt_defesa_bloqueio
			// 
			this->txt_defesa_bloqueio->Location = System::Drawing::Point(0, 20);
			this->txt_defesa_bloqueio->Name = L"txt_defesa_bloqueio";
			this->txt_defesa_bloqueio->ReadOnly = true;
			this->txt_defesa_bloqueio->Size = System::Drawing::Size(33, 20);
			this->txt_defesa_bloqueio->TabIndex = 20;
			this->txt_defesa_bloqueio->Text = L"1";
			this->txt_defesa_bloqueio->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(16, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(57, 17);
			this->label22->TabIndex = 0;
			this->label22->Text = L"Defesa:";
			// 
			// tmr_backup
			// 
			this->tmr_backup->Interval = 300000;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->txt_ataque);
			this->panel5->Controls->Add(this->btn_ataque_add);
			this->panel5->Controls->Add(this->label26);
			this->panel5->Controls->Add(this->label25);
			this->panel5->Controls->Add(this->label24);
			this->panel5->Controls->Add(this->label23);
			this->panel5->Location = System::Drawing::Point(4, 237);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(411, 138);
			this->panel5->TabIndex = 31;
			// 
			// txt_ataque
			// 
			this->txt_ataque->Location = System::Drawing::Point(0, 33);
			this->txt_ataque->Multiline = true;
			this->txt_ataque->Name = L"txt_ataque";
			this->txt_ataque->ReadOnly = true;
			this->txt_ataque->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_ataque->Size = System::Drawing::Size(412, 105);
			this->txt_ataque->TabIndex = 22;
			this->txt_ataque->Text = L".";
			this->txt_ataque->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_ataque_add
			// 
			this->btn_ataque_add->Location = System::Drawing::Point(378, 0);
			this->btn_ataque_add->Name = L"btn_ataque_add";
			this->btn_ataque_add->Size = System::Drawing::Size(33, 23);
			this->btn_ataque_add->TabIndex = 22;
			this->btn_ataque_add->Text = L"+/-";
			this->btn_ataque_add->UseVisualStyleBackColor = true;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(304, 17);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(31, 13);
			this->label26->TabIndex = 34;
			this->label26->Text = L"Tipo:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(74, 17);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(34, 13);
			this->label25->TabIndex = 33;
			this->label25->Text = L"Arma:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(188, 17);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(36, 13);
			this->label24->TabIndex = 30;
			this->label24->Text = L"Dano:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(183, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(57, 17);
			this->label23->TabIndex = 30;
			this->label23->Text = L"Ataque:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(150, 0);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(86, 17);
			this->label30->TabIndex = 30;
			this->label30->Text = L"Habilidades:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(265, 27);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(23, 13);
			this->label29->TabIndex = 30;
			this->label29->Text = L"Dif:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(123, 26);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(38, 13);
			this->label28->TabIndex = 33;
			this->label28->Text = L"Nome:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(301, 27);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(37, 13);
			this->label27->TabIndex = 34;
			this->label27->Text = L"Mana:";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->txt_habilidade);
			this->panel6->Controls->Add(this->label27);
			this->panel6->Controls->Add(this->label28);
			this->panel6->Controls->Add(this->label29);
			this->panel6->Controls->Add(this->label30);
			this->panel6->Location = System::Drawing::Point(422, 28);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(358, 170);
			this->panel6->TabIndex = 47;
			// 
			// txt_habilidade
			// 
			this->txt_habilidade->Location = System::Drawing::Point(0, 43);
			this->txt_habilidade->Multiline = true;
			this->txt_habilidade->Name = L"txt_habilidade";
			this->txt_habilidade->ReadOnly = true;
			this->txt_habilidade->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_habilidade->Size = System::Drawing::Size(358, 127);
			this->txt_habilidade->TabIndex = 35;
			this->txt_habilidade->Text = L".";
			this->txt_habilidade->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->txt_equipamentos);
			this->panel7->Controls->Add(this->btn_equip_add);
			this->panel7->Controls->Add(this->label31);
			this->panel7->Controls->Add(this->label32);
			this->panel7->Controls->Add(this->label33);
			this->panel7->Controls->Add(this->label34);
			this->panel7->Location = System::Drawing::Point(422, 205);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(358, 170);
			this->panel7->TabIndex = 83;
			// 
			// txt_equipamentos
			// 
			this->txt_equipamentos->Location = System::Drawing::Point(0, 43);
			this->txt_equipamentos->Multiline = true;
			this->txt_equipamentos->Name = L"txt_equipamentos";
			this->txt_equipamentos->ReadOnly = true;
			this->txt_equipamentos->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_equipamentos->Size = System::Drawing::Size(358, 127);
			this->txt_equipamentos->TabIndex = 36;
			this->txt_equipamentos->Text = L".";
			this->txt_equipamentos->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_equip_add
			// 
			this->btn_equip_add->Location = System::Drawing::Point(325, 0);
			this->btn_equip_add->Name = L"btn_equip_add";
			this->btn_equip_add->Size = System::Drawing::Size(33, 23);
			this->btn_equip_add->TabIndex = 35;
			this->btn_equip_add->Text = L"+/-";
			this->btn_equip_add->UseVisualStyleBackColor = true;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(301, 26);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(37, 13);
			this->label31->TabIndex = 34;
			this->label31->Text = L"Custo:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(123, 26);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(30, 13);
			this->label32->TabIndex = 33;
			this->label32->Text = L"Item:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(265, 26);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(34, 13);
			this->label33->TabIndex = 30;
			this->label33->Text = L"Peso:";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(150, 0);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(102, 17);
			this->label34->TabIndex = 30;
			this->label34->Text = L"Equipamentos:";
			// 
			// pgSqlConnection1
			// 
			this->pgSqlConnection1->CommitTimeout = 0;
			this->pgSqlConnection1->Name = L"pgSqlConnection1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(787, 382);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->pnl_desc);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->pnl_desc->ResumeLayout(false);
			this->pnl_desc->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void load_click(System::Object^  sender, System::EventArgs^  e){
			//Abre uma janela para perguntar o nome do personagem
			//loadPersonagem(idDoPersonagem)
		}

		//tem que testar
		void loadPersonagem(int _id){	//id do personagem
			//PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, personagem, jogador, motivacao, experiencia, nivel, mana_max, mana, vida_max, vida, "+
			//"raca, classe, atributos, defesa, carga  FROM personagem WHERE id = " + id, pgSqlConnection1);
			PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, personagem, jogador, motivacao, experiencia, nivel, mana_max, mana, vida_max, vida, "+
			//													 0		1			2		3			4			5		6		7		8		9
				"raca, classe, atributos[1], atributos[2], atributos[3], atributos[4], defesa[1], defesa[2], defesa[3], carga[1], carga[2], carga[3]  FROM personagem WHERE id = "+_id, pgSqlConnection1);
			//		10		11		12			13			14				15			16			17			18			19		20			21
			
			pgSqlConnection1->Open();
			PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
			try{
				//while(pgReader->Read()){
				if(pgReader->Read()){	//vai ler só uma linha, a do personagem atual
					id =				Int32::Parse(pgReader->GetString(0));
					
					lbl_personagem->Text = pgReader->GetString(1);
					lbl_jogador->Text = pgReader->GetString(2);
					lbl_motivacao->Text = pgReader->GetString(3);
					
					experiencia			= Int32::Parse(pgReader->GetString(4));
					nivel				= Int32::Parse(pgReader->GetString(5));
					mana_max			= Int32::Parse(pgReader->GetString(6));
					mana				= Int32::Parse(pgReader->GetString(7));
					vida_max			= Int32::Parse(pgReader->GetString(8));
					vida				= Int32::Parse(pgReader->GetString(9));

					raca =				Int32::Parse(pgReader->GetString(10));
					classe =			Int32::Parse(pgReader->GetString(11));

					forca =				Int32::Parse(pgReader->GetString(12));
					agilidade =			Int32::Parse(pgReader->GetString(13));
					inteligencia =		Int32::Parse(pgReader->GetString(14));
					vontade =			Int32::Parse(pgReader->GetString(15));

					bloqueio =			Int32::Parse(pgReader->GetString(16));
					esquiva =			Int32::Parse(pgReader->GetString(17));
					determinacao =		Int32::Parse(pgReader->GetString(18));
					basica =			Int32::Parse(pgReader->GetString(19));
					pesada =			Int32::Parse(pgReader->GetString(20));
					maxima =			Int32::Parse(pgReader->GetString(21));

					lbl_experiencia->Text	= "" + experiencia;
					lbl_nivel->Text			= "" + nivel;

					lbl_mana_max->Text		= "" + mana_max;
					txt_mana->Text			= "" + mana;
					lbl_vida_max->Text		= "" + vida_max;
					txt_vida->Text			= "" + vida;

					txt_forca->Text =			"" + forca;
					txt_agilidade->Text =		"" + agilidade;
					txt_inteligencia->Text =	"" + inteligencia;
					txt_vontade->Text =			"" + vontade;
					
					txt_defesa_bloqueio->Text = "" + bloqueio;
					txt_defesa_esquiva->Text = "" + esquiva;
					txt_defesa_determinacao->Text = "" + determinacao;

					txt_carga_basica->Text = ""+ basica;
					txt_carga_pesada->Text = ""+ pesada;
					txt_carga_maxima->Text = ""+ maxima;

					//le a raça e a classe pelos id de cada tabela armazenados na tabela personagem
					PgSqlCommand^ pgCommand2 = gcnew PgSqlCommand("SELECT nome FROM raca WHERE id = " + raca, pgSqlConnection1);
					PgSqlDataReader^ pgReader2 = pgCommand2->ExecuteReader();
					pgReader2->Read();
					lbl_raca->Text = pgReader2->GetString(0);

					pgCommand2 = gcnew PgSqlCommand("SELECT nome FROM classe WHERE id = " + classe, pgSqlConnection1);
					pgReader2 = pgCommand2->ExecuteReader();
					pgReader2->Read();
					lbl_classe->Text = pgReader2->GetString(0);
				}
			} finally {
				//pgReader->Close();
				//pgSqlConnection1->Close();
			}
		}

		int rand6(){
			return ((int)DateTime::Now.Subtract(open).TotalSeconds) % 6;
		}
	};
}

