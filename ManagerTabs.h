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
		Panel^ bottomPanel;

        Panel^ centerPanelAddRec;
        Panel^ centerPanelRemoveRec;
        Panel^ centerPanelAddCoach;
        Panel^ centerPanelRemoveCoach;

		//Button^ btnLogOut;

		SystemManager* system;
        Manager* man;
    
    public:
        ManagerForm(SystemManager* system, Manager* man)
        {
			this->system = system;
            this->man = man;

            // Make the window fullscreen
            this->WindowState = FormWindowState::Maximized;
            this->Text = "Gym Manager Panel";

            // Top panel with welcome label
            topPanel = gcnew Panel();
            topPanel->Height = 60;
            topPanel->Dock = DockStyle::Top;
            topPanel->BackColor = Color::LightSteelBlue;

            Label^ lblWelcome = gcnew Label();
			Button^ btnLogOut = gcnew Button();
            lblWelcome->Text = "Welcome Manager " + gcnew String(man->getname().c_str());
            lblWelcome->Font = gcnew Drawing::Font("Segoe UI", 20, FontStyle::Bold);
            lblWelcome->AutoSize = true;
            lblWelcome->Location = Point(20, 15);
            btnLogOut->Text = "Logout";
            btnLogOut->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Regular);
            btnLogOut->Size = Drawing::Size(100, 40);
            btnLogOut->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            btnLogOut->Location = Point(topPanel->Width - btnLogOut->Width - 20, 20);
            topPanel->Controls->Add(lblWelcome);
			topPanel->Controls->Add(btnLogOut);
            btnLogOut->Click += gcnew System::EventHandler(this, &ManagerForm::btnLogOut_Click);


            // Bottom panel to hold tab control
            bottomPanel = gcnew Panel();
            bottomPanel->Dock = DockStyle::Fill;

            // Tab Control
            tabControl = gcnew TabControl();
            tabControl->Dock = DockStyle::Fill;
            bottomPanel->Controls->Add(tabControl);

            // Initialize all tabs
            InitAddReceptionistTab();
            InitRemoveReceptionistTab();
            InitAddCoachTab();
            InitRemoveCoachTab();

            tabControl->TabPages->Add(tabAddRec);
            tabControl->TabPages->Add(tabRemoveRec);
            tabControl->TabPages->Add(tabAddCoach);
            tabControl->TabPages->Add(tabRemoveCoach);

            // Add panels to form
            this->Controls->Add(bottomPanel);
            this->Controls->Add(topPanel);


        }
    private:

        void InitAddReceptionistTab()
        {
            tabAddRec = gcnew TabPage("Add Receptionist");

            // Main container panel (fills the tab)
            Panel^ mainPanel = gcnew Panel();
            mainPanel->Dock = DockStyle::Fill;
            tabAddRec->Controls->Add(mainPanel);

            // Center panel (fixed size, centered manually)
            centerPanelAddRec = gcnew Panel();
            centerPanelAddRec->Size = Drawing::Size(600, 400);
            mainPanel->Controls->Add(centerPanelAddRec);

            // Center the panel after the tab is loaded
            tabAddRec->Resize += gcnew EventHandler(this, &ManagerForm::OnResizeAddRecTab);
            CenterPanelInTab(tabAddRec, centerPanelAddRec);

            // --- Form Controls ---
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
            dgvRec->ColumnCount = 4;
            dgvRec->Columns[0]->Name = "Name";
            dgvRec->Columns[1]->Name = "ID";
            dgvRec->Columns[2]->Name = "Password";
            dgvRec->Columns[3]->Name = "Salary";

            centerPanelAddRec->Controls->Add(CreateLabel("Name:", 10, 20));
            centerPanelAddRec->Controls->Add(txtRecName);
            centerPanelAddRec->Controls->Add(CreateLabel("ID:", 10, 50));
            centerPanelAddRec->Controls->Add(txtRecID);
            centerPanelAddRec->Controls->Add(CreateLabel("Password:", 10, 80));
            centerPanelAddRec->Controls->Add(txtRecPass);
            centerPanelAddRec->Controls->Add(CreateLabel("Salary:", 10, 110));
            centerPanelAddRec->Controls->Add(txtRecSalary);
            centerPanelAddRec->Controls->Add(btnAddRec);
            centerPanelAddRec->Controls->Add(dgvRec);

            mainPanel->Controls->Add(centerPanelAddRec);

            
        }


        void InitRemoveReceptionistTab()
        {
            tabRemoveRec = gcnew TabPage("Remove Receptionist");

            // Main container panel (fills the tab)
            Panel^ mainPanel = gcnew Panel();
            mainPanel->Dock = DockStyle::Fill;
            tabRemoveRec->Controls->Add(mainPanel);

            // Center panel (fixed size, centered manually)
            centerPanelRemoveRec = gcnew Panel();
            centerPanelRemoveRec->Size = Drawing::Size(600, 400);
            mainPanel->Controls->Add(centerPanelRemoveRec);

            // Center the panel after the tab is loaded
            tabRemoveRec->Resize += gcnew EventHandler(this, &ManagerForm::OnResizeRemoveRecTab);
            CenterPanelInTab(tabRemoveRec, centerPanelRemoveRec);

			// --- Form Controls ---
            txtRecRemoveName = CreateTextBox(200, 30);
            btnRemoveRec = gcnew Button();
            btnRemoveRec->Text = "Delete Receptionist by Name";
            btnRemoveRec->Location = Point(200, 70);
            btnRemoveRec->Click += gcnew EventHandler(this, &ManagerForm::RemoveReceptionist);

            centerPanelRemoveRec->Controls->Add(CreateLabel("Enter Name to Delete:", 10, 30));
            centerPanelRemoveRec->Controls->Add(txtRecRemoveName);
            centerPanelRemoveRec->Controls->Add(btnRemoveRec);

            mainPanel->Controls->Add(centerPanelRemoveRec);
        }

        void InitAddCoachTab()
        {
            tabAddCoach = gcnew TabPage("Add Coach");

            // Main container panel (fills the tab)
            Panel^ mainPanel = gcnew Panel();
            mainPanel->Dock = DockStyle::Fill;
            tabAddCoach->Controls->Add(mainPanel);

            // Center panel (fixed size, centered manually)
            centerPanelAddCoach = gcnew Panel();
            centerPanelAddCoach->Size = Drawing::Size(600, 400);
            mainPanel->Controls->Add(centerPanelAddCoach);

            // Center the panel after the tab is loaded
            tabAddCoach->Resize += gcnew EventHandler(this, &ManagerForm::OnResizeAddCoachTab);
            CenterPanelInTab(tabAddCoach, centerPanelAddCoach);

			// --- Form Controls ---
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
            dgvCoach->ColumnCount = 4;
            dgvCoach->Columns[0]->Name = "Name";
            dgvCoach->Columns[1]->Name = "ID";
			dgvCoach->Columns[2]->Name = "Password";
			dgvCoach->Columns[3]->Name = "Salary";

            centerPanelAddCoach->Controls->Add(CreateLabel("Name:", 10, 20));
            centerPanelAddCoach->Controls->Add(txtCoachName);
            centerPanelAddCoach->Controls->Add(CreateLabel("ID:", 10, 50));
            centerPanelAddCoach->Controls->Add(txtCoachID);
            centerPanelAddCoach->Controls->Add(CreateLabel("Password:", 10, 80));
            centerPanelAddCoach->Controls->Add(txtCoachPass);
            centerPanelAddCoach->Controls->Add(CreateLabel("Salary:", 10, 110));
            centerPanelAddCoach->Controls->Add(txtCoachSalary);
            centerPanelAddCoach->Controls->Add(btnAddCoach);
            centerPanelAddCoach->Controls->Add(dgvCoach);

            mainPanel->Controls->Add(centerPanelAddCoach);
        }

        void InitRemoveCoachTab()
        {
            tabRemoveCoach = gcnew TabPage("Remove Coach");

            // Main container panel (fills the tab)
            Panel^ mainPanel = gcnew Panel();
            mainPanel->Dock = DockStyle::Fill;
            tabRemoveCoach->Controls->Add(mainPanel);

            // Center panel (fixed size, centered manually)
            centerPanelRemoveCoach = gcnew Panel();
            centerPanelRemoveCoach->Size = Drawing::Size(600, 400);
            mainPanel->Controls->Add(centerPanelRemoveCoach);

            // Center the panel after the tab is loaded
            tabRemoveCoach->Resize += gcnew EventHandler(this, &ManagerForm::OnResizeRemoveCoachTab);
            CenterPanelInTab(tabRemoveCoach, centerPanelRemoveCoach);

            // --- Form Controls ---
            txtCoachRemoveName = CreateTextBox(200, 30);
            btnRemoveCoach = gcnew Button();
            btnRemoveCoach->Text = "Delete Coach by Name";
            btnRemoveCoach->Location = Point(200, 70);
            btnRemoveCoach->Click += gcnew EventHandler(this, &ManagerForm::RemoveCoach);

            centerPanelRemoveCoach->Controls->Add(CreateLabel("Enter Name to Delete:", 10, 30));
            centerPanelRemoveCoach->Controls->Add(txtCoachRemoveName);
            centerPanelRemoveCoach->Controls->Add(btnRemoveCoach);

            mainPanel->Controls->Add(centerPanelRemoveCoach);
        }

        void CenterPanelInTab(TabPage^ tab, Panel^ panel)
        {
            if (tab && panel)
            {
                panel->Location = Point(
                    (tab->ClientSize.Width - panel->Width) / 2,
                    (tab->ClientSize.Height - panel->Height) / 2
                );
            }
        }

        void OnResizeAddRecTab(Object^ sender, EventArgs^ e)
        {
            CenterPanelInTab(tabAddRec, centerPanelAddRec);
        }

        void OnResizeRemoveRecTab(Object^ sender, EventArgs^ e)
        {
            CenterPanelInTab(tabRemoveRec, centerPanelRemoveRec);
        }

        void OnResizeAddCoachTab(Object^ sender, EventArgs^ e)
        {
            CenterPanelInTab(tabAddCoach, centerPanelAddCoach);
        }

        void OnResizeRemoveCoachTab(Object^ sender, EventArgs^ e)
        {
            CenterPanelInTab(tabRemoveCoach, centerPanelRemoveCoach);
        }


        Label^ CreateLabel(String^ text, int x, int y)
        {
            Label^ label = gcnew Label();
            label->Text = text;
            label->Location = Point(x, y);
            label->Font = gcnew Drawing::Font("Segoe UI", 12);
            label->AutoSize = true;
            return label;
        }

        TextBox^ CreateTextBox(int x, int y)
        {
            TextBox^ txt = gcnew TextBox();
            txt->Location = Point(x, y);
            txt->Width = 300;
            txt->Font = gcnew Drawing::Font("Segoe UI", 12);
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
            float salary = std::stof(msclr::interop::marshal_as<std::string>(txtRecSalary->Text));

            Receptionist* rec = new Receptionist(name, id, pass, salary);
			system->receptionistList[id] = *rec;
            

            dgvRec->Rows->Add(gcnew cli::array<String^> { txtRecName->Text, txtRecID->Text });

            txtRecName->Clear(); txtRecID->Clear(); txtRecPass->Clear(); txtRecSalary->Clear();
            MessageBox::Show("Receptionist added successfully.");
        }

        void RemoveReceptionist(Object^ sender, EventArgs^ e)
        {
            String^ id = txtRecRemoveName->Text;
            for (int i = 0; i < dgvRec->Rows->Count - 1; i++) {
                if (dgvRec->Rows[i]->Cells[1]->Value->ToString() == id) {
                    dgvRec->Rows->RemoveAt(i);
                    break;
                }
            }
            auto it = system->receptionistList.find(msclr::interop::marshal_as<std::string>(id));
            if (it != system->receptionistList.end()) {
                system->receptionistList.erase(it);
                MessageBox::Show("Receptionist removed successfully.");
                return;
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
            float salary = std::stof(msclr::interop::marshal_as<std::string>(txtCoachSalary->Text));

            Coatch* coach = new Coatch(name, id, pass, salary);
			system->coatchList[id] = *coach;

            dgvRec->Rows->Add(gcnew cli::array<String^, 1> { txtRecName->Text, txtRecID->Text });

            txtCoachName->Clear(); txtCoachID->Clear(); txtCoachPass->Clear(); txtCoachSalary->Clear();
            MessageBox::Show("Coach added successfully.");
        }

        void RemoveCoach(Object^ sender, EventArgs^ e)
        {
            String^ id = txtCoachRemoveName->Text;
            for (int i = 0; i < dgvCoach->Rows->Count - 1; i++) {
                if (dgvCoach->Rows[i]->Cells[1]->Value->ToString() == id) {
                    dgvCoach->Rows->RemoveAt(i);
                    break;
                }
            }
			auto it = system->coatchList.find(msclr::interop::marshal_as<std::string>(id));
            if (it != system->coatchList.end()) {
				system->coatchList.erase(it);
				MessageBox::Show("Coach removed successfully.");
				return;
            }
            MessageBox::Show("Coach not found.");
        }
        System::Void btnLogOut_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
