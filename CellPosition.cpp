#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	// Implement this function as described in the .h file (don't forget the validation)
	if(0<=v && v<NumVerticalCells){
		vCell=v;
		return true;
	}
	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	// Implement this function as described in the .h file (don't forget the validation)
	if(0<=h && h<NumHorizontalCells){
		hCell=h;
		return true;
	}
	return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	// Implement this function as described in the .h file  ✓
	if (0<=vCell && vCell<NumVerticalCells && 0<=hCell&& hCell<NumHorizontalCells)
	{
		return true;
	}
	else
	{
		return false; // this line sould be changed with your implementation
	}
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it
	int cellnum=((NumVerticalCells-cellPosition.vCell-1)*10)+(cellPosition.hCell+NumVerticalCells-cellPosition.vCell);
	return cellnum;
	// Implement this function as described in the .h file

	return 0; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	
	// Implement this function as described in the .h file
	if(45<=cellNum && cellNum<=55){
		position.SetVCell(0);
		position.SetHCell(cellNum-45);
	}else if(34<=cellNum && cellNum<45){
		position.SetVCell(1);
		position.SetHCell(cellNum-34);
	}else if(23<=cellNum && cellNum<34){
		position.SetVCell(2);
		position.SetHCell(cellNum-23);
	}else if(12<=cellNum && cellNum<23){
		position.SetVCell(3);
		position.SetHCell(cellNum-12);
	}else if(0<=cellNum && cellNum<12){
		position.SetVCell(4);
		position.SetHCell(cellNum-1);
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	

	return position;
} 

bool CellPosition::AddCellNum(int addedNum, Direction direction)
{
	
	// Implement this function as described in the .h file
	if(direction==UP && (vCell-addedNum)>=0){
		vCell-=addedNum;
		return true;
	}else if(direction==DOWN && (vCell+addedNum)<5){
		vCell+=addedNum;
		return true;
	}else if(direction==RIGHT && (hCell+addedNum)<11){
		hCell+=addedNum;
		return true;
	}else if(direction==LEFT && (hCell-addedNum)>=0){
		hCell-=addedNum;
		return true;
	}
	return false;


	// Note: this function updates the data members (vCell and hCell) of the calling object

}