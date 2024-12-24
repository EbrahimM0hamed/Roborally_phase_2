#include "SelectMovement.h"
#include <cstdlib>
#include <ctime>

SelectMovement::SelectMovement(ApplicationManager *pApp) : Action(pApp)
{
}

void SelectMovement::ReadActionParameters()
{
}

void SelectMovement::Execute()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    Player *pPlayer=pGrid->GetCurrentPlayer();
    int health = pGrid->GetCurrentPlayer()->GetHealth();
    srand(time(0));
    Command *avilableMoveCommands = new Command[health];
    for (int i = 0; i < health; i++)
    {
        avilableMoveCommands[i] = NO_COMMAND;
    }
    for (int i = 0; i < health; i++)
    {
        int command = rand() % 8; // Generate a new command for each iteration
        switch (command)
        {
        case 0:
            avilableMoveCommands[i] = MOVE_FORWARD_ONE_STEP;
            break;
        case 1:
            avilableMoveCommands[i] = MOVE_BACKWARD_ONE_STEP;
            break;
        case 2:
            avilableMoveCommands[i] = MOVE_FORWARD_TWO_STEPS;
            break;
        case 3:
            avilableMoveCommands[i] = MOVE_BACKWARD_TWO_STEPS;
            break;
        case 4:
            avilableMoveCommands[i] = MOVE_FORWARD_THREE_STEPS;
            break;
        case 5:
            avilableMoveCommands[i] = MOVE_BACKWARD_THREE_STEPS;
            break;
        case 6:
            avilableMoveCommands[i] = ROTATE_CLOCKWISE;
            break;
        case 7:
            avilableMoveCommands[i] = ROTATE_COUNTERCLOCKWISE;
            break;
        }
    }
    pPlayer->SetAvilableMoveCommands(avilableMoveCommands, health);
    int size = (health > 5) ? 5 : health;
    Command *saveedMoveCommands = new Command[size];
    for (int i = 0; i < size; i++)
    {
        saveedMoveCommands[i] = NO_COMMAND;
    }

    pOut->CreateCommandsBar(saveedMoveCommands, size, avilableMoveCommands, health);

    int limit = (health > 5) ? 5 : health;
    for (int i = 0; i < limit; i++)
    {
        int selectedIndex = pIn->GetSelectedCommandIndex();
        if (selectedIndex >= 0 && selectedIndex < health)
        {
            saveedMoveCommands[i] = avilableMoveCommands[selectedIndex];
            pOut->CreateCommandsBar(saveedMoveCommands, limit, avilableMoveCommands, health);
        }
    }
    pPlayer->SetSaveedMoveCommands(saveedMoveCommands, size);
    

    delete[] avilableMoveCommands;
    delete[] saveedMoveCommands;
}

SelectMovement::~SelectMovement()
{
}