#pragma once
#include "Coatch.h"
#include "Receptionist.h"
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include "Manager.h"
#include "System.h"

namespace gymproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ManagerForm : public System::Windows::Forms::Form
    {
    private:
        TabControl^ tabControl;

        TabPage^ tabAddRec;
        TabPage^ tabRemoveRec;
        TabPage^ tabAddCoach;
        TabPage^ tabRemoveCoach;

        TextBox^ txtRecName;
        TextBox^ txtRecID;
        TextBox^ txtRecPass;
        TextBox^ txtRecSalary;
        TextBox^ txtRecRemoveName;
        Button^ btnAddRec;
        Button^ btnRemoveRec;
        DataGridView^ dgvRec;

        TextBox^ txtCoachName;
        TextBox^ txtCoachID;
        TextBox^ txtCoachPass;
        TextBox^ txtCoachSalary;
        TextBox^ txtCoachRemoveName;
        Button^ btnAddCoach;
        Button^ btnRemoveCoach;
        DataGridView^ dgvCoach;

		Panel^ topPanel;
        Button^ logOut;
		Panel^ bottomPanel;

		Manager* manager;
		SystemManager* system;

    public:
        ManagerForm()
        {
            this->Text = "Gym Manager Panel";
            this->Size = Drawing::Size(500, 500);

            topPanel = gcnew Panel();
            bottomPanel = gcnew Panel();

            Label^ lblWelcome = gcnew Label();
            lblWelcome->Text = "Welcome, Manager!";
            lblWelcome->Font = gcnew Drawing::Font("Arial", 14, FontStyle::Bold);
            lblWelcome->AutoSize = true;
            lblWelcome->Location = Point(10, 10);

            topPanel->Controls->Add(lblWelcome);
            topPanel->Dock = DockStyle::Top;
            topPanel->Height = 40;

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

            bottomPanel->Controls->Add(tabControl);
            bottomPanel->Dock = DockStyle::Fill;

            this->Controls->Add(bottomPanel);
            this->Controls->Add(topPanel);
        }

    private:

        void InitAddReceptionistTab()
        {
            tabAddRec = gcnew TabPage("Add Receptionist");
            Panel^ panel = gcnew Panel();
            panel->Dock = DockStyle::Fill;
            //panel->Size = Drawing::Size(500, 500);
           /* panel->Location = Drawing::Point(
                (tabAddRec->ClientSize.Width - panel->Width) / 2,
                (tabAddRec->ClientSize.Height - panel->Height) / 2
            );
            panel->Anchor = AnchorStyles::None;*/

            txtRecName = CreateTextBox(120, 20);
            txtRecID = CreateTextBox(120, 50);
            txtRecPass = CreateTextBox(120, 80);
            txtRecSalary = CreateTextBox(120, 110);
            btnAddRec = gcnew Button();
            btnAddRec->Text = "Add Receptionist";
            btnAddRec->Location = Point(10, 150);
            btnAddRec->Click += gcnew EventHandler(this, &ManagerForm::AddReceptionist);

            dgvRec = gcnew DataGridView();
            dgvRec->Location = Point(10, 190);
            dgvRec->Size = Drawing::Size(440, 200);
            dgvRec->ColumnCount = 2;
            dgvRec->Columns[0]->Name = "Name";
            dgvRec->Columns[1]->Name = "ID";

            panel->Controls->Add(CreateLabel("Name:", 10, 20));
            panel->Controls->Add(txtRecName);
            panel->Controls->Add(CreateLabel("ID:", 10, 50));
            panel->Controls->Add(txtRecID);
            panel->Controls->Add(CreateLabel("Password:", 10, 80));
            panel->Controls->Add(txtRecPass);
            panel->Controls->Add(CreateLabel("Salary:", 10, 110));
            panel->Controls->Add(txtRecSalary);
            panel->Controls->Add(btnAddRec);
            panel->Controls->Add(dgvRec);

            tabAddRec->Controls->Add(panel);
        }

        void InitRemoveReceptionistTab()
        {
            tabRemoveRec = gcnew TabPage("Remove Receptionist");
            Panel^ panel = gcnew Panel();
            panel->Dock = DockStyle::Fill;
            panel->Size = Drawing::Size(350, 300);
            panel->Location = Drawing::Point(
                (tabAddRec->ClientSize.Width - panel->Width) / 2,
                (tabAddRec->ClientSize.Height - panel->Height) / 2
            );
            panel->Anchor = AnchorStyles::None;

            txtRecRemoveName = CreateTextBox(200, 30);
            btnRemoveRec = gcnew Button();
            btnRemoveRec->Text = "Delete Receptionist by Name";
            btnRemoveRec->Location = Point(200, 70);
            btnRemoveRec->Click += gcnew EventHandler(this, &ManagerForm::RemoveReceptionist);

            panel->Controls->Add(CreateLabel("Enter Name to Delete:", 10, 30));
            panel->Controls->Add(txtRecRemoveName);
            panel->Controls->Add(btnRemoveRec);

            tabRemoveRec->Controls->Add(panel);
        }

        void InitAddCoachTab()
        {
            tabAddCoach = gcnew TabPage("Add Coach");
            Panel^ panel = gcnew Panel();
            panel->Dock = DockStyle::Fill;
            panel->Size = Drawing::Size(350, 300);
            panel->Location = Drawing::Point(
                (tabAddRec->ClientSize.Width - panel->Width) / 2,
                (tabAddRec->ClientSize.Height - panel->Height) / 2
            );
            panel->Anchor = AnchorStyles::None;

            txtCoachName = CreateTextBox(120, 20);
            txtCoachID = CreateTextBox(120, 50);
            txtCoachPass = CreateTextBox(120, 80);
            txtCoachSalary = CreateTextBox(120, 110);
            btnAddCoach = gcnew Button();
            btnAddCoach->Text = "Add Coach";
            btnAddCoach->Location = Point(10, 150);
            btnAddCoach->Click += gcnew EventHandler(this, &ManagerForm::AddCoach);

            dgvCoach = gcnew DataGridView();
            dgvCoach->Location = Point(10, 190);
            dgvCoach->Size = Drawing::Size(440, 200);
            dgvCoach->ColumnCount = 2;
            dgvCoach->Columns[0]->Name = "Name";
            dgvCoach->Columns[1]->Name = "ID";

            panel->Controls->Add(CreateLabel("Name:", 10, 20));
            panel->Controls->Add(txtCoachName);
            panel->Controls->Add(CreateLabel("ID:", 10, 50));
            panel->Controls->Add(txtCoachID);
            panel->Controls->Add(CreateLabel("Password:", 10, 80));
            panel->Controls->Add(txtCoachPass);
            panel->Controls->Add(CreateLabel("Salary:", 10, 110));
            panel->Controls->Add(txtCoachSalary);
            panel->Controls->Add(btnAddCoach);
            panel->Controls->Add(dgvCoach);

            tabAddCoach->Controls->Add(panel);
        }

        void InitRemoveCoachTab()
        {
            tabRemoveCoach = gcnew TabPage("Remove Coach");
            Panel^ panel = gcnew Panel();
            panel->Dock = DockStyle::Fill;
            panel->Size = Drawing::Size(350, 300);
            panel->Location = Drawing::Point(
                (tabAddRec->ClientSize.Width - panel->Width) / 2,
                (tabAddRec->ClientSize.Height - panel->Height) / 2
            );
            panel->Anchor = AnchorStyles::None;

            txtCoachRemoveName = CreateTextBox(200, 30);
            btnRemoveCoach = gcnew Button();
            btnRemoveCoach->Text = "Delete Coach by Name";
            btnRemoveCoach->Location = Point(200, 70);
            btnRemoveCoach->Click += gcnew EventHandler(this, &ManagerForm::RemoveCoach);

            panel->Controls->Add(CreateLabel("Enter Name to Delete:", 10, 30));
            panel->Controls->Add(txtCoachRemoveName);
            panel->Controls->Add(btnRemoveCoach);

            tabRemoveCoach->Controls->Add(panel);
        }

        Label^ CreateLabel(String^ text, int x, int y)
        {
            Label^ label = gcnew Label();
            label->Text = text;
            label->Location = Point(x, y);
            label->AutoSize = true;
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

            std::string name = msclr::interop::marshal_as<std::string>(txtRecName->Text);
            std::string id = msclr::interop::marshal_as<std::string>(txtRecID->Text);
            std::string pass = msclr::interop::marshal_as<std::string>(txtRecPass->Text);
            double salary = std::stod(msclr::interop::marshal_as<std::string>(txtRecSalary->Text));

            Receptionist* rec = new Receptionist(name, id, pass, salary);
            

            dgvRec->Rows->Add(gcnew cli::array<String^> { txtRecName->Text, txtRecID->Text });

            txtRecName->Clear(); txtRecID->Clear(); txtRecPass->Clear(); txtRecSalary->Clear();
            MessageBox::Show("Receptionist added successfully.");
        }

        void RemoveReceptionist(Object^ sender, EventArgs^ e)
        {
            String^ name = txtRecRemoveName->Text;
            for (int i = 0; i < dgvRec->Rows->Count - 1; i++) {
                if (dgvRec->Rows[i]->Cells[0]->Value->ToString() == name) {
                    dgvRec->Rows->RemoveAt(i);
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

            std::string name = msclr::interop::marshal_as<std::string>(txtCoachName->Text);
            std::string id = msclr::interop::marshal_as<std::string>(txtCoachID->Text);
            std::string pass = msclr::interop::marshal_as<std::string>(txtCoachPass->Text);
            double salary = std::stod(msclr::interop::marshal_as<std::string>(txtCoachSalary->Text));

            Coatch* coach = new Coatch(name, id, pass, salary);
            

            dgvRec->Rows->Add(gcnew cli::array<String^, 1> { txtRecName->Text, txtRecID->Text });

            txtCoachName->Clear(); txtCoachID->Clear(); txtCoachPass->Clear(); txtCoachSalary->Clear();
            MessageBox::Show("Coach added successfully.");
        }

        void RemoveCoach(Object^ sender, EventArgs^ e)
        {
            String^ name = txtCoachRemoveName->Text;
            for (int i = 0; i < dgvCoach->Rows->Count - 1; i++) {
                if (dgvCoach->Rows[i]->Cells[0]->Value->ToString() == name) {
                    dgvCoach->Rows->RemoveAt(i);
                    MessageBox::Show("Coach removed successfully.");
                    return;
                }
            }
            MessageBox::Show("Coach not found.");
        }
    };
}
