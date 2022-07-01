#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <utility>

class Board
{
  private:
    static const int BOARD_HEIGHT_ = 4;
    static const int BOARD_WIDTH_  = BOARD_HEIGHT_;
    const int BLANK_NUMBER  = 16;
    int board_number_[BOARD_HEIGHT_][BOARD_WIDTH_];
    std::pair<int, int> blank_point_;

    void shuffle_puzzle ();
    void move_blank (int num);
    void swap_between_blank_and_number (std::pair<int, int> old_blank_point);


  public:
    static constexpr std::string_view CLEAR_MESSAGE_ = "Conguraturations!!!!11!";

    Board ();
    void print ();
    void operate_puzzle ();
    bool is_complete ();
};
