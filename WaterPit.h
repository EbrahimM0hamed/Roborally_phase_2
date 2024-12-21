#pragma once
#include "GameObject.h"
class WaterPit:public GameObject
{
public:
	WaterPit(const CellPosition & waterPitPosition); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a water pit in the cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the waterPit by killing the robot instantly and ending the game
	virtual void Save(ofstream &OutFile,string file);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream &Infile, string file);
	virtual ~WaterPit();
};

