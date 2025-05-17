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
	/// Summary for RenewSubscription
	/// </summary>
	public ref class RenewSubscription : public System::Windows::Forms::Form
	{
		Trainee* trainee;
	public:
		RenewSubscription(Trainee* trainee)
		{
			InitializeComponent();
			this->trainee = trainee;
			this->WindowState = FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		}

	protected:
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {
			if (keyData == Keys::Escape) {
				Application::Exit(); // Cleanly closes the application
				return true;         // Block further processing of the key
			}
			return Form::ProcessCmdKey(msg, keyData);
		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RenewSubscription()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(669, 565);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RenewSubscription::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(900, 565);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 31);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RenewSubscription::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::LightGray;
			this->label1->Location = System::Drawing::Point(734, 215);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(274, 33);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Renew Subscription";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(683, 388);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Period";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1461, 892);
			this->panel1->TabIndex = 5;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"3 Months", L"6 Months", L"1 Year" });
			this->comboBox1->Location = System::Drawing::Point(740, 388);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(300, 21);
			this->comboBox1->TabIndex = 5;
			// 
			// RenewSubscription
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1461, 892);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RenewSubscription";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RenewSubscription";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedPeriod = comboBox1->SelectedItem->ToString();
		int period = 0;
		if (selectedPeriod == "3 Months") {
			period = 3;
		}
		else if (selectedPeriod == "6 Months") {
			period = 6;
		}
		else if (selectedPeriod == "1 Year") {
			period = 1;
		}
		if (period > 0) {
			trainee->renew_subscription(period);
			MessageBox::Show("Subscription renewed to " + gcnew String(trainee->getSubscription().getEndDate().c_str()));

		}
		else {
			MessageBox::Show("Please select a valid period.");
		}
	}
};
}
