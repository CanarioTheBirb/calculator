#pragma once
#include "wx/wx.h"
class CalculatorProcess
{
	wxString _equation;
	wxString _label;
	static CalculatorProcess* instance;
	CalculatorProcess();
public:
	static CalculatorProcess* getInstance();
	void SetText(wxString text);
	void SetLabel(wxString label);
	wxString GetText();
	CalculatorProcess(CalculatorProcess& other) = delete;
	void operator=(CalculatorProcess& other) = delete;
	void Process();
};

