#pragma once
#include "wx/wx.h"

class MAN : public wxFrame
{
public:
	MAN();
	~MAN();

public:
	//wxButton *m_btn1 = nullptr;
	//wxTextCtrl *m_txt1 = nullptr;
	//wxListBox *m_list1 = nullptr;

	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;

	int* nfield = nullptr;
	bool bfirstclick = true;

	void OnButtonClicked(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};


