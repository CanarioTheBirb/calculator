#include "ButtonFactory.h"
wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString label,const wxPoint position, const wxSize size)
{
	wxButton* button = new wxButton(parent,id,label,position,size);
	return button;
}

wxButton* ButtonFactory::CreateAddButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1021, "+", wxPoint(310, 160), wxSize(60, 35));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateMinusButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1020, "-",wxPoint(310,110),wxSize(60,35));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateEqualButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1024, "=", wxPoint(310, 310), wxSize(60, 35));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}
wxButton* ButtonFactory::CreateDivideButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1023, "/", wxPoint(310, 260), wxSize(60, 35));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}
wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1022, "*", wxPoint(310, 210), wxSize(60, 35));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}
wxButton* ButtonFactory::CreateModButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1005, "%", wxPoint(190, 70), wxSize(55, 30));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}
wxButton* ButtonFactory::Create1Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1014, "1", wxPoint(10, 230), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create2Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1015, "2", wxPoint(110, 230), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create3Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1016, "3", wxPoint(210, 230), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create4Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1011, "4", wxPoint(10, 170), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create5Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1012, "5", wxPoint(110, 170), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create6Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1013, "6", wxPoint(210, 170), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create7Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1008, "7", wxPoint(10, 110), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create8Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1009, "8", wxPoint(110, 110), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create9Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1010, "9", wxPoint(210, 110), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::Create0Button(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1018, "0", wxPoint(110, 290), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1002, "sin", wxPoint(10, 70), wxSize(55, 30));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1004, "cos", wxPoint(130, 70), wxSize(55, 30));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1003, "tan", wxPoint(70, 70), wxSize(55, 30));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1017, "+/-", wxPoint(10, 290), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateDotButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1019, ".", wxPoint(210, 290), wxSize(90, 55));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1006, "C", wxPoint(250, 70), wxSize(55, 30));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}

wxButton* ButtonFactory::CreateDeleteButton(wxWindow* parent)
{
	wxButton* button = ButtonFactory::CreateButton(parent, 1007, "Delete", wxPoint(310, 70), wxSize(60, 30));
	button->SetFont(button->GetFont().Scale(1.5));
	return button;
}