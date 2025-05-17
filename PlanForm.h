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
    private: System::Windows::Forms::TextBox^ txtWorkoutPlan;
    private: System::Windows::Forms::Button^ btnAssignWorkout;
    private: System::Windows::Forms::DataGridView^ workoutPlanDataGridView;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Session;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Workout;
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
            this->txtWorkoutPlan = (gcnew System::Windows::Forms::TextBox());
            this->btnAssignWorkout = (gcnew System::Windows::Forms::Button());
            this->workoutPlanDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->Session = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Workout = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workoutPlanDataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // txtSession
            // 
            this->txtSession->Location = System::Drawing::Point(296, 284);
            this->txtSession->Name = L"txtSession";
            this->txtSession->Size = System::Drawing::Size(259, 20);
            this->txtSession->TabIndex = 0;
            // 
            // txtWorkoutPlan
            // 
            this->txtWorkoutPlan->Location = System::Drawing::Point(296, 326);
            this->txtWorkoutPlan->Name = L"txtWorkoutPlan";
            this->txtWorkoutPlan->Size = System::Drawing::Size(259, 20);
            this->txtWorkoutPlan->TabIndex = 1;
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
            this->workoutPlanDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                this->Session,
                    this->Workout
            });
            this->workoutPlanDataGridView->Location = System::Drawing::Point(111, 25);
            this->workoutPlanDataGridView->Name = L"workoutPlanDataGridView";
            this->workoutPlanDataGridView->Size = System::Drawing::Size(608, 207);
            this->workoutPlanDataGridView->TabIndex = 3;
            // 
            // Session
            // 
            this->Session->HeaderText = L"Session";
            this->Session->Name = L"Session";
            this->Session->ReadOnly = true;
            this->Session->Width = 200;
            // 
            // Workout
            // 
            this->Workout->HeaderText = L"Workout";
            this->Workout->Name = L"Workout";
            this->Workout->ReadOnly = true;
            this->Workout->Width = 200;
            // 
            // PlanForm
            // 
            this->ClientSize = System::Drawing::Size(849, 523);
            this->Controls->Add(this->workoutPlanDataGridView);
            this->Controls->Add(this->btnAssignWorkout);
            this->Controls->Add(this->txtWorkoutPlan);
            this->Controls->Add(this->txtSession);
            this->Name = L"PlanForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workoutPlanDataGridView))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


        void LoadWorkoutPlans()
        {
            if (currentCoach == nullptr) return;

            workoutPlanDataGridView->Rows->Clear();
            auto& plans = currentCoach->getWorkoutPlans();
            for (auto& p : plans)
            {
                String^ sName = gcnew String(p.first.c_str());
                String^ plan = gcnew String(p.second.c_str());
                workoutPlanDataGridView->Rows->Add(sName, plan);
            }
        }
    private: System::Void btnAssignWorkout_Click_1(System::Object^ sender, System::EventArgs^ e) {
        String^ session = txtSession->Text->Trim();
        String^ workout = txtWorkoutPlan->Text->Trim();

        if (session != "" && workout != "")
        {
            workoutPlanDataGridView->Rows->Add(session, workout);

            if (currentCoach != nullptr)
            {
                std::string stdSession = msclr::interop::marshal_as<std::string>(session);
                std::string stdWorkout = msclr::interop::marshal_as<std::string>(workout);
                currentCoach->assignWorkoutPlan(stdSession, stdWorkout);
            }

            txtSession->Clear();
            txtWorkoutPlan->Clear();
        }
        else
        {
            MessageBox::Show("Please enter both a session and a workout plan.", "Missing Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }
};
}