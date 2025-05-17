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


    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ workoutIntensity;

    private: System::Windows::Forms::TextBox^ workoutName;
    private: System::Windows::Forms::NumericUpDown^ hours;


    private: System::Windows::Forms::TextBox^ workoutType;
    private: System::Windows::Forms::NumericUpDown^ lost;
    private: System::Windows::Forms::DataGridView^ workoutPlanDataGridView;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ sessionName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ intensity;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ hoursper1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ lostC;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;














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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->workoutIntensity = (gcnew System::Windows::Forms::TextBox());
            this->workoutName = (gcnew System::Windows::Forms::TextBox());
            this->hours = (gcnew System::Windows::Forms::NumericUpDown());
            this->workoutType = (gcnew System::Windows::Forms::TextBox());
            this->lost = (gcnew System::Windows::Forms::NumericUpDown());
            this->workoutPlanDataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->sessionName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->intensity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->hoursper1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->lostC = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hours))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lost))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workoutPlanDataGridView))->BeginInit();
            this->SuspendLayout();
            // 
            // txtSession
            // 
            this->txtSession->Location = System::Drawing::Point(300, 258);
            this->txtSession->Name = L"txtSession";
            this->txtSession->Size = System::Drawing::Size(259, 20);
            this->txtSession->TabIndex = 0;
            // 
            // btnAssignWorkout
            // 
            this->btnAssignWorkout->Location = System::Drawing::Point(331, 463);
            this->btnAssignWorkout->Name = L"btnAssignWorkout";
            this->btnAssignWorkout->Size = System::Drawing::Size(136, 30);
            this->btnAssignWorkout->TabIndex = 2;
            this->btnAssignWorkout->Text = L"Add Workout Plan";
            this->btnAssignWorkout->UseVisualStyleBackColor = true;
            this->btnAssignWorkout->Click += gcnew System::EventHandler(this, &PlanForm::btnAssignWorkout_Click_1);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(218, 261);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(76, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Seesion Name";
            // 
            // workoutIntensity
            // 
            this->workoutIntensity->Location = System::Drawing::Point(300, 336);
            this->workoutIntensity->Name = L"workoutIntensity";
            this->workoutIntensity->Size = System::Drawing::Size(259, 20);
            this->workoutIntensity->TabIndex = 5;
            // 
            // workoutName
            // 
            this->workoutName->Location = System::Drawing::Point(300, 284);
            this->workoutName->Name = L"workoutName";
            this->workoutName->Size = System::Drawing::Size(259, 20);
            this->workoutName->TabIndex = 6;
            // 
            // hours
            // 
            this->hours->DecimalPlaces = 2;
            this->hours->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
            this->hours->Location = System::Drawing::Point(347, 376);
            this->hours->Name = L"hours";
            this->hours->Size = System::Drawing::Size(120, 20);
            this->hours->TabIndex = 7;
            // 
            // workoutType
            // 
            this->workoutType->Location = System::Drawing::Point(300, 310);
            this->workoutType->Name = L"workoutType";
            this->workoutType->Size = System::Drawing::Size(259, 20);
            this->workoutType->TabIndex = 8;
            // 
            // lost
            // 
            this->lost->Location = System::Drawing::Point(347, 412);
            this->lost->Name = L"lost";
            this->lost->Size = System::Drawing::Size(120, 20);
            this->lost->TabIndex = 9;
            // 
            // workoutPlanDataGridView
            // 
            this->workoutPlanDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->workoutPlanDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->sessionName,
                    this->name, this->type, this->intensity, this->hoursper1, this->lostC
            });
            this->workoutPlanDataGridView->Location = System::Drawing::Point(137, 34);
            this->workoutPlanDataGridView->Name = L"workoutPlanDataGridView";
            this->workoutPlanDataGridView->Size = System::Drawing::Size(551, 195);
            this->workoutPlanDataGridView->TabIndex = 10;
            // 
            // sessionName
            // 
            this->sessionName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->sessionName->HeaderText = L"Session Name";
            this->sessionName->Name = L"sessionName";
            this->sessionName->ReadOnly = true;
            // 
            // name
            // 
            this->name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->name->HeaderText = L"Workout Name";
            this->name->Name = L"name";
            this->name->ReadOnly = true;
            // 
            // type
            // 
            this->type->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->type->HeaderText = L"Workout Type";
            this->type->Name = L"type";
            this->type->ReadOnly = true;
            // 
            // intensity
            // 
            this->intensity->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->intensity->HeaderText = L"Workout Intensity";
            this->intensity->Name = L"intensity";
            this->intensity->ReadOnly = true;
            // 
            // hoursper1
            // 
            this->hoursper1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->hoursper1->HeaderText = L"Hours";
            this->hoursper1->Name = L"hoursper1";
            this->hoursper1->ReadOnly = true;
            // 
            // lostC
            // 
            this->lostC->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
            this->lostC->HeaderText = L"Lost Calories";
            this->lostC->Name = L"lostC";
            this->lostC->ReadOnly = true;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(215, 287);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(79, 13);
            this->label2->TabIndex = 11;
            this->label2->Text = L"Workout Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(219, 313);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(75, 13);
            this->label3->TabIndex = 12;
            this->label3->Text = L"Workout Type";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(204, 339);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(90, 13);
            this->label4->TabIndex = 13;
            this->label4->Text = L"Workout Intensity";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(306, 378);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(35, 13);
            this->label5->TabIndex = 14;
            this->label5->Text = L"Hours";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(274, 414);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(67, 13);
            this->label6->TabIndex = 15;
            this->label6->Text = L"Lost Calories";
            // 
            // PlanForm
            // 
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->workoutPlanDataGridView);
            this->Controls->Add(this->lost);
            this->Controls->Add(this->workoutType);
            this->Controls->Add(this->hours);
            this->Controls->Add(this->workoutName);
            this->Controls->Add(this->workoutIntensity);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnAssignWorkout);
            this->Controls->Add(this->txtSession);
            this->Name = L"PlanForm";
            this->Size = System::Drawing::Size(849, 523);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hours))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lost))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workoutPlanDataGridView))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }


        void LoadWorkoutPlans()
        {
            if (currentCoach == nullptr) return;

            workoutPlanDataGridView->Rows->Clear();
            auto& plans = currentCoach->getCoatchWorkoutPlans();
			auto& sessions = currentCoach->getClassAssignments();
            for (auto& s : sessions)
            {
				String^ sessionName = gcnew String(s.getName().c_str());
				auto& workoutPlans = s.getClassWorkoutPlans();
				for (auto& plan : workoutPlans)
				{
					String^ workoutName = gcnew String(plan.getName().c_str());
					String^ workoutType = gcnew String(plan.getType().c_str());
					String^ workoutIntensity = gcnew String(plan.getIntensity().c_str());
					String^ hours = gcnew String(std::to_string(plan.getHoursPerDay()).c_str());
					String^ lostCalories = gcnew String(std::to_string(plan.getLostCalories()).c_str());
					workoutPlanDataGridView->Rows->Add(sessionName);
					workoutPlanDataGridView->Rows->Add(workoutName);
					workoutPlanDataGridView->Rows->Add(workoutType);
					workoutPlanDataGridView->Rows->Add(workoutIntensity);
					workoutPlanDataGridView->Rows->Add(hours);
					workoutPlanDataGridView->Rows->Add(lostCalories);

				}
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