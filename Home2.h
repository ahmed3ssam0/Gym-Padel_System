#pragma once
#include "Coatch.h"
#include <string>
#include "Gym.h"
#include "GymClass.h"
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <vector>
#include "System.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace msclr::interop;

namespace gymproject {
    public ref class Home2 : public System::Windows::Forms::UserControl
    {
    private:
        Coatch* currentCoach;
		SystemManager* system;

    public:
        Home2(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
            loadSessions();
        }

        void loadSessions()
        {
            lblToday->Text = "Today's Sessions - " + DateTime::Now.ToString("D");

            sessionDataGridView->Rows->Clear();

            std::list<GymClass> classes = currentCoach->getClassAssignments();
            for (GymClass gClass : classes)
            {
                sessionDataGridView->Rows->Add(
                    gcnew String((gClass.getStartTime() + " hrs").c_str()),
                    gcnew String(gClass.getName().c_str()),
                    gcnew String((std::to_string(gClass.getTimePeriod()) + " hrs").c_str())
                );
            }
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
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {

            Button^ logoutButton = gcnew Button();
            logoutButton->Location = System::Drawing::Point(this->ClientSize.Width - 85, 10); // Adjust as needed
            logoutButton->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            logoutButton->Name = L"logoutButton";
            logoutButton->Size = System::Drawing::Size(75, 23);
            logoutButton->BackColor = Color::Blue;
            logoutButton->ForeColor = Color::White;
            logoutButton->TabIndex = 0;
            logoutButton->Text = L"Logout";
            logoutButton->UseVisualStyleBackColor = false; // So it uses BackColor
            logoutButton->Click += gcnew System::EventHandler(this, &Home2::logoutButton_Click);
			this->Controls->Add(logoutButton);

            Button^ reButton = gcnew Button();
            reButton->Location = System::Drawing::Point(this->ClientSize.Width - 125, 10); // Adjust as needed
            reButton->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            reButton->Name = L"reButton";
            reButton->Size = System::Drawing::Size(75, 23);
            reButton->BackColor = Color::Blue;
            reButton->ForeColor = Color::White;
            reButton->TabIndex = 0;
            reButton->Text = L"Refresh";
            reButton->UseVisualStyleBackColor = false; // So it uses BackColor
            reButton->Click += gcnew System::EventHandler(this, &Home2::reButton_Click);
            this->Controls->Add(reButton);


            this->sessionDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->lblToday = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sessionDataGridView))->BeginInit();
            this->SuspendLayout();

            this->sessionDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->sessionDataGridView->Location = System::Drawing::Point(20, 70);
            this->sessionDataGridView->Name = L"sessionDataGridView";
            this->sessionDataGridView->Size = System::Drawing::Size(540, 200);
            this->sessionDataGridView->TabIndex = 0;
            this->sessionDataGridView->ReadOnly = true;
            this->sessionDataGridView->AllowUserToAddRows = false;
            this->sessionDataGridView->AllowUserToDeleteRows = false;
            this->sessionDataGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            this->sessionDataGridView->Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right;

            this->sessionDataGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10);
            this->sessionDataGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 10);

            this->sessionDataGridView->Columns->Add("Time", "Time");
            this->sessionDataGridView->Columns->Add("Session", "Session Name");
            this->sessionDataGridView->Columns->Add("Duration", "Duration");

            this->lblToday->AutoSize = true;
            this->lblToday->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
            this->lblToday->Location = System::Drawing::Point(20, 20);
            this->lblToday->Name = L"lblToday";
            this->lblToday->Size = System::Drawing::Size(200, 22);
            this->lblToday->TabIndex = 1;
            this->lblToday->Text = L"Today's Sessions";

            this->Controls->Add(this->lblToday);
            this->Controls->Add(this->sessionDataGridView);
            this->Name = L"Home";
            this->Size = System::Drawing::Size(600, 300);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sessionDataGridView))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
        private:
        System::Void logoutButton_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void reButton_Click(System::Object^ sender, System::EventArgs^ e);
    };
}