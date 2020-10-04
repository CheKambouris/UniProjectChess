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


	std::cout << "\n---------------\n";


	std::vector<int> visual_board(64, 0);

	for (auto &&p : board.get_pieces())
	{
		int row = p->get_location().get_row();
		int col = p->get_location().get_column();
		int current_piece = p->get_piece_character();

		if (current_piece == 0) { current_piece = 'P'; }
		
		visual_board[(row * 8) + col] = current_piece;
	}

	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			char current_piece = visual_board[(row * 8) + col];
			std::cout << current_piece << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "---------------\n";

	return 0;
}
