#pragma once

namespace projetoBase {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormD6
	/// </summary>
	public ref class FormD6 : public System::Windows::Forms::Form{
	private:
		int somaParcial, somaTotal;
	private: System::Windows::Forms::Button^  btn_voltar;

	public:
		FormD6(void){
			InitializeComponent();
		}
		FormD6(int n, int forca, int agilidade, int inteligencia, int vontade){
			InitializeComponent();

			this->Text = "" + n + "d6";

			rb_nenhum->Tag		 = (int)0;
			rb_agilidade->Tag	 = forca; 
			rb_forca->Tag		 = agilidade;
			rb_inteligencia->Tag = inteligencia;
			rb_vontade->Tag		 = vontade;

			rb_agilidade->Text		+= forca;
			rb_forca->Text			+= agilidade;
			rb_inteligencia->Text	+= inteligencia;
			rb_vontade->Text		+= vontade;

			//joga os dados
			Random^ rand = gcnew Random( DateTime::Now.Millisecond );
			somaParcial = 0;
			for(int i = 0; i < n-1; i++){
				int r = 1 + (rand->Next() % 6);
				txt_d6_values->Text += "" + r + ", ";
				somaParcial += r;
			}
			int r = 1 + (rand->Next() % 6);
			txt_d6_values->Text += "" + r;
			somaParcial += r;

			//somaTotal = somaParcial;
			lbl_soma->Text = "" + somaParcial;
			lbl_st->Text = "" + somaParcial;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormD6(){
			if (components){
				delete components;
			}
		}
	private: 
		System::Windows::Forms::TextBox^  txt_d6_values;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  lbl_soma;
		System::Windows::Forms::RadioButton^  rb_nenhum;
		System::Windows::Forms::RadioButton^  rb_agilidade;
		System::Windows::Forms::RadioButton^  rb_forca;
		System::Windows::Forms::RadioButton^  rb_inteligencia;
		System::Windows::Forms::RadioButton^  rb_vontade;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  lbl_st;

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormD6::typeid));
			this->txt_d6_values = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_soma = (gcnew System::Windows::Forms::Label());
			this->rb_nenhum = (gcnew System::Windows::Forms::RadioButton());
			this->rb_agilidade = (gcnew System::Windows::Forms::RadioButton());
			this->rb_forca = (gcnew System::Windows::Forms::RadioButton());
			this->rb_inteligencia = (gcnew System::Windows::Forms::RadioButton());
			this->rb_vontade = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lbl_st = (gcnew System::Windows::Forms::Label());
			this->btn_voltar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txt_d6_values
			// 
			this->txt_d6_values->Location = System::Drawing::Point(59, 27);
			this->txt_d6_values->Name = L"txt_d6_values";
			this->txt_d6_values->ReadOnly = true;
			this->txt_d6_values->Size = System::Drawing::Size(137, 20);
			this->txt_d6_values->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Dados:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Soma dos dados:";
			// 
			// lbl_soma
			// 
			this->lbl_soma->AutoSize = true;
			this->lbl_soma->Location = System::Drawing::Point(107, 58);
			this->lbl_soma->Name = L"lbl_soma";
			this->lbl_soma->Size = System::Drawing::Size(13, 13);
			this->lbl_soma->TabIndex = 3;
			this->lbl_soma->Text = L"0";
			// 
			// rb_nenhum
			// 
			this->rb_nenhum->AutoSize = true;
			this->rb_nenhum->Checked = true;
			this->rb_nenhum->Location = System::Drawing::Point(15, 107);
			this->rb_nenhum->Name = L"rb_nenhum";
			this->rb_nenhum->Size = System::Drawing::Size(65, 17);
			this->rb_nenhum->TabIndex = 4;
			this->rb_nenhum->TabStop = true;
			this->rb_nenhum->Text = L"Nenhum";
			this->rb_nenhum->UseVisualStyleBackColor = true;
			this->rb_nenhum->CheckedChanged += gcnew System::EventHandler(this, &FormD6::rbs_CheckedChanged);
			// 
			// rb_agilidade
			// 
			this->rb_agilidade->AutoSize = true;
			this->rb_agilidade->Location = System::Drawing::Point(15, 153);
			this->rb_agilidade->Name = L"rb_agilidade";
			this->rb_agilidade->Size = System::Drawing::Size(74, 17);
			this->rb_agilidade->TabIndex = 5;
			this->rb_agilidade->Text = L"Agilidade  ";
			this->rb_agilidade->UseVisualStyleBackColor = true;
			this->rb_agilidade->CheckedChanged += gcnew System::EventHandler(this, &FormD6::rbs_CheckedChanged);
			// 
			// rb_forca
			// 
			this->rb_forca->AutoSize = true;
			this->rb_forca->Location = System::Drawing::Point(15, 130);
			this->rb_forca->Name = L"rb_forca";
			this->rb_forca->Size = System::Drawing::Size(58, 17);
			this->rb_forca->TabIndex = 6;
			this->rb_forca->Text = L"Força  ";
			this->rb_forca->UseVisualStyleBackColor = true;
			this->rb_forca->CheckedChanged += gcnew System::EventHandler(this, &FormD6::rbs_CheckedChanged);
			// 
			// rb_inteligencia
			// 
			this->rb_inteligencia->AutoSize = true;
			this->rb_inteligencia->Location = System::Drawing::Point(117, 130);
			this->rb_inteligencia->Name = L"rb_inteligencia";
			this->rb_inteligencia->Size = System::Drawing::Size(85, 17);
			this->rb_inteligencia->TabIndex = 7;
			this->rb_inteligencia->Text = L"Inteligencia  ";
			this->rb_inteligencia->UseVisualStyleBackColor = true;
			this->rb_inteligencia->CheckedChanged += gcnew System::EventHandler(this, &FormD6::rbs_CheckedChanged);
			// 
			// rb_vontade
			// 
			this->rb_vontade->AutoSize = true;
			this->rb_vontade->Location = System::Drawing::Point(117, 153);
			this->rb_vontade->Name = L"rb_vontade";
			this->rb_vontade->Size = System::Drawing::Size(71, 17);
			this->rb_vontade->TabIndex = 8;
			this->rb_vontade->Text = L"Vontade  ";
			this->rb_vontade->UseVisualStyleBackColor = true;
			this->rb_vontade->CheckedChanged += gcnew System::EventHandler(this, &FormD6::rbs_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Somar com:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(16, 202);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Soma total:";
			// 
			// lbl_st
			// 
			this->lbl_st->AutoSize = true;
			this->lbl_st->Location = System::Drawing::Point(82, 202);
			this->lbl_st->Name = L"lbl_st";
			this->lbl_st->Size = System::Drawing::Size(13, 13);
			this->lbl_st->TabIndex = 11;
			this->lbl_st->Text = L"0";
			// 
			// btn_voltar
			// 
			this->btn_voltar->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btn_voltar->Location = System::Drawing::Point(121, 197);
			this->btn_voltar->Name = L"btn_voltar";
			this->btn_voltar->Size = System::Drawing::Size(75, 23);
			this->btn_voltar->TabIndex = 12;
			this->btn_voltar->Text = L"Voltar";
			this->btn_voltar->UseVisualStyleBackColor = true;
			// 
			// FormD6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(213, 230);
			this->Controls->Add(this->btn_voltar);
			this->Controls->Add(this->lbl_st);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->rb_vontade);
			this->Controls->Add(this->rb_inteligencia);
			this->Controls->Add(this->rb_forca);
			this->Controls->Add(this->rb_agilidade);
			this->Controls->Add(this->rb_nenhum);
			this->Controls->Add(this->lbl_soma);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_d6_values);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormD6";
			this->Text = L"FormD6";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void rbs_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
			lbl_st->Text = "" + (somaParcial + (int)((RadioButton^)sender)->Tag);
		}
	};
}
