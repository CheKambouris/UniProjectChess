#include "Pieces.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace Chess;

int main(int argc, char const *argv[])
{
	Board board = Board();
	Bitboard filled_spaces;

	for (auto &&p : board.get_pieces())
	{
		filled_spaces += p->get_location();
	}
	std::cout << filled_spaces.to_string() << std::endl;

	std::cout << "\n\n";

	std::cout << board.to_string() << std::endl;

	return 0;
}
