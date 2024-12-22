#include "RotatingGear.h"




RotatingGear::RotatingGear(const CellPosition & gearposition,bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn;

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	if (isClockWise)
		pGrid->PrintErrorMessage("You have reached a rotating gear, you will rotate clockwise Click to continue ...");
	else
		pGrid->PrintErrorMessage("You have reached a rotating gear, you will rotate anti-clockwise Click to continue ...");

	//2- Apply the roating gear's effect by rotating the player according to the direction
	if (pPlayer->GetCurrDirection() == RIGHT)
	{
		if (isClockWise)
			pPlayer->SetCurrDirection(DOWN);
		else if (!isClockWise)
			pPlayer->SetCurrDirection(UP);
	}
	else if (pPlayer->GetCurrDirection() == LEFT)
	{
		if (isClockWise)
			pPlayer->SetCurrDirection(UP);
		else if (!isClockWise)
			pPlayer->SetCurrDirection(DOWN);
	}
	else if (pPlayer->GetCurrDirection() == UP)
	{
		if (isClockWise)
			pPlayer->SetCurrDirection(RIGHT);
		else if (!isClockWise)
			pPlayer->SetCurrDirection(LEFT);
	}
	else if (pPlayer->GetCurrDirection() == DOWN)
	{
		if (isClockWise)
			pPlayer->SetCurrDirection(LEFT);
		else if (!isClockWise)
			pPlayer->SetCurrDirection(RIGHT);
    }
	
}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}
void RotatingGear::Save(ofstream &OutFile,string file)
{
	if(!OutFile.is_open())
		OutFile.open(file,ios::out);
	OutFile<<position.GetCellNum()<<endl;
}
void RotatingGear::Load(ifstream &Infile, string file)
{
	if(!Infile.is_open())
		Infile.open(file,ios::in);
	int cellnum;
	Infile>>cellnum;
	CellPosition cell(cellnum);
	position = cell;
}

RotatingGear::~RotatingGear()
{
}
