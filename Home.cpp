#include "Home.h"
#include "Login1.h"

using namespace gymproject;

System::Void Home::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Login1^ nextForm = gcnew Login1(sys, padel);
	nextForm->StartPosition = FormStartPosition::Manual;
	nextForm->Location = this->Location;
	nextForm->Size = this->Size;
	nextForm->BackgroundImage = this->BackgroundImage;
	nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	nextForm->Show();
	this->Hide();
}