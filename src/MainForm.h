#pragma once
#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>

#include <map>
#include <vector>
#include <utility>



namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Resources;




	std::string SysToSTL(System::String ^ in_s) {  //parameter inputed string
		using namespace System::Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(in_s)).ToPointer();
		std::string out_s = chars; //output string
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));
		//return std::string(out_s);
		return out_s;
	}


	bool pred(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
	{
		return a.second < b.second;
	}

	bool isWordSep(char ch){
		return ((ch == '(') || (ch == ')') || (ch == ',') || (ch == '.') || (ch == '[') || (ch == ']')
			|| (ch == '{') || (ch == '}') || (ch == ' ') || (ch == '>') || (ch == '<') || (ch == '=')
			|| (ch == ';') || (ch == '\n') || (ch == '&') || (ch == '|') || (ch == '!')

			//added 17.08 19:00
			|| (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%'));
	}
	bool isBrace(char ch){
		return ((ch == '(') || (ch == ')') || (ch == '{') || (ch == '}') || (ch == '[') || (ch == ']'));
	}
	bool isSeparator(char ch){
		return ((ch == ',') || (ch == '.') || (ch == ';') || (ch == '\'') || (ch == '"') || (ch == ':'));
	}
	bool isArithmetical(char ch){
		return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '%') || (ch == '='));
	}
	bool isDigit(char ch){
		return ((ch == '0') || (ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') || (ch == '5')
			|| (ch == '6') || (ch == '7') || (ch == '8') || (ch == '9'));
	}


	//строка ввода входной последовательности и ее обработка:
	//вычленение каждого символа последовательности

	std::map<std::string, int> keyWords; //ключевые слова (10)
	std::map<std::string, int> iden; //идентификаторы (20)
	std::map<std::string, int> contstants; //константы (30)
	std::map<std::string, int> opS; //знаки операций (40)
	std::map<std::string, int> logS; //логические операторы (50)
	std::map<std::string, int> sepS; //знаки разделителей (60)
	std::map<std::string, int> constText; //константы текстовые (70)

	std::vector <int> descriptionCode;
	std::string pseudoCode;

	//создание и инициализация всего связанного с автоматом
	int state = 0;	//текущее состояние автомата
	int pz = 0; //nothing
	int previous_state = 0;	//предшествующее состояние (на всякий случай)
	int x = 0;	//вход
	int y = 0;	//выход
	int n_symbol = -1; //номер символа строки последовательности

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonAnalyze;
	protected:


	private: System::Windows::Forms::Label^  labelSource;

	
	protected:
		String ^str;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;










































	private: System::Windows::Forms::Button^  buttonReset;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::RichTextBox^  richTextBox30;
	private: System::Windows::Forms::RichTextBox^  richTextBox29;
	private: System::Windows::Forms::RichTextBox^  richTextBox28;
	private: System::Windows::Forms::RichTextBox^  richTextBox27;
	private: System::Windows::Forms::RichTextBox^  richTextBox26;
	private: System::Windows::Forms::RichTextBox^  richTextBox25;
	private: System::Windows::Forms::RichTextBox^  richTextBox24;
	private: System::Windows::Forms::RichTextBox^  richTextBox23;
	private: System::Windows::Forms::RichTextBox^  richTextBox22;
	private: System::Windows::Forms::RichTextBox^  richTextBox21;
	private: System::Windows::Forms::RichTextBox^  richTextBox20;
	private: System::Windows::Forms::RichTextBox^  richTextBox19;
	private: System::Windows::Forms::RichTextBox^  richTextBox18;
	private: System::Windows::Forms::RichTextBox^  richTextBox17;
	private: System::Windows::Forms::RichTextBox^  richTextBox16;
	private: System::Windows::Forms::RichTextBox^  richTextBox15;
	private: System::Windows::Forms::RichTextBox^  richTextBox14;
	private: System::Windows::Forms::RichTextBox^  richTextBox13;
	private: System::Windows::Forms::RichTextBox^  richTextBox12;
	private: System::Windows::Forms::RichTextBox^  richTextBox11;
	private: System::Windows::Forms::RichTextBox^  richTextBox10;
	private: System::Windows::Forms::RichTextBox^  richTextBox9;
	private: System::Windows::Forms::RichTextBox^  richTextBox8;
	private: System::Windows::Forms::RichTextBox^  richTextBox7;
	private: System::Windows::Forms::RichTextBox^  richTextBox6;
	private: System::Windows::Forms::RichTextBox^  richTextBox5;
	private: System::Windows::Forms::RichTextBox^  richTextBox4;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
private: System::Windows::Forms::Label^  label1;

private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::RichTextBox^  richTextBox32;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::RichTextBox^  richTextBox31;





















	protected:

	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonAnalyze = (gcnew System::Windows::Forms::Button());
			this->labelSource = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->richTextBox30 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox29 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox28 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox27 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox26 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox25 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox24 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox23 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox22 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox21 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox20 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox19 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox18 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox17 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox15 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox14 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox13 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox12 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox11 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox10 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox9 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox8 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox7 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox16 = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox32 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox31 = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonAnalyze
			// 
			this->buttonAnalyze->Location = System::Drawing::Point(368, 23);
			this->buttonAnalyze->Name = L"buttonAnalyze";
			this->buttonAnalyze->Size = System::Drawing::Size(66, 23);
			this->buttonAnalyze->TabIndex = 0;
			this->buttonAnalyze->Text = L"Analyze";
			this->buttonAnalyze->UseVisualStyleBackColor = true;
			this->buttonAnalyze->Click += gcnew System::EventHandler(this, &MainForm::buttonStartAuto_Click);
			// 
			// labelSource
			// 
			this->labelSource->AutoSize = true;
			this->labelSource->Location = System::Drawing::Point(9, 9);
			this->labelSource->Name = L"labelSource";
			this->labelSource->Size = System::Drawing::Size(88, 13);
			this->labelSource->TabIndex = 2;
			this->labelSource->Text = L"Код программы";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 14;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				45)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				135)));
			this->tableLayoutPanel1->Controls->Add(this->richTextBox30, 13, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox29, 12, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox28, 11, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox27, 10, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox26, 9, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox25, 8, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox24, 7, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox23, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox22, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox21, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox20, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox19, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox18, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox17, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox15, 12, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox14, 11, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox13, 10, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox12, 9, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox11, 8, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox10, 7, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox9, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox8, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox7, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox6, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox5, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox4, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox3, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->richTextBox16, 13, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 319);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1268, 339);
			this->tableLayoutPanel1->TabIndex = 3;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::tableLayoutPanel1_Paint);
			// 
			// richTextBox30
			// 
			this->richTextBox30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox30->Location = System::Drawing::Point(1128, 43);
			this->richTextBox30->Name = L"richTextBox30";
			this->richTextBox30->ReadOnly = true;
			this->richTextBox30->Size = System::Drawing::Size(137, 296);
			this->richTextBox30->TabIndex = 41;
			this->richTextBox30->TabStop = false;
			this->richTextBox30->Text = L"";
			// 
			// richTextBox29
			// 
			this->richTextBox29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox29->Location = System::Drawing::Point(1083, 43);
			this->richTextBox29->Name = L"richTextBox29";
			this->richTextBox29->ReadOnly = true;
			this->richTextBox29->Size = System::Drawing::Size(39, 296);
			this->richTextBox29->TabIndex = 40;
			this->richTextBox29->TabStop = false;
			this->richTextBox29->Text = L"";
			// 
			// richTextBox28
			// 
			this->richTextBox28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox28->Location = System::Drawing::Point(948, 43);
			this->richTextBox28->Name = L"richTextBox28";
			this->richTextBox28->ReadOnly = true;
			this->richTextBox28->Size = System::Drawing::Size(129, 296);
			this->richTextBox28->TabIndex = 39;
			this->richTextBox28->TabStop = false;
			this->richTextBox28->Text = L"";
			// 
			// richTextBox27
			// 
			this->richTextBox27->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox27->Location = System::Drawing::Point(903, 43);
			this->richTextBox27->Name = L"richTextBox27";
			this->richTextBox27->ReadOnly = true;
			this->richTextBox27->Size = System::Drawing::Size(39, 296);
			this->richTextBox27->TabIndex = 38;
			this->richTextBox27->TabStop = false;
			this->richTextBox27->Text = L"";
			// 
			// richTextBox26
			// 
			this->richTextBox26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox26->Location = System::Drawing::Point(768, 43);
			this->richTextBox26->Name = L"richTextBox26";
			this->richTextBox26->ReadOnly = true;
			this->richTextBox26->Size = System::Drawing::Size(129, 296);
			this->richTextBox26->TabIndex = 37;
			this->richTextBox26->TabStop = false;
			this->richTextBox26->Text = L"";
			// 
			// richTextBox25
			// 
			this->richTextBox25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox25->Location = System::Drawing::Point(723, 43);
			this->richTextBox25->Name = L"richTextBox25";
			this->richTextBox25->ReadOnly = true;
			this->richTextBox25->Size = System::Drawing::Size(39, 296);
			this->richTextBox25->TabIndex = 36;
			this->richTextBox25->TabStop = false;
			this->richTextBox25->Text = L"";
			// 
			// richTextBox24
			// 
			this->richTextBox24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox24->Location = System::Drawing::Point(588, 43);
			this->richTextBox24->Name = L"richTextBox24";
			this->richTextBox24->ReadOnly = true;
			this->richTextBox24->Size = System::Drawing::Size(129, 296);
			this->richTextBox24->TabIndex = 35;
			this->richTextBox24->TabStop = false;
			this->richTextBox24->Text = L"";
			// 
			// richTextBox23
			// 
			this->richTextBox23->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox23->Location = System::Drawing::Point(543, 43);
			this->richTextBox23->Name = L"richTextBox23";
			this->richTextBox23->ReadOnly = true;
			this->richTextBox23->Size = System::Drawing::Size(39, 296);
			this->richTextBox23->TabIndex = 34;
			this->richTextBox23->TabStop = false;
			this->richTextBox23->Text = L"";
			// 
			// richTextBox22
			// 
			this->richTextBox22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox22->Location = System::Drawing::Point(408, 43);
			this->richTextBox22->Name = L"richTextBox22";
			this->richTextBox22->ReadOnly = true;
			this->richTextBox22->Size = System::Drawing::Size(129, 296);
			this->richTextBox22->TabIndex = 33;
			this->richTextBox22->TabStop = false;
			this->richTextBox22->Text = L"";
			// 
			// richTextBox21
			// 
			this->richTextBox21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox21->Location = System::Drawing::Point(363, 43);
			this->richTextBox21->Name = L"richTextBox21";
			this->richTextBox21->ReadOnly = true;
			this->richTextBox21->Size = System::Drawing::Size(39, 296);
			this->richTextBox21->TabIndex = 32;
			this->richTextBox21->TabStop = false;
			this->richTextBox21->Text = L"";
			// 
			// richTextBox20
			// 
			this->richTextBox20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox20->Location = System::Drawing::Point(228, 43);
			this->richTextBox20->Name = L"richTextBox20";
			this->richTextBox20->ReadOnly = true;
			this->richTextBox20->Size = System::Drawing::Size(129, 296);
			this->richTextBox20->TabIndex = 31;
			this->richTextBox20->TabStop = false;
			this->richTextBox20->Text = L"";
			// 
			// richTextBox19
			// 
			this->richTextBox19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox19->Location = System::Drawing::Point(183, 43);
			this->richTextBox19->Name = L"richTextBox19";
			this->richTextBox19->ReadOnly = true;
			this->richTextBox19->Size = System::Drawing::Size(39, 296);
			this->richTextBox19->TabIndex = 30;
			this->richTextBox19->TabStop = false;
			this->richTextBox19->Text = L"";
			// 
			// richTextBox18
			// 
			this->richTextBox18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox18->Location = System::Drawing::Point(48, 43);
			this->richTextBox18->Name = L"richTextBox18";
			this->richTextBox18->ReadOnly = true;
			this->richTextBox18->Size = System::Drawing::Size(129, 296);
			this->richTextBox18->TabIndex = 29;
			this->richTextBox18->TabStop = false;
			this->richTextBox18->Text = L"";
			// 
			// richTextBox17
			// 
			this->richTextBox17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox17->Location = System::Drawing::Point(3, 43);
			this->richTextBox17->Name = L"richTextBox17";
			this->richTextBox17->ReadOnly = true;
			this->richTextBox17->Size = System::Drawing::Size(39, 296);
			this->richTextBox17->TabIndex = 28;
			this->richTextBox17->TabStop = false;
			this->richTextBox17->Text = L"";
			// 
			// richTextBox15
			// 
			this->richTextBox15->Location = System::Drawing::Point(1083, 3);
			this->richTextBox15->Multiline = false;
			this->richTextBox15->Name = L"richTextBox15";
			this->richTextBox15->ReadOnly = true;
			this->richTextBox15->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox15->Size = System::Drawing::Size(39, 34);
			this->richTextBox15->TabIndex = 26;
			this->richTextBox15->TabStop = false;
			this->richTextBox15->Text = L"70";
			// 
			// richTextBox14
			// 
			this->richTextBox14->Location = System::Drawing::Point(948, 3);
			this->richTextBox14->Multiline = false;
			this->richTextBox14->Name = L"richTextBox14";
			this->richTextBox14->ReadOnly = true;
			this->richTextBox14->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox14->Size = System::Drawing::Size(129, 34);
			this->richTextBox14->TabIndex = 25;
			this->richTextBox14->TabStop = false;
			this->richTextBox14->Text = L"Разделители";
			// 
			// richTextBox13
			// 
			this->richTextBox13->Location = System::Drawing::Point(903, 3);
			this->richTextBox13->Multiline = false;
			this->richTextBox13->Name = L"richTextBox13";
			this->richTextBox13->ReadOnly = true;
			this->richTextBox13->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox13->Size = System::Drawing::Size(39, 34);
			this->richTextBox13->TabIndex = 24;
			this->richTextBox13->TabStop = false;
			this->richTextBox13->Text = L"60";
			// 
			// richTextBox12
			// 
			this->richTextBox12->Location = System::Drawing::Point(768, 3);
			this->richTextBox12->Multiline = false;
			this->richTextBox12->Name = L"richTextBox12";
			this->richTextBox12->ReadOnly = true;
			this->richTextBox12->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox12->Size = System::Drawing::Size(129, 34);
			this->richTextBox12->TabIndex = 23;
			this->richTextBox12->TabStop = false;
			this->richTextBox12->Text = L"Логич. опер.";
			// 
			// richTextBox11
			// 
			this->richTextBox11->Location = System::Drawing::Point(723, 3);
			this->richTextBox11->Multiline = false;
			this->richTextBox11->Name = L"richTextBox11";
			this->richTextBox11->ReadOnly = true;
			this->richTextBox11->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox11->Size = System::Drawing::Size(39, 34);
			this->richTextBox11->TabIndex = 22;
			this->richTextBox11->TabStop = false;
			this->richTextBox11->Text = L"50";
			// 
			// richTextBox10
			// 
			this->richTextBox10->Location = System::Drawing::Point(588, 3);
			this->richTextBox10->Multiline = false;
			this->richTextBox10->Name = L"richTextBox10";
			this->richTextBox10->ReadOnly = true;
			this->richTextBox10->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox10->Size = System::Drawing::Size(129, 34);
			this->richTextBox10->TabIndex = 21;
			this->richTextBox10->TabStop = false;
			this->richTextBox10->Text = L"Зн. операций";
			// 
			// richTextBox9
			// 
			this->richTextBox9->Location = System::Drawing::Point(543, 3);
			this->richTextBox9->Multiline = false;
			this->richTextBox9->Name = L"richTextBox9";
			this->richTextBox9->ReadOnly = true;
			this->richTextBox9->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox9->Size = System::Drawing::Size(39, 34);
			this->richTextBox9->TabIndex = 20;
			this->richTextBox9->TabStop = false;
			this->richTextBox9->Text = L"40";
			this->richTextBox9->TextChanged += gcnew System::EventHandler(this, &MainForm::richTextBox9_TextChanged);
			// 
			// richTextBox8
			// 
			this->richTextBox8->Location = System::Drawing::Point(408, 3);
			this->richTextBox8->Multiline = false;
			this->richTextBox8->Name = L"richTextBox8";
			this->richTextBox8->ReadOnly = true;
			this->richTextBox8->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox8->Size = System::Drawing::Size(129, 34);
			this->richTextBox8->TabIndex = 19;
			this->richTextBox8->TabStop = false;
			this->richTextBox8->Text = L"Константы числ.";
			// 
			// richTextBox7
			// 
			this->richTextBox7->Location = System::Drawing::Point(363, 3);
			this->richTextBox7->Multiline = false;
			this->richTextBox7->Name = L"richTextBox7";
			this->richTextBox7->ReadOnly = true;
			this->richTextBox7->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox7->Size = System::Drawing::Size(39, 34);
			this->richTextBox7->TabIndex = 18;
			this->richTextBox7->TabStop = false;
			this->richTextBox7->Text = L"30";
			// 
			// richTextBox6
			// 
			this->richTextBox6->Location = System::Drawing::Point(228, 3);
			this->richTextBox6->Multiline = false;
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->ReadOnly = true;
			this->richTextBox6->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox6->Size = System::Drawing::Size(129, 34);
			this->richTextBox6->TabIndex = 17;
			this->richTextBox6->TabStop = false;
			this->richTextBox6->Text = L"Идентиф.";
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(183, 3);
			this->richTextBox5->Multiline = false;
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->ReadOnly = true;
			this->richTextBox5->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox5->Size = System::Drawing::Size(39, 34);
			this->richTextBox5->TabIndex = 16;
			this->richTextBox5->TabStop = false;
			this->richTextBox5->Text = L"20";
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(48, 3);
			this->richTextBox4->Multiline = false;
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->ReadOnly = true;
			this->richTextBox4->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox4->Size = System::Drawing::Size(129, 34);
			this->richTextBox4->TabIndex = 15;
			this->richTextBox4->TabStop = false;
			this->richTextBox4->Text = L"Ключевые";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(3, 3);
			this->richTextBox3->Multiline = false;
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox3->Size = System::Drawing::Size(39, 34);
			this->richTextBox3->TabIndex = 14;
			this->richTextBox3->TabStop = false;
			this->richTextBox3->Text = L"10";
			// 
			// richTextBox16
			// 
			this->richTextBox16->Location = System::Drawing::Point(1128, 3);
			this->richTextBox16->Multiline = false;
			this->richTextBox16->Name = L"richTextBox16";
			this->richTextBox16->ReadOnly = true;
			this->richTextBox16->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextBox16->Size = System::Drawing::Size(137, 34);
			this->richTextBox16->TabIndex = 27;
			this->richTextBox16->TabStop = false;
			this->richTextBox16->Text = L"Константы текст.";
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(368, 138);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(66, 23);
			this->buttonReset->TabIndex = 10;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &MainForm::buttonZeroState_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(12, 25);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(350, 269);
			this->richTextBox1->TabIndex = 11;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(484, 25);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(165, 267);
			this->richTextBox2->TabIndex = 12;
			this->richTextBox2->Text = L"";
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(368, 271);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(66, 23);
			this->buttonClear->TabIndex = 13;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(481, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Ошибки";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(672, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(110, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Дескрипторный код";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 306);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Классы лексем";
			// 
			// richTextBox32
			// 
			this->richTextBox32->Location = System::Drawing::Point(982, 25);
			this->richTextBox32->Name = L"richTextBox32";
			this->richTextBox32->Size = System::Drawing::Size(301, 267);
			this->richTextBox32->TabIndex = 18;
			this->richTextBox32->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(979, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Псеводокод";
			// 
			// richTextBox31
			// 
			this->richTextBox31->Location = System::Drawing::Point(675, 25);
			this->richTextBox31->Name = L"richTextBox31";
			this->richTextBox31->Size = System::Drawing::Size(301, 267);
			this->richTextBox31->TabIndex = 20;
			this->richTextBox31->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1292, 670);
			this->Controls->Add(this->richTextBox31);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox32);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->labelSource);
			this->Controls->Add(this->buttonAnalyze);
			this->Name = L"MainForm";
			this->Text = L"Analyzer";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//нумеруем столбцы строки t
		/**
		Control ^c;
		c = tableLayoutPanel1->GetControlFromPosition(0, 0);
		c->Text = gcnew String(System::Environment::NewLine + "0");
		c = tableLayoutPanel1->GetControlFromPosition(0, 2);
		c->Text = gcnew String(System::Environment::NewLine + "0");
		/**/

	}

	

	private: System::Void textBoxInput_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			
	}


			 //ввод последовательности: запрещаем все, кроме 0..3, разрешаем Backspace
	private: System::Void textBoxInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if ((e->KeyChar == '0') || (e->KeyChar == '1') || (e->KeyChar == '2') || (e->KeyChar == '3')){
			return;
		}
		if (e->KeyChar == (char)Keys::Back){
			return;
		}
		e->Handled = true;
	}

			 //берем очередной входной символ из строки
	public: System::Int32 GetInputedX(){
		n_symbol++;
		int sym;

		sym = richTextBox1->Text[n_symbol];

		return sym - 48;
	}

	public: System::Void DeleteCommentsSpaces(){
		std::string buf = SysToSTL(richTextBox1->Text);
		char newline = '\n';

		for (std::string::iterator it = buf.begin(), end = buf.end(); it != end; ++it) {	
			if (*it == newline) pz++;

			if ((*it == '/') && (*(it + 1) == '*')){
				while (!((*it == '*') && (*(it + 1) == '/')))
					buf.erase(it);
				buf.erase(it);
				buf.erase(it);
			}

			if ((*it == '/') && (*(it + 1) == '/')){

				while (*it != '\n') {
					buf.erase(it);
					if (it == buf.end()){
					buf += ' ';
					break;
				}
				}
			}

			//commented 18.08 19:20
			if (*(it) == '"'){
				it++;
				while ((*it != '"') && (it!=end))
					it++;
			}


			//commented 18.08 17:30
			if ((*it) == ' ' && *(it + 1) == ' '){
				while (*(it) == ' '){
					it++;
					buf.erase(it-1);
				}
			}

			if (*(it)== '\t'){
				buf.erase(it++);
			}
			//

			if (*it == ' ' && *(it + 1) == ' '){
				if (*(it - 1) == '"'){
					while (*(it + 1) != '"') it++;
					break;
				}
			buf.erase(it--);
			}

			//commented 17.08 19:00
			/**
			if (*it == '=' && *(it + 1) == ' ' && *(it + 2) == '='){
				buf.erase(++it);
			}
			/**/
			if (isArithmetical(*it) && *(it + 1) == ' ' && isArithmetical(*it+2)){
				buf.erase(++it);
			}


		}

		richTextBox1->Clear();
		richTextBox1->Text = gcnew System::String(buf.c_str());
	}

			
			//заполняем сетку
	public: System::Void PaintGreed(){
		Control ^c;

		//t
		c = tableLayoutPanel1->GetControlFromPosition((n_symbol%9), 0);
		c->Text = gcnew String(System::Environment::NewLine + (n_symbol));

		//x
		c = tableLayoutPanel1->GetControlFromPosition((n_symbol % 9), 1);
		c->Text = gcnew String(System::Environment::NewLine + x);

		//s
		c = tableLayoutPanel1->GetControlFromPosition(((n_symbol+1) % 9), 2);
		c->Text = gcnew String(System::Environment::NewLine + state);

		//y
		c = tableLayoutPanel1->GetControlFromPosition((n_symbol % 9), 3);
		c->Text = gcnew String(System::Environment::NewLine + y);
	}

	//ф-я, рисующая картинку в зависимости от состояния

			
	//in project?
	private: System::Void buttonDoStep_Click(System::Object^  sender, System::EventArgs^  e) {
		if ((richTextBox1->Text == "") || (n_symbol + 1) == richTextBox1->Text->Length) return;
		x = GetInputedX();

			/**/
		switch (state){



		case 0: {
			if (x == 0) {
				previous_state = state;
				state = 1;
				y = 0;
			}
			else goto d;
			break;
		}
		case 1: {
			if (x == 1) {
				previous_state = state;
				state = 2;
				y = 2;
			}
			else goto d;
			break;
		}
		case 2:{
			if (x == 3) {
				previous_state = state;
				state = 3;
				y = 1;
			}
			else goto d;
			break;
		}
		case 3: {
			if (x == 1) {
				previous_state = state;
				state = 4;
				y = 2;
			}
			else goto d;
			break;
		}
		case 4: {
			if (x == 2) {
				previous_state = state;
				state = 0;
				y = 0;
			}
			else if (x == 3){
				previous_state = state;
				state = 5;
				y = 0;
			}
			else goto d;
			break;
		}
		case 5: {
			if (x == 1) {
				previous_state = state;
				state = 2;
				y = 2;
			}
			else goto d;
			break;
		}
			d:
		default:
			MessageBox::Show("There is something wrong with input", "Wrong Input", MessageBoxButtons::OK, MessageBoxIcon::Error);
			break;
		}
		/**/
	
	}

	//analyzing!
	private: System::Void buttonStartAuto_Click(System::Object^  sender, System::EventArgs^  e) {
		bool wm = false; //without mistake
		state = 0;
		buttonZeroState_Click(sender, e);
		int iter = richTextBox1->Text->Length;
		try{
			/**
			for (int i = 0; i < iter; i++){
				buttonDoStep_Click(sender, e);
			}
			/**/
			DeleteCommentsSpaces();
			DeleteCommentsSpaces();
			DeleteCommentsSpaces();

			std::string buf = SysToSTL(richTextBox1->Text);
			buf.append(" ");

			//delete '\n'
			//buf.erase(std::remove(buf.begin(), buf.end(), '\n'), buf.end());
			for (std::string::iterator it = buf.begin(), end = buf.end(); it != end; ++it) {
				if (*(it) == '\n'){
					*it = ' ';
				}
			}

			int nu = 0;
			char ch;
			std::string chain;
			for (std::string::iterator it = buf.begin(), end = buf.end(); it != end; ++it) {
				ch = *it;
				nu++;
				//richTextBox31->Text += gcnew System::String("b4 st: ") + state + Environment::NewLine;

			switch (state){
			case 0:{
				if (ch == 'i'){
					state = 3;
					chain += ch;
				}
				else if (ch == 'f'){
					state = 9;
					chain += ch;
				}
				else if (ch == 'd'){
					state = 15;
					chain += ch;
				}
				else if (ch == 'b'){
					state = 23;
					chain += ch;
				}
				else if (ch == 'c'){
					state = 33;
					chain += ch;
				}
				else if (ch == 'e'){
					state = 46;
					chain += ch;
				}
				else if (ch == 'l'){
					state = 54;
					chain += ch;
				}
				else if (ch == 'r'){
					state = 59;
					chain += ch;
				}
				else if (ch == 'w'){
					state = 66;
					chain += ch;
				}
				else if (ch == 't'){
					state = 72;
					chain += ch;
				}
				else if (ch == 's'){
					state = 84;
					chain += ch;
				}
				else if (isBrace(ch)){
					state = 102;
					chain += ch;
				}
				else if (isSeparator(ch) && ch != '"'){
					state = 103;
					chain += ch;
				}
				/**
				//17.08 19:00 commented
				else if (isArithmetical(ch)){
					state = 104;
					chain += ch;
				}
				/**/
				else if (ch == '+'){
					state = 104;
					chain += ch;
				}

				else if (ch == '-'){
					//state = 108;
					state = 136;
					chain += ch;
				}

				else if (ch == '/'){
					state = 112;
					chain += ch;
				}

				else if (ch == '*'){
					state = 115;
					chain += ch;
				}

				else if (ch == '%'){
					state = 118;
					chain += ch;
				}
				
				else if (ch == '>'){
					state = 121;
					chain += ch;
				}

				else if (ch == '<'){
					state = 124;
					chain += ch;
				}

				else if (ch == '!'){
					state = 127;
					chain += ch;
				}

				else if (ch == '='){
					state = 131;
					chain += ch;
				}

				else if (ch == '"'){
					state = 134;
					//chain += ch;
				}

				/**
				//commented 25.08
				else if (ch != ' '){
					chain += ch;
					state = 1;
				}
				/**/

				//digits

				else if (ch == '-'){
					state = 136;
					chain += ch;
				}
				else if (ch == '0'){
					state = 142;
					chain += ch;
				}
				else if ((isDigit(ch)) && (ch != '0')){
					state = 137;
					chain += ch;
				}
				/**
				//commented 25.08 01:30
				else{
					state = 22;
				}
				/**/
				//digits-end

				//substitution label: commented 25.08
				else if (ch != ' '){
					chain += ch;
					state = 1;
				}

				
				break;
			}
			case 1:{
				if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else if (ch == ' '){
					break;
				}
				else{
					chain += ch;
				}
				break;
			}
			
			case 3:{
				if (ch == 'n'){
					state = 4;
					chain += ch;
				}
				else if (ch == 'f'){
					chain += ch;
					state = 7;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 4:{
				if (ch == 't'){
					state = 5;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 5:{
				if (isWordSep(ch)){
					state = 6;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 7:{
				if (isWordSep(ch)){
					state = 8;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 9:{
				if (ch == 'l'){
					state = 10;
					chain += ch;
				}
				else if (ch == 'o'){
					state = 51;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 10:{
				if (ch == 'o'){
					state = 11;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				} 
				else{
					//
					chain += ch;
					state = 1;

				} 
				break;
			}
			case 11:{
				if (ch == 'a'){
					state = 12;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 12:{
				if (ch == 't'){
					state = 13;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 13:{
				if (isWordSep(ch)){
					state = 14;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 15:{
				if (ch == 'o'){
					state = 16;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 16:{
				if (ch == 'u'){
					state = 17;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					//state = 2;
					state = 45;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 17:{
				if (ch == 'b'){
					state = 18;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 18:{
				if (ch == 'l'){
					state = 19;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 19:{
				if (ch == 'e'){
					state = 20;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 20:{
				if (isWordSep(ch)){
					state = 21;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 23:{
				if (ch == 'o'){
					state = 24;
					chain += ch;
				}
				else if (ch=='r'){
					state = 28;
					chain += ch;

				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 24:{
				if (ch == 'o'){
					state = 25;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 25:{
				if (ch == 'l'){
					state = 26;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 26:{
				if (isWordSep(ch)){
					state = 27;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 28:{
				if (ch == 'e'){
					state = 29;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 29:{
				if (ch == 'a'){
					state = 30;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 30:{
				if (ch == 'k'){
					state = 31;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 31:{
				if (isWordSep(ch)){
					state = 32;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 33:{
				if (ch == 'o'){
					state = 34;
					chain += ch;
				}
				else if (ch == 'a'){
					state = 76;
					chain += ch;
				}
				else if (ch == 'i'){
					state = 96;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 34:{
				if (ch == 'n'){
					state = 35;
					chain += ch;
				}
				else if (ch == 'u'){
					state = 99;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 35:{
				if (ch == 's'){
					state = 36;
					chain += ch;
				}
				else if (ch == 't'){
					state = 39;
					chain += ch;

				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 36:{
				if (ch == 't'){
					state = 37;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 37:{
				if (isWordSep(ch)){
					state = 38;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 39:{
				if (ch == 'i'){
					state = 40;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 40:{
				if (ch == 'n'){
					state = 41;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 41:{
				if (ch == 'u'){
					state = 42;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 42:{
				if (ch == 'e'){
					state = 43;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;
				}
				break;
			}
			case 43:{
				if (isWordSep(ch)){
					state = 44;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 46:{
				if (ch == 'l'){
					state = 47;
					chain += ch;
				}
				else if (ch == 'n'){
					state = 147;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 47:{
				if (ch == 's'){
					state = 48;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 48:{
				if (ch == 'e'){
					state = 49;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 49:{
				if (isWordSep(ch)){
					state = 50;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 51:{
				if (ch == 'r'){
					state = 52;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 52:{
				if (isWordSep(ch)){
					state = 53;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 54:{
				if (ch == 'o'){
					state = 55;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 55:{
				if (ch == 'n'){
					state = 56;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 56:{
				if (ch == 'g'){
					state = 57;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 57:{
				if (isWordSep(ch)){
					state = 58;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 59:{
				if (ch == 'e'){
					state = 60;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 60:{
				if (ch == 't'){
					state = 61;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 61:{
				if (ch == 'u'){
					state = 62;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 62:{
				if (ch == 'r'){
					state = 63;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 63:{
				if (ch == 'n'){
					state = 64;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 64:{
				if (isWordSep(ch)){
					state = 65;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 66:{
				if (ch == 'h'){
					state = 67;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 67:{
				if (ch == 'i'){
					state = 68;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 68:{
				if (ch == 'l'){
					state = 69;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 69:{
				if (ch == 'e'){
					state = 70;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 70:{
				if (isWordSep(ch)){
					state = 71;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 72:{
				if (ch == 'r'){
					state = 73;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 73:{
				if (ch == 'y'){
					state = 74;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 74:{
				if (isWordSep(ch)){
					state = 75;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 76:{
				if (ch == 't'){
					state = 77;
					chain += ch;
				}
				else if (ch == 's'){
					state = 81;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 77:{
				if (ch == 'c'){
					state = 78;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 78:{
				if (ch == 'h'){
					state = 79;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 79:{
				if (isWordSep(ch)){
					state = 80;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 81:{
				if (ch == 'e'){
					state = 82;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 82:{
				if (isWordSep(ch)){
					state = 83;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 84:{
				if (ch == 'h'){
					state = 85;
					chain += ch;
				}
				else if (ch == 'w'){
					state = 90;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 85:{
				if (ch == 'o'){
					state = 86;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 86:{
				if (ch == 'r'){
					state = 87;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 87:{
				if (ch == 't'){
					state = 88;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 88:{
				if (isWordSep(ch)){
					state = 89;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 90:{
				if (ch == 'i'){
					state = 91;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 91:{
				if (ch == 't'){
					state = 92;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 92:{
				if (ch == 'c'){
					state = 93;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 93:{
				if (ch == 'h'){
					state = 94;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 94:{
				if (isWordSep(ch)){
					state = 95;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 96:{
				if (ch == 'n'){
					state = 97;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 97:{
				if (isWordSep(ch)){
					state = 98;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 99:{
				if (ch == 't'){
					state = 100;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
			case 100:{
				if (isWordSep(ch)){
					state = 101;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}

					 /**
			case 105:{
				if (isArithmetical(ch) || isWordSep(ch) || (ch != ' ')){
					state = 106;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 22; //to mistake
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}
					 /**/

			case 104:{
				if (ch == '+'){
					state = 105;
					chain += ch;
				}
				else if (ch == '='){
					state = 107;
					chain += ch;
				}
				else{
					it--;
					nu--;
					state = 106;
				}
				break;
			}
			case 108:{
				if (ch == '-'){
					state = 109;
					chain += ch;
				}
				else if (ch == '='){
					state = 110;
					chain += ch;
				}
				else{
					it--;
					nu--;
					state = 111;
				}
				break;
			}

			case 112:{
				if (ch == '='){
					state = 113;
					chain += ch;
				}
				else if (ch == '*' || ch == '-' || ch == '+' || ch == '%'){
					state = 22;
				}
				else{
					it--;
					nu--;
					state = 114;
				}
				break;
			}

			case 115:{
				if (ch == '/' || ch == '-' || ch == '+' || ch == '%'){
					state = 22;
				}

				else if (ch == '='){
					state = 116;
					chain += ch;
				}
				else{
					it--;
					nu--;
					state = 117;
				}
				break;
			}

			case 118:{
				if (ch == '/' || ch == '*'){
					state = 22;
					chain += ch;
				}

				else if (ch == '='){
					state = 119;
					chain += ch;
				}
				else{
					it--;
					nu--;
					state = 120;
				}
				break;
			}

			case 121:{
				if (ch == '>'){
					state = 122;
					chain += ch;
				}

				else if (ch == '='){
					state = 129;
					chain += ch;
				}

				else{
					it--;
					nu--;
					state = 123;
				}
				break;
			}

			case 124:{
				if (ch == '<'){
					state = 125;
					chain += ch;
				}

				else if (ch == '='){
					state = 130;
					chain += ch;
				}

				else{
					it--;
					nu--;
					state = 126;
				}
				break;
			}

			case 127:{
				if (ch == '='){
					state = 128;
					chain += ch;
				}
				else{
					it--;
					nu--;
					state = 22;
				}
				break;
			}

			case 131:{
				if (ch == '='){
					state = 132;
					chain += ch;
				}
				else{
					it--;
					nu--;
					state = 133;
				}
				break;
			}

			case 134:{
				if (ch != '"'){
					state = 134;
					chain += ch;
				}
				else{
					//it--;
					//nu--;
					state = 135;
				}
				break;
			}



			//digits
			case 136:{
				/**
				if (*(it + 1) == ' '){
					state = 22;
				}
				/**/
				if (ch == '-'){
					state = 109;
					chain += ch;
				}
				else if (ch == '='){
					state = 110;
					chain += ch;
				}
				
				else if ((isDigit(ch)) && (ch != '0')){
					state = 137;
					chain += ch;
				}
				else if (ch == '0'){
					state = 138;
					chain += ch;
				}
				else{
					state = 22;
				}
				break;
			}
			case 137:{
				if (ch == ' '){
					state = 141;
					it--;
					nu--;
				}
				/**
				else if (*(it + 1) == ' '){
					state = 141;
					chain += ch;
				}
				/**/
				else if (isDigit(ch)){
					chain += ch;
				}
				else if (ch == '.'){
					state = 139;
					chain += ch;
				}
				else if (isWordSep(ch) || ch != '.'){
					it--;
					nu--;
					state = 141;					
				}
				/**
				else{
					it--;
					nu--;
					state = 141;
					//state = 22;
				}
				/**/
				break;
			}
			case 138:{
				if (*(it + 1) == ' '){
					state = 22;
				}
				else if (ch == '.'){
					state = 139;
					chain += ch;
				}
				else{
					state = 22;
				}
				break;
			}
			case 139:{
				/**
				if (*(it + 1) == ' '){
					state = 22;
				}
				/**/
				if ((isDigit(ch)) && (ch != '0')){
					state = 140;
					chain += ch;
				}
				else if (ch == '0'){
					state = 143;
					chain += ch;
				}
				else{
					state = 22;
				}
				break;
			}
			case 140:{
				if (*(it + 1) == ' '){
					state = 141;
				}
				else if (isDigit(ch)){
					chain += ch;
				}
				else if (isArithmetical(ch)){
					state = 141;
				}
				else{
					state = 22;
				}
				break;
			}
			case 142:{
				if (*(it + 1) == ' '){
					state = 141;
				}
				else if (ch == '.'){
					state = 139;
					chain += ch;
				}
				else if (isWordSep(ch) || (ch != '.')){
					state = 141;
				}
				else{
					state = 22;
				}
				break;
			}
			case 143:{
				if (*(it + 1) == ' '){
					state = 22;
				}
				else if (ch == '0'){
					chain += ch;
				}
				else if ((isDigit(ch)) && (ch != '0')){
					state = 140;
					chain += ch;
				}
				else if ((isWordSep(ch)) || (ch != '.')){
					state = 141;
				}
				else{
					state = 22;
				}
				break;
			}
			//digits-end

			case 147:{
				if (ch == 'd'){
					state = 148;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}

			case 148:{
				if (ch == 'l'){
					state = 149;
					chain += ch;
				}
				else if (isWordSep(ch)){
					it--;
					nu--;
					state = 2;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}

			case 149:{
				if (isWordSep(ch)){
					state = 150;
				}
				else{
					//
					chain += ch;
					state = 1;

				}
				break;
			}

			}//end of 1st switch

			//final states
			switch (state){
				
			case 2:{//any iden
				state = 0;
				iden.insert(std::pair<std::string, int>(chain, iden.size()+1));

				//richTextBox31->Text += gcnew System::String("(10,") + iden.at(chain) + gcnew System::String("),");
				descriptionCode.push_back(20);
				descriptionCode.push_back(iden.at(chain));
				pseudoCode.append("iden ");
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 6:{//int
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size()+1));
				//
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				//
				chain.clear();
				break;
			}
			case 8:{//if
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 14:{//float
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 21:{//double
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 27:{//bool
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 32:{//break
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 38:{//const
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 44:{//continue
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 45:{//do
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 50:{//else
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 53:{//for
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 58:{//long
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 65:{//return
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 71:{//while
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 75:{//try
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 80:{//catch
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 83:{//case
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 89:{//short
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 95:{//switch
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 98:{//cin
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 101:{//cout
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 102:{//braces
				state = 0;
				//braces.insert(std::pair<std::string, int>(chain, braces.size() + 1));
				sepS.insert(std::pair<std::string, int>(chain, sepS.size() + 1));
				descriptionCode.push_back(60);
				descriptionCode.push_back(sepS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
			case 103:{//sepS
				state = 0;
				sepS.insert(std::pair<std::string, int>(chain, sepS.size() + 1));
				descriptionCode.push_back(60);
				descriptionCode.push_back(sepS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}
					 /**
					 //commented 17.08 19:00
			case 104:{//opS
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				chain.clear();
				break;
			}
					 /**/

			case 105:{//++
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 106:{//+
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 107:{//+=
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 109:{//--
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 110:{//-=
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 111:{//-
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 113:{// /=
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 114:{// /
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 116:{// *=
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 117:{// *
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 119:{// =
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 120:{// %
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 122:{// >>
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 123:{// >
				state = 0;
				logS.insert(std::pair<std::string, int>(chain, logS.size() + 1));
				descriptionCode.push_back(50);
				descriptionCode.push_back(logS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 125:{// <<
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 126:{// <
				state = 0;
				logS.insert(std::pair<std::string, int>(chain, logS.size() + 1));
				descriptionCode.push_back(50);
				descriptionCode.push_back(logS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 128:{// !=
				state = 0;
				logS.insert(std::pair<std::string, int>(chain, logS.size() + 1));
				descriptionCode.push_back(50);
				descriptionCode.push_back(logS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 129:{// >=
				state = 0;
				logS.insert(std::pair<std::string, int>(chain, logS.size() + 1));
				descriptionCode.push_back(50);
				descriptionCode.push_back(logS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 130:{// <=
				state = 0;
				logS.insert(std::pair<std::string, int>(chain, logS.size() + 1));
				descriptionCode.push_back(50);
				descriptionCode.push_back(logS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 132:{// ==
				state = 0;
				logS.insert(std::pair<std::string, int>(chain, logS.size() + 1));
				descriptionCode.push_back(50);
				descriptionCode.push_back(logS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 133:{// =
				state = 0;
				opS.insert(std::pair<std::string, int>(chain, opS.size() + 1));
				descriptionCode.push_back(40);
				descriptionCode.push_back(opS.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 135:{// constText
				state = 0;
				constText.insert(std::pair<std::string, int>(chain, constText.size() + 1));
				descriptionCode.push_back(70);
				descriptionCode.push_back(constText.at(chain));
				pseudoCode.append("text");
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 141:{// constDigit
				state = 0;
				contstants.insert(std::pair<std::string, int>(chain, contstants.size() + 1));
				descriptionCode.push_back(30);
				descriptionCode.push_back(contstants.at(chain));
				pseudoCode.append("digit");
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 150:{//endl
				state = 0;
				keyWords.insert(std::pair<std::string, int>(chain, keyWords.size() + 1));
				descriptionCode.push_back(10);
				descriptionCode.push_back(keyWords.at(chain));
				pseudoCode.append(chain);
				pseudoCode.append(" ");
				chain.clear();
				break;
			}

			case 22:{ //error state
				richTextBox2->Text += gcnew System::String("Mistake in line: ") + 
					(richTextBox1->GetLineFromCharIndex(nu) + 1) + System::Environment::NewLine; //find a number of line
				it = end - 1;
				break;
			}
			}			
			//richTextBox31->Text += gcnew System::String("after st: ") + state + Environment::NewLine;
		} //end of for(it)
		wm = true;

			//output of maps
			std::vector <std::pair <std::string, int> > vecKeyWords(keyWords.begin(), keyWords.end());
			std::vector <std::pair <std::string, int> > vecIden(iden.begin(), iden.end());
			std::vector <std::pair <std::string, int> > vecConst(contstants.begin(), contstants.end());
			std::vector <std::pair <std::string, int> > vecOpS(opS.begin(), opS.end());
			std::vector <std::pair <std::string, int> > vecLogS(logS.begin(), logS.end());
			std::vector <std::pair <std::string, int> > vecSepS(sepS.begin(), sepS.end());
			std::vector <std::pair <std::string, int> > vecconstText(constText.begin(), constText.end());


			//сортируем этот вектор по ключу
			std::sort(vecKeyWords.begin(), vecKeyWords.end(), pred);
			std::sort(vecIden.begin(), vecIden.end(), pred);
			std::sort(vecConst.begin(), vecConst.end(), pred);
			std::sort(vecOpS.begin(), vecOpS.end(), pred);
			std::sort(vecLogS.begin(), vecLogS.end(), pred);
			std::sort(vecSepS.begin(), vecSepS.end(), pred);
			std::sort(vecconstText.begin(), vecconstText.end(), pred);

			//вывод 
			for (auto p : vecKeyWords){ //цикл в стиле c++11
				richTextBox17->Text += p.second + System::Environment::NewLine;
				richTextBox18->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;
				
			}
			for (auto p : vecIden){ //цикл в стиле c++11
				richTextBox19->Text += p.second + System::Environment::NewLine;
				richTextBox20->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;

			}
			for (auto p : vecConst){ //цикл в стиле c++11
				richTextBox21->Text += p.second + System::Environment::NewLine;
				richTextBox22->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;

			}
			for (auto p : vecOpS){ //цикл в стиле c++11
				richTextBox23->Text += p.second + System::Environment::NewLine;
				richTextBox24->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;

			}
			for (auto p : vecLogS){ //цикл в стиле c++11
				richTextBox25->Text += p.second + System::Environment::NewLine;
				richTextBox26->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;

			}
			for (auto p : vecSepS){ //цикл в стиле c++11
				richTextBox27->Text += p.second + System::Environment::NewLine;
				richTextBox28->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;

			}
			for (auto p : vecconstText){ //цикл в стиле c++11
				richTextBox29->Text += p.second + System::Environment::NewLine;
				richTextBox30->Text += gcnew System::String(p.first.c_str()) + System::Environment::NewLine;

			}

			//description code
			/**/
			for (int i = 0; i < descriptionCode.size(); i++) {
				richTextBox31->Text += gcnew System::String("(") + descriptionCode[i] + gcnew System::String(",") + descriptionCode[i+1] + gcnew System::String("),");
				i++;
			}
			/**/

			//pseudo code
			/**
			int group = 0; int lexemCode = 0;
			for (int i = 0; i < descriptionCode.size(); i = i + 2) { //construction
				group = i;
				lexemCode = i + 1;

				switch (group){
					case 10:{
						//идея такова: создать новые контейнеры (map?) из старых map
						//поменяв ключ и значение, затем pseudoCode.append(map_name.at(lexemCode));
						pseudoCode.append(keyWords.at("int"));
						break;
					}
					case 20:{
						break;
					}
					case 30:{
						break;
					}
					case 40:{
						break;
					}
					case 50:{
						break;
					}
					case 60:{
						break;
					}
					case 70:{
						break;
					}
				}
			}
			/**/
			if (wm){
				richTextBox32->Text += gcnew System::String(pseudoCode.c_str()); //pseudoCode output
			}



		}
		catch (FormatException^) {
			MessageBox::Show("There is something wrong", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}


	//reset
	private: System::Void buttonZeroState_Click(System::Object^  sender, System::EventArgs^  e) {
		//вернем автомату начальное состояние
		state = 0;	//текущее состояние автомата
		previous_state = 0;	//предшествующее состояние (на всякий случай)
		x = 0;	//вход
		y = 0;	//выход
		n_symbol = -1; //обрабатываемый символ последовательности

		//первоначальные значения таблицы
		//buttonClear_Click(sender, e);
	
		Control ^c;
		/**
		c = tableLayoutPanel1->GetControlFromPosition(1,1);
		c->Text = gcnew String("sdlkfjlsdkjflsk" + System::Environment::NewLine + "djflkdsjflkdsflsdkjflkdjfls");
		/**/

		for (int j = 0; j < 14; j++){
			c = tableLayoutPanel1->GetControlFromPosition(j,1);
			c->Text = gcnew String("");
		}

		richTextBox2->Clear();
		richTextBox31->Clear();
		richTextBox32->Clear();

		keyWords.clear(); //ключевые слова (10)
		iden.clear(); //идентификаторы (20)
		contstants.clear(); //константы числовые(30)
		opS.clear(); //знаки операций (40)
		logS.clear(); //логические операторы (50)
		sepS.clear(); //знаки разделителей (60)
		constText.clear(); //константы текстовые (70)
		descriptionCode.clear();
		pseudoCode.clear();

	}

private: System::Void textBox17_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBoxInput_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void richTextBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox1->Clear();
}
};
}

/**

Graphics^ g = pictureBox2->CreateGraphics();
Pen^ pen = gcnew Pen(Color::Blue);
pen->Width = 3;
g->DrawRectangle(pen, 20,20,40,40);

/**/