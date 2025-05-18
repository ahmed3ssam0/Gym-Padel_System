#include "Home2.h"
#include "Login1.h"

namespace gymproject {
	System::Void Home2::logoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Login1^ nextForm = gcnew Login1(system);
		nextForm->StartPosition = FormStartPosition::Manual;
		nextForm->Location = this->Location;
		nextForm->Size = this->Size;
		nextForm->BackgroundImage = this->BackgroundImage;
		nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		nextForm->Show();
		this->Hide();
	}
	System::Void Home2::reButton_Click(System::Object^ sender, System::EventArgs^ e) {
		loadSessions();
	}

	
}