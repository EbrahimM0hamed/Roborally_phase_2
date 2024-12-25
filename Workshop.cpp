#include "Workshop.h"
#include "Output.h" 
#include "Grid.h"
#include "Player.h"  
#include "RebootRepair.h"


Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer,Input *pIn)
{
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You reached a workshop! To Purchase additional equipment enter : 1 Double Laser - 2 Extended Memory - 3 Toolkit - 4 Hack Device -5 Shield Mechanic");
	int choice = pIn->GetInteger(pOut);
	if (choice == 1)
	{
		pOut->PrintMessage("You purchased a Double Laser");
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pPlayer->SetDoubleLaser(1);
	}
	else if (choice == 2)
	{
		pOut->PrintMessage("You purchased an Extended Memory");
	}
	else if (choice == 3)
	{
		pPlayer->SetToolkit(1);
		pOut->PrintMessage("You purchased a Toolkit");
	}
	else if (choice == 4)
	{
		pOut->PrintMessage("You purchased a Hack Device");
		Player* pPlayer = pGrid->GetCurrentPlayer();
;		pPlayer->SetNumHacked(1);
	}
	else if (choice == 5)
	{
		if (pPlayer->getHasShield() == false)
		{
			pPlayer->purchaseShield();
			pOut->PrintMessage("You purchased a Shield");
		}
		else
		{
			pOut->PrintMessage("You already have a Shield");
		}
	}
	else
	{
		pOut->PrintMessage("Invalid choice");
	}
	pOut->ClearStatusBar();
	// not ended yet
}
void Workshop::Save(ofstream &OutFile,string file)
{
	if(!OutFile.is_open())
		OutFile.open(file,ios::out);
	OutFile<<position.GetCellNum()<<endl;
}
void Workshop::Load(ifstream &Infile, string file)
{
	if(!Infile.is_open())
		Infile.open(file,ios::in);
	int cellnum;
	Infile>>cellnum;
	CellPosition cell(cellnum);
	position = cell;
}

Workshop::~Workshop()
{
}
