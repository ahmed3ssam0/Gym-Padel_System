#pragma once
#include <iostream>
#include <Windows.h>
#using <System.Windows.Forms.dll>
#include <unordered_map>
#include "Coatch.h"
#include "GymClass.h"

namespace gymproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class Home2 : public System::Windows::Forms::UserControl
	{
	private:
		Coatch* currentCoach;

	public:
		Home2(void)
		{
			InitializeComponent();
			loadSessions();
		}
		Home2(Coatch* coach) : currentCoach(coach)
		{
			InitializeComponent();
			loadSessions();
		}

	protected:
		~Home2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::DataGridView^ sessionDataGridView;
		System::Windows::Forms::Label^ lblToday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cap;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
	private: System::Windows::Forms::Label^ label2;









		   System::ComponentModel::Container^ components;

		void loadSessions()
		{
			label2->Text = "Welcome Coach " + gcnew String(currentCoach->getname().c_str());
			lblToday->Text = "Today's Sessions - " + DateTime::Now.ToString("D");
			sessionDataGridView->Rows->Clear();

			list<GymClass> classes = currentCoach->getClassAssignments();
			for (GymClass& gymClass : classes)
			{
				String^ name = gcnew String(gymClass.getName().c_str());
				String^ startTime = gcnew String(gymClass.getStartTime().c_str());
				int capacity = gymClass.getCapacity();
				int numberOfSessions = gymClass.getNumberOfSessions();
				float duration = gymClass.getTimePeriod();
				bool type = gymClass.getType();
				sessionDataGridView->Rows->Add(
					gcnew String(name),
					gcnew String(startTime),
					gcnew String(std::to_string(duration).substr(0, 4).c_str()),
					gcnew String(std::to_string(capacity).c_str()),
					gcnew String(std::to_string(numberOfSessions).c_str()),
					gcnew String(type ? "Private" : "Group")
				);
			}
		}

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->sessionDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->lblToday = (gcnew System::Windows::Forms::Label());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cap = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sessionDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// sessionDataGridView
			// 
			this->sessionDataGridView->AllowUserToAddRows = false;
			this->sessionDataGridView->AllowUserToDeleteRows = false;
			this->sessionDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->sessionDataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->sessionDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->sessionDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn2,
					this->dataGridViewTextBoxColumn1, this->dataGridViewTextBoxColumn3, this->cap, this->nos, this->type
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->sessionDataGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->sessionDataGridView->Location = System::Drawing::Point(24, 125);
			this->sessionDataGridView->Name = L"sessionDataGridView";
			this->sessionDataGridView->ReadOnly = true;
			this->sessionDataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->sessionDataGridView->Size = System::Drawing::Size(760, 200);
			this->sessionDataGridView->TabIndex = 0;
			// 
			// lblToday
			// 
			this->lblToday->AutoSize = true;
			this->lblToday->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->lblToday->Location = System::Drawing::Point(20, 74);
			this->lblToday->Name = L"lblToday";
			this->lblToday->Size = System::Drawing::Size(175, 22);
			this->lblToday->TabIndex = 1;
			this->lblToday->Text = L"Today\'s Sessions";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn2->HeaderText = L"Session Name";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Start Time";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn3->HeaderText = L"Duration In Hours";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// cap
			// 
			this->cap->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->cap->HeaderText = L"Capacity";
			this->cap->Name = L"cap";
			this->cap->ReadOnly = true;
			// 
			// nos
			// 
			this->nos->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->nos->HeaderText = L"Number Of Sessions";
			this->nos->Name = L"nos";
			this->nos->ReadOnly = true;
			// 
			// type
			// 
			this->type->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->type->HeaderText = L"Type";
			this->type->Name = L"type";
			this->type->ReadOnly = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(20, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(164, 22);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Welcome Coach \r\n";
			// 
			// Home2
			// 
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblToday);
			this->Controls->Add(this->sessionDataGridView);
			this->Name = L"Home2";
			this->Size = System::Drawing::Size(813, 442);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sessionDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	};
}
