#include "ExecuteMovement.h"

ExecuteMovement::ExecuteMovement(ApplicationManager *pApp) : Action(pApp)
{
}

void ExecuteMovement::ReadActionParameters()
{
}

void ExecuteMovement::Execute()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    Player *pPlayer = pGrid->GetCurrentPlayer();
    Command *moveCommands = new Command[5];
    for (int i = 0; i < 5; i++)
    {
        moveCommands[i] = pPlayer->GetSaveedMoveCommands(i);
    }
    pPlayer->Move(pGrid, moveCommands, pIn);
}

ExecuteMovement::~ExecuteMovement()
{
}