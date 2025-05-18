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

    public ref class RemoveWorkoutPlan : public UserControl
    {
    private:
        Coatch* currentCoach;
        Label^ lblSessionName;
        TextBox^ txtSessionName;
        Label^ lblWorkoutName;
        TextBox^ txtWorkoutName;
        Button^ btnRemove;

    public:
        RemoveWorkoutPlan(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            lblSessionName = gcnew Label();
            lblWorkoutName = gcnew Label();
            txtSessionName = gcnew TextBox();
            txtWorkoutName = gcnew TextBox();
            btnRemove = gcnew Button();

            lblSessionName->Text = "Session Name:";
            lblSessionName->Location = Point(30, 30);
            lblSessionName->Size = Drawing::Size(100, 20);

            txtSessionName->Location = Point(150, 30);
            txtSessionName->Size = Drawing::Size(200, 22);

            lblWorkoutName->Text = "Workout Plan Name:";
            lblWorkoutName->Location = Point(30, 70);
            lblWorkoutName->Size = Drawing::Size(120, 20);

            txtWorkoutName->Location = Point(150, 70);
            txtWorkoutName->Size = Drawing::Size(200, 22);

            btnRemove->Text = "Remove Plan";
            btnRemove->Location = Point(150, 110);
            btnRemove->Size = Drawing::Size(120, 30);
            btnRemove->Click += gcnew EventHandler(this, &RemoveWorkoutPlan::btnRemove_Click);

            this->Controls->Add(lblSessionName);
            this->Controls->Add(txtSessionName);
            this->Controls->Add(lblWorkoutName);
            this->Controls->Add(txtWorkoutName);
            this->Controls->Add(btnRemove);
            this->Size = Drawing::Size(600, 200);
        }

        void btnRemove_Click(Object^ sender, EventArgs^ e)
        {
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
                    gclass.removeWorkoutPlan(stdWorkout);
                    found = true;
                    break;
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