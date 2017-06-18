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
	/// Summary for FormDB
	/// </summary>
	public ref class FormDB : public System::Windows::Forms::Form {
	private:
		PgSqlConnection^ pgc;
	public:
		FormDB(PgSqlConnection^ _pgc){
			InitializeComponent();
			pgc = _pgc;

			txt_conn->Text	= pgc->Host;
			txt_user->Text	= pgc->UserId;
			txt_senha->Text	= pgc->Password;
			nud_porta->Value= pgc->Port;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormDB(){
			if (components){
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::TextBox^  txt_user;
		System::Windows::Forms::TextBox^  txt_senha;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  label3;
		Devart::Data::PostgreSql::PgSqlConnection^  pgcTest;
		System::Windows::Forms::Button^  btn_ok;
		System::Windows::Forms::Button^  btn_cancel;
		System::Windows::Forms::Button^  btn_test;
		System::Windows::Forms::TextBox^  txt_conn;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::NumericUpDown^  nud_porta;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_user = (gcnew System::Windows::Forms::TextBox());
			this->txt_senha = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pgcTest = (gcnew Devart::Data::PostgreSql::PgSqlConnection());
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_test = (gcnew System::Windows::Forms::Button());
			this->txt_conn = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nud_porta = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_porta))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Usuario:";
			// 
			// txt_user
			// 
			this->txt_user->Location = System::Drawing::Point(91, 57);
			this->txt_user->Name = L"txt_user";
			this->txt_user->Size = System::Drawing::Size(122, 20);
			this->txt_user->TabIndex = 1;
			// 
			// txt_senha
			// 
			this->txt_senha->Location = System::Drawing::Point(91, 93);
			this->txt_senha->Name = L"txt_senha";
			this->txt_senha->Size = System::Drawing::Size(122, 20);
			this->txt_senha->TabIndex = 3;
			this->txt_senha->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Senha";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Porta:";
			// 
			// pgcTest
			// 
			this->pgcTest->CommitTimeout = 0;
			this->pgcTest->Name = L"pgcTest";
			// 
			// btn_ok
			// 
			this->btn_ok->Location = System::Drawing::Point(31, 197);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(75, 23);
			this->btn_ok->TabIndex = 6;
			this->btn_ok->Text = L"Ok";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &FormDB::btn_ok_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->Location = System::Drawing::Point(138, 197);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 7;
			this->btn_cancel->Text = L"Cancelar";
			this->btn_cancel->UseVisualStyleBackColor = true;
			// 
			// btn_test
			// 
			this->btn_test->Location = System::Drawing::Point(31, 168);
			this->btn_test->Name = L"btn_test";
			this->btn_test->Size = System::Drawing::Size(75, 23);
			this->btn_test->TabIndex = 8;
			this->btn_test->Text = L"Testar";
			this->btn_test->UseVisualStyleBackColor = true;
			this->btn_test->Click += gcnew System::EventHandler(this, &FormDB::btn_test_Click);
			// 
			// txt_conn
			// 
			this->txt_conn->Location = System::Drawing::Point(91, 23);
			this->txt_conn->Name = L"txt_conn";
			this->txt_conn->Size = System::Drawing::Size(122, 20);
			this->txt_conn->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 26);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Conecção:";
			// 
			// nud_porta
			// 
			this->nud_porta->Location = System::Drawing::Point(93, 131);
			this->nud_porta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 65535, 0, 0, 0 });
			this->nud_porta->Name = L"nud_porta";
			this->nud_porta->Size = System::Drawing::Size(120, 20);
			this->nud_porta->TabIndex = 11;
			this->nud_porta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4){ 5432, 0, 0, 0 });
			// 
			// FormDB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->nud_porta);
			this->Controls->Add(this->txt_conn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btn_test);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->btn_ok);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_senha);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_user);
			this->Controls->Add(this->label1);
			this->Name = L"FormDB";
			this->Text = L"FormDB";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_porta))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool testar(){
			if(txt_conn->Text->Length == 0){
				MessageBox::Show("digite a string de conecção do banco de dados\r\n"
					"tente 'localhost'", "Usuario em branco");
				return false;
			}
			if(txt_user->Text->Length == 0){
				MessageBox::Show("digite o nome do usuario do banco de dados", "Usuario em branco");
				return false;
			}
			if(txt_senha->Text->Length == 0)
				MessageBox::Show("Talvez seja necessario inserir senha para\r\n"
					"conectar-se a este banco de dados", "Senha em branco");
			//if(txt_port->Text->Length == 0){		troquei o textBox por um Nud
			//	MessageBox::Show("digite o numero da porta do banco de dados", "Porta em branco");
			//	return false;
			//}

			try{
				pgcTest->Host = txt_conn->Text;
				pgcTest->UserId = txt_user->Text;
				pgcTest->Password = txt_senha->Text;
				//pgcTest->Port = Int32::Parse(txt_port->Text);
				pgcTest->Port = (int)nud_porta->Value;
				pgcTest->Open();	//se tiver erro de conecção vai jogar uma exceção
				pgcTest->Close();
				return true;
			} catch(Exception^){}
			MessageBox::Show("Verifique o pgAdmin\r\nChame o administrador em caso de duvidas", "Conecção Invalida");
			return false;
		}

		System::Void btn_test_Click(System::Object^  sender, System::EventArgs^  e){
			if(testar()) MessageBox::Show("Conecção Valida", "Teste de Conecção");
		}
		System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e){
			if(testar()){
				pgc->Host = pgcTest->Host;
				pgc->UserId = pgcTest->UserId;
				pgc->Password  = pgcTest->Password;
				pgc->Port = pgcTest->Port;
				this->Close();
			}
		}
	};
}
