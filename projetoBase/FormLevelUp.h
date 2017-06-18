#pragma once

namespace projetoBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Devart::Data::PostgreSql;

	/// <summary>
	/// Summary for FormLevelUp
	/// </summary>
	public ref class FormLevelUp : public System::Windows::Forms::Form {
	private:
		PgSqlConnection^ pgc;
		int id, xp, lv;
	public:
		FormLevelUp(PgSqlConnection^ _pgc, int _id, int _xp, int _lv){
			InitializeComponent();
			
			pgc = _pgc;
			id = _id;
			xp = _xp;
			lv = _lv;

			btn_forca->Tag = 1;
			btn_agilidade->Tag = 2;
			btn_integligencia->Tag = 3;
			btn_vontade->Tag = 4;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormLevelUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Button^  btn_forca;
		System::Windows::Forms::Button^  btn_agilidade;
		System::Windows::Forms::Button^  btn_integligencia;
		System::Windows::Forms::Button^  btn_vontade;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormLevelUp::typeid));
			this->btn_forca = (gcnew System::Windows::Forms::Button());
			this->btn_agilidade = (gcnew System::Windows::Forms::Button());
			this->btn_integligencia = (gcnew System::Windows::Forms::Button());
			this->btn_vontade = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_forca
			// 
			this->btn_forca->Location = System::Drawing::Point(118, 76);
			this->btn_forca->Name = L"btn_forca";
			this->btn_forca->Size = System::Drawing::Size(75, 23);
			this->btn_forca->TabIndex = 0;
			this->btn_forca->Text = L"Forca";
			this->btn_forca->UseVisualStyleBackColor = true;
			this->btn_forca->Click += gcnew System::EventHandler(this, &FormLevelUp::btn_Click);
			// 
			// btn_agilidade
			// 
			this->btn_agilidade->Location = System::Drawing::Point(118, 105);
			this->btn_agilidade->Name = L"btn_agilidade";
			this->btn_agilidade->Size = System::Drawing::Size(75, 23);
			this->btn_agilidade->TabIndex = 1;
			this->btn_agilidade->Text = L"Agilidade";
			this->btn_agilidade->UseVisualStyleBackColor = true;
			this->btn_agilidade->Click += gcnew System::EventHandler(this, &FormLevelUp::btn_Click);
			// 
			// btn_integligencia
			// 
			this->btn_integligencia->Location = System::Drawing::Point(118, 134);
			this->btn_integligencia->Name = L"btn_integligencia";
			this->btn_integligencia->Size = System::Drawing::Size(75, 23);
			this->btn_integligencia->TabIndex = 2;
			this->btn_integligencia->Text = L"Inteligencia";
			this->btn_integligencia->UseVisualStyleBackColor = true;
			this->btn_integligencia->Click += gcnew System::EventHandler(this, &FormLevelUp::btn_Click);
			// 
			// btn_vontade
			// 
			this->btn_vontade->Location = System::Drawing::Point(118, 163);
			this->btn_vontade->Name = L"btn_vontade";
			this->btn_vontade->Size = System::Drawing::Size(75, 23);
			this->btn_vontade->TabIndex = 3;
			this->btn_vontade->Text = L"Vontade";
			this->btn_vontade->UseVisualStyleBackColor = true;
			this->btn_vontade->Click += gcnew System::EventHandler(this, &FormLevelUp::btn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(85, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Você subiu de nivel!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(11, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(304, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Selecione um atributo para addicionar 1 ponto:";
			// 
			// FormLevelUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(320, 202);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_vontade);
			this->Controls->Add(this->btn_integligencia);
			this->Controls->Add(this->btn_agilidade);
			this->Controls->Add(this->btn_forca);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormLevelUp";
			this->Text = L"FormLevelUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::Void btn_Click(System::Object^  sender, System::EventArgs^  e){
			int i = (int)(((Button^)sender)->Tag);
			try{
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand(
					"UPDATE personagem SET "
					"atributos[" + i + "] = (SELECT atributos[" + i + "] + 1 FROM personagem WHERE id = " + id + "), "
					"experiencia = " + xp + ", nivel = " + lv + " WHERE id = " + id, pgc);
				pgc->Open();
				pgCommand->ExecuteNonQuery();
			} catch(Exception^){}
			this->Close();
		}
	};
}
