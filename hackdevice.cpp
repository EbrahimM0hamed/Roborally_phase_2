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
	 Grid* pGrid = pManager->GetGrid();
	 Output* pOut = pGrid->GetOutput();
	 Input* pIn = pGrid->GetInput();
	 Player* pPlayer = pGrid->GetNextPlayer();
	 //pPlayer->SetIsHack(true);
 }
  hackdevice::~hackdevice()
 {
 }
