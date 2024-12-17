#include "AddWaterPitAction.h"


AddWaterPitAction::AddWaterPitAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddWaterPitAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the flagPos
	pOut->PrintMessage("New WaterPit: Click on a Cell ...");
	WaterPitPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddWaterPitAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a WaterPit object
	WaterPit * pWaterPit =new WaterPit(WaterPitPosition);
	// 2-get a pointer to the Grid from the ApplicationManager
	Grid * pGrid = pManager->GetGrid();
	// 3-Add the flag object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pWaterPit);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}

AddWaterPitAction::~AddWaterPitAction()
{
}