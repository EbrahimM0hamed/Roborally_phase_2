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

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	//2- Apply the roating gear's effect by rotating the player according to the direction
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
