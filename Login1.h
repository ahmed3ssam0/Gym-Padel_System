#pragma once

#include <iostream>
#include "Trainee.h"
#include "Coatch.h"
#include "Receptionist.h"
#include "Manager.h"
#include <unordered_map>
#include <msclr/marshal_cppstd.h>
#include <string>
#include "Home.h"
#include "Home2.h"
#include "Register.h"
#include "Gym.h"
#include "System.h"


namespace gymproject {

	using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
	
		/// <summary>
		/// Summary for LogIn
		/// </summary>
		public ref class Login1 : public System::Windows::Forms::Form
		{
			unordered_map<int, Trainee>* traineeList;
			unordered_map<string, Coatch>* coatchList;
			unordered_map<string, Receptionist>* receptionistList;
			unordered_map<string, Manager>* manager;
			SystemManager* sys;
		public:
			Login1(SystemManager* sys)
			{
				InitializeComponent();
				this->sys = sys;
				traineeList = &(sys->traineeList);
				coatchList = &(sys->coatchList);
				receptionistList = &(sys->receptionistList);
				manager = &(sys->managerList);
			}
	
		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Login1()
			{
				if (components)
				{
					delete components;
				}
			}
	
		private: System::Windows::Forms::TextBox^ cellPass;
		private: System::Windows::Forms::TextBox^ cellEmail;
		private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
		protected: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Button^ btnSave;
		protected: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::DateTimePicker^ DOB;
		private: System::Windows::Forms::RadioButton^ RadFemale;
		private: System::Windows::Forms::RadioButton^ RadMale;
		protected: System::Windows::Forms::Label^ label5;
		protected: System::Windows::Forms::Label^ label4;
		protected: System::Windows::Forms::Label^ label3;
		protected: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ cellPhoneNum;
		protected: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ cellName;
		private: System::Windows::Forms::GroupBox^ groupBox1;
		private: System::Windows::Forms::GroupBox^ groupBox2;
		private: System::Windows::Forms::Button^ signup;
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
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->btnSave = (gcnew System::Windows::Forms::Button());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->cellPass = (gcnew System::Windows::Forms::TextBox());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->cellEmail = (gcnew System::Windows::Forms::TextBox());
				this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
				this->signup = (gcnew System::Windows::Forms::Button());
				this->groupBox1->SuspendLayout();
				this->groupBox2->SuspendLayout();
				this->SuspendLayout();
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
				this->btnSave->Location = System::Drawing::Point(200, 296);
				this->btnSave->Margin = System::Windows::Forms::Padding(2);
				this->btnSave->Name = L"btnSave";
				this->btnSave->Size = System::Drawing::Size(76, 25);
				this->btnSave->TabIndex = 13;
				this->btnSave->Text = L"Log In";
				this->btnSave->UseVisualStyleBackColor = true;
				this->btnSave->Click += gcnew System::EventHandler(this, &Login1::btnSave_Click);
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
				this->label3->Size = System::Drawing::Size(54, 13);
				this->label3->TabIndex = 5;
				this->label3->Text = L"Email / ID";
				// 
				// cellEmail
				// 
				this->cellEmail->Location = System::Drawing::Point(61, 155);
				this->cellEmail->Name = L"cellEmail";
				this->cellEmail->Size = System::Drawing::Size(344, 20);
				this->cellEmail->TabIndex = 4;
				// 
				// groupBox1
				// 
				this->groupBox1->Controls->Add(this->groupBox2);
				this->groupBox1->Location = System::Drawing::Point(394, 43);
				this->groupBox1->Margin = System::Windows::Forms::Padding(2);
				this->groupBox1->Name = L"groupBox1";
				this->groupBox1->Padding = System::Windows::Forms::Padding(2);
				this->groupBox1->Size = System::Drawing::Size(458, 419);
				this->groupBox1->TabIndex = 1;
				this->groupBox1->TabStop = false;
				this->groupBox1->Text = L"Sign Up";
				// 
				// groupBox2
				// 
				this->groupBox2->BackColor = System::Drawing::SystemColors::ButtonFace;
				this->groupBox2->Controls->Add(this->signup);
				this->groupBox2->Controls->Add(this->label7);
				this->groupBox2->Controls->Add(this->btnSave);
				this->groupBox2->Controls->Add(this->label4);
				this->groupBox2->Controls->Add(this->cellPass);
				this->groupBox2->Controls->Add(this->label3);
				this->groupBox2->Controls->Add(this->cellEmail);
				this->groupBox2->Location = System::Drawing::Point(1, 0);
				this->groupBox2->Name = L"groupBox2";
				this->groupBox2->Size = System::Drawing::Size(456, 436);
				this->groupBox2->TabIndex = 1;
				this->groupBox2->TabStop = false;
				this->groupBox2->Text = L"Login";
				// 
				// signup
				// 
				this->signup->Location = System::Drawing::Point(201, 353);
				this->signup->Name = L"signup";
				this->signup->Size = System::Drawing::Size(75, 23);
				this->signup->TabIndex = 15;
				this->signup->Text = L"Sign Up";
				this->signup->UseVisualStyleBackColor = true;
				this->signup->Click += gcnew System::EventHandler(this, &Login1::signup_Click);
				// 
				// Login1
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1443, 839);
				this->Controls->Add(this->groupBox1);
				this->Margin = System::Windows::Forms::Padding(2);
				this->Name = L"Login1";
				this->Text = L"LogIn";
				this->groupBox1->ResumeLayout(false);
				this->groupBox2->ResumeLayout(false);
				this->groupBox2->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion
		private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ id = cellEmail->Text;
			String^ password = cellPass->Text;

			int numericId;
			bool isNumeric = Int32::TryParse(id, numericId);

			if (isNumeric && ValidateTraineeLogin(numericId, password)) {
				MessageBox::Show("Trainee login successful!");
				Trainee* trainee = &(traineeList->at(numericId));
				Gym* gym = new Gym();
				Home^ nextForm = gcnew Home(gym, trainee);
				nextForm->StartPosition = FormStartPosition::Manual;
				nextForm->Location = this->Location;
				nextForm->Size = this->Size;
				nextForm->BackgroundImage = this->BackgroundImage;
				nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				nextForm->Show();
				this->Hide();
			}
			else if (ValidateCoatchLogin(id, password)) {
				MessageBox::Show("Coach login successful!");
				std::string coachId = msclr::interop::marshal_as<std::string>(id);
				Coatch* coach = &(coatchList->at(coachId));
				Home2^ nextForm = gcnew Home2(coach);
				nextForm->Location = this->Location;
				nextForm->Size = this->Size;
				nextForm->BackgroundImage = this->BackgroundImage;
				nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				nextForm->Show();
				this->Hide();
			}
			else if (ValidateReceptionistLogin(id, password)) {
				MessageBox::Show("Receptionist login successful!");
			}
			else if (ValidateManagerLogin(id, password)) {
				MessageBox::Show("Manager login successful!");
			}
			else {
				MessageBox::Show("Invalid ID or password!", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		private: bool ValidateTraineeLogin(int id, String^ password)
		{
			if (traineeList->at(id).getPassword() == msclr::interop::marshal_as<string>(password)) {
				return true;
			}
			else
			{
				return false;
			}
		}
		private: bool ValidateCoatchLogin(String^ id, String^ password)
		{
			if (coatchList->at(msclr::interop::marshal_as<std::string>(id)).getpassword() == msclr::interop::marshal_as<std::string>(password)) {
				return true;
			}
			else
			{
				return false;
			}
		}
		private: bool ValidateReceptionistLogin(String^ id, String^ password)
		{
			if (receptionistList->at(msclr::interop::marshal_as<std::string>(id)).getpassword() == msclr::interop::marshal_as<std::string>(password)) {
				return true;
			}
			else
			{
				return false;
			}
		}
		private: bool ValidateManagerLogin(String^ name, String^ password)
		{
			if (manager->at(msclr::interop::marshal_as<std::string>(name)).getpassword() == msclr::interop::marshal_as<std::string>(password)) {
				return true;
			}
			else
			{
				return false;
			}
		}

		private: System::Void signup_Click(System::Object^ sender, System::EventArgs^ e) {
			Register^ nextForm = gcnew Register(sys);
			nextForm->StartPosition = FormStartPosition::Manual;
			nextForm->Location = this->Location;
			nextForm->Size = this->Size;
			nextForm->BackgroundImage = this->BackgroundImage;
			nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			nextForm->Show();
			this->Hide();
		}
};
}
