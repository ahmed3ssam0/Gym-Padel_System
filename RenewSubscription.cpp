#include "RenewSubscription.h"
#include "Home.h"

namespace gymproject {
	System::Void RenewSubscription::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Home^ nextForm = gcnew Home();
		nextForm->StartPosition = FormStartPosition::Manual;
		nextForm->Location = this->Location;
		nextForm->Size = this->Size;
		nextForm->BackgroundImage = this->BackgroundImage;
		nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		nextForm->Show();
		this->Hide();
	}
}