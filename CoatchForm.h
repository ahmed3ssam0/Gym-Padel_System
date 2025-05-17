#pragma once
#include "Coatch.h"
#include "PlanForm.h"
#include "Add_Sessions.h"
#include "Home2.h"

namespace gymproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class CoatchForm : public System::Windows::Forms::Form
    {
	private:
		Coatch* currentCoach;
		Home2^ homeTab;
		Add_Sessions^ addSessionTab;
		PlanForm^ workoutPlanTab;
    public:
        CoatchForm(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
            homeTab = gcnew Home2(currentCoach);
            addSessionTab = gcnew Add_Sessions(currentCoach);
            workoutPlanTab = gcnew PlanForm(currentCoach);

            // Embed your user controls inside tab pages
            homeTab->Dock = DockStyle::Fill;
            addSessionTab->Dock = DockStyle::Fill;
            workoutPlanTab->Dock = DockStyle::Fill;

            this->tabHome->Controls->Add(homeTab);
            this->tabAddSession->Controls->Add(addSessionTab);
            this->tabWorkout->Controls->Add(workoutPlanTab);
        }

    protected:
        ~CoatchForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TabControl^ tabControl1;
    protected:
    private: System::Windows::Forms::TabPage^ tabHome;
    private: System::Windows::Forms::TabPage^ tabAddSession;
    private: System::Windows::Forms::TabPage^ tabWorkout;




    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabHome = (gcnew System::Windows::Forms::TabPage());
            this->tabAddSession = (gcnew System::Windows::Forms::TabPage());
            this->tabWorkout = (gcnew System::Windows::Forms::TabPage());
            this->tabControl1->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabHome);
            this->tabControl1->Controls->Add(this->tabAddSession);
            this->tabControl1->Controls->Add(this->tabWorkout);
            this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabControl1->Location = System::Drawing::Point(0, 0);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(800, 500);
            this->tabControl1->TabIndex = 0;
            // 
            // tabHome
            // 
            this->tabHome->Location = System::Drawing::Point(4, 22);
            this->tabHome->Name = L"tabHome";
            this->tabHome->Padding = System::Windows::Forms::Padding(3);
            this->tabHome->Size = System::Drawing::Size(792, 474);
            this->tabHome->TabIndex = 0;
            this->tabHome->Text = L"tabPage1";
            this->tabHome->UseVisualStyleBackColor = true;
            // 
            // tabAddSession
            // 
            this->tabAddSession->Location = System::Drawing::Point(4, 22);
            this->tabAddSession->Name = L"tabAddSession";
            this->tabAddSession->Padding = System::Windows::Forms::Padding(3);
            this->tabAddSession->Size = System::Drawing::Size(581, 376);
            this->tabAddSession->TabIndex = 1;
            this->tabAddSession->Text = L"tabPage2";
            this->tabAddSession->UseVisualStyleBackColor = true;
            // 
            // tabWorkout
            // 
            this->tabWorkout->Location = System::Drawing::Point(4, 22);
            this->tabWorkout->Name = L"tabWorkout";
            this->tabWorkout->Size = System::Drawing::Size(581, 376);
            this->tabWorkout->TabIndex = 2;
            this->tabWorkout->Text = L"tabPage3";
            this->tabWorkout->UseVisualStyleBackColor = true;
            // 
            // CoatchForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 500);
            this->Controls->Add(this->tabControl1);
            this->Name = L"CoatchForm";
            this->Text = L"CoatchForm";
            this->tabControl1->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}
