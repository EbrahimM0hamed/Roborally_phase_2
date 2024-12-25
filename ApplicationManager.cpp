#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "DeleteAction.h"
#include "AddWaterPitAction.h"
#include "AddDangerZoneAction.h"
#include "AddAntennaAction.h"
#include "AddWorkshopAction.h"
#include "SaveGridAction.h"
#include "LoadAction.h"
#include "SwichToPlayMode.h"
#include "SwichToDesignMode.h"
#include "SelectMovement.h"
#include "ExecuteMovement.h"
#include "RebootRepair.h"
#include "Rounds.h"
#include "UseConsumable.h"
#include "NewGame.h"
/// TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
	pRounds = new Rounds;
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid *ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action *pAct = NULL;
	if (pGrid->GetEndGame())
	{
		pOut->PrintMessage("Game Ended, Please Start New Game");
		//have to start new came
	}
	// According to Action Type, create the corresponding action object
	switch (ActType)
	{

	case SET_FLAG_CELL:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;
	case SET_ANTENNA:
		pAct = new AddAntennaAction(this);
		break;
	case SET_BELT:
		pAct = new AddBeltAction(this);
		break;
	case SET_WATERPIT:
		pAct = new AddWaterPitAction(this);
		break;
	case SET_WORKSHOP:
		pAct = new AddWorkshopAction(this);
		break;
	case SET_DANGERZONE:
		pAct = new AddDangerZoneAction(this);
		break;
	case SET_ROTATINGGEAR:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case COPY_GAMEOBJECT:
		pAct = new CopyAction(this);
		break;
	case CUT_GAMEOBJECT:
		pAct = new CutAction(this);
		break;
	case PASTE_GAMEOBJECT:
		pAct = new PasteAction(this);
		break;
	case DELETE_GAMEOBJECT:
		pAct = new DeleteAction(this);
		break;
	case SAVEGRID:
		pAct = new SaveGridAction(this);
		break;
	case LOAD_OPENGRID:
		pAct = new LoadAction(this);
		break;
	case EXIT:
		break;

	case TO_PLAY_MODE:				   // TODO:
		pAct = new SwichToPlayMode(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case TO_DESIGN_MODE:				 // TODO:
		pAct = new SwichToDesignMode(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;
	case SELECT_COMMAND:
		if (pGrid->GetCurrentPlayer()->GetIsHack())
		{
			pGrid->PrintErrorMessage("You are hacked, you can't play this round");
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		pAct = new SelectMovement(this);
		break;
		/// TODO: Add a case for EACH Action type in the Design mode or Play mode
	case EXECUTE_COMMANDS:
		if (pGrid->GetCurrentPlayer()->GetIsHack())
		{
			pGrid->PrintErrorMessage("You are hacked, you can't play this round");
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		pAct = new ExecuteMovement(this);
		break;
	case REBOOT_REPAIR:
		if (pGrid->GetCurrentPlayer()->GetIsHack())
		{
			pGrid->PrintErrorMessage("You are hacked, you can't play this round");
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		pAct = new RebootRepairAction(this);
		break;
	case USE_CONSUMABLE:
		if (pGrid->GetCurrentPlayer()->GetIsHack())
		{
			pGrid->PrintErrorMessage("You are hacked, you can't play this round");
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		pAct = new UseConsumable(this);
		break;
	case NEW_GAME:
		if (pGrid->GetCurrentPlayer()->GetIsHack())
		{
			pGrid->PrintErrorMessage("You are hacked, you can't play this round");
			pGrid->AdvanceCurrentPlayer();
			return;
		}
		pAct = new NewGame(this);
		break;
	case STATUS: // a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
	pRounds->Execute(this, ActType);
}
