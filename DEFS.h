#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	SET_FLAG_CELL,
	SET_ANTENNA,
	SET_BELT,
	SET_WATERPIT,
	SET_DANGERZONE,
	SET_WORKSHOP,
	SET_ROTATINGGEAR,
	COPY_GAMEOBJECT,
	CUT_GAMEOBJECT,
	PASTE_GAMEOBJECT,
	DELETE_GAMEOBJECT,
	SAVEGRID,
	LOAD_OPENGRID,
	TO_PLAY_MODE,
	EXIT,

	// Add more action types of Design Mode

	//  [2] Actions of Play Mode

	SELECT_COMMAND,
	EXECUTE_COMMANDS,
	REBOOT_REPAIR,
	USE_CONSUMABLE,
	NEW_GAME,
	TO_DESIGN_MODE,
	EXIT_PLAY,


	// Add more action types of Play Mode

	//  [3] Others

	EMPTY,							// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,						// Inside Grid Area
	STATUS 							// Inside StatusBar Area
};

enum Direction // Directions of the game
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,

	COMMANDS_COUNT,
};
enum Type
{
	FLAG,
	ANTENNA,
	BELT,
	WATERPIT,
	WORKSHOP,
	DANGERZONE,
	ROTATINGGEAR,
};
#endif