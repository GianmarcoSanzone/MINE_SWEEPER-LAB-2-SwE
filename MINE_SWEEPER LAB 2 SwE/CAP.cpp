#include "CAP.h"

wxIMPLEMENT_APP(CAP);

CAP::CAP()
{

}

CAP::~CAP()
{

}

bool CAP::OnInit()
{
	m_frame1 = new MAN();
	m_frame1->Show();
	return true;
}
