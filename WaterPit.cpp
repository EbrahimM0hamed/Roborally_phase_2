#include "WaterPit.h"





WaterPit::WaterPit(const CellPosition & waterPitPosition):GameObject(waterPitPosition)
{
}

void WaterPit::Draw(Output * pOut) const
{
	pOut->DrawWaterPit(position);
}

void WaterPit::Apply(Grid * pGrid, Player * pPlayer,Input *pIn)
{
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message, make sure to edit this message according to which player wins "You drowned in a water pit. Player (0/1) wins !  Click to continue ..." and wait mouse click
	if (pGrid->GetCurrentPlayer() == 0)
		pGrid->PrintErrorMessage("You drowned in a water pit. Player (1) wins !  Click to continue ...");
	else
		pGrid->PrintErrorMessage("You drowned in a water pit. Player (0) wins !  Click to continue ...");
	    pIn->GetCellClicked();
    // 2- Apply the water pit's effect by setting the player's health which drowned to zero and ending the game
		pPlayer->SetHealth(0);
		pGrid->SetEndGame(true);

			// 3- Update the players info which is displayed (check Grid class and decide which function to use)
			pGrid->UpdateInterface();

}
void WaterPit::Save(ofstream &OutFile,string file)
{
	if(!OutFile.is_open())
		OutFile.open(file,ios::out);
	OutFile<<position.GetCellNum()<<endl;
}
void WaterPit::Load(ifstream &Infile, string file)
{
	if(!Infile.is_open())
		Infile.open(file,ios::in);
	int cellnum;
	Infile>>cellnum;
	CellPosition cell(cellnum);
	position = cell;
}


WaterPit::~WaterPit()
{
}
