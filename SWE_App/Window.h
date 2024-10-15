#pragma once
#include "wx/wx.h"
class Window : public wxFrame
{
	wxButton* zeroButton = nullptr;
	wxButton* oneButton = nullptr;
	wxButton* twoButton = nullptr;
	wxButton* threeButton = nullptr; 
	wxButton* fourButton = nullptr;
	wxButton* fiveButton = nullptr;
	wxButton* sixButton = nullptr;
	wxButton* sevenButton = nullptr;
	wxButton* eightButton = nullptr;
	wxButton* nineButton = nullptr;
	wxButton* plusButton = nullptr;
	wxButton* minusButton = nullptr;
	wxButton* divideButton = nullptr;
	wxButton* multiplyButton = nullptr;
	wxButton* equalButton = nullptr;
	wxButton* clearButton = nullptr;
	wxButton* backButton = nullptr;
	wxButton* modButton = nullptr;
	wxButton* dotButton = nullptr;
	wxButton* sinButton = nullptr;
	wxButton* cosButton = nullptr;
	wxButton* tanButton = nullptr;
	wxButton* negativeButton = nullptr;

	wxTextCtrl* textBox = nullptr;
public:
	Window();
	void OnButtonClick(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

