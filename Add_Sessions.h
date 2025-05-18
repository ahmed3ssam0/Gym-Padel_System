#pragma once
#include "Coatch.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <vector>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace msclr::interop;

namespace gymproject {

    public ref class AddSession : public UserControl
    {
    private:
        Coatch* currentCoach;

        Label^ lblSessionName;
        TextBox^ txtSessionName;

        Label^ lblCapacity;
        NumericUpDown^ numCapacity;

        Label^ lblNumSessions;
        NumericUpDown^ numSessions;

        Label^ lblTimePeriod;
        ComboBox^ cmbTimePeriod;

        Label^ lblStartTime;
        DateTimePicker^ dtpStartTime;

        GroupBox^ grpSessionType;
        RadioButton^ rdoPrivate;
        RadioButton^ rdoPublic;

        Label^ lblEndTimeLabel;
        Label^ lblEndTime;

        Button^ btnAdd;

    public:
        AddSession(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Size = Drawing::Size(600, 300);

            lblSessionName = gcnew Label();
            lblSessionName->Text = "Session Name:";
            lblSessionName->Location = Point(20, 20);
            lblSessionName->AutoSize = true;

            txtSessionName = gcnew TextBox();
            txtSessionName->Location = Point(140, 18);
            txtSessionName->Width = 150;

            lblCapacity = gcnew Label();
            lblCapacity->Text = "Capacity:";
            lblCapacity->Location = Point(20, 60);
            lblCapacity->AutoSize = true;

            numCapacity = gcnew NumericUpDown();
            numCapacity->Location = Point(140, 58);
            numCapacity->Minimum = 1;
            numCapacity->Maximum = 1000;

            lblNumSessions = gcnew Label();
            lblNumSessions->Text = "Number of Sessions:";
            lblNumSessions->Location = Point(20, 100);
            lblNumSessions->AutoSize = true;

            numSessions = gcnew NumericUpDown();
            numSessions->Location = Point(140, 98);
            numSessions->Minimum = 1;
            numSessions->Maximum = 100;

            lblTimePeriod = gcnew Label();
            lblTimePeriod->Text = "Time Period (minutes):";
            lblTimePeriod->Location = Point(20, 140);
            lblTimePeriod->AutoSize = true;

            cmbTimePeriod = gcnew ComboBox();
            cmbTimePeriod->Location = Point(160, 138);
            cmbTimePeriod->Width = 80;
            cmbTimePeriod->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbTimePeriod->Items->AddRange(gcnew cli::array< Object^ >(5) { "15", "30", "45", "60", "90" });
            cmbTimePeriod->SelectedIndex = 0;

            lblStartTime = gcnew Label();
            lblStartTime->Text = "Start Time:";
            lblStartTime->Location = Point(20, 180);
            lblStartTime->AutoSize = true;

            dtpStartTime = gcnew DateTimePicker();
            dtpStartTime->Format = DateTimePickerFormat::Time;
            dtpStartTime->ShowUpDown = true;
            dtpStartTime->Location = Point(140, 178);
            dtpStartTime->Width = 100;

            grpSessionType = gcnew GroupBox();
            grpSessionType->Text = "Session Type";
            grpSessionType->Location = Point(320, 20);
            grpSessionType->Size = Drawing::Size(200, 60);

            rdoPrivate = gcnew RadioButton();
            rdoPrivate->Text = "Private";
            rdoPrivate->Location = Point(10, 25);
            rdoPrivate->AutoSize = true;
            rdoPrivate->Checked = true;

            rdoPublic = gcnew RadioButton();
            rdoPublic->Text = "Public";
            rdoPublic->Location = Point(100, 25);
            rdoPublic->AutoSize = true;

            grpSessionType->Controls->Add(rdoPrivate);
            grpSessionType->Controls->Add(rdoPublic);

            lblEndTimeLabel = gcnew Label();
            lblEndTimeLabel->Text = "End Time:";
            lblEndTimeLabel->Location = Point(320, 100);
            lblEndTimeLabel->AutoSize = true;

            lblEndTime = gcnew Label();
            lblEndTime->Location = Point(380, 100);
            lblEndTime->Width = 100;
            lblEndTime->Text = "--:--";

            btnAdd = gcnew Button();
            btnAdd->Text = "Add Session";
            btnAdd->Location = Point(320, 140);
            btnAdd->Width = 150;
            btnAdd->Click += gcnew EventHandler(this, &AddSession::OnAddSession);

            cmbTimePeriod->SelectedIndexChanged += gcnew EventHandler(this, &AddSession::CalculateEndTime);
            dtpStartTime->ValueChanged += gcnew EventHandler(this, &AddSession::CalculateEndTime);

            this->Controls->Add(lblSessionName);
            this->Controls->Add(txtSessionName);
            this->Controls->Add(lblCapacity);
            this->Controls->Add(numCapacity);
            this->Controls->Add(lblNumSessions);
            this->Controls->Add(numSessions);
            this->Controls->Add(lblTimePeriod);
            this->Controls->Add(cmbTimePeriod);
            this->Controls->Add(lblStartTime);
            this->Controls->Add(dtpStartTime);
            this->Controls->Add(grpSessionType);
            this->Controls->Add(lblEndTimeLabel);
            this->Controls->Add(lblEndTime);
            this->Controls->Add(btnAdd);

            CalculateEndTime(nullptr, nullptr);
        }

        void CalculateEndTime(Object^ sender, EventArgs^ e)
        {
            if (cmbTimePeriod == nullptr || cmbTimePeriod->SelectedItem == nullptr || dtpStartTime == nullptr)
            {
                lblEndTime->Text = "Invalid input";
                return;
            }

            int timePeriodMins;
            bool success = Int32::TryParse(cmbTimePeriod->SelectedItem->ToString(), timePeriodMins);
            if (!success)
            {
                lblEndTime->Text = "Invalid time period";
                return;
            }

            DateTime start = dtpStartTime->Value;
            DateTime end = start.AddMinutes(timePeriodMins);

            lblEndTime->Text = end.ToString("HH:mm");
        }

        void OnAddSession(Object^ sender, EventArgs^ e)
        {
            String^ sessionName = txtSessionName->Text->Trim();
            int capacity = (int)numCapacity->Value;
            int numSess = (int)numSessions->Value;
            int timePeriod = Int32::Parse(cmbTimePeriod->SelectedItem->ToString());
            DateTime startTime = dtpStartTime->Value;
            String^ sessionType = rdoPrivate->Checked ? "Private" : "Public";

            if (String::IsNullOrEmpty(sessionName))
            {
                MessageBox::Show("Please enter a session name.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            String^ coachID = gcnew String(currentCoach->getid().c_str());

            String^ msg = String::Format(
                "Session Added:\nName: {0}\nCapacity: {1}\nSessions: {2}\nTime Period: {3} mins\nStart: {4}\nEnd: {5}\nType: {6}\nCoach ID: {7}",
                sessionName, capacity, numSess, timePeriod, startTime.ToString("HH:mm"), lblEndTime->Text, sessionType, coachID
            );

            MessageBox::Show(msg, "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

            txtSessionName->Clear();
            numCapacity->Value = 1;
            numSessions->Value = 1;
            cmbTimePeriod->SelectedIndex = 0;
            dtpStartTime->Value = DateTime::Now;
            rdoPrivate->Checked = true;
            CalculateEndTime(nullptr, nullptr);
        }
    };
}