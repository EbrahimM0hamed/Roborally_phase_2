#include "AddAntennaAction.h"

AddAntennaAction::AddAntennaAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddAntennaAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the parameter
	pOut->PrintMessage("New Belt: Click on its Start Cell ...");
	antennaPos = pIn->GetCellClicked();
	// Clear messages
	pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Antenna object with the parameters read from the user
	Antenna * pAntenna = new Antenna(antennaPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// if the GameObject cannot be added
	if(!pGrid->GetHasAntenna()){
		bool added = pGrid->AddObjectToCell(pAntenna);
	// 4-Check if added and print an errror message if flag couldn't be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}else
		pGrid->PrintErrorMessage("Error: There is an antenna already ! Click to continue ...");
	// Here, the is created and added to the GameObject of its Cell, so we finished executing

}

AddAntennaAction::~AddAntennaAction()
{
}
