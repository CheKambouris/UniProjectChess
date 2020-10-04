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
	std::cout << filled_spaces.serialize_board() << std::endl;


	std::cout << "\n\n";
	board.render();

	return 0;
}
