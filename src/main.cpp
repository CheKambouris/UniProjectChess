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
	// Bitboard filled_spaces;

	// for (auto &&p : board.get_pieces())
	// {
	// 	filled_spaces += p->get_location();
	// }
	// std::cout << filled_spaces.to_string() << std::endl;


	std::string input;

	std::cout << board.to_string() << std::endl;

	while (1)
	{
		std::cout << ">>> ";

		std::getline(std::cin, input);

		if (input == "quit") { break; };

		if (board.move(input.substr(0, input.find(" ")), input.substr(input.find(" ") + 1, input.length())))
		{
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			std::cout << board.to_string() << std::endl;
		}
		else { std::cout << "Invalid move, try again!" << std::endl; }
	}
	std::cout << "\n Bye!" << std::endl;

	return 0;
}
