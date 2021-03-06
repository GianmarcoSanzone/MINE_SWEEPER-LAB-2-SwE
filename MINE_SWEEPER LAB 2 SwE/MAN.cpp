#include "MAN.h"

wxBEGIN_EVENT_TABLE(MAN, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

MAN::MAN() : wxFrame(nullptr, wxID_ANY,"MINESWEEPER.com", wxPoint(30,30), wxSize(800,600))
{
	/*m_btn1 = new wxButton(this, wxID_ANY, "CLICK", wxPoint(10,10), wxSize(150,50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 1), wxSize(300, 300));*/

	btn = new wxButton * [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

	nfield = new int[nFieldWidth * nFieldHeight];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			btn[y * nFieldWidth + x]->SetFont(font);
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MAN::OnButtonClicked, this);

			nfield[y * nFieldWidth + x] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

MAN::~MAN()
{
	delete[] btn;
}

void MAN::OnButtonClicked(wxCommandEvent &evt)
{
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;

	if (bfirstclick)
	{
		int mines = 30;

		while (mines)
		{
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHeight;

			if (nfield[ry * nFieldWidth + rx] == 0 && rx != x && ry != y)
			{
				nfield[ry * nFieldWidth + rx] = -1;
				mines--;
			}
		}

		bfirstclick = false;
	}

	/*m_list1->AppendString(m_txt1->GetValue());*/

	btn[y * nFieldWidth + x]->Enable(false);
	if (nfield[y*nFieldWidth + x] == -1)
	{
		wxMessageBox("KABLAM !!! \n GAME OVER  :(");

		bfirstclick = true;

		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{

				nfield[y * nFieldWidth + x] = 0;
				btn[y * nFieldWidth + x]->SetLabel("");
				btn[y * nFieldWidth + x]->Enable(true);
			}
		}
	}
	else
	{
		int mine_count = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x+i < nFieldWidth && y + j >= 0 && y+ j < nFieldHeight)
				{
					if (nfield[(y+j)*nFieldWidth + (x + i)] == -1)
					{
						mine_count++;
					}
				}
			}
		}

		if (mine_count > 0)
		{
			btn[y * nFieldWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}
	evt.Skip();

}
