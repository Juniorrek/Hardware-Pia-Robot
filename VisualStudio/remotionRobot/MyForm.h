#pragma once

namespace remotionRobot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			procurarPortas();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  comboBoxPortas;
	private: System::Windows::Forms::ComboBox^  comboBoxTaxas;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  botaoConectarDesconectar;


	private: bool conectado = false;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  botaoFrente;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ProgressBar^  progressBarStatus;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  botaoTras;
	private: System::Windows::Forms::Button^  botaoEsquerda;
	private: System::Windows::Forms::Button^  botaoDireita;


	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBoxPortas = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxTaxas = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->botaoConectarDesconectar = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->botaoFrente = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->progressBarStatus = (gcnew System::Windows::Forms::ProgressBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->botaoTras = (gcnew System::Windows::Forms::Button());
			this->botaoEsquerda = (gcnew System::Windows::Forms::Button());
			this->botaoDireita = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 500;
			this->serialPort1->WriteTimeout = 500;
			// 
			// comboBoxPortas
			// 
			this->comboBoxPortas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxPortas->FormattingEnabled = true;
			this->comboBoxPortas->Location = System::Drawing::Point(142, 60);
			this->comboBoxPortas->Name = L"comboBoxPortas";
			this->comboBoxPortas->Size = System::Drawing::Size(121, 21);
			this->comboBoxPortas->TabIndex = 0;
			// 
			// comboBoxTaxas
			// 
			this->comboBoxTaxas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTaxas->FormattingEnabled = true;
			this->comboBoxTaxas->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"300", L"600", L"1200", L"2400", L"4800",
					L"9600", L"14400", L"19200", L"28800", L"38400", L"57600", L"115200"
			});
			this->comboBoxTaxas->Location = System::Drawing::Point(142, 96);
			this->comboBoxTaxas->Name = L"comboBoxTaxas";
			this->comboBoxTaxas->Size = System::Drawing::Size(121, 21);
			this->comboBoxTaxas->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Porta COM:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Taxa de transmissão:";
			// 
			// botaoConectarDesconectar
			// 
			this->botaoConectarDesconectar->Location = System::Drawing::Point(142, 134);
			this->botaoConectarDesconectar->Name = L"botaoConectarDesconectar";
			this->botaoConectarDesconectar->Size = System::Drawing::Size(83, 23);
			this->botaoConectarDesconectar->TabIndex = 4;
			this->botaoConectarDesconectar->Text = L"Conectar";
			this->botaoConectarDesconectar->UseVisualStyleBackColor = true;
			this->botaoConectarDesconectar->Click += gcnew System::EventHandler(this, &MyForm::botaoConectarDesconectar_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(339, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(156, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Recebido aqui";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(339, 173);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(156, 20);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"Envie aqui";
			// 
			// botaoFrente
			// 
			this->botaoFrente->Location = System::Drawing::Point(401, 54);
			this->botaoFrente->Name = L"botaoFrente";
			this->botaoFrente->Size = System::Drawing::Size(30, 30);
			this->botaoFrente->TabIndex = 8;
			this->botaoFrente->Text = L"/\\";
			this->botaoFrente->UseVisualStyleBackColor = true;
			this->botaoFrente->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoFrente_MouseDown);
			this->botaoFrente->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoFrente_MouseUp);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(37, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Status da conexão:";
			// 
			// progressBarStatus
			// 
			this->progressBarStatus->BackColor = System::Drawing::SystemColors::Control;
			this->progressBarStatus->Location = System::Drawing::Point(142, 20);
			this->progressBarStatus->Name = L"progressBarStatus";
			this->progressBarStatus->Size = System::Drawing::Size(23, 23);
			this->progressBarStatus->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(189, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(117, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Configurações de porta";
			// 
			// botaoTras
			// 
			this->botaoTras->Location = System::Drawing::Point(401, 130);
			this->botaoTras->Name = L"botaoTras";
			this->botaoTras->Size = System::Drawing::Size(30, 30);
			this->botaoTras->TabIndex = 14;
			this->botaoTras->Text = L"\\/";
			this->botaoTras->UseVisualStyleBackColor = true;
			this->botaoTras->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoTras_MouseDown);
			this->botaoTras->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoTras_MouseUp);
			// 
			// botaoEsquerda
			// 
			this->botaoEsquerda->Location = System::Drawing::Point(356, 90);
			this->botaoEsquerda->Name = L"botaoEsquerda";
			this->botaoEsquerda->Size = System::Drawing::Size(30, 30);
			this->botaoEsquerda->TabIndex = 15;
			this->botaoEsquerda->Text = L"<";
			this->botaoEsquerda->UseVisualStyleBackColor = true;
			this->botaoEsquerda->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoEsquerda_MouseDown);
			this->botaoEsquerda->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoEsquerda_MouseUp);
			// 
			// botaoDireita
			// 
			this->botaoDireita->Location = System::Drawing::Point(444, 90);
			this->botaoDireita->Name = L"botaoDireita";
			this->botaoDireita->Size = System::Drawing::Size(30, 30);
			this->botaoDireita->TabIndex = 16;
			this->botaoDireita->Text = L">";
			this->botaoDireita->UseVisualStyleBackColor = true;
			this->botaoDireita->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoDireita_MouseDown);
			this->botaoDireita->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::botaoDireita_MouseUp);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 210);
			this->Controls->Add(this->botaoDireita);
			this->Controls->Add(this->botaoEsquerda);
			this->Controls->Add(this->botaoTras);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->progressBarStatus);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->botaoFrente);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->botaoConectarDesconectar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxTaxas);
			this->Controls->Add(this->comboBoxPortas);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"Remotion Robot";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Procura as portas seriais COM disponíveis.
		private : void procurarPortas(void) {
			//Carrega um vetor com as portas disponíveis.
			array<Object^>^ vetorObjetos = SerialPort::GetPortNames();

			//Carrega o combobox com o vetor de portas.
			this->comboBoxPortas->Items->AddRange(vetorObjetos);
		}
	private: System::Void botaoConectarDesconectar_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!conectado) {
			//Limpa a primeira caixa de texto.
			this->textBox2->Text = String::Empty;
			if (this->comboBoxPortas->Text == String::Empty || this->comboBoxTaxas->Text == String::Empty) // Verifica se foi selecionado
				this->textBox1->Text = "Preencha as configurações de porta";
			else {
				try {
					if (!this->serialPort1->IsOpen) { // Carrega os dados no objeto serial e logo depois inicia a comunicação.
						this->serialPort1->PortName = this->comboBoxPortas->Text;
						this->serialPort1->BaudRate = Int32::Parse(this->comboBoxTaxas->Text);
						this->textBox2->Text = "Envie msgs aqui";
						this->serialPort1->Open();
						this->progressBarStatus->Value = 100;
						conectado = true;
						this->botaoConectarDesconectar->Text = "Desconectar";
					}
					else
						this->textBox1->Text = "Porta fechada";
				}
				catch (UnauthorizedAccessException^) {
					this->textBox1->Text = "Acesso negado";
				}
			}
		}
		else {
			//close serialPort
			this->serialPort1->Close();
			// update progress bar
			this->progressBarStatus->Value = 0;
			// Enable read button
			this->botaoTras->Enabled = true;
			// Enable the init button
			this->botaoConectarDesconectar->Enabled = true;
			conectado = false;
			this->botaoConectarDesconectar->Text = "Conectar";
		}
	}
/*
String^ name = this->serialPort1->PortName;
String^ message = "1";
if (this->serialPort1->IsOpen)
this->serialPort1->WriteLine(message);
else
this->textBox1->Text = "Porta fechada";
*/
private: System::Void botaoFrente_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Frente \\/";
}
private: System::Void botaoFrente_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Frente /\\";
	this->textBox2->Focus();
}
private: System::Void botaoEsquerda_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Esquerda \\/";
}
private: System::Void botaoEsquerda_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Esquerda /\\";
	this->textBox2->Focus();
}
private: System::Void botaoTras_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Tras \\/";
}
private: System::Void botaoTras_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Tras /\\";
	this->textBox2->Focus();
}
private: System::Void botaoDireita_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Direita \\/";
}
private: System::Void botaoDireita_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->textBox1->Text = "Direita /\\";
	this->textBox2->Focus();
}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Up) {
		this->textBox1->Text = "Frente \\/";
	} else if (e->KeyCode == Keys::Left) {
		this->textBox1->Text = "Esquerda \\/";
	} else if (e->KeyCode == Keys::Down) {
		this->textBox1->Text = "Tras \\/";
	} else if (e->KeyCode == Keys::Right) {
		this->textBox1->Text = "Direita \\/";
	}
}
private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Up) {
		this->textBox1->Text = "Frente /\\";
	}
	else if (e->KeyCode == Keys::Left) {
		this->textBox1->Text = "Esquerda /\\";
	}
	else if (e->KeyCode == Keys::Down) {
		this->textBox1->Text = "Tras /\\";
	}
	else if (e->KeyCode == Keys::Right) {
		this->textBox1->Text = "Direita /\\";
	}
}
};
}
