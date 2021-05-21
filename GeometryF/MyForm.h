#pragma once
#include "GeometryF.h"
#include <iostream>


namespace GeometryF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Graphics^ gr;
		TPoint* A, * B;
		TChart* P,*ch,*P1;
		Pen^ ErrorPoint, ^ ErrorLine;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox8;
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = CreateGraphics();
			ErrorPoint = ErrorLine = gcnew Pen(Color::Red);
			//ErrorPoint->Width = (float)(PointWidth);
			//ErrorLine->Width = (float)(LineWidth);
			A=B = NULL;
			//P = new TChart;
			P1=P =ch= NULL;
			//f1 = f2 = res = false;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(649, 83);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(640, 209);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(611, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(61, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(721, 19);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(59, 26);
			this->textBox2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(576, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Х=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(687, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(28, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"У=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(567, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Х1=";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(678, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"У1=";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(611, 51);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 26);
			this->textBox3->TabIndex = 8;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(721, 51);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(59, 26);
			this->textBox4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(576, 148);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Х=";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(687, 148);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(28, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"У=";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(567, 180);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Х1=";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(678, 180);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 20);
			this->label8->TabIndex = 13;
			this->label8->Text = L"У1=";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(611, 145);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(61, 26);
			this->textBox5->TabIndex = 14;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(721, 145);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(59, 26);
			this->textBox6->TabIndex = 15;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(611, 177);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(61, 26);
			this->textBox7->TabIndex = 16;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(721, 177);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(59, 26);
			this->textBox8->TabIndex = 17;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(611, 285);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(169, 34);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Восстановить всё";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(611, 245);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(169, 34);
			this->button4->TabIndex = 19;
			this->button4->Text = L"Очистить всё";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(814, 472);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			A = new TPoint;
			ch = new TChart;
			A->SetX(Convert::ToInt32(textBox1->Text));
			A->SetY(Convert::ToInt32(textBox2->Text));
			this->textBox1->Text = L"";
			this->textBox2->Text = L"";
			ch->SetFirst(A);
			B = new TPoint;
			B->SetX(Convert::ToInt32(textBox3->Text));
			B->SetY(Convert::ToInt32(textBox4->Text));
			this->textBox3->Text = L"";
			this->textBox4->Text = L"";
			ch->SetLast(B);
			if (P)
				P->InsLine(ch);
			else
				P = ch;
			P->Show(gr);

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	    A = new TPoint;
		ch = new TChart;
		//P = new TChart;
		A->SetX(Convert::ToInt32(textBox5->Text));
		A->SetY(Convert::ToInt32(textBox6->Text));
		this->textBox5->Text = L"";
		this->textBox6->Text = L"";
		ch->SetFirst(A);
		B = new TPoint;
		B->SetX(Convert::ToInt32(textBox7->Text));
		B->SetY(Convert::ToInt32(textBox8->Text));
		this->textBox7->Text = L"";
		this->textBox8->Text = L"";
		ch->SetLast(B);
		if (P1)
			P1->InsLine(ch);
		else
			P1 = ch;
		P1->Hide(gr);
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	if (P)
		P->Hide(gr);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	if (P)
		P->Show(gr);
	if (P1)
	{
		P1->Show(gr);
		P1 = NULL;
	}
}
};
}
