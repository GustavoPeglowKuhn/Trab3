#pragma once

#include "Equipamento.h";

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
	/// Summary for FormNewEquip
	/// </summary>
	public ref class FormNewEquip : public System::Windows::Forms::Form{
	private:
		List<Equipamento^> ^itens, ^equipamentos;
		PgSqlConnection^ pgc;
		int id;
	public:
		FormNewEquip(PgSqlConnection^ _pgc, int _id){
			InitializeComponent();
			id = _id;
			pgc = _pgc;

			loadEquipamentos();
			loadItens();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormNewEquip()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::ComboBox^  cb_item;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  lbl_peso;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  lbl_peso_total;
		System::Windows::Forms::Label^  label6;
		System::Windows::Forms::NumericUpDown^  nud_quant;
		System::Windows::Forms::Button^  btn_cancel;
		System::Windows::Forms::Button^  btn_ok;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormNewEquip::typeid));
			this->cb_item = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_peso = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lbl_peso_total = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nud_quant = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_quant))->BeginInit();
			this->SuspendLayout();
			// 
			// cb_item
			// 
			this->cb_item->FormattingEnabled = true;
			this->cb_item->Location = System::Drawing::Point(83, 12);
			this->cb_item->Name = L"cb_item";
			this->cb_item->Size = System::Drawing::Size(121, 21);
			this->cb_item->TabIndex = 0;
			this->cb_item->SelectedIndexChanged += gcnew System::EventHandler(this, &FormNewEquip::cb_item_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Item:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Peso:";
			// 
			// lbl_peso
			// 
			this->lbl_peso->AutoSize = true;
			this->lbl_peso->Location = System::Drawing::Point(80, 36);
			this->lbl_peso->Name = L"lbl_peso";
			this->lbl_peso->Size = System::Drawing::Size(10, 13);
			this->lbl_peso->TabIndex = 3;
			this->lbl_peso->Text = L".";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Quantidade:";
			// 
			// lbl_peso_total
			// 
			this->lbl_peso_total->AutoSize = true;
			this->lbl_peso_total->Location = System::Drawing::Point(80, 75);
			this->lbl_peso_total->Name = L"lbl_peso_total";
			this->lbl_peso_total->Size = System::Drawing::Size(10, 13);
			this->lbl_peso_total->TabIndex = 6;
			this->lbl_peso_total->Text = L".";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 75);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Peso total:";
			// 
			// nud_quant
			// 
			this->nud_quant->Location = System::Drawing::Point(83, 52);
			this->nud_quant->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 500, 0, 0, 0 });
			this->nud_quant->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 1, 0, 0, 0 });
			this->nud_quant->Name = L"nud_quant";
			this->nud_quant->Size = System::Drawing::Size(120, 20);
			this->nud_quant->TabIndex = 7;
			this->nud_quant->Value = System::Decimal(gcnew cli::array< System::Int32 >(4){ 1, 0, 0, 0 });
			this->nud_quant->ValueChanged += gcnew System::EventHandler(this, &FormNewEquip::nud_quant_ValueChanged);
			// 
			// btn_cancel
			// 
			this->btn_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_cancel->Location = System::Drawing::Point(111, 104);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(93, 23);
			this->btn_cancel->TabIndex = 8;
			this->btn_cancel->Text = L"Voltar";
			this->btn_cancel->UseVisualStyleBackColor = true;
			// 
			// btn_ok
			// 
			this->btn_ok->Location = System::Drawing::Point(12, 104);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(93, 23);
			this->btn_ok->TabIndex = 9;
			this->btn_ok->Text = L"Adicionar";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &FormNewEquip::btn_ok_Click);
			// 
			// FormNewEquip
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(219, 142);
			this->Controls->Add(this->btn_ok);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->nud_quant);
			this->Controls->Add(this->lbl_peso_total);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbl_peso);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cb_item);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormNewEquip";
			this->Text = L"New Equip";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_quant))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void cb_item_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			int i = cb_item->SelectedIndex;
			lbl_peso->Text = ""+itens[i]->peso;
			lbl_peso_total->Text = "" + itens[i]->peso*(float)nud_quant->Value;
			btn_ok->Enabled = true;
		}
		System::Void nud_quant_ValueChanged(System::Object^  sender, System::EventArgs^  e){
			lbl_peso_total->Text = "" + itens[cb_item->SelectedIndex]->peso*(float)nud_quant->Value;
		}

		void loadEquipamentos(){
			//ex://SELECT id, nome, peso FROM equipamento
			try{
				//lista dosequipamentos que o personagem ja possui
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, nome, peso, quantidade, n_usando "
					"FROM equipamento, m_equip WHERE e_id = id AND p_id = " + id, pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				equipamentos = gcnew List<Equipamento^>();
				while(pgReader->Read()){
					equipamentos->Add(gcnew Equipamento(
						pgReader->GetInt32(0),					//id
						pgReader->GetString(1),					//nome
						pgReader->GetFloat(2),					//peso
						pgReader->GetInt32(3),					//quantidade
						pgReader->GetInt32(4)					//n_usando
					));
				}
			} catch(Exception^){}
		}
		void loadItens(){
			try{
				//todos os itens
				PgSqlCommand^ pgCommand = gcnew PgSqlCommand("SELECT id, nome, peso FROM equipamento", pgc);
				pgc->Open();
				PgSqlDataReader^ pgReader = pgCommand->ExecuteReader();
				itens = gcnew List<Equipamento^>();
				while(pgReader->Read()){
					itens->Add(gcnew Equipamento(
						pgReader->GetInt32(0),					//id
						pgReader->GetString(1),					//nome
						pgReader->GetFloat(2),					//peso
						1,
						0
					));
				}
				cb_item->Items->Clear();
				for each(Equipamento^ e in itens){ cb_item->Items->Add(e->nome); }
			}catch(Exception^){}
		}

		System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e){
			try{
				int itemId = itens[cb_item->SelectedIndex]->id;
				bool contem = false;
				int qual;
				for(int i=0; i<equipamentos->Count && !contem; i++){
					if(equipamentos[i]->id == itemId){
						contem = true;
						qual = i;
					}
				}
				PgSqlCommand^ pgCommand;
				if(contem)
					pgCommand = gcnew PgSqlCommand("UPDATE m_equip SET quantidade = "
						+(equipamentos[qual]->quantidade + (int)nud_quant->Value)
						+" WHERE p_id = " + id + " AND e_id = " + itemId, pgc);
				else
					pgCommand = gcnew PgSqlCommand("INSERT INTO m_equip (p_id, e_id, quantidade, n_usando) VALUES (" 
						+ id + ", " + itemId + ", "+ nud_quant->Value+", 0)", pgc);
				pgc->Open();
				pgCommand->ExecuteNonQuery();
				//equipamentos = gcnew List<Equipamento^>();
			} catch(Exception^){}

			loadEquipamentos();
		}
	};
}
