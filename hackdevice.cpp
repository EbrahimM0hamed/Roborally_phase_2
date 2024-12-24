#include "hackdevice.h"
#include"ApplicationManager.h"
#include  "Player.h"
#include  "Grid.h"

hackdevice::hackdevice(ApplicationManager* pApp, Player* player, Grid* pGrid):Action(pApp)
{
}

 void hackdevice:: ReadActionParameters()
 {
 }

 void hackdevice::  Execute()
 {
	 this->pApp = pApp;
	 this->player = player;
	 this->pGrid = pGrid;
	 
 }
  hackdevice::~hackdevice()
 {
 }
