#pragma once
#include "Coatch.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <vector>

namespace gymproject {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace msclr::interop;

    public ref class RemoveWorkoutPlan : public UserControl
    {
    private: Coatch* currentCoach;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ txtSessionName;

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ txtWorkoutName;

    private: System::Windows::Forms::Label^ label3;

    public:
        RemoveWorkoutPlan(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->txtSessionName = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->txtWorkoutName = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(271, 67);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(284, 31);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Remove Workout Plan";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(216, 178);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(75, 13);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Session Name";
            // 
            // txtSessionName
            // 
            this->txtSessionName->Location = System::Drawing::Point(297, 175);
            this->txtSessionName->Name = L"txtSessionName";
            this->txtSessionName->Size = System::Drawing::Size(246, 20);
            this->txtSessionName->TabIndex = 2;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(373, 291);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Remove";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &RemoveWorkoutPlan::button1_Click);
            // 
            // txtWorkoutName
            // 
            this->txtWorkoutName->Location = System::Drawing::Point(297, 229);
            this->txtWorkoutName->Name = L"txtWorkoutName";
            this->txtWorkoutName->Size = System::Drawing::Size(246, 20);
            this->txtWorkoutName->TabIndex = 4;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(188, 232);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(103, 13);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Workout Plan Name";
            // 
            // RemoveWorkoutPlan
            // 
            this->Controls->Add(this->label3);
            this->Controls->Add(this->txtWorkoutName);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->txtSessionName);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"RemoveWorkoutPlan";
            this->Size = System::Drawing::Size(868, 492);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ sessionName = txtSessionName->Text->Trim();
        String^ workoutName = txtWorkoutName->Text->Trim();

        if (sessionName == "" || workoutName == "")
        {
            MessageBox::Show("Please enter both session and workout plan names.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        std::string stdSession = msclr::interop::marshal_as<std::string>(sessionName);
        std::string stdWorkout = msclr::interop::marshal_as<std::string>(workoutName);
        auto& classes = currentCoach->getClassAssignments();

        bool found = false;
        for (auto& gclass : classes)
        {
            if (gclass.getName() == stdSession)
            {
                auto& workoutPlans = gclass.getClassWorkoutPlans();
                for (auto& wp : workoutPlans)
                {
                    if (wp.getName() == stdWorkout)
                    {
                        gclass.removeWorkoutPlan(wp);
						currentCoach->removeWorkoutPlan(stdWorkout);
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found)
        {
            MessageBox::Show("Workout plan removed successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            txtSessionName->Clear();
            txtWorkoutName->Clear();
        }
        else
        {
            MessageBox::Show("Session not found.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
};
}
