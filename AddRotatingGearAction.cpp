#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager *pApp) : Action(pApp)
{
}

void AddRotatingGearAction::ReadActionParameters()
{
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	// 2- Read the gearPos
	pOut->PrintMessage("New Rotating Gear: Click on a Cell ...");
	gearPos = pIn->GetCellClicked();
	
	// 3- Read whether the direction will be clockwise or not
	pOut->PrintMessage("Please enter a number: 1.Clockwise Or 2.CounterClockwise ! Click to continue ...");
	int clock = pIn->GetInteger(pOut);
	if (clock == 1){
		clockwise = true;
		choice = true;
	}
	else if (clock == 2){
		clockwise = false;
		choice = true;
	}
	else
	{
		choice=false;
	}


	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddRotatingGearAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first
	// and hence initializes its data members
	ReadActionParameters();
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a rotating gear object
	Grid *pGrid = pManager->GetGrid();
	RotatingGear *pRotatingGear = new RotatingGear(gearPos,clockwise);

	// 2-get a pointer to the Grid from the ApplicationManager

	// 3-Add the rotating object to the GameObject of its Cell:
	

	// 4-Check if the rotating gear was added and print an errror message if flag couldn't be added
	if(!choice){
		pGrid->PrintErrorMessage("Invalid Choice");
		return;
	}
	bool added = pGrid->AddObjectToCell(pRotatingGear);
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
