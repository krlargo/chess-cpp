#include "King.hpp"

King::King(Square* sq)
{
  setName("K");
  setSquare(sq);
}

bool King::isValidMove(Square* sq)
{
  //check that square is not attacked first
  
  if(getColor() == "white")
  {
    if(sq->isAttackedByBlack)
      return false;
  }
  
  else if(getColor() == "black")
  {
    if(sq->isAttackedByWhite)
      return false;
  }
  
  //check rank above
  if(getSquare()->getAboveSq()) //if there's a square above
  {
    if(getSquare()->getAboveSq() == sq) //check if this is that square
      return true;
    
    if(getSquare()->getAboveSq()->getLeftSq())
      if(getSquare()->getAboveSq()->getLeftSq() == sq)
        return true;
    
    if(getSquare()->getAboveSq()->getRightSq())
      if(getSquare()->getAboveSq()->getRightSq() == sq)
        return true;
  }
  
  //check rightSquare
  if(getSquare()->getRightSq())
    if(getSquare()->getRightSq() == sq)
      return true;
  
  //check rank below
  if(getSquare()->getBelowSq())
  {
    if(getSquare()->getBelowSq() == sq)
      return true;
    
    if(getSquare()->getBelowSq()->getLeftSq())
      if(getSquare()->getBelowSq()->getLeftSq() == sq)
        return true;
    
    if(getSquare()->getBelowSq()->getRightSq())
      if(getSquare()->getBelowSq()->getRightSq() == sq)
        return true;
  }
  
  //check left
  if(getSquare()->getLeftSq())
    if(getSquare()->getLeftSq() == sq)
      return true;
  
  return false;
}