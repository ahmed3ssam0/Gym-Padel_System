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

    public ref class RemoveSession : public UserControl
    {
    private:
        Coatch* currentCoach;
        Label^ lblSessionName;
        TextBox^ txtSessionName;
        Button^ btnRemove;

    public:
        RemoveSession(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Size = Drawing::Size(400, 150);

            lblSessionName = gcnew Label();
            lblSessionName->Text = "Session Name to Remove:";
            lblSessionName->Location = Point(20, 30);
            lblSessionName->AutoSize = true;

            txtSessionName = gcnew TextBox();
            txtSessionName->Location = Point(180, 28);
            txtSessionName->Width = 180;

            btnRemove = gcnew Button();
            btnRemove->Text = "Remove Session";
            btnRemove->Location = Point(180, 70);
            btnRemove->Width = 120;
            btnRemove->Click += gcnew EventHandler(this, &RemoveSession::OnRemoveSession);

            this->Controls->Add(lblSessionName);
            this->Controls->Add(txtSessionName);
            this->Controls->Add(btnRemove);
        }

        void OnRemoveSession(Object^ sender, EventArgs^ e)
        {
            String^ sessionName = txtSessionName->Text->Trim();

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
                txtSessionName->Clear();
            }
            else
            {
                MessageBox::Show("Session '" + sessionName + "' not found or could not be removed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}