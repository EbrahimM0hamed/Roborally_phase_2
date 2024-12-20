#include "SaveGridAction.h"
SaveGridAction::SaveGridAction(ApplicationManager *pApp) : Action(pApp)
{
    // Initializes the pManager pointer of Action with the passed pointer
}

void SaveGridAction::ReadActionParameters()
{
    // Get a Pointer to the Input / Output Interfaces
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    // Read the parameter
    pOut->PrintMessage("New Save: Please Enter the File Name ...");
    file=pIn->GetSrting(pOut);
    // Clear messages
    pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
    ReadActionParameters();
    if(!(file[file.length()]=='t' && file[file.length() - 1] == 'x' && file[file.length() - 3] == 'e' && file[file.length() - 2] == 't'))
        file+=".txet";
    ofstream OutFile;
    OutFile.open(file,ios::out);
    Grid *pGrid = pManager->GetGrid();
    // Save the grid
    pGrid->SaveAll(OutFile,file,FLAG);
    pGrid->SaveAll(OutFile,file,BELT);
    pGrid->SaveAll(OutFile,file,ANTENNA);
    pGrid->SaveAll(OutFile,file,ROTATINGGEAR);
    pGrid->SaveAll(OutFile,file,WORKSHOP);
    pGrid->SaveAll(OutFile,file,WATERPIT);
    pGrid->SaveAll(OutFile,file,DANGERZONE);
    // Close the file
    OutFile.close();
}
SaveGridAction::~SaveGridAction()
{
}