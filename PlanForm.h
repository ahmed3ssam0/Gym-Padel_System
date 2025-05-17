#pragma once
#include <iostream>
#include <Windows.h>
#using <System.Windows.Forms.dll>
#include "Coatch.h"
#include <msclr/marshal_cppstd.h>

namespace gymproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class PlanForm : public System::Windows::Forms::UserControl
    {
    private:
        Coatch* currentCoach;

    public:
        // Designer-safe constructor
        PlanForm()
        {
            InitializeComponent();
        }

        // Runtime constructor with coach pointer
        PlanForm(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
            LoadWorkoutPlans();
        }

    protected:
        ~PlanForm()
        {
            if (components)
                delete components;
        }
    private: System::Windows::Forms::TextBox^ txtSession;

    private: System::Windows::Forms::Button^ btnAssignWorkout;
    private: System::Windows::Forms::DataGridView^ workoutPlanDataGridView;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Workout;
    private: System::Windows::Forms::Label^ label1;


    protected:

    protected:




    private:
        /*TextBox^ txtSession;
        TextBox^ txtWorkoutPlan;
        Button^ btnAssignWorkout;
        DataGridView^ workoutPlanDataGridView;
        Label^ lblSession;
        Label^ lblWorkoutPlan;*/


           System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->txtSession = (gcnew System::Windows::Forms::TextBox());
            this->btnAssignWorkout = (gcnew System::Windows::Forms::Button());
            this->workoutPlanDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->Workout = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workoutPlanDataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // txtSession
            // 
            this->txtSession->Location = System::Drawing::Point(303, 315);
            this->txtSession->Name = L"txtSession";
            this->txtSession->Size = System::Drawing::Size(259, 20);
            this->txtSession->TabIndex = 0;
            // 
            // btnAssignWorkout
            // 
            this->btnAssignWorkout->Location = System::Drawing::Point(362, 375);
            this->btnAssignWorkout->Name = L"btnAssignWorkout";
            this->btnAssignWorkout->Size = System::Drawing::Size(136, 30);
            this->btnAssignWorkout->TabIndex = 2;
            this->btnAssignWorkout->Text = L"Add Workout Plan";
            this->btnAssignWorkout->UseVisualStyleBackColor = true;
            this->btnAssignWorkout->Click += gcnew System::EventHandler(this, &PlanForm::btnAssignWorkout_Click_1);
            // 
            // workoutPlanDataGridView
            // 
            this->workoutPlanDataGridView->AllowUserToAddRows = false;
            this->workoutPlanDataGridView->AllowUserToDeleteRows = false;
            this->workoutPlanDataGridView->AllowUserToResizeRows = false;
            this->workoutPlanDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->workoutPlanDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Workout });
            this->workoutPlanDataGridView->Location = System::Drawing::Point(111, 25);
            this->workoutPlanDataGridView->Name = L"workoutPlanDataGridView";
            this->workoutPlanDataGridView->Size = System::Drawing::Size(608, 207);
            this->workoutPlanDataGridView->TabIndex = 3;
            // 
            // Workout
            // 
            this->Workout->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->Workout->HeaderText = L"Workout";
            this->Workout->Name = L"Workout";
            this->Workout->ReadOnly = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(221, 318);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(76, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Seesion Name";
            // 
            // PlanForm
            // 
            this->Controls->Add(this->label1);
            this->Controls->Add(this->workoutPlanDataGridView);
            this->Controls->Add(this->btnAssignWorkout);
            this->Controls->Add(this->txtSession);
            this->Name = L"PlanForm";
            this->Size = System::Drawing::Size(849, 523);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workoutPlanDataGridView))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


        void LoadWorkoutPlans()
        {
            if (currentCoach == nullptr) return;

            workoutPlanDataGridView->Rows->Clear();
            auto& plans = currentCoach->getCoatchWorkoutPlans();
            for (auto& p : plans)
            {
                String^ sName = gcnew String(p.getName().c_str());
                workoutPlanDataGridView->Rows->Add(sName);
            }
        }
    private: System::Void btnAssignWorkout_Click_1(System::Object^ sender, System::EventArgs^ e) {
        String^ session = txtSession->Text->Trim();

        if (session != "")
        {
            workoutPlanDataGridView->Rows->Add(session);

            if (currentCoach != nullptr)
            {
                std::string stdSession = msclr::interop::marshal_as<std::string>(session);
                currentCoach->assignWorkoutPlan(stdSession);
            }

            txtSession->Clear();
        }
        else
        {
            MessageBox::Show("Please enter both a session and a workout plan.", "Missing Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
};
}