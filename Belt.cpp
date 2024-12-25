#include "Belt.h"


Belt::Belt(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
void Belt::Draw(Output* pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid* pGrid, Player* pPlayer,Input *pIn)
{

	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	
    // 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a belt. Click to continue ...");
	pIn->GetCellClicked();
	// 2- Apply the belt's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that
}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}
void Belt::Save(ofstream &OutFile,string file)
{
	if(!OutFile.is_open())
		OutFile.open(file,ios::out);
	OutFile<<position.GetCellNum()<<" "<<endCellPos.GetCellNum()<<endl;
}
void Belt::Load(ifstream &Infile, string file)
{
	if(!Infile.is_open())
		Infile.open(file,ios::in);
	int startcellnum,endcellnum;
	Infile>>startcellnum>>endcellnum;
	CellPosition startcell(startcellnum);
	CellPosition endcell(endcellnum);
	position = startcell;
	endCellPos = endcell;
}

Belt::~Belt()
{
}
