#pragma once
#include "Coatch.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <vector>

namespace gymproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RemoveSession
	/// </summary>
    public ref class RemoveSession : public UserControl
    {
    private: Coatch* currentCoach;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;



    public:
        RemoveSession(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(250, 256);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(319, 20);
            this->textBox1->TabIndex = 0;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(354, 332);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Remove";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &RemoveSession::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(286, 75);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(191, 31);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Remove Class";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(181, 259);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(63, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Class Name";
            // 
            // RemoveSession
            // 
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->Name = L"RemoveSession";
            this->Size = System::Drawing::Size(841, 545);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ sessionName = textBox1->Text->Trim();

        if (String::IsNullOrEmpty(sessionName))
        {
            MessageBox::Show("Please enter a session name to remove.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        std::string session_name_std = msclr::interop::marshal_as<std::string>(sessionName);
        bool removed = currentCoach->removeClass(session_name_std);
        if (removed)
        {
            MessageBox::Show("Session '" + sessionName + "' removed successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            textBox1->Clear();
        }
        else
        {
            MessageBox::Show("Session '" + sessionName + "' not found or could not be removed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    };
}
