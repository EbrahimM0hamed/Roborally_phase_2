#include "Cell.h"

#include "Grid.h"
#include "GameObject.h"
#include "Belt.h"
#include "WaterPit.h"
#include "Player.h"
#include "DangerZone.h"
#include "Output.h"
#include "Flag.h"
#include "RotatingGear.h"
#include "Antenna.h"
#include "Workshop.h"

Cell::Cell(const CellPosition & pos) : position(pos)
{
	// initializes the data members (position & pGameObject)
	pGameObject = NULL;
	insideBeltBody=false;
}

Cell::Cell(int v, int h) : position(v, h)
{
	// initializes the data members (position & pGameObject)
	pGameObject = NULL;
	insideBeltBody=false;
	
}


// ======= Setters and Getters Functions ======= 


CellPosition Cell::GetCellPosition() const
{
	return position;
}

bool Cell::SetGameObject(GameObject * pGObj)
{
	if (pGameObject != NULL && pGObj != NULL) // already contains one
		return false; // do NOT add it and return false

	pGameObject = pGObj;
	return true;
}

GameObject * Cell::GetGameObject() const
{
	return pGameObject;
}

Belt * Cell::HasBelt() const
{
	return dynamic_cast<Belt *>(pGameObject);
}


Flag * Cell::HasFlag() const
{

	// Implement the following function like HasBelt() function
	return dynamic_cast<Flag *>(pGameObject);
	
}
WaterPit * Cell::HasWaterPit() const
{

	// Implement the following function like HasBelt() function

	return dynamic_cast<WaterPit *>(pGameObject);; // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION

}

DangerZone * Cell::HasDangerZone() const
{
	// Implement the following function like HasBelt() function

	return dynamic_cast<DangerZone *>(pGameObject);;; // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION
}

RotatingGear * Cell::HasRotatingGear() const
{
	return dynamic_cast<RotatingGear *>(pGameObject);

}
Antenna * Cell::HasAntenna() const
{
	return dynamic_cast<Antenna *>(pGameObject);

}
Workshop * Cell::HasWorkshop() const
{
	return dynamic_cast<Workshop *>(pGameObject);

}
void Cell::SetInsideBeltBody(bool beltBody)
{
	insideBeltBody=beltBody;
}
bool Cell::GetInsideBeltBody()
{
	return insideBeltBody;
}

// ======= Drawing Functions ======= 

void Cell::DrawCellOrWaterPitOrDangerZone(Output* pOut) const
{
	// Checks if there is a dangerzone or a waterpit on the cell
	if (HasDangerZone()||HasWaterPit()) // means if not NULL
		pGameObject->Draw(pOut); // draw the dangerzone or waterpit  then
	else
		pOut->DrawCell(position,UI.CellColor); // draw empty cell 
}

// separate from the above function 
//because other game objects should be drawn AFTER All Cells are drawn
//because other game objects don't change color of the cell
void Cell::DrawGameObject(Output* pOut) const
{
	//TODO: edit this incomplete implemntation to check for other game objects (excluding waterpits and dangerzones)
	if (HasFlag()|| HasBelt()|| HasRotatingGear()|| HasAntenna()|| HasWorkshop())
		pGameObject->Draw(pOut); // draw game object
	

}
