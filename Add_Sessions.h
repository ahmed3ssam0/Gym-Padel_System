#pragma once
#include <iostream>
#include <Windows.h>
#using <System.Windows.Forms.dll>
#include "Coatch.h"
#include "GymClass.h"
#include <msclr/marshal_cppstd.h>


namespace gymproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Add_Sessions
    /// </summary>
    public ref class Add_Sessions : public System::Windows::Forms::UserControl
    {
    private:
        Coatch* currentCoach;

    public:
        Add_Sessions(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
			loadSessions();

        }

    private: System::Windows::Forms::Label^ lblName;
    private: System::Windows::Forms::TextBox^ txtName;
    private: System::Windows::Forms::Label^ lblDuration;
    private: System::Windows::Forms::TextBox^ txtDuration;
    private: System::Windows::Forms::Label^ lblTime;
    private: System::Windows::Forms::DateTimePicker^ timePicker;
    private: System::Windows::Forms::Button^ btnAdd;
    private: System::Windows::Forms::DataGridView^ dgvSessions;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ SessionName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ StartTime;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ textBox1;

    private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
    private: System::Windows::Forms::DataGridView^ dataGridView1;



    private: System::Windows::Forms::Button^ button1;





    private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
    private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::RadioButton^ radioButton1;
    private: System::Windows::Forms::RadioButton^ radioButton2;






    private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ start;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ cap;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nos;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;








    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Duration;


           void loadSessions()
           {
               //lblToday->Text = "Today's Sessions - " + DateTime::Now.ToString("D");
               dataGridView1->Rows->Clear();

               list<GymClass> classes = currentCoach->getClassAssignments();
               for (GymClass& gymClass : classes)
               {
                   String^ name = gcnew String(gymClass.getName().c_str());
                   String^ startTime = gcnew String(gymClass.getStartTime().c_str());
                   int capacity = gymClass.getCapacity();
                   int numberOfSessions = gymClass.getNumberOfSessions();
                   float duration = gymClass.getTimePeriod();
                   bool type = gymClass.getType();
                   dataGridView1->Rows->Add(
                       gcnew String(name),
                       gcnew String(startTime),
                       gcnew String(std::to_string(duration).substr(0, 4).c_str()),
                       gcnew String(std::to_string(capacity).c_str()),
                       gcnew String(std::to_string(numberOfSessions).c_str()),
                       gcnew String(type ? "Private" : "Group")
                   );
               }
           }

           void InitializeComponent()
           {
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
               this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
               this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
               this->start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
               this->dur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
               this->cap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
               this->nos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
               this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
               this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
               this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
               this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
               this->SuspendLayout();
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Location = System::Drawing::Point(264, 211);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(75, 13);
               this->label1->TabIndex = 0;
               this->label1->Text = L"Session Name";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Location = System::Drawing::Point(359, 295);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(47, 13);
               this->label2->TabIndex = 1;
               this->label2->Text = L"Duration";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Location = System::Drawing::Point(310, 339);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(55, 13);
               this->label3->TabIndex = 2;
               this->label3->Text = L"Start Time";
               // 
               // textBox1
               // 
               this->textBox1->Location = System::Drawing::Point(345, 208);
               this->textBox1->Name = L"textBox1";
               this->textBox1->Size = System::Drawing::Size(247, 20);
               this->textBox1->TabIndex = 3;
               // 
               // dateTimePicker1
               // 
               this->dateTimePicker1->Checked = false;
               this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Time;
               this->dateTimePicker1->Location = System::Drawing::Point(371, 333);
               this->dateTimePicker1->Name = L"dateTimePicker1";
               this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
               this->dateTimePicker1->TabIndex = 5;
               // 
               // dataGridView1
               // 
               this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                   this->name, this->start,
                       this->dur, this->cap, this->nos, this->type
               });
               this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Top;
               this->dataGridView1->Location = System::Drawing::Point(0, 0);
               this->dataGridView1->Name = L"dataGridView1";
               this->dataGridView1->Size = System::Drawing::Size(948, 178);
               this->dataGridView1->TabIndex = 6;
               // 
               // name
               // 
               this->name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
               this->name->HeaderText = L"Session Name";
               this->name->Name = L"name";
               // 
               // start
               // 
               this->start->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
               this->start->HeaderText = L"Start Time";
               this->start->Name = L"start";
               // 
               // dur
               // 
               this->dur->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
               this->dur->HeaderText = L"Duration In Hours";
               this->dur->Name = L"dur";
               // 
               // cap
               // 
               this->cap->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
               this->cap->HeaderText = L"Capacity";
               this->cap->Name = L"cap";
               // 
               // nos
               // 
               this->nos->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
               this->nos->HeaderText = L"Number Of Sessions";
               this->nos->Name = L"nos";
               // 
               // type
               // 
               this->type->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
               this->type->HeaderText = L"Type";
               this->type->Name = L"type";
               // 
               // button1
               // 
               this->button1->Location = System::Drawing::Point(419, 408);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(75, 23);
               this->button1->TabIndex = 7;
               this->button1->Text = L"button1";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &Add_Sessions::button1_Click);
               // 
               // numericUpDown1
               // 
               this->numericUpDown1->Location = System::Drawing::Point(419, 241);
               this->numericUpDown1->Name = L"numericUpDown1";
               this->numericUpDown1->Size = System::Drawing::Size(120, 20);
               this->numericUpDown1->TabIndex = 11;
               // 
               // numericUpDown2
               // 
               this->numericUpDown2->Location = System::Drawing::Point(419, 267);
               this->numericUpDown2->Name = L"numericUpDown2";
               this->numericUpDown2->Size = System::Drawing::Size(120, 20);
               this->numericUpDown2->TabIndex = 12;
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Location = System::Drawing::Point(359, 243);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(48, 13);
               this->label4->TabIndex = 13;
               this->label4->Text = L"Capacity";
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->Location = System::Drawing::Point(327, 269);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(89, 13);
               this->label5->TabIndex = 14;
               this->label5->Text = L"Sessions Number";
               // 
               // radioButton1
               // 
               this->radioButton1->AutoSize = true;
               this->radioButton1->Location = System::Drawing::Point(371, 368);
               this->radioButton1->Name = L"radioButton1";
               this->radioButton1->Size = System::Drawing::Size(58, 17);
               this->radioButton1->TabIndex = 15;
               this->radioButton1->Text = L"Private";
               this->radioButton1->UseVisualStyleBackColor = true;
               // 
               // radioButton2
               // 
               this->radioButton2->AutoSize = true;
               this->radioButton2->Location = System::Drawing::Point(462, 368);
               this->radioButton2->Name = L"radioButton2";
               this->radioButton2->Size = System::Drawing::Size(54, 17);
               this->radioButton2->TabIndex = 16;
               this->radioButton2->Text = L"Group";
               this->radioButton2->UseVisualStyleBackColor = true;
               // 
               // numericUpDown3
               // 
               this->numericUpDown3->DecimalPlaces = 2;
               this->numericUpDown3->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
               this->numericUpDown3->Location = System::Drawing::Point(419, 293);
               this->numericUpDown3->Name = L"numericUpDown3";
               this->numericUpDown3->Size = System::Drawing::Size(120, 20);
               this->numericUpDown3->TabIndex = 17;
               // 
               // Add_Sessions
               // 
               this->Controls->Add(this->numericUpDown3);
               this->Controls->Add(this->radioButton2);
               this->Controls->Add(this->radioButton1);
               this->Controls->Add(this->label5);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->numericUpDown2);
               this->Controls->Add(this->numericUpDown1);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->dataGridView1);
               this->Controls->Add(this->dateTimePicker1);
               this->Controls->Add(this->textBox1);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Name = L"Add_Sessions";
               this->Size = System::Drawing::Size(948, 496);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        using namespace msclr::interop;

        std::string name = marshal_as<std::string>(textBox1->Text);
        std::string startTime = marshal_as<std::string>(dateTimePicker1->Value.ToString("HH:mm"));
        int capacity = (int)numericUpDown1->Value;
        int numberOfSessions = (int)numericUpDown2->Value;
        float duration = (float)numericUpDown3->Value;
        bool type = radioButton1->Checked;

        GymClass newClass(name, capacity, startTime, duration, numberOfSessions, type);
        currentCoach->addClass(newClass);

        dataGridView1->Rows->Add(
            gcnew String(name.c_str()),
            gcnew String(startTime.c_str()),
            gcnew String(std::to_string(duration).substr(0,4).c_str()),
            gcnew String(std::to_string(capacity).c_str()),
            gcnew String(std::to_string(numberOfSessions).c_str()),
            gcnew String(type ? "Private" : "Group")
        );

        MessageBox::Show("Session added!");
    }

};
}