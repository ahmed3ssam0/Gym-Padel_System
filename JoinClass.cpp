#include "JoinClass.h"

#include "Home.h"
using namespace msclr::interop;

namespace gymproject {
	System::Void JoinClass::button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Home^ nextForm = gcnew Home(this->gym, this->trainee);
		nextForm->StartPosition = FormStartPosition::Manual;
		nextForm->Location = this->Location;
		nextForm->Size = this->Size;
		nextForm->BackgroundImage = this->BackgroundImage;
		nextForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
		nextForm->Show();
		this->Hide();
	}
	System::Void JoinClass::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string className = marshal_as<string>(comboBox1->SelectedItem->ToString());;
		unordered_map<string, GymClass> gymClasses = gym->getGymClasses();
		auto it = gymClasses.find(className);
		if (it != gymClasses.end()) {
			it->second.addTraineeToClass(*trainee);
			MessageBox::Show("You have successfully joined the class: " + gcnew String(className.c_str()));
		}
		else {
			MessageBox::Show("Class not found!");
		}
	}
}