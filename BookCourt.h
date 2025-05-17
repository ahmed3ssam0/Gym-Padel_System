#pragma once
#include "Padel.h"
#include "Trainee.h"
#include "Court.h"
#include "Booking.h"
#include<iostream>
#include <msclr/marshal_cppstd.h> 
#include <unordered_map>
using namespace std;
using namespace msclr::interop;
namespace gymproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class ava_court : public System::Windows::Forms::Form
	{
		Padel* padel;
		Trainee* trainee;
	public:
		ava_court(Padel* padel, Trainee* trainee)
		{
			InitializeComponent();
			this->padel = padel;
			this->trainee = trainee;
			unordered_map<string, Court> courts = padel->getCourts();
			for (auto& court : courts) {
				comboBox1->Items->Add(gcnew String(court.second.getName().c_str()));
			}
		}

	protected:
		
		~ava_court()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label8;
	protected:

	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(120, 47);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(310, 2);
			this->label8->TabIndex = 22;
			this->label8->Text = L"label8";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(19, 268);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(107, 23);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Day             ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 23);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Time Period  ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(16, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 23);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Start Time   ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 23);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Court name ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(112, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(333, 31);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Padel Court Reservation";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Green;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(471, 413);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 45);
			this->button1->TabIndex = 24;
			this->button1->Text = L"Book Now";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ava_court::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 98);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 25;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(16, 308);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 26;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dateTimePicker2->Location = System::Drawing::Point(12, 167);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->ShowUpDown = true;
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 27;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 2;
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->numericUpDown1->Location = System::Drawing::Point(12, 229);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(189, 20);
			this->numericUpDown1->TabIndex = 28;
			// 
			// ava_court
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 470);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"ava_court";
			this->Text = L"ava_court";
			this->Load += gcnew System::EventHandler(this, &ava_court::ava_court_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ courtName = comboBox1->SelectedItem->ToString();
		String^ startTimeStr = dateTimePicker2->Value.ToString("HH:mm");
		String^ dayStr = dateTimePicker1->Value.ToString("yyyy-MM-dd");
		float timePeriodStr = (float)numericUpDown1->Value;
		auto it = padel->getCourts().find(marshal_as<string>(courtName));
		if (it != padel->getCourts().end()) {
			Court court = it->second;
			Booking booking(*trainee, court, marshal_as<string>(dayStr), marshal_as<string>(startTimeStr), timePeriodStr);
			if (padel->bookCourt(booking)) {
				MessageBox::Show("Court booked successfully!");
			}
			else {
				MessageBox::Show("Failed to book the court.");
			}
		}
		else {
			MessageBox::Show("Court not found.");
		}
	}
	private: System::Void ava_court_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
