#pragma once
#include "wx/wx.h"
class ButtonFactory
{
	static wxButton* CreateButton(wxWindow* parent, wxWindowID id, const wxString label, const wxPoint position, const wxSize size);
public:
	static wxButton* CreateAddButton(wxWindow* parent);
	static wxButton* CreateMinusButton(wxWindow* parent);
	static wxButton* CreateEqualButton(wxWindow* parent);
	static wxButton* CreateDivideButton(wxWindow* parent);
	static wxButton* CreateMultiplyButton(wxWindow* parent);
	static wxButton* CreateModButton(wxWindow* parent);
	static wxButton* Create1Button(wxWindow* parent);
	static wxButton* Create2Button(wxWindow* parent);
	static wxButton* Create3Button(wxWindow* parent);
	static wxButton* Create4Button(wxWindow* parent);
	static wxButton* Create5Button(wxWindow* parent);
	static wxButton* Create6Button(wxWindow* parent);
	static wxButton* Create7Button(wxWindow* parent);
	static wxButton* Create8Button(wxWindow* parent);
	static wxButton* Create9Button(wxWindow* parent);
	static wxButton* Create0Button(wxWindow* parent);
	static wxButton* CreateSinButton(wxWindow* parent);
	static wxButton* CreateCosButton(wxWindow* parent);
	static wxButton* CreateTanButton(wxWindow* parent);
	static wxButton* CreateNegativeButton(wxWindow* parent);
	static wxButton* CreateDotButton(wxWindow* parent);
	static wxButton* CreateClearButton(wxWindow* parent);
	static wxButton* CreateDeleteButton(wxWindow* parent);
};

