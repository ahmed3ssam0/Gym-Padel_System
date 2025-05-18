#pragma once
#include "Coatch.h"
#include "RemoveSession.h" 
#include "Home2.h"
#include "Add_Sessions.h"
#include "PlanForm.h"
#include "RemovePlan.h"
#include "System.h"
#include "Register.h"

namespace gymproject {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class coachForm : public System::Windows::Forms::Form
    {
    private:
        Coatch* currentCoach;
        SystemManager* sysmanager;
        TabControl^ tabControl;
        TabPage^ tabHome;
        TabPage^ tabAddSession;
        TabPage^ tabPlan;
        TabPage^ tabRemovePlan;
        TabPage^ tabRemoveSession;

        Home2^ homeTab;
        AddSession^ addSessionTab;
        wPlan^ planTab;
        RemoveWorkoutPlan^ removePlanTab;
        RemoveSession^ removeSessionTab;

    public:
        coachForm(Coatch* coach)
        {
            currentCoach = coach;
            InitializeComponent();
        }

    private:
        void InitializeComponent(void)
        {
            this->Text = "Coach Dashboard";
            this->Size = Drawing::Size(800, 600);
            this->StartPosition = FormStartPosition::CenterScreen;
  
            // Initialize tab control
            tabControl = gcnew TabControl();
            tabControl->Dock = DockStyle::Fill;
            tabControl->Size = System::Drawing::Size(800, 600);
            tabControl->Location = System::Drawing::Point(0, 0);
            tabControl->TabIndex = 0;
            tabControl->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Regular, GraphicsUnit::Point, 0);
            tabControl->ItemSize = System::Drawing::Size(100, 30);

            // Initialize tab pages
            tabHome = gcnew TabPage("Home");
            tabAddSession = gcnew TabPage("Add Session");
            tabPlan = gcnew TabPage("Workout Plan");
            tabRemovePlan = gcnew TabPage("Remove Plan");
            tabRemoveSession = gcnew TabPage("Remove Session");

            // Initialize tab content
            homeTab = gcnew Home2(currentCoach);
            addSessionTab = gcnew AddSession(currentCoach);
            planTab = gcnew wPlan(currentCoach);
            removePlanTab = gcnew RemoveWorkoutPlan(currentCoach);
            removeSessionTab = gcnew RemoveSession(currentCoach);

            // Set dock style for all tabs
            homeTab->Dock = DockStyle::Fill;
            addSessionTab->Dock = DockStyle::Fill;
            planTab->Dock = DockStyle::Fill;
            removePlanTab->Dock = DockStyle::Fill;
            removeSessionTab->Dock = DockStyle::Fill;

            // Add controls to tab pages
            tabHome->Controls->Add(homeTab);
            tabAddSession->Controls->Add(addSessionTab);
            tabPlan->Controls->Add(planTab);
            tabRemovePlan->Controls->Add(removePlanTab);
            tabRemoveSession->Controls->Add(removeSessionTab);

            // Add tab pages to tab control
            tabControl->TabPages->Add(tabHome);
            tabControl->TabPages->Add(tabAddSession);
            tabControl->TabPages->Add(tabRemoveSession);
            tabControl->TabPages->Add(tabPlan);
            tabControl->TabPages->Add(tabRemovePlan);

            // Add controls to form
            this->Controls->Add(tabControl);
        }

    };
}