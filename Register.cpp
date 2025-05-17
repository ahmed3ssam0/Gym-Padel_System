#include "Register.h"
#include "Login1.h"

using namespace gymproject;
System::Void Register::nxt_form(System::Object^ sender, System::EventArgs^ e) {
	Login1^ nextForm = gcnew Login1(sys);
	nextForm->StartPosition = FormStartPosition::Manual;
	nextForm->Location = this->Location;
	nextForm->Size = this->Size;
	nextForm->BackgroundImage = this->BackgroundImage;
	nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	nextForm->Show();
	this->Hide();
}