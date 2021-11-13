#include <iostream>

#include "board.hpp"

int main ()
{
  Board board;
  while (1) {
    board.print ();

    if (board.is_complete ()) {
      std::cout << board.CLEAR_MESSAGE_ << std::endl;
      break;
    }

    board.operate_puzzle ();
  }

  return 0;
}
