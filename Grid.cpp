#include "Grid.h"
#include <cstdlib>
#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include "Player.h"
#include "Flag.h"
#include "Antenna.h"
#include "RotatingGear.h"
#include "Workshop.h"
#include "WaterPit.h"
#include "DangerZone.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	hasFlag=false;
	hasAntenna=false;
	
	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell() &&!(pos.GetCellNum()==1) &&!(pos.GetCellNum()==55)) // Check if valid position
	{
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false
		if(dynamic_cast<Antenna *>(pNewObject)){
			hasAntenna=true;
			AntennaPosition=pNewObject->GetPosition();
		}
		if(Belt* pBelt=dynamic_cast<Belt *>(pNewObject)){
			if(!checkBeltEnd(pos))
				return false;
			if(!checkBeltBody(pBelt))
				return false;
			setBeltBody(pBelt,true);
		}
		if(dynamic_cast<Flag *>(pNewObject)){
			if(!checkBeltEnd(pos))
				return false;
			hasFlag=true;
		}
		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done

	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
bool Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		if(dynamic_cast<Flag *>(CellList[pos.VCell()][pos.HCell()]->GetGameObject()))
			hasFlag=false;
		if(dynamic_cast<Antenna *>(CellList[pos.VCell()][pos.HCell()]->GetGameObject()))
			hasAntenna=false;
		if(Belt* pBelt=dynamic_cast<Belt *>(CellList[pos.VCell()][pos.HCell()]->GetGameObject()))
			setBeltBody(pBelt,false);
		return CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
	return false;
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}

void Grid::SaveAll(ofstream &OutFile,string file,Type type)
{
	int flagNum=0,beltNum=0,antennaNum=0,rotatingGearNum=0,workShopNum=0,waterPitnum=0,dangerZonenum=0;
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			if (dynamic_cast<Flag*>(CellList[i][j]->GetGameObject()))
				flagNum++;
			if (dynamic_cast<Belt*>(CellList[i][j]->GetGameObject()))
				beltNum++;
			if (dynamic_cast<RotatingGear*>(CellList[i][j]->GetGameObject()))
				rotatingGearNum++;
			if (dynamic_cast<Antenna*>(CellList[i][j]->GetGameObject()))
				antennaNum++;
			if (dynamic_cast<WaterPit*>(CellList[i][j]->GetGameObject()))
				waterPitnum++;
			if (dynamic_cast<DangerZone*>(CellList[i][j]->GetGameObject()))
				dangerZonenum++;
			if (dynamic_cast<Workshop*>(CellList[i][j]->GetGameObject()))
				workShopNum++;
		}
	}
	switch (type)
	{
	case FLAG:
		OutFile<<"Flag Number: "<<flagNum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
		for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (Flag *pFlag=dynamic_cast<Flag*>(CellList[i][j]->GetGameObject()))
					pFlag->Save(OutFile,file);
			}
		}
		break;
	case BELT:
		OutFile<<"Belt Number: "<<beltNum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (Belt *pBelt=dynamic_cast<Belt*>(CellList[i][j]->GetGameObject()))
					pBelt->Save(OutFile,file);
			}
		}
		break;
	case ANTENNA:
		OutFile<<"Antenna Number: "<<antennaNum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (Antenna *pAntenna=dynamic_cast<Antenna*>(CellList[i][j]->GetGameObject()))
					pAntenna->Save(OutFile,file);
			}
		}
		break;
	case ROTATINGGEAR:
		OutFile<<"RotatingGear Number: "<<rotatingGearNum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (RotatingGear *pRotatingGear=dynamic_cast<RotatingGear*>(CellList[i][j]->GetGameObject()))
					pRotatingGear->Save(OutFile,file);
			}
		}
		break;
	case WORKSHOP:
		OutFile<<"Workshop Number: "<<workShopNum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (Workshop *pWorkshop=dynamic_cast<Workshop*>(CellList[i][j]->GetGameObject()))
					pWorkshop->Save(OutFile,file);
			}
		}
		break;
	case WATERPIT:
		OutFile<<"WaterPit Number: "<<waterPitnum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (WaterPit *pWaterPit=dynamic_cast<WaterPit*>(CellList[i][j]->GetGameObject()))
					pWaterPit->Save(OutFile,file);
			}
		}
		break;
	case DANGERZONE:
		OutFile<<"DangerZone Number: "<<dangerZonenum<<endl;
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (DangerZone *pDangerZone=dynamic_cast<DangerZone*>(CellList[i][j]->GetGameObject()))
					pDangerZone->Save(OutFile,file);
			}
		}
		break;
	}
}

void Grid::LoadAll(ifstream &Infile, string file,Type type)
{
	switch (type)
	{
	case FLAG:
		{
			Flag* pFlag = new Flag(CellPosition());
			pFlag->Load(Infile, file);
			AddObjectToCell(pFlag);
		}
		break;
	case BELT:
		{
			Belt* pBelt = new Belt(CellPosition(),CellPosition());
			pBelt->Load(Infile, file);
			AddObjectToCell(pBelt);
		}
		break;
	case ANTENNA:
		{
			Antenna* pAntenna = new Antenna(CellPosition());
			pAntenna->Load(Infile, file);
			AddObjectToCell(pAntenna);
		}
		break;
	case ROTATINGGEAR:
		{
			RotatingGear* pRotatingGear = new RotatingGear(CellPosition(),true);
			pRotatingGear->Load(Infile, file);
			AddObjectToCell(pRotatingGear);
		}
		break;
	case WORKSHOP:
		{
			Workshop* pWorkshop = new Workshop(CellPosition());
			pWorkshop->Load(Infile, file);
			AddObjectToCell(pWorkshop);
		}
		break;
	case WATERPIT:
		{
			WaterPit* pWaterPit = new WaterPit(CellPosition());
			pWaterPit->Load(Infile, file);
			AddObjectToCell(pWaterPit);
		}
		break;
	case DANGERZONE:
		{
			DangerZone* pDangerZone = new DangerZone(CellPosition());
			pDangerZone->Load(Infile, file);
			AddObjectToCell(pDangerZone);
		}
		break;
	}
}
// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(GameObject * gameObject) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = gameObject;
}

GameObject * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

int Grid::GetDistanceFromAntenna(CellPosition & pos)
{
	return abs(pos.HCell()-AntennaPosition.HCell())+abs(pos.VCell()-AntennaPosition.VCell());
}
void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

bool Grid::GetHasFlag()
{
	return hasFlag;
}
bool Grid::GetHasAntenna()
{
	return hasAntenna;
}
void Grid::setBeltBody(Belt *pBelt,bool exist)
{
	int vStart=pBelt->GetPosition().VCell();	
	int hStart=pBelt->GetPosition().HCell();	
	int vEnd=pBelt->GetEndPosition().VCell();	
	int hEnd=pBelt->GetEndPosition().HCell();
	for(int i=vStart;i<=vEnd;i++){
		for(int j=hStart;j<=hEnd;j++){
			CellList[i][j]->SetInsideBeltBody(exist);
		}
		for(int j=hStart;j>=hEnd;j--){
			CellList[i][j]->SetInsideBeltBody(exist);
		}
	}	
	for(int i=vStart;i>=vEnd;i--){
		for(int j=hStart;j<=hEnd;j++){
			CellList[i][j]->SetInsideBeltBody(exist);
		}
		for(int j=hStart;j>=hEnd;j--){
			CellList[i][j]->SetInsideBeltBody(exist);
		}
	}	
}
bool Grid::checkBeltBody(Belt *pBelt)
{
	int vStart=pBelt->GetPosition().VCell();	
	int hStart=pBelt->GetPosition().HCell();	
	int vEnd=pBelt->GetEndPosition().VCell();	
	int hEnd=pBelt->GetEndPosition().HCell();
	for(int i=vStart;i<=vEnd;i++){
		for(int j=hStart;j<=hEnd;j++){
			if(CellList[i][j]->GetInsideBeltBody())
				return false;
		}
		for(int j=hStart;j>=hEnd;j--){
			if(CellList[i][j]->GetInsideBeltBody())
				return false;
		}
	}	
	for(int i=vStart;i>=vEnd;i--){
		for(int j=hStart;j<=hEnd;j++){
			if(CellList[i][j]->GetInsideBeltBody())
				return false;
		}
		for(int j=hStart;j>=hEnd;j--){
			if(CellList[i][j]->GetInsideBeltBody())
				return false;
		}
	}
	return true;
}

bool Grid::checkBeltEnd(CellPosition cellpos)
{
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			if(Belt *pBelt=dynamic_cast<Belt *>(CellList[i][j]->GetGameObject()))
				if(cellpos.GetCellNum()==pBelt->GetEndPosition().GetCellNum())
					return false;
		}
	}
	return true;
}
// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt * Grid::GetNextBelt(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a belt, if yes return it
			
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


// ========= User Interface Functions =========


GameObject *Grid::GetGameObject(CellPosition pos) const
{
	int v=pos.VCell();
	int h=pos.HCell();
	return CellList[v][h]->GetGameObject();
}

void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}