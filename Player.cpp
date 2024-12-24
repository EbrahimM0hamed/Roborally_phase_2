#include "Player.h"
#include "Grid.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;
	for (int i = 0; i < 5; i++)
    {
		saveedMoveCommands[i] = NO_COMMAND;
    }
	for (int i = 0; i < 10; i++)
    {
        avilableMoveCommands[i] = NO_COMMAND;
    }
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	this->health = h;
	///TODO: Do any needed validations

}
void Player::SetCurrDirection(Direction direction)
{
	 this->currDirection=direction;
}

int Player::GetHealth()
{
	return this->health;
}

void Player::reduceHealth(int h)
{
	this->health -= h;
}
Direction Player::GetCurrDirection()
{
	return this->currDirection;
}
int Player::GetplayerNum()
{
	return playerNum;
}
void Player::SetAvilableMoveCommands(Command  avilableMoveCommands[],int index)
{
	for (int i = 0; i < index; i++)
    {
		if (avilableMoveCommands[i] == MOVE_FORWARD_ONE_STEP)
			this->avilableMoveCommands[i] = MOVE_FORWARD_ONE_STEP;
		else if (avilableMoveCommands[i] == MOVE_BACKWARD_ONE_STEP)
			this->avilableMoveCommands[i] = MOVE_BACKWARD_ONE_STEP;
		else if (avilableMoveCommands[i] == MOVE_FORWARD_TWO_STEPS)
			this->avilableMoveCommands[i] = MOVE_FORWARD_TWO_STEPS;
		else if (avilableMoveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
			this->avilableMoveCommands[i] = MOVE_BACKWARD_TWO_STEPS;
		else if (avilableMoveCommands[i] == MOVE_FORWARD_THREE_STEPS)
			this->avilableMoveCommands[i] = MOVE_FORWARD_THREE_STEPS;
		else if (avilableMoveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
			this->avilableMoveCommands[i] = MOVE_BACKWARD_THREE_STEPS;
		else if (avilableMoveCommands[i] == ROTATE_CLOCKWISE)
			this->avilableMoveCommands[i] = ROTATE_CLOCKWISE;
		else if (avilableMoveCommands[i] == ROTATE_COUNTERCLOCKWISE)
			this->avilableMoveCommands[i] = ROTATE_COUNTERCLOCKWISE;
        // this->avilableMoveCommands[i] = avilableMoveCommands[i];
    }
}
void Player::SetSaveedMoveCommands(Command  saveedMoveCommands[],int index)
{
	for (int i = 0; i < index; i++)
    {
		if (saveedMoveCommands[i] == NO_COMMAND)
			this->saveedMoveCommands[i] = NO_COMMAND;
		else if (saveedMoveCommands[i] == MOVE_FORWARD_ONE_STEP)
			this->saveedMoveCommands[i] = MOVE_FORWARD_ONE_STEP;
		else if (saveedMoveCommands[i] == MOVE_BACKWARD_ONE_STEP)
			this->saveedMoveCommands[i] = MOVE_BACKWARD_ONE_STEP;
		else if (saveedMoveCommands[i] == MOVE_FORWARD_TWO_STEPS)
			this->saveedMoveCommands[i] = MOVE_FORWARD_TWO_STEPS;
		else if (saveedMoveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
			this->saveedMoveCommands[i] = MOVE_BACKWARD_TWO_STEPS;
		else if (saveedMoveCommands[i] == MOVE_FORWARD_THREE_STEPS)
			this->saveedMoveCommands[i] = MOVE_FORWARD_THREE_STEPS;
		else if (saveedMoveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
			this->saveedMoveCommands[i] = MOVE_BACKWARD_THREE_STEPS;
		else if (saveedMoveCommands[i] == ROTATE_CLOCKWISE)
			this->saveedMoveCommands[i] = ROTATE_CLOCKWISE;
		else if (saveedMoveCommands[i] == ROTATE_COUNTERCLOCKWISE)
			this->saveedMoveCommands[i] = ROTATE_COUNTERCLOCKWISE;
        // this->saveedMoveCommands[i] = saveedMoveCommands[i];
    }
}
Command Player::GetAvilableMoveCommands(int index)
{
	return avilableMoveCommands[index];
}
Command Player::GetSaveedMoveCommands(int index)
{
	return saveedMoveCommands[index];
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor,currDirection);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;
	
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor,currDirection);
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, Command moveCommands[], Input* pIn)
{

	///TODO: Implement this function using the guidelines mentioned below

	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	// 
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending
	CellPosition *position;
	position=&pCell->GetCellPosition();
	for (int i = 0;i < 5;i++)
	{
		if(currDirection==RIGHT){
			if (moveCommands[i]==MOVE_FORWARD_ONE_STEP)
			{
				position->AddCellNum(1, RIGHT);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_ONE_STEP)
			{
				position->AddCellNum(1, LEFT);
			}
			else if (moveCommands[i] == MOVE_FORWARD_TWO_STEPS)
			{
				position->AddCellNum(2, RIGHT);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
			{
				position->AddCellNum(2, LEFT);
			}
			else if (moveCommands[i] == MOVE_FORWARD_THREE_STEPS)
			{
				position->AddCellNum(3, RIGHT);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
			{
				position->AddCellNum(3, LEFT);
			}
			else if (moveCommands[i] == ROTATE_CLOCKWISE)
			{
				currDirection = DOWN;
			}
			else if (moveCommands[i] == ROTATE_COUNTERCLOCKWISE)
			{
				currDirection = UP;
			}
		}
		else if(currDirection==LEFT){
			if (moveCommands[i]==MOVE_FORWARD_ONE_STEP)
			{
				position->AddCellNum(1, LEFT);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_ONE_STEP)
			{
				position->AddCellNum(1, RIGHT);
			}
			else if (moveCommands[i] == MOVE_FORWARD_TWO_STEPS)
			{
				position->AddCellNum(2, LEFT);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
			{
				position->AddCellNum(2, RIGHT);
			}
			else if (moveCommands[i] == MOVE_FORWARD_THREE_STEPS)
			{
				position->AddCellNum(3, LEFT);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
			{
				position->AddCellNum(3, RIGHT);
			}
			else if (moveCommands[i] == ROTATE_CLOCKWISE)
			{
				currDirection = UP;
			}
			else if (moveCommands[i] == ROTATE_COUNTERCLOCKWISE)
			{
				currDirection = DOWN;
			}
		}
		else if(currDirection==UP){
			if (moveCommands[i]==MOVE_FORWARD_ONE_STEP)
			{
				position->AddCellNum(1, UP);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_ONE_STEP)
			{
				position->AddCellNum(1, DOWN);
			}
			else if (moveCommands[i] == MOVE_FORWARD_TWO_STEPS)
			{
				position->AddCellNum(2, UP);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
			{
				position->AddCellNum(2, DOWN);
			}
			else if (moveCommands[i] == MOVE_FORWARD_THREE_STEPS)
			{
				position->AddCellNum(3, UP);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
			{
				position->AddCellNum(3, DOWN);
			}
			else if (moveCommands[i] == ROTATE_CLOCKWISE)
			{
				currDirection = RIGHT;
			}
			else if (moveCommands[i] == ROTATE_COUNTERCLOCKWISE)
			{
				currDirection = LEFT;
			}
		}
		else if(currDirection==DOWN){
			if (moveCommands[i]==MOVE_FORWARD_ONE_STEP)
			{
				position->AddCellNum(1, DOWN);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_ONE_STEP)
			{
				position->AddCellNum(1, UP);
			}
			else if (moveCommands[i] == MOVE_FORWARD_TWO_STEPS)
			{
				position->AddCellNum(2, DOWN);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_TWO_STEPS)
			{
				position->AddCellNum(2, UP);
			}
			else if (moveCommands[i] == MOVE_FORWARD_THREE_STEPS)
			{
				position->AddCellNum(3, DOWN);
			}
			else if (moveCommands[i] == MOVE_BACKWARD_THREE_STEPS)
			{
				position->AddCellNum(3, UP);
			}
			else if (moveCommands[i] == ROTATE_CLOCKWISE)
			{
				currDirection = LEFT;
			}
			else if (moveCommands[i] == ROTATE_COUNTERCLOCKWISE)
			{
				currDirection = RIGHT;
			}
		}
	
		if (position->IsValidCell())
		{
			pGrid->UpdatePlayerCell(this , *position);
			pGrid->UpdateInterface();
		}
		
		pGrid->PrintErrorMessage("Click anywhere to execute the next command.");
		int x = 0, y = 0;
		pGrid->GetInput()->GetPointClicked(x,y);

		Cell* fCell = pGrid->GetCurrentPlayer()->GetCell();
		if (fCell->GetGameObject())
		{
			fCell->GetGameObject()->Apply(pGrid, this, pIn);
		}
	}
	
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	switch (currDirection)
	{
	case RIGHT:
		playersInfo += "RIGHT, ";
		break;
	case LEFT:
		playersInfo += "LEFT, ";
		break;
	case UP:
		playersInfo += "UP, ";
		break;
	case DOWN:
		playersInfo += "DOWN, ";
		break;
	}
	playersInfo += to_string(health) + ")";

}