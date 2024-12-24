#include "Antenna.h"





Antenna::Antenna(const CellPosition & antennaPosition):GameObject(antennaPosition)
{
}

void Antenna::Draw(Output * pOut) const
{
	pOut->DrawAntenna(position);
}

void Antenna::Apply(Grid * pGrid,Player *pPlayer,Input *pIn)
{
	pGrid->PrintErrorMessage("the antenna will decide the turn of players. Click to continue ...");
	pIn->GetCellClicked();
	// 2- Apply the antenna effect by following these notes, check grid class and decide which function to use
	Player* pNextPlayer = pGrid->GetNextPlayer();
	//The antenna determines the turn order for players.
	//The distance of each player from the antenna determines his turn order in each rount.
	//Player with the minimum distance[ from the antenna will have the first turn in that round.
	int d1;
	int d2;
	d1 = pGrid->GetDistanceFromAntenna(pPlayer->GetCell()->GetCellPosition());
	d2 = pGrid->GetDistanceFromAntenna(pNextPlayer->GetCell()->GetCellPosition());
	if (pPlayer->GetplayerNum() == 0)
	{
		if (d1 > d2)
			pGrid->AdvanceCurrentPlayer();
	}
	else
	{
		if (d2 > d1)
			pGrid->AdvanceCurrentPlayer();
	}
	if (d1 == d2 && pPlayer->GetplayerNum() == 1)
	{
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->PrintErrorMessage("Player " + to_string(pGrid->GetCurrentPlayer()->GetplayerNum() + 1) + " will play first");
	// 3- After deciding the turn of player Print a message indicating which player will play first example: "Player 1 will play first"
		//If there is a tie, player number will break it, for example if player 1 & 2 are in the same cell and they have the same distance from the antenna, player 1 will play first in that round.
	

}
void Antenna::Save(ofstream &OutFile, string file)
{
	if(!OutFile.is_open())
		OutFile.open(file,ios::out);
	OutFile<<position.GetCellNum()<<endl;
}
void Antenna::Load(ifstream &Infile, string file)
{
	if(!Infile.is_open())
		Infile.open(file,ios::in);
	int cellnum;
	Infile>>cellnum;
	CellPosition cell(cellnum);
	position = cell;
}
Antenna::~Antenna()
{   
}
//