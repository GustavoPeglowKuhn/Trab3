#pragma once
#include "FormMain.h"
#include "FormNewEquip.h"
#include "FormRemoveItem.h"
#include "FormHabilidades.h"
#include "FormLevelUp.h"
#include "FormD6.h"

enum habilidadeTipo{ acao = 0, reacao = 1, suporte = 2 };

//#include "Habilidade.h"
//#include "Equipamento.h"

namespace projetoBase{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	using namespace System::Collections::Generic;		//List<...>
	using namespace Devart::Data::PostgreSql;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class FormFicha : public System::Windows::Forms::Form {
	private:
		PgSqlConnection^ pgc;
		System::Windows::Forms::ToolTip^ toolTip1 = gcnew System::Windows::Forms::ToolTip();

		//propriedades do personagem atual
		int id, raca, classe;
		int experiencia, nivel, mana_max, mana, vida_max, vida;
		int forca, agilidade, inteligencia, vontade;
		int bloqueio, esquiva, determinacao;
		int basica, pesada, maxima;
		//List<Habilidade^>^ habilidades;
		//List<Equipamento^>^ equipamentos;
		//!propriedades do personagem atual

	public:
		FormFicha( PgSqlConnection^ _pgc, int _id){
			InitializeComponent();

			////double buffer
			//this->SetStyle(static_cast<ControlStyles>(
			//	ControlStyles::AllPaintingInWmPaint |
			//	ControlStyles::DoubleBuffer |
			//	ControlStyles::UserPaint), true);
			//this->UpdateStyles();

			pgc = _pgc;
			id = _id;
			loadPersonagem();
			loadHabilidades();
			loadEquipamentos();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormFicha(){
			if(components){
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
		System::Windows::Forms::SaveFileDialog^  saveFileDialog;
		System::Windows::Forms::ToolStripDropDownButton^  dd_help;
		System::Windows::Forms::ToolStripMenuItem^  dd_btn_desenvolvedores;
		System::Windows::Forms::ToolStripMenuItem^  dd_btn_problemas;
		System::Windows::Forms::Button^  btn_add;
		System::Windows::Forms::NumericUpDown^  nud_xp;
		System::Windows::Forms::NumericUpDown^  nud_mana;
		System::Windows::Forms::NumericUpDown^  nud_vida;
		System::Windows::Forms::ToolStripButton^  btn_5d6;
		System::Windows::Forms::ToolStripButton^  btn_2d6;
		System::Windows::Forms::ToolStripButton^  btn_3d6;
		System::Windows::Forms::ToolStripButton^  btn_4d6;
		System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
		System::Windows::Forms::Label^  lbl_peso_carga;
		System::Windows::Forms::Label^  label23;
		System::Windows::Forms::Button^  btn_equip_add;
		System::Windows::Forms::Button^  btn_hab_add;
		System::Windows::Forms::Panel^  panel5;
		System::Windows::Forms::Label^  label29;
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
		System::Windows::Forms::Label^  lbl_mana_max;
		System::Windows::Forms::Label^  lbl_vida_max;
		System::Windows::Forms::Button^  btn_mana;
		System::Windows::Forms::Button^  btn_vida;
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
		System::Windows::Forms::ToolStripMenuItem^  dd_file_export;
		System::Windows::Forms::Label^  label30;
		System::Windows::Forms::Label^  label28;
		System::Windows::Forms::Label^  label27;
		System::Windows::Forms::Panel^  panel6;
		System::Windows::Forms::TextBox^  txt_habilidade;
		System::Windows::Forms::Panel^  panel7;
		System::Windows::Forms::TextBox^  txt_equipamentos;
		System::Windows::Forms::Button^  btn_equip_remove;
		System::Windows::Forms::Label^  label31;
		System::Windows::Forms::Label^  label32;
		System::Windows::Forms::Label^  label33;
		System::Windows::Forms::Label^  label34;
		System::Windows::Forms::ToolStripButton^  btn_1d6;
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void){
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormFicha::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl_personagem = (gcnew System::Windows::Forms::Label());
			this->lbl_raca = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lbl_jogador = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pnl_desc = (gcnew System::Windows::Forms::Panel());
			this->btn_add = (gcnew System::Windows::Forms::Button());
			this->nud_xp = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_peso_carga = (gcnew System::Windows::Forms::Label());
			this->lbl_motivacao = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
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
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_file_export = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->btn_1d6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_2d6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_3d6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_4d6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->btn_5d6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->dd_help = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->dd_btn_desenvolvedores = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dd_btn_problemas = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txt_vida = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->nud_mana = (gcnew System::Windows::Forms::NumericUpDown());
			this->nud_vida = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_mana_max = (gcnew System::Windows::Forms::Label());
			this->lbl_vida_max = (gcnew System::Windows::Forms::Label());
			this->btn_mana = (gcnew System::Windows::Forms::Button());
			this->btn_vida = (gcnew System::Windows::Forms::Button());
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
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->btn_hab_add = (gcnew System::Windows::Forms::Button());
			this->txt_habilidade = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->btn_equip_add = (gcnew System::Windows::Forms::Button());
			this->txt_equipamentos = (gcnew System::Windows::Forms::TextBox());
			this->btn_equip_remove = (gcnew System::Windows::Forms::Button());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pnl_desc->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_xp))->BeginInit();
			this->toolStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_mana))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_vida))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel5->SuspendLayout();
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
			this->label4->Text = L"Ra�a:";
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
			this->pnl_desc->Controls->Add(this->btn_add);
			this->pnl_desc->Controls->Add(this->nud_xp);
			this->pnl_desc->Controls->Add(this->lbl_peso_carga);
			this->pnl_desc->Controls->Add(this->lbl_motivacao);
			this->pnl_desc->Controls->Add(this->label23);
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
			// btn_add
			// 
			this->btn_add->Location = System::Drawing::Point(145, 52);
			this->btn_add->Name = L"btn_add";
			this->btn_add->Size = System::Drawing::Size(37, 20);
			this->btn_add->TabIndex = 41;
			this->btn_add->Text = L"Add";
			this->btn_add->UseVisualStyleBackColor = true;
			this->btn_add->Click += gcnew System::EventHandler(this, &FormFicha::btn_add_Click);
			// 
			// nud_xp
			// 
			this->nud_xp->Location = System::Drawing::Point(107, 52);
			this->nud_xp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 10, 0, 0, 0 });
			this->nud_xp->Name = L"nud_xp";
			this->nud_xp->Size = System::Drawing::Size(36, 20);
			this->nud_xp->TabIndex = 40;
			// 
			// lbl_peso_carga
			// 
			this->lbl_peso_carga->AutoSize = true;
			this->lbl_peso_carga->Location = System::Drawing::Point(278, 72);
			this->lbl_peso_carga->Name = L"lbl_peso_carga";
			this->lbl_peso_carga->Size = System::Drawing::Size(16, 13);
			this->lbl_peso_carga->TabIndex = 39;
			this->lbl_peso_carga->Text = L"...";
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
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(192, 72);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(80, 13);
			this->label23->TabIndex = 38;
			this->label23->Text = L"Peso da Carga:";
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
			this->label5->Text = L"Motiva��o:";
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
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9){
				this->dd_file, this->toolStripSeparator1,
					this->btn_1d6, this->btn_2d6, this->btn_3d6, this->btn_4d6, this->btn_5d6, this->toolStripSeparator2, this->dd_help
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(838, 25);
			this->toolStrip1->TabIndex = 7;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// dd_file
			// 
			this->dd_file->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->dd_file->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->dd_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2){
				this->menuToolStripMenuItem,
					this->dd_file_export
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
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->menuToolStripMenuItem->Text = L"Menu";
			this->menuToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormFicha::menuToolStripMenuItem_Click);
			// 
			// dd_file_export
			// 
			this->dd_file_export->Name = L"dd_file_export";
			this->dd_file_export->Size = System::Drawing::Size(126, 22);
			this->dd_file_export->Text = L"Exportar";
			this->dd_file_export->Click += gcnew System::EventHandler(this, &FormFicha::dd_file_export_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// btn_1d6
			// 
			this->btn_1d6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_1d6.Image")));
			this->btn_1d6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_1d6->Name = L"btn_1d6";
			this->btn_1d6->Size = System::Drawing::Size(46, 22);
			this->btn_1d6->Tag = L"1";
			this->btn_1d6->Text = L"1d6";
			this->btn_1d6->ToolTipText = L"rolar 1 d6";
			this->btn_1d6->Click += gcnew System::EventHandler(this, &FormFicha::btn_d6_Click);
			// 
			// btn_2d6
			// 
			this->btn_2d6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_2d6.Image")));
			this->btn_2d6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_2d6->Name = L"btn_2d6";
			this->btn_2d6->Size = System::Drawing::Size(46, 22);
			this->btn_2d6->Tag = L"2";
			this->btn_2d6->Text = L"2d6";
			this->btn_2d6->ToolTipText = L"rolar 2 d6";
			this->btn_2d6->Click += gcnew System::EventHandler(this, &FormFicha::btn_d6_Click);
			// 
			// btn_3d6
			// 
			this->btn_3d6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_3d6.Image")));
			this->btn_3d6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_3d6->Name = L"btn_3d6";
			this->btn_3d6->Size = System::Drawing::Size(46, 22);
			this->btn_3d6->Tag = L"3";
			this->btn_3d6->Text = L"3d6";
			this->btn_3d6->ToolTipText = L"rolar 3 d6";
			this->btn_3d6->Click += gcnew System::EventHandler(this, &FormFicha::btn_d6_Click);
			// 
			// btn_4d6
			// 
			this->btn_4d6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_4d6.Image")));
			this->btn_4d6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_4d6->Name = L"btn_4d6";
			this->btn_4d6->Size = System::Drawing::Size(46, 22);
			this->btn_4d6->Tag = L"4";
			this->btn_4d6->Text = L"4d6";
			this->btn_4d6->ToolTipText = L"rolar 4 d6";
			this->btn_4d6->Click += gcnew System::EventHandler(this, &FormFicha::btn_d6_Click);
			// 
			// btn_5d6
			// 
			this->btn_5d6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_5d6.Image")));
			this->btn_5d6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_5d6->Name = L"btn_5d6";
			this->btn_5d6->Size = System::Drawing::Size(46, 22);
			this->btn_5d6->Tag = L"5";
			this->btn_5d6->Text = L"5d6";
			this->btn_5d6->ToolTipText = L"rolar 5 d6";
			this->btn_5d6->Click += gcnew System::EventHandler(this, &FormFicha::btn_d6_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// dd_help
			// 
			this->dd_help->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->dd_help->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2){
				this->dd_btn_desenvolvedores,
					this->dd_btn_problemas
			});
			this->dd_help->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dd_help.Image")));
			this->dd_help->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->dd_help->Name = L"dd_help";
			this->dd_help->Size = System::Drawing::Size(51, 22);
			this->dd_help->Text = L"Ajuda";
			// 
			// dd_btn_desenvolvedores
			// 
			this->dd_btn_desenvolvedores->Name = L"dd_btn_desenvolvedores";
			this->dd_btn_desenvolvedores->Size = System::Drawing::Size(163, 22);
			this->dd_btn_desenvolvedores->Text = L"Desenvolvedores";
			this->dd_btn_desenvolvedores->Click += gcnew System::EventHandler(this, &FormFicha::dd_btn_desenvolvedores_Click);
			// 
			// dd_btn_problemas
			// 
			this->dd_btn_problemas->Name = L"dd_btn_problemas";
			this->dd_btn_problemas->Size = System::Drawing::Size(163, 22);
			this->dd_btn_problemas->Text = L"Problemas\?";
			this->dd_btn_problemas->Click += gcnew System::EventHandler(this, &FormFicha::dd_btn_problemas_Click);
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
			this->panel1->Controls->Add(this->nud_mana);
			this->panel1->Controls->Add(this->nud_vida);
			this->panel1->Controls->Add(this->lbl_mana_max);
			this->panel1->Controls->Add(this->lbl_vida_max);
			this->panel1->Controls->Add(this->btn_mana);
			this->panel1->Controls->Add(this->btn_vida);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->txt_mana);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txt_vida);
			this->panel1->Location = System::Drawing::Point(3, 7);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(97, 95);
			this->panel1->TabIndex = 16;
			// 
			// nud_mana
			// 
			this->nud_mana->Location = System::Drawing::Point(54, 58);
			this->nud_mana->Name = L"nud_mana";
			this->nud_mana->Size = System::Drawing::Size(42, 20);
			this->nud_mana->TabIndex = 23;
			// 
			// nud_vida
			// 
			this->nud_vida->Location = System::Drawing::Point(0, 58);
			this->nud_vida->Name = L"nud_vida";
			this->nud_vida->Size = System::Drawing::Size(45, 20);
			this->nud_vida->TabIndex = 22;
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
			// btn_mana
			// 
			this->btn_mana->Location = System::Drawing::Point(54, 75);
			this->btn_mana->Name = L"btn_mana";
			this->btn_mana->Size = System::Drawing::Size(43, 20);
			this->btn_mana->TabIndex = 19;
			this->btn_mana->Text = L"+/-";
			this->btn_mana->UseVisualStyleBackColor = true;
			this->btn_mana->Click += gcnew System::EventHandler(this, &FormFicha::btn_mana_Click);
			// 
			// btn_vida
			// 
			this->btn_vida->Location = System::Drawing::Point(0, 75);
			this->btn_vida->Name = L"btn_vida";
			this->btn_vida->Size = System::Drawing::Size(45, 20);
			this->btn_vida->TabIndex = 18;
			this->btn_vida->Text = L"+/-";
			this->btn_vida->UseVisualStyleBackColor = true;
			this->btn_vida->Click += gcnew System::EventHandler(this, &FormFicha::btn_vida_Click);
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
			this->panel2->Location = System::Drawing::Point(103, 1);
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
			this->label11->Text = L"For�a";
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
			this->panel3->Location = System::Drawing::Point(204, 1);
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
			this->label18->Text = L"M�xima";
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
			this->label16->Text = L"B�sica";
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
			this->panel4->Location = System::Drawing::Point(298, 1);
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
			this->label19->Text = L"Determina��o";
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
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(3, 27);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(38, 13);
			this->label28->TabIndex = 33;
			this->label28->Text = L"Nome:";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(246, 27);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(40, 13);
			this->label27->TabIndex = 34;
			this->label27->Text = L"Bonus:";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->btn_hab_add);
			this->panel6->Controls->Add(this->txt_habilidade);
			this->panel6->Controls->Add(this->label27);
			this->panel6->Controls->Add(this->label28);
			this->panel6->Controls->Add(this->label29);
			this->panel6->Controls->Add(this->label30);
			this->panel6->Location = System::Drawing::Point(4, 238);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(825, 214);
			this->panel6->TabIndex = 47;
			// 
			// btn_hab_add
			// 
			this->btn_hab_add->Location = System::Drawing::Point(0, 0);
			this->btn_hab_add->Name = L"btn_hab_add";
			this->btn_hab_add->Size = System::Drawing::Size(24, 23);
			this->btn_hab_add->TabIndex = 36;
			this->btn_hab_add->Text = L"+";
			this->btn_hab_add->UseVisualStyleBackColor = true;
			this->btn_hab_add->Click += gcnew System::EventHandler(this, &FormFicha::btn_hab_add_Click);
			// 
			// txt_habilidade
			// 
			this->txt_habilidade->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_habilidade->Location = System::Drawing::Point(0, 43);
			this->txt_habilidade->Multiline = true;
			this->txt_habilidade->Name = L"txt_habilidade";
			this->txt_habilidade->ReadOnly = true;
			this->txt_habilidade->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txt_habilidade->Size = System::Drawing::Size(819, 168);
			this->txt_habilidade->TabIndex = 35;
			this->txt_habilidade->WordWrap = false;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(184, 27);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(31, 13);
			this->label29->TabIndex = 30;
			this->label29->Text = L"Tipo:";
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->btn_equip_add);
			this->panel7->Controls->Add(this->txt_equipamentos);
			this->panel7->Controls->Add(this->btn_equip_remove);
			this->panel7->Controls->Add(this->label31);
			this->panel7->Controls->Add(this->label32);
			this->panel7->Controls->Add(this->label33);
			this->panel7->Controls->Add(this->label34);
			this->panel7->Location = System::Drawing::Point(422, 28);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(407, 204);
			this->panel7->TabIndex = 83;
			// 
			// btn_equip_add
			// 
			this->btn_equip_add->Location = System::Drawing::Point(353, 0);
			this->btn_equip_add->Name = L"btn_equip_add";
			this->btn_equip_add->Size = System::Drawing::Size(24, 23);
			this->btn_equip_add->TabIndex = 37;
			this->btn_equip_add->Text = L"+";
			this->btn_equip_add->UseVisualStyleBackColor = true;
			this->btn_equip_add->Click += gcnew System::EventHandler(this, &FormFicha::btn_equip_add_Click);
			// 
			// txt_equipamentos
			// 
			this->txt_equipamentos->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_equipamentos->Location = System::Drawing::Point(0, 43);
			this->txt_equipamentos->Multiline = true;
			this->txt_equipamentos->Name = L"txt_equipamentos";
			this->txt_equipamentos->ReadOnly = true;
			this->txt_equipamentos->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_equipamentos->Size = System::Drawing::Size(407, 161);
			this->txt_equipamentos->TabIndex = 36;
			this->txt_equipamentos->WordWrap = false;
			// 
			// btn_equip_remove
			// 
			this->btn_equip_remove->Location = System::Drawing::Point(383, 0);
			this->btn_equip_remove->Name = L"btn_equip_remove";
			this->btn_equip_remove->Size = System::Drawing::Size(24, 23);
			this->btn_equip_remove->TabIndex = 35;
			this->btn_equip_remove->Text = L"-";
			this->btn_equip_remove->UseVisualStyleBackColor = true;
			this->btn_equip_remove->Click += gcnew System::EventHandler(this, &FormFicha::btn_equip_remove_Click);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(274, 26);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(55, 13);
			this->label31->TabIndex = 34;
			this->label31->Text = L"Unidades:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(9, 26);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(30, 13);
			this->label32->TabIndex = 33;
			this->label32->Text = L"Item:";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(344, 26);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(57, 13);
			this->label33->TabIndex = 30;
			this->label33->Text = L"Peso total:";
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
			// panel5
			// 
			this->panel5->Controls->Add(this->panel1);
			this->panel5->Controls->Add(this->panel2);
			this->panel5->Controls->Add(this->panel3);
			this->panel5->Controls->Add(this->panel4);
			this->panel5->Location = System::Drawing::Point(5, 130);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(411, 102);
			this->panel5->TabIndex = 84;
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->Filter = L"Saves files|*.rpg|All files|*.*";
			// 
			// FormFicha
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(838, 586);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->pnl_desc);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"FormFicha";
			this->Text = L"Form1";
			this->pnl_desc->ResumeLayout(false);
			this->pnl_desc->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_xp))->EndInit();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_mana))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_vida))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void loadPersonagem(){
			//ex://SELECT personagem.id, personagem, jogador, motivacao, experiencia, nivel, mana_max, mana, vida_max, vida, raca.nome, classe.nome, raca.atributos[1]+classe.atributos[1]+personagem.atributos[1] AS forca, raca.atributos[2]+classe.atributos[2]+personagem.atributos[2] AS agilidade, raca.atributos[3]+classe.atributos[3]+personagem.atributos[3] AS inteligencia, raca.atributos[4]+classe.atributos[4]+personagem.atributos[4] AS vontade, defesa[1], defesa[2], defesa[3], carga[1], carga[2], carga[3] FROM personagem, raca, classe WHERE personagem.id = 1 AND raca.id = personagem.raca AND classe.id = personagem.classe
			PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT personagem.id, personagem, jogador, motivacao, "+
				"experiencia, nivel, mana_max, mana, vida_max, vida, "+
				"raca.nome, classe.nome, "+
				"raca.atributos[1] + classe.atributos[1] + personagem.atributos[1], "+
				"raca.atributos[2] + classe.atributos[2] + personagem.atributos[2], "+
				"raca.atributos[3] + classe.atributos[3] + personagem.atributos[3], "+
				"raca.atributos[4] + classe.atributos[4] + personagem.atributos[4], "+
				"defesa[1], defesa[2], defesa[3], carga[1], carga[2], carga[3] FROM personagem, raca, classe WHERE "+
				"raca.id = personagem.raca AND classe.id = personagem.classe AND personagem.id = "+ id, pgc);
			pgc->Open();
			PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
			try{
				//while(pgReader->Read()){
				if(pgReader->Read()){	//vai ler s� uma linha, a do personagem atual
										//id =				Int32::Parse(pgReader->GetString(0));	//eu to recebendo o id na chamada da funcao, nao tem porque ler o id aqui

					lbl_personagem->Text = pgReader->GetString(1);
					lbl_jogador->Text = pgReader->GetString(2);

					lbl_motivacao->Text = pgReader->GetString(3);
					if(lbl_motivacao->Text->Length > 24) lbl_motivacao->Text = lbl_motivacao->Text->Remove(20) + "... ";
					toolTip1->SetToolTip(lbl_motivacao, pgReader->GetString(3));
					

					experiencia	= pgReader->GetInt32(4);
					nivel		= pgReader->GetInt32(5);
					mana_max	= pgReader->GetInt32(6);
					mana		= pgReader->GetInt32(7);
					vida_max	= pgReader->GetInt32(8);
					vida		= pgReader->GetInt32(9);

					lbl_raca->Text		= pgReader->GetString(10);
					lbl_classe->Text	= pgReader->GetString(11);

					forca			= pgReader->GetInt32(12);
					agilidade		= pgReader->GetInt32(13);
					inteligencia	= pgReader->GetInt32(14);
					vontade			= pgReader->GetInt32(15);

					bloqueio		= pgReader->GetInt32(16);
					esquiva			= pgReader->GetInt32(17);
					determinacao	= pgReader->GetInt32(18);
					basica			= pgReader->GetInt32(19);
					pesada			= pgReader->GetInt32(20);
					maxima			= pgReader->GetInt32(21);

					lbl_experiencia->Text	= "" + experiencia + " / 10";
					lbl_nivel->Text			= "" + nivel + " / 10";

					lbl_mana_max->Text	= "/" + mana_max;
					txt_mana->Text		= "" + mana;
					lbl_vida_max->Text	= "/" + vida_max;
					txt_vida->Text		= "" + vida;

					txt_forca->Text			= "" + forca;
					txt_agilidade->Text		= "" + agilidade;
					txt_inteligencia->Text	= "" + inteligencia;
					txt_vontade->Text		= "" + vontade;

					txt_defesa_bloqueio->Text = "" + (5 + forca + bloqueio);		//pag.34	//bonus da armadura incluso em bloqueio
					txt_defesa_esquiva->Text = "" + (5 + agilidade + esquiva);
					txt_defesa_determinacao->Text = "" + (8 + (inteligencia > vontade ? inteligencia : vontade) + determinacao);

					txt_carga_basica->Text = "" + (07 * forca + basica);
					txt_carga_pesada->Text = "" + (35 * forca + pesada);
					txt_carga_maxima->Text = "" + (70 * forca + maxima);

					this->Text = lbl_personagem->Text + ", " + lbl_raca->Text + " " + lbl_classe->Text + ", nivel " + nivel;

					nud_vida->Minimum = -vida;
					nud_vida->Maximum = vida_max - vida;
					nud_mana->Minimum = -mana;
					nud_mana->Maximum = mana_max - mana;
				}
			} finally {
				//pgReader->Close();
				//pgSqlConnection1->Close();
			}
		}
		void loadHabilidades(){
			//ex://SELECT habilidade.id, nome, tipo, req_nivel, bonus FROM habilidade, m_hab WHERE h_id = id AND p_id = 1
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT habilidade.id, tipo, nome, bonus "
					"FROM habilidade, m_hab WHERE h_id = id AND p_id = " + id, pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();

				txt_habilidade->Clear();
				while(pgReader->Read()){
					String^ res = pgReader->GetString(2);			//nome
					if(res->Length > 30) res = res->Remove(26) + "... ";
					else res = res->PadRight(30);
					int ht = pgReader->GetInt32(1);					//tipo
					res += (ht == acao ? "A��o       " : (ht == reacao ? "Rea��o     " : "Suporte    "));
					res += pgReader->GetString(3) + "\r\n";			//bonus
					txt_habilidade->AppendText(res);
				}
			} catch(Exception^){}
		}
		void loadEquipamentos(){
			//ex://SELECT id, nome, peso, quantidade, n_usando FROM equipamento, m_equip WHERE e_id = id AND p_id = 1
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, nome, peso, quantidade, n_usando "
					"FROM equipamento, m_equip WHERE e_id = id AND p_id = " + id, pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				
				float pesoTotal = 0;
				txt_equipamentos->Clear();

				while(pgReader->Read()){
					String^ res = pgReader->GetString(1);
					if(res->Length > 46) res = res->Remove(32) + "... ";
					else res = res->PadRight(46);
					res += "" + pgReader->GetInt32(3);
					int q = pgReader->GetInt32(3);
					float p = pgReader->GetFloat(2);
					float pt = p*q;
					pesoTotal += pt;
					res = res->PadRight(57) + pt + "\r\n";
					txt_equipamentos->AppendText(res);
				}

				lbl_peso_carga->Text = "" + pesoTotal;
			}catch(Exception^){}
		}

		void changeForm(Form^ newForm){
			this->Enabled = false;
			newForm->ShowDialog();		//fica travado at� fechar o form
			this->Enabled = true;
		}
		System::Void btn_equip_add_Click(System::Object^  sender, System::EventArgs^  e){
			changeForm(gcnew FormNewEquip(pgc, id));
			loadEquipamentos();
		}
		System::Void btn_equip_remove_Click(System::Object^  sender, System::EventArgs^  e){
			changeForm(gcnew FormRemoveItem(pgc, id));
			loadEquipamentos();
		}
		System::Void btn_hab_add_Click(System::Object^  sender, System::EventArgs^  e){
			changeForm(gcnew FormHabilidades(pgc, id));
			loadHabilidades();
		}
		System::Void btn_d6_Click(System::Object^  sender, System::EventArgs^  e){
			try{
				int i = Int32::Parse(((String^)safe_cast<ToolStripButton^>(sender)->Tag));
				changeForm(gcnew FormD6(i, forca, agilidade, inteligencia, vontade));
			} catch(Exception^){}
		}

		System::Void menuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
			this->Close();
		}

		System::Void btn_vida_Click(System::Object^  sender, System::EventArgs^  e){
			vida += (int)nud_vida->Value;
			txt_vida->Text = "" + vida;

			//nud_vida->Value = 0;
			nud_vida->Minimum = -vida;
			nud_vida->Maximum = vida_max - vida;

			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("UPDATE personagem SET vida = " + vida
					+ " WHERE id = " + id, pgc);
				pgc->Open();
				pgCommand->ExecuteNonQuery();
			} catch(Exception^){}
		}
		System::Void btn_mana_Click(System::Object^  sender, System::EventArgs^  e){
			mana += (int)nud_mana->Value;
			txt_mana->Text = "" + mana;
			
			//nud_mana->Value = 0;
			nud_mana->Minimum = -mana;
			nud_mana->Maximum = mana_max - mana;

			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("UPDATE personagem SET mana = "+ mana
					+ " WHERE id = " + id, pgc);
				pgc->Open();
				pgCommand->ExecuteNonQuery();
			} catch(Exception^){}
		}
		
		System::Void dd_btn_desenvolvedores_Click(System::Object^  sender, System::EventArgs^  e){
			MessageBox::Show(
				"   Este programa foi desenvolvido por Gustavo e Lucas." + "\r\n"
				"   Este progama � um trabalho da disciplina de Informatica Aplicada" + "\r\n"
				"   Esta � apenas uma vers�o pre-alpha, muitas noites sem dormir" + "\r\n"
				"e muitos litros de caf� ser�o necessarios at� o lan�amento final." + "\r\n"
				"   E lembre-se, sempre � melhor chamar o Saul",
				"Desenvolvedores");
		}
		System::Void dd_btn_problemas_Click(System::Object^  sender, System::EventArgs^  e){
			MessageBox::Show(
				"   Antes de usar o programa, lembre-se de instalar o postgresql," + "\r\n"
				"criar o banco de dados chamado 'rpg3' e popular ele (um arquivo" + "\r\n"
				"'CreateInsert.sql' � disponibilizado junto com este programa para" + "\r\n"
				"criar as tabelas e os dados, execute ele pelo pgAdmin)" + "\r\n"
				"   Esta � apenas uma vers�o pre-alpha, muitas noites sem dormir e" + "\r\n"
				"muitos litro de caf� ser�o nescessarios at� o lan�amento final" + "\r\n"
				"   E lembre-se, sempre � melhor chamar o Saul",
				"Problemas?");
		}

		System::Void btn_add_Click(System::Object^  sender, System::EventArgs^  e){
			if(nud_xp->Value == 0) return;
			experiencia += (int)nud_xp->Value;
			if(experiencia >= 10){
				experiencia -= 10;
				nivel++;
				changeForm(gcnew FormLevelUp(pgc, id, experiencia, nivel));

			} else{	//n�o subiu de nivel
				try{
					PgSqlCommand^ pgCommand = gcnew PgSqlCommand("UPDATE personagem SET "
						"experiencia = " + experiencia + " WHERE id = " + id, pgc);
					pgc->Open();
					pgCommand->ExecuteNonQuery();
				} catch(Exception^){}
			}
			nud_xp->Value = 0;
			loadPersonagem();
		}
		System::Void dd_file_export_Click(System::Object^  sender, System::EventArgs^  e){
			//se clicar em cancel acaba a fun��o
			if(saveFileDialog->ShowDialog() == ::System::Windows::Forms::DialogResult::Cancel) return;
			
			try{
				IO::FileStream^ f = gcnew IO::FileStream(saveFileDialog->FileName, IO::FileMode::Create);
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand(
					"SELECT "
					+"personagem, jogador, motivacao, "
					+"experiencia, nivel, mana_max, mana, vida_max, vida, raca, classe, "
					+"atributos[1], atributos[2], atributos[3], atributos[4], "
					+"defesa[1], defesa[2], defesa[3], carga[1], carga[2], carga[3] "
					" FROM personagem WHERE id = "+id, pgc);// +id, pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader;
				pgReader = pgCommand->ExecuteReader();
				String^ res="";
				if(pgReader->Read()){
					for(int i=0; i<20; i++)
						res += pgReader->GetString(i) + ",";
					res += pgReader->GetString(20) + ";";
				}
				
				pgCommand->CommandText = "SELECT h_id FROM m_hab WHERE p_id = " + id;
				pgc->Open();
				pgReader = pgCommand->ExecuteReader();
				if(pgReader->Read()){
					res += pgReader->GetString(0);
				}while(pgReader->Read()){
					res += ","+pgReader->GetString(0);
				}
				res += ";";
				
				pgCommand->CommandText = " SELECT e_id, quantidade, n_usando "
					" FROM m_equip WHERE p_id = " + id;
				pgc->Open();
				pgReader = pgCommand->ExecuteReader();

				//esse if serve apenas para gerar a formata��o do arquio, h� uma '/' entre os elementos
				if(pgReader->Read()){
					res += pgReader->GetString(0) +","+ pgReader->GetString(1) + "," + pgReader->GetString(2);
				}while(pgReader->Read()){
					res += "/"+pgReader->GetString(0) + "," + pgReader->GetString(1) + "," + pgReader->GetString(2);
				}

				array<Byte>^info = (gcnew UTF8Encoding(true))->GetBytes(res);
				f->Write(info, 0, info->Length);
				f->Close();
			} catch(Exception^){}
		}
	};
}

