#include "Queen.hpp"
#include "Piece.hpp"

Queen::Queen(Square* sq)
{
  setName("Q");
  setSquare(sq);
}

bool Queen::isValidMove(Square* sq)
{
    return (isValidBishopMove(sq) || isValidRookMove(sq));
}

//Remove later, should be using function directly from Bishop class
bool Queen::isValidBishopMove(Square* sq)
{
  //check NE
  walker = getSquare(); //walker = current square location
  
  while(walker != NULL)
  {
    //if there's a square to the right, then move to the right
    if(walker->getRightSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getRightSq();
    
    //if there's a square above, then move up
    if(walker->getAboveSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getAboveSq();
    
    //diagonal shift made, now check square
    if(walker->piece && walker != sq) //if piece found, but not at destination square, then piece is in the way
      break;
    
    if(walker == sq) //if square is found
      return true;
  }
  
  //check SE
  walker = getSquare(); //walker = current square location
  
  while(walker != NULL)
  {
    //if there's a square to the right, then move to the right
    if(walker->getRightSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getRightSq();
    
    //if there's a square above, then move up
    if(walker->getBelowSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getBelowSq();
    
    //diagonal shift made, now check square
    if(walker->piece && walker != sq) //if piece found, but not at destination square, then piece is in the way
      break;
    
    if(walker == sq) //if square is found
      return true;
  }
  
  //check SW
  walker = getSquare(); //walker = current square location
  
  while(walker != NULL)
  {
    //if there's a square to the right, then move to the right
    if(walker->getLeftSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getLeftSq();
    
    //if there's a square above, then move up
    if(walker->getBelowSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getBelowSq();
    
    //diagonal shift made, now check square
    if(walker->piece && walker != sq) //if piece found, but not at destination square, then piece is in the way
      break;
    
    if(walker == sq) //if square is found
      return true;
  }
  
  //check NW
  walker = getSquare(); //walker = current square location
  
  while(walker != NULL)
  {
    //if there's a square to the right, then move to the right
    if(walker->getLeftSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getLeftSq();
    
    //if there's a square above, then move up
    if(walker->getAboveSq() == NULL)
      break; //reached edge of board
    else
      walker = walker->getAboveSq();
    
    //diagonal shift made, now check square
    if(walker->piece && walker != sq) //if piece found, but not at destination square, then piece is in the way
      break;
    
    if(walker == sq) //if square is found
      return true;
  }
  return false;
}

//Remove later, should be using function directly from Rook class
bool Queen::isValidRookMove(Square* sq)
{
  int i;
  //must either match rank or file
  if(getRank() == sq->getRank())
  {
    if(getFile() < sq->getFile()) //if targetSquare is to the right
    {
      walker = getSquare(); //walker = piece's current square
      
      for(i = getFile(); i < sq->getFile() - 1; i++)
      {
        walker = walker->getRightSq();
        if(walker->piece)
          return false;
      }
    }
    
    else if(getFile() > sq->getFile()) //if targetSquare is to the left
    {
      walker = getSquare(); //walker = piece's current square
      for(i = getFile(); i > sq->getFile() + 1; i--)
      {
        walker = walker->getLeftSq();
        if(walker->piece)
          return false;
      }
    }
    
    else //file matches, targetSquare = currentSquare
      return false;
  }
  
  else if(getFile() == sq->getFile())
  {
    if(getRank() < sq->getRank()) //if targetSquare is above
    {
      walker = getSquare(); //walker = piece's current square
      for(i = getRank(); i < sq->getRank() - 1; i++)
      {
        walker = walker->getAboveSq();
        
        if(walker->piece)
          return false;
      }
    }
    
    else if(getFile() > sq->getRank()) //if targetSquare is to the left
    {
      walker = getSquare(); //walker = piece's current square
      for(i = getRank(); i > sq->getRank() + 1; i--)
      {
        walker = walker->getBelowSq();
        
        if(walker->piece)
          return false;
      }
    }
    
    else //rank matches, targetSquare = currentSquare
      return false;
  }
  
  else //rank or file don't match; not a straight line movement
    return false;
  return true;
}
