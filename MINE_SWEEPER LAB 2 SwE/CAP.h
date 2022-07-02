#pragma once

#include "wx/wx.h"
#include "MAN.h"
class CAP : public wxApp
{
public:
	CAP();
	~CAP();
	
private:
	MAN* m_frame1 = nullptr;

public:

	virtual bool OnInit();
};

