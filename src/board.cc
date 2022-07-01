#include "board.hpp"

Board::Board ()
{
  for (int i = 0; i < BOARD_HEIGHT_; ++i) {
    for (int j = 0; j < BOARD_WIDTH_; ++j) {
      board_number_[i][j] = i * BOARD_HEIGHT_ + j + 1;
    }
  }

  blank_point_.first  = BOARD_WIDTH_  - 1;
  blank_point_.second = BOARD_HEIGHT_ - 1;

  shuffle_puzzle ();
}

void Board::shuffle_puzzle ()
{
  const int OPERATE_TIEMS = 1000;

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  for (int i = 0; i < OPERATE_TIEMS; ++i) {
    move_blank (static_cast<int> (engine () % 4));
  }
}

void Board::move_blank (int num)
{
  std::pair<int, int> old_blank_point;

  old_blank_point.first  = blank_point_.first;
  old_blank_point.second = blank_point_.second;

  switch (num) {
    case 0: // d
      blank_point_.first =
        std::min (BOARD_WIDTH_ - 1, blank_point_.first + 1);
      break;
    case 1: // a
      blank_point_.first =
        std::max (0, blank_point_.first - 1);
      break;
    case 2: // w
      blank_point_.second =
        std::max (0, blank_point_.second - 1);
      break;
    case 3: // s
      blank_point_.second =
        std::min (BOARD_HEIGHT_ - 1, blank_point_.second + 1);
      break;
  }
  swap_between_blank_and_number (old_blank_point);
}

void Board::swap_between_blank_and_number (std::pair<int, int> old_blank_point)
{
  board_number_[old_blank_point.second][old_blank_point.first] =
    board_number_[blank_point_.second][blank_point_.first];
}

void Board::print ()
{
  std::system ("clear");
  printf ("+--+--+--+--+\n");
  for (int i = 0; i < BOARD_HEIGHT_; ++i) {
    for (int j = 0; j < BOARD_WIDTH_; ++j) {
      (blank_point_.first != j || blank_point_.second != i)
        && board_number_[i][j] != BLANK_NUMBER
      ? printf ("|%2d", board_number_[i][j])
      : printf ("|  ");
    }
    printf ("|\n");
    printf ("+--+--+--+--+\n");
  }
}

void Board::operate_puzzle ()
{
  int operate_number = -1;
  std::string key_char;

  getline (std::cin, key_char);

  operate_number =
    key_char[0] == 'd' ? 0 :
    key_char[0] == 'a' ? 1 :
    key_char[0] == 'w' ? 2 :
    key_char[0] == 's' ? 3 : 0;

  move_blank (operate_number);
}

bool Board::is_complete ()
{
  int counter = 1;

  for (int i = 0; i < BOARD_HEIGHT_; ++i) {
    for (int j = 0; j < BOARD_HEIGHT_; ++j) {
      if (counter != board_number_[i][j]) {
        return false;
      }

      if (15 == counter) {
        return true;
      }

      ++counter;
    }
  }
  return false;
}
