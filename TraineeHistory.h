#pragma once
#include "Trainee.h"

namespace gymproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TraineeHistory
	/// </summary>
	public ref class TraineeHistory : public System::Windows::Forms::Form
	{
	private: Trainee* trainee;
	public:

        TraineeHistory(Trainee* trainee)
        {
           InitializeComponent();
           this->trainee = trainee;
           list<WorkoutPlan> workoutHistory = trainee->getWorkoutHistory();
           for (auto& workout : workoutHistory) {
               // Use msclr::interop to convert std::string to System::String
               String^ name = gcnew String(workout.getName().c_str());
               String^ type = gcnew String(workout.getType().c_str());
               String^ intensity = gcnew String(workout.getIntensity().c_str());

               dataGridView1->Rows->Add(name, workout.getHoursPerDay(), type, intensity, workout.getLostCalories());
           }
        }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TraineeHistory()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ hours;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ intensity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ lost;












	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->hours = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->intensity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->name, this->hours,
					this->type, this->intensity, this->lost
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Top;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(723, 282);
			this->dataGridView1->TabIndex = 0;
			// 
			// name
			// 
			this->name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->name->HeaderText = L"Name";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			// 
			// hours
			// 
			this->hours->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->hours->HeaderText = L"Hours Per Day";
			this->hours->Name = L"hours";
			this->hours->ReadOnly = true;
			// 
			// type
			// 
			this->type->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->type->HeaderText = L"Type";
			this->type->Name = L"type";
			this->type->ReadOnly = true;
			// 
			// intensity
			// 
			this->intensity->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->intensity->HeaderText = L"Intensity";
			this->intensity->Name = L"intensity";
			this->intensity->ReadOnly = true;
			// 
			// lost
			// 
			this->lost->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->lost->HeaderText = L"Lost Calories";
			this->lost->Name = L"lost";
			this->lost->ReadOnly = true;
			// 
			// TraineeHistory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(723, 512);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"TraineeHistory";
			this->Text = L"TraineeHistory";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
