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
	/// Summary for FormRemoveItem
	/// </summary>
	public ref class FormRemoveItem : public System::Windows::Forms::Form{
	private:
		List<Equipamento^>^ equipamentos;
		PgSqlConnection^ pgc;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl_peso;
	private: System::Windows::Forms::Button^  btn_all;
			 int id;

	public:
		FormRemoveItem(PgSqlConnection^ _pgc, int _id)
		{
			InitializeComponent();

			id = _id;
			pgc = _pgc;
			loadEquipamentos();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormRemoveItem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_remove;
	protected:
	private: System::Windows::Forms::Button^  btn_cancel;
	private: System::Windows::Forms::NumericUpDown^  nud_quant;
	private: System::Windows::Forms::Label^  lbl_qt;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cb_item;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormRemoveItem::typeid));
			this->btn_remove = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->nud_quant = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl_qt = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cb_item = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl_peso = (gcnew System::Windows::Forms::Label());
			this->btn_all = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_quant))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_remove
			// 
			this->btn_remove->Enabled = false;
			this->btn_remove->Location = System::Drawing::Point(15, 114);
			this->btn_remove->Name = L"btn_remove";
			this->btn_remove->Size = System::Drawing::Size(93, 23);
			this->btn_remove->TabIndex = 19;
			this->btn_remove->Text = L"Remover";
			this->btn_remove->UseVisualStyleBackColor = true;
			this->btn_remove->Click += gcnew System::EventHandler(this, &FormRemoveItem::btn_remove_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btn_cancel->Location = System::Drawing::Point(114, 114);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(93, 23);
			this->btn_cancel->TabIndex = 18;
			this->btn_cancel->Text = L"Voltar";
			this->btn_cancel->UseVisualStyleBackColor = true;
			// 
			// nud_quant
			// 
			this->nud_quant->Location = System::Drawing::Point(83, 79);
			this->nud_quant->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 500, 0, 0, 0 });
			this->nud_quant->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 1, 0, 0, 0 });
			this->nud_quant->Name = L"nud_quant";
			this->nud_quant->Size = System::Drawing::Size(90, 20);
			this->nud_quant->TabIndex = 17;
			this->nud_quant->Value = System::Decimal(gcnew cli::array< System::Int32 >(4){ 1, 0, 0, 0 });
			// 
			// lbl_qt
			// 
			this->lbl_qt->AutoSize = true;
			this->lbl_qt->Location = System::Drawing::Point(127, 61);
			this->lbl_qt->Name = L"lbl_qt";
			this->lbl_qt->Size = System::Drawing::Size(10, 13);
			this->lbl_qt->TabIndex = 16;
			this->lbl_qt->Text = L".";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 59);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Quantidade disponiel:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Quantidade:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Item:";
			// 
			// cb_item
			// 
			this->cb_item->FormattingEnabled = true;
			this->cb_item->Location = System::Drawing::Point(83, 6);
			this->cb_item->Name = L"cb_item";
			this->cb_item->Size = System::Drawing::Size(121, 21);
			this->cb_item->TabIndex = 10;
			this->cb_item->SelectedIndexChanged += gcnew System::EventHandler(this, &FormRemoveItem::cb_item_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Peso unitario:";
			// 
			// lbl_peso
			// 
			this->lbl_peso->AutoSize = true;
			this->lbl_peso->Location = System::Drawing::Point(89, 37);
			this->lbl_peso->Name = L"lbl_peso";
			this->lbl_peso->Size = System::Drawing::Size(10, 13);
			this->lbl_peso->TabIndex = 13;
			this->lbl_peso->Text = L".";
			// 
			// btn_all
			// 
			this->btn_all->Location = System::Drawing::Point(179, 79);
			this->btn_all->Name = L"btn_all";
			this->btn_all->Size = System::Drawing::Size(28, 23);
			this->btn_all->TabIndex = 20;
			this->btn_all->Text = L"All";
			this->btn_all->UseVisualStyleBackColor = true;
			this->btn_all->Click += gcnew System::EventHandler(this, &FormRemoveItem::btn_all_Click);
			// 
			// FormRemoveItem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(217, 151);
			this->Controls->Add(this->btn_all);
			this->Controls->Add(this->btn_remove);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->nud_quant);
			this->Controls->Add(this->lbl_qt);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lbl_peso);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cb_item);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormRemoveItem";
			this->Text = L"Remove Item";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_quant))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

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
				cb_item->Items->Clear();
				for each(Equipamento^ e in equipamentos){ cb_item->Items->Add(e->nome); }
			} catch(Exception^){}
		}

		System::Void btn_remove_Click(System::Object^  sender, System::EventArgs^  e){
			int listId = cb_item->SelectedIndex;
			int itemId = equipamentos[cb_item->SelectedIndex]->id;
			try{
				PgSqlCommand^ pgCommand;
				if(equipamentos[listId]->quantidade == nud_quant->Value){
					pgCommand = gcnew PgSqlCommand("DELETE FROM m_equip "
						+ " WHERE p_id = " + id + " AND e_id = " + itemId, pgc);
				} else{
					pgCommand = gcnew PgSqlCommand("UPDATE m_equip SET quantidade = "
						+ (equipamentos[listId]->quantidade - (int)nud_quant->Value)
						+ " WHERE p_id = " + id + " AND e_id = " + itemId, pgc);
				}
				pgc->Open();
				pgCommand->ExecuteNonQuery();
				btn_remove->Enabled = false;
			} catch(Exception^){}
			loadEquipamentos();;
		}
		System::Void cb_item_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e){
			int listId = cb_item->SelectedIndex;
			lbl_peso->Text = ""+equipamentos[listId]->peso;
			lbl_qt->Text = ""+equipamentos[listId]->quantidade;
			nud_quant->Maximum = equipamentos[listId]->quantidade;
			btn_remove->Enabled = true;
		}
		System::Void btn_all_Click(System::Object^  sender, System::EventArgs^  e){
			nud_quant->Value = equipamentos[cb_item->SelectedIndex]->quantidade;
		}
	};
}
