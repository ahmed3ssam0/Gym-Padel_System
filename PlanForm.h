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

    public ref class wPlan : public UserControl
    {
    private:
        Coatch* currentCoach;

    public:
        wPlan(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    protected:
        ~wPlan()
        {
            if (components)
                delete components;
        }

    private:
        TextBox^ txtSession;
        TextBox^ txtWorkoutPlan;
        TextBox^ txtHoursPerDay;
        TextBox^ txtIntensity;
        TextBox^ txtLostCalories;
        Button^ btnSave;
        Label^ lblSession;
        Label^ lblWorkoutPlan;
        Label^ lblHours;
        Label^ lblIntensity;
        Label^ lblCalories;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            txtSession = gcnew TextBox();
            txtWorkoutPlan = gcnew TextBox();
            txtHoursPerDay = gcnew TextBox();
            txtIntensity = gcnew TextBox();
            txtLostCalories = gcnew TextBox();
            btnSave = gcnew Button();

            lblSession = gcnew Label();
            lblWorkoutPlan = gcnew Label();
            lblHours = gcnew Label();
            lblIntensity = gcnew Label();
            lblCalories = gcnew Label();

            int y = 20;
            int spacing = 40;

            lblSession->Text = "Session Name:";
            lblSession->Location = Point(20, y);
            txtSession->Location = Point(160, y);
            txtSession->Size = Drawing::Size(200, 22);

            y += spacing;
            lblWorkoutPlan->Text = "Workout Plan Name:";
            lblWorkoutPlan->Location = Point(20, y);
            txtWorkoutPlan->Location = Point(160, y);
            txtWorkoutPlan->Size = Drawing::Size(200, 22);

            y += spacing;
            lblHours->Text = "Hours Per Day:";
            lblHours->Location = Point(20, y);
            txtHoursPerDay->Location = Point(160, y);
            txtHoursPerDay->Size = Drawing::Size(200, 22);

            y += spacing;
            lblIntensity->Text = "Intensity:";
            lblIntensity->Location = Point(20, y);
            txtIntensity->Location = Point(160, y);
            txtIntensity->Size = Drawing::Size(200, 22);

            y += spacing;
            lblCalories->Text = "Estimated Lost Calories:";
            lblCalories->Location = Point(20, y);
            txtLostCalories->Location = Point(160, y);
            txtLostCalories->Size = Drawing::Size(200, 22);

            y += spacing + 10;
            btnSave->Text = "Save Workout Plan";
            btnSave->Location = Point(160, y);
            btnSave->Size = Drawing::Size(200, 30);
            btnSave->Click += gcnew EventHandler(this, &wPlan::btnSave_Click);

            this->Controls->Add(lblSession);
            this->Controls->Add(txtSession);
            this->Controls->Add(lblWorkoutPlan);
            this->Controls->Add(txtWorkoutPlan);
            this->Controls->Add(lblHours);
            this->Controls->Add(txtHoursPerDay);
            this->Controls->Add(lblIntensity);
            this->Controls->Add(txtIntensity);
            this->Controls->Add(lblCalories);
            this->Controls->Add(txtLostCalories);
            this->Controls->Add(btnSave);

            this->Size = Drawing::Size(600, 400);
        }

        void btnSave_Click(Object^ sender, EventArgs^ e)
        {
            String^ sessionName = txtSession->Text->Trim();
            String^ planName = txtWorkoutPlan->Text->Trim();
            String^ hoursStr = txtHoursPerDay->Text->Trim();
            String^ intensityStr = txtIntensity->Text->Trim();
            String^ caloriesStr = txtLostCalories->Text->Trim();

            if (sessionName == "" || planName == "" || hoursStr == "" || intensityStr == "" || caloriesStr == "")
            {
                MessageBox::Show("Please fill in all fields.", "Missing Data", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            try
            {

                std::string sessionStd = msclr::interop::marshal_as<std::string>(sessionName);
                std::string planStd = msclr::interop::marshal_as<std::string>(planName);
                float hours = std::stof(msclr::interop::marshal_as<std::string>(hoursStr));
                std::string intensity = msclr::interop::marshal_as<std::string>(intensityStr);
                float lostCalories = std::stof(msclr::interop::marshal_as<std::string>(caloriesStr));

                WorkoutPlan wp(planStd, hours, intensity, lostCalories, sessionStd);

                std::list<GymClass>& sessions = currentCoach->getClassAssignments();
                bool found = false;
                for (auto& s : sessions)
                {
                    if (s.getName() == sessionStd)
                    {
                        s.addWorkoutPlan(wp);
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    MessageBox::Show("Workout Plan assigned successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    txtSession->Clear();
                    txtWorkoutPlan->Clear();
                    txtHoursPerDay->Clear();
                    txtIntensity->Clear();
                    txtLostCalories->Clear();
                }
                else
                {
                    MessageBox::Show("Session not found among coach's assignments.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Invalid data format.\n" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}