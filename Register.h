#pragma once
#include <iostream>
#include "System.h"
#include <map>
#include <unordered_map>
#include <string>
#include <msclr/marshal_cppstd.h>
using namespace std;
namespace gymproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class Register : public System::Windows::Forms::Form
	{
		unordered_map<int, Trainee>* traineeList;
		SystemManager* sys;
	public:
		Register(void)
		{
			InitializeComponent();
		}
		Register(SystemManager* sys)
		{
			InitializeComponent();
			this->sys = sys;
			traineeList = &(sys->traineeList);
			comboBox1->Items->Add("1 Year");
			comboBox1->Items->Add("6 Months");
			comboBox1->Items->Add("3 Months");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected: System::Windows::Forms::Label^ label7;
	private:
	private: System::Windows::Forms::Button^ btnSave;
	protected:
	protected: System::Windows::Forms::Label^ label6;
	private:
	private: System::Windows::Forms::DateTimePicker^ DOB;
	protected:
	private: System::Windows::Forms::RadioButton^ RadFemale;
	private: System::Windows::Forms::RadioButton^ RadMale;
	protected: System::Windows::Forms::Label^ label5;
	private:
	protected: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ cellPass;
	protected:
	protected: System::Windows::Forms::Label^ label3;
	private:
	private: System::Windows::Forms::TextBox^ cellEmail;
	protected:
	protected: System::Windows::Forms::Label^ label2;
	private:
	private: System::Windows::Forms::TextBox^ cellPhoneNum;
	protected:
	protected: System::Windows::Forms::Label^ label1;
	private:
	private: System::Windows::Forms::TextBox^ cellName;
	protected:
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::ComponentModel::IContainer^ components;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DOB = (gcnew System::Windows::Forms::DateTimePicker());
			this->RadFemale = (gcnew System::Windows::Forms::RadioButton());
			this->RadMale = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cellPass = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cellEmail = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cellPhoneNum = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cellName = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Location = System::Drawing::Point(368, 30);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(458, 577);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sign Up";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label10);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->btnSave);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->DOB);
			this->groupBox2->Controls->Add(this->RadFemale);
			this->groupBox2->Controls->Add(this->RadMale);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->cellPass);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->cellEmail);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->cellPhoneNum);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->cellName);
			this->groupBox2->Location = System::Drawing::Point(1, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(456, 578);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sign Up";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(111, 482);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(224, 13);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Note: There is extra cost for VIP Subscriptions";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(60, 427);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(37, 13);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Period";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(59, 379);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Start Date";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(56, 343);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(114, 24);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Subscription";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"d-MM-yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(59, 395);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(151, 20);
			this->dateTimePicker1->TabIndex = 17;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(62, 482);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(43, 17);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->Text = L"VIP";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(59, 443);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(197, 430);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 14;
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(189, 533);
			this->btnSave->Margin = System::Windows::Forms::Padding(2);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(76, 25);
			this->btnSave->TabIndex = 13;
			this->btnSave->Text = L"Sign Up";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &Register::btnSave_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(59, 295);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Date Of Birth";
			// 
			// DOB
			// 
			this->DOB->CustomFormat = L"d-MM-yyyy";
			this->DOB->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->DOB->Location = System::Drawing::Point(59, 310);
			this->DOB->Margin = System::Windows::Forms::Padding(2);
			this->DOB->Name = L"DOB";
			this->DOB->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->DOB->Size = System::Drawing::Size(151, 20);
			this->DOB->TabIndex = 11;
			this->DOB->Value = System::DateTime(2025, 5, 4, 21, 46, 58, 0);
			// 
			// RadFemale
			// 
			this->RadFemale->AutoSize = true;
			this->RadFemale->Location = System::Drawing::Point(139, 262);
			this->RadFemale->Margin = System::Windows::Forms::Padding(2);
			this->RadFemale->Name = L"RadFemale";
			this->RadFemale->Size = System::Drawing::Size(59, 17);
			this->RadFemale->TabIndex = 10;
			this->RadFemale->Text = L"Female";
			this->RadFemale->UseVisualStyleBackColor = true;
			this->RadFemale->CheckedChanged += gcnew System::EventHandler(this, &Register::RadFemale_CheckedChanged);
			// 
			// RadMale
			// 
			this->RadMale->AutoSize = true;
			this->RadMale->Checked = true;
			this->RadMale->Location = System::Drawing::Point(62, 262);
			this->RadMale->Margin = System::Windows::Forms::Padding(2);
			this->RadMale->Name = L"RadMale";
			this->RadMale->Size = System::Drawing::Size(48, 17);
			this->RadMale->TabIndex = 9;
			this->RadMale->TabStop = true;
			this->RadMale->Text = L"Male";
			this->RadMale->UseVisualStyleBackColor = true;
			this->RadMale->CheckedChanged += gcnew System::EventHandler(this, &Register::RadMale_CheckedChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(59, 236);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Gender";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(57, 190);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Password";
			// 
			// cellPass
			// 
			this->cellPass->Location = System::Drawing::Point(60, 206);
			this->cellPass->Name = L"cellPass";
			this->cellPass->PasswordChar = '*';
			this->cellPass->Size = System::Drawing::Size(344, 20);
			this->cellPass->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(58, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Email";
			// 
			// cellEmail
			// 
			this->cellEmail->Location = System::Drawing::Point(61, 155);
			this->cellEmail->Name = L"cellEmail";
			this->cellEmail->Size = System::Drawing::Size(344, 20);
			this->cellEmail->TabIndex = 4;
			this->cellEmail->Text = L"Enter Your  Email";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(58, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Phone Number";
			// 
			// cellPhoneNum
			// 
			this->cellPhoneNum->Location = System::Drawing::Point(61, 106);
			this->cellPhoneNum->Name = L"cellPhoneNum";
			this->cellPhoneNum->Size = System::Drawing::Size(344, 20);
			this->cellPhoneNum->TabIndex = 2;
			this->cellPhoneNum->Text = L"Enter Your Phone Number";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(58, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Name";
			// 
			// cellName
			// 
			this->cellName->Location = System::Drawing::Point(61, 54);
			this->cellName->Name = L"cellName";
			this->cellName->Size = System::Drawing::Size(344, 20);
			this->cellName->TabIndex = 0;
			this->cellName->Text = L"Enter Your Name";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1443, 839);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Register";
			this->Text = L"SignUp";
			this->Load += gcnew System::EventHandler(this, &Register::SignUp_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SignUp_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		
		string name = msclr::interop::marshal_as<std::string>(cellName->Text);
		string phone = msclr::interop::marshal_as<std::string>(cellPhoneNum->Text);
		string email = msclr::interop::marshal_as<std::string>(cellEmail->Text);
		string password = msclr::interop::marshal_as<std::string>(cellPass->Text);
		string dob = msclr::interop::marshal_as<std::string>(DOB->Text);
		string gender;
		bool vip = false;
		if (RadFemale->Checked) gender ="Female";
		else if (RadMale->Checked) gender = "Male";
		
		if (checkBox1->Checked) vip = true;
		Trainee* trainee = new Trainee(name, phone, gender, dob, email, password, vip);
		trainee->setId(++sys->maxTraineeID);
		int per;
		if (comboBox1->Text == "1 Year") per = 1;
		else if (comboBox1->Text == "6 Months") per = 6;
		else if (comboBox1->Text == "3 Months") per = 3;
		Subscription* subscription = new Subscription(msclr::interop::marshal_as<std::string>(dateTimePicker1->Text), per);
		string endDate = subscription->getEndDate();
		//trainee->setSubscription(*subscription);
		(*traineeList)[trainee->getId()] = *trainee;
		MessageBox::Show("Your ID is: " + trainee->getId() + "\n and the Subscription end date is: " + gcnew String(endDate.c_str()));
		trainee->~Trainee();
		subscription->~Subscription();
		trainee = nullptr;
		subscription = nullptr;
		delete trainee;
		delete subscription;
		// open login page
		nxt_form(sender, e);
	}
	private: System::Void RadFemale_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (RadFemale->Checked)
		{
			RadMale->Checked = false;
		}
		else
		{
			RadMale->Checked = true;
		}
	}
	private: System::Void RadMale_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void nxt_form(System::Object^ sender, System::EventArgs^ e);
	};
}
