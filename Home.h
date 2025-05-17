#pragma once
#include "JoinClass.h"
#include "RenewSubscription.h"
#include "BookCourt.h"
namespace gymproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	static System::Drawing::Image^ cachedBackground = nullptr;
	private: Gym* gym;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Button^ button1;
	private: Trainee* trainee;
	private: Padel* padel;
	public:
		Home(Gym* gym, Trainee* trainee)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			this->gym = gym;
			this->trainee = trainee;
			this->WindowState = FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			if (cachedBackground == nullptr)
				cachedBackground = System::Drawing::Image::FromFile("C:\\Users\\Islam\\Downloads\\6725081-Photoroom.png");

			this->BackgroundImage = cachedBackground;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			tabPage1->Controls->Add(gcnew JoinClass(gym, trainee));
			tabPage2->Controls->Add(gcnew RenewSubscription(trainee));
			tabPage3->Controls->Add(gcnew ava_court(padel, trainee));

		}
		Home(Gym* gym)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			this->gym = gym;
			this->WindowState = FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			if (cachedBackground == nullptr)
				cachedBackground = System::Drawing::Image::FromFile("C:\\Users\\Islam\\Downloads\\6725081-Photoroom.png");

			this->BackgroundImage = cachedBackground;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;

		}
		Home(void)
		{
			InitializeComponent();
			this->WindowState = FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			if (cachedBackground == nullptr)
				cachedBackground = System::Drawing::Image::FromFile("background.jpg");

			this->BackgroundImage = cachedBackground;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->label1->Text = L"Welcome Trainee " + gcnew System::String(trainee->getName().c_str());

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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;







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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1169, 163);
			this->panel1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"PT Bold Heading", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label1->ForeColor = System::Drawing::Color::Snow;
			this->label1->Location = System::Drawing::Point(12, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(276, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome Trainee ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->tabControl1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 163);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1169, 500);
			this->panel2->TabIndex = 2;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1169, 500);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1161, 474);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Join Class";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1161, 474);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Renew Subscription";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1161, 474);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Book a Padel Court";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1161, 474);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"View Workout History";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1028, 73);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Logout";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1169, 663);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
};
}
