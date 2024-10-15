#include "Window.h"
#include "ButtonFactory.h"
#include "CalculatorProcess.h"
wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(1002, Window::OnButtonClick)
EVT_BUTTON(1003, Window::OnButtonClick)
EVT_BUTTON(1004, Window::OnButtonClick)
EVT_BUTTON(1005, Window::OnButtonClick)
EVT_BUTTON(1006, Window::OnButtonClick)
EVT_BUTTON(1007, Window::OnButtonClick)
EVT_BUTTON(1008, Window::OnButtonClick)
EVT_BUTTON(1009, Window::OnButtonClick)
EVT_BUTTON(1010, Window::OnButtonClick)
EVT_BUTTON(1011, Window::OnButtonClick)
EVT_BUTTON(1012, Window::OnButtonClick)
EVT_BUTTON(1013, Window::OnButtonClick)
EVT_BUTTON(1014, Window::OnButtonClick)
EVT_BUTTON(1015, Window::OnButtonClick)
EVT_BUTTON(1016, Window::OnButtonClick)
EVT_BUTTON(1017, Window::OnButtonClick)
EVT_BUTTON(1018, Window::OnButtonClick)
EVT_BUTTON(1019, Window::OnButtonClick)
EVT_BUTTON(1020, Window::OnButtonClick)
EVT_BUTTON(1021, Window::OnButtonClick)
EVT_BUTTON(1022, Window::OnButtonClick)
EVT_BUTTON(1023, Window::OnButtonClick)
EVT_BUTTON(1024, Window::OnButtonClick)
wxEND_EVENT_TABLE()
Window::Window() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(500, 500), wxSize(400, 400))
{
	textBox = new wxTextCtrl(this, 1001, "", wxPoint(10, 10), wxSize(360, 50), wxTE_RIGHT | wxTE_READONLY);
	textBox->SetFont(textBox->GetFont().Scale(2.0));

	oneButton = ButtonFactory::Create1Button(this);
	twoButton = ButtonFactory::Create2Button(this);
	threeButton = ButtonFactory::Create3Button(this);

	fourButton = ButtonFactory::Create4Button(this);
	fiveButton = ButtonFactory::Create5Button(this);
	sixButton = ButtonFactory::Create6Button(this);

	sevenButton = ButtonFactory::Create7Button(this);
	eightButton = ButtonFactory::Create8Button(this);
	nineButton = ButtonFactory::Create9Button(this);

	negativeButton = ButtonFactory::CreateNegativeButton(this);
	zeroButton = ButtonFactory::Create0Button(this);
	dotButton = ButtonFactory::CreateDotButton(this);

	sinButton = ButtonFactory::CreateSinButton(this);
	tanButton = ButtonFactory::CreateTanButton(this);
	cosButton = ButtonFactory::CreateCosButton(this);
	modButton = ButtonFactory::CreateModButton(this);

	clearButton = ButtonFactory::CreateClearButton(this);
	backButton = ButtonFactory::CreateDeleteButton(this);

	negativeButton = ButtonFactory::CreateMinusButton(this);
	plusButton = ButtonFactory::CreateAddButton(this);
	multiplyButton = ButtonFactory::CreateMultiplyButton(this);
	divideButton = ButtonFactory::CreateDivideButton(this);
	equalButton = ButtonFactory::CreateEqualButton(this);
}
void Window::OnButtonClick(wxCommandEvent& evt)
{
	wxButton* calledButton = static_cast<wxButton*>(evt.GetEventObject());

	CalculatorProcess* calculator = CalculatorProcess::getInstance();
	calculator->SetLabel(calledButton->GetLabel());
	calculator->SetText(textBox->GetValue());
	calculator->Process();

	textBox->SetValue(calculator->GetText());
}
