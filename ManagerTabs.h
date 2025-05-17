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
	/// Summary for ManagerTabs
	/// </summary>
	public ref class ManagerForm : public System::Windows::Forms::Form
	{
    private:
        TabControl^ tabControl;

        TabPage^ tabAddRec;
        TextBox^ txtRecName;
        TextBox^ txtRecID;
        TextBox^ txtRecPass;
        TextBox^ txtRecSalary;
        Button^ btnAddRec;
        ListBox^ listRec;

        TabPage^ tabRemoveRec;
        TextBox^ txtRecRemoveName;
        Button^ btnRemoveRec;

        TabPage^ tabAddCoach;
        TextBox^ txtCoachName;
        TextBox^ txtCoachID;
        TextBox^ txtCoachPass;
        TextBox^ txtCoachSalary;
        Button^ btnAddCoach;
        ListBox^ listCoach;

        TabPage^ tabRemoveCoach;
        TextBox^ txtCoachRemoveName;
        Button^ btnRemoveCoach;

    public:
        ManagerForm()
        {
            this->Text = "Gym Manager Panel";
            this->Size = System::Drawing::Size(500, 400);

            tabControl = gcnew TabControl();
            tabControl->Dock = DockStyle::Fill;

            InitAddReceptionistTab();
            InitRemoveReceptionistTab();
            InitAddCoachTab();
            InitRemoveCoachTab();

            tabControl->TabPages->Add(tabAddRec);
            tabControl->TabPages->Add(tabRemoveRec);
            tabControl->TabPages->Add(tabAddCoach);
            tabControl->TabPages->Add(tabRemoveCoach);

            this->Controls->Add(tabControl);
        }

    private:

        void InitAddReceptionistTab()
        {
            tabAddRec = gcnew TabPage("Add Receptionist");

            txtRecName = CreateTextBox(120, 20);
            txtRecID = CreateTextBox(120, 50);
            txtRecPass = CreateTextBox(120, 80);
            txtRecSalary = CreateTextBox(120, 110);
            btnAddRec = gcnew Button();
            btnAddRec->Text = "Add Receptionist";
            btnAddRec->Location = Point(10, 150);
            btnAddRec->Click += gcnew EventHandler(this, &ManagerForm::AddReceptionist);

            listRec = gcnew ListBox();
            listRec->Location = Point(10, 190);
            listRec->Size = Drawing::Size(440, 120);

            tabAddRec->Controls->Add(CreateLabel("Name:", 10, 20));
            tabAddRec->Controls->Add(txtRecName);
            tabAddRec->Controls->Add(CreateLabel("ID:", 10, 50));
            tabAddRec->Controls->Add(txtRecID);
            tabAddRec->Controls->Add(CreateLabel("Password:", 10, 80));
            tabAddRec->Controls->Add(txtRecPass);
            tabAddRec->Controls->Add(CreateLabel("Salary:", 10, 110));
            tabAddRec->Controls->Add(txtRecSalary);
            tabAddRec->Controls->Add(btnAddRec);
            tabAddRec->Controls->Add(listRec);
        }

        void InitRemoveReceptionistTab()
        {
            tabRemoveRec = gcnew TabPage("Remove Receptionist");

            txtRecRemoveName = CreateTextBox(150, 30);
            btnRemoveRec = gcnew Button();
            btnRemoveRec->Text = "Delete Receptionist by Name";
            btnRemoveRec->Location = Point(150, 70);
            btnRemoveRec->Click += gcnew EventHandler(this, &ManagerForm::RemoveReceptionist);

            tabRemoveRec->Controls->Add(CreateLabel("Enter Name to Delete:", 10, 30));
            tabRemoveRec->Controls->Add(txtRecRemoveName);
            tabRemoveRec->Controls->Add(btnRemoveRec);
        }

        void InitAddCoachTab()
        {
            tabAddCoach = gcnew TabPage("Add Coach");

            txtCoachName = CreateTextBox(120, 20);
            txtCoachID = CreateTextBox(120, 50);
            txtCoachPass = CreateTextBox(120, 80);
            txtCoachSalary = CreateTextBox(120, 110);
            btnAddCoach = gcnew Button();
            btnAddCoach->Text = "Add Coach";
            btnAddCoach->Location = Point(10, 150);
            btnAddCoach->Click += gcnew EventHandler(this, &ManagerForm::AddCoach);

            listCoach = gcnew ListBox();
            listCoach->Location = Point(10, 190);
            listCoach->Size = Drawing::Size(440, 120);

            tabAddCoach->Controls->Add(CreateLabel("Name:", 10, 20));
            tabAddCoach->Controls->Add(txtCoachName);
            tabAddCoach->Controls->Add(CreateLabel("ID:", 10, 50));
            tabAddCoach->Controls->Add(txtCoachID);
            tabAddCoach->Controls->Add(CreateLabel("Password:", 10, 80));
            tabAddCoach->Controls->Add(txtCoachPass);
            tabAddCoach->Controls->Add(CreateLabel("Salary:", 10, 110));
            tabAddCoach->Controls->Add(txtCoachSalary);
            tabAddCoach->Controls->Add(btnAddCoach);
            tabAddCoach->Controls->Add(listCoach);
        }

        void InitRemoveCoachTab()
        {
            tabRemoveCoach = gcnew TabPage("Remove Coach");

            txtCoachRemoveName = CreateTextBox(150, 30);
            btnRemoveCoach = gcnew Button();
            btnRemoveCoach->Text = "Delete Coach by Name";
            btnRemoveCoach->Location = Point(150, 70);
            btnRemoveCoach->Click += gcnew EventHandler(this, &ManagerForm::RemoveCoach);

            tabRemoveCoach->Controls->Add(CreateLabel("Enter Name to Delete:", 10, 30));
            tabRemoveCoach->Controls->Add(txtCoachRemoveName);
            tabRemoveCoach->Controls->Add(btnRemoveCoach);
        }

        Label^ CreateLabel(String^ text, int x, int y)
        {
            Label^ label = gcnew Label();
            label->Text = text;
            label->Location = Point(x, y);
            return label;
        }

        TextBox^ CreateTextBox(int x, int y)
        {
            TextBox^ txt = gcnew TextBox();
            txt->Location = Point(x, y);
            txt->Width = 200;
            return txt;
        }

        void AddReceptionist(Object^ sender, EventArgs^ e)
        {
            if (txtRecName->Text == "" || txtRecID->Text == "" || txtRecPass->Text == "" || txtRecSalary->Text == "") {
                MessageBox::Show("Please fill all Receptionist fields.");
                return;
            }

            String^ entry = txtRecName->Text + " | ID: " + txtRecID->Text;
            listRec->Items->Add(entry);
            txtRecName->Clear(); txtRecID->Clear(); txtRecPass->Clear(); txtRecSalary->Clear();
            MessageBox::Show("Receptionist added successfully.");
        }

        void RemoveReceptionist(Object^ sender, EventArgs^ e)
        {
            String^ name = txtRecRemoveName->Text;
            for (int i = 0; i < listRec->Items->Count; i++) {
                if (listRec->Items[i]->ToString()->StartsWith(name + " ")) {
                    listRec->Items->RemoveAt(i);
                    MessageBox::Show("Receptionist removed successfully.");
                    return;
                }
            }
            MessageBox::Show("Receptionist not found.");
        }

        void AddCoach(Object^ sender, EventArgs^ e)
        {
            if (txtCoachName->Text == "" || txtCoachID->Text == "" || txtCoachPass->Text == "" || txtCoachSalary->Text == "") {
                MessageBox::Show("Please fill all Coach fields.");
                return;
            }

            String^ entry = txtCoachName->Text + " | ID: " + txtCoachID->Text;
            listCoach->Items->Add(entry);
            txtCoachName->Clear(); txtCoachID->Clear(); txtCoachPass->Clear(); txtCoachSalary->Clear();
            MessageBox::Show("Coach added successfully.");
        }

        void RemoveCoach(Object^ sender, EventArgs^ e)
        {
            String^ name = txtCoachRemoveName->Text;
            for (int i = 0; i < listCoach->Items->Count; i++) {
                if (listCoach->Items[i]->ToString()->StartsWith(name + " ")) {
                    listCoach->Items->RemoveAt(i);
                    MessageBox::Show("Coach removed successfully.");
                    return;
                }
            }
            MessageBox::Show("Coach not found.");
        }
	};
}
