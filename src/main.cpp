#include "Pieces.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

using namespace Chess;

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, ""); // allows it to use wcout properly, but seems to break normal cout
	Board board;
	board.init();

	std::string input;

	std::wcout << board.to_string_unicode() << std::endl;

	while (1)
	{
		std::wcout << "(" << (board.get_current_turn() == Piece::White? "White": "Black") << "'s turn) >>> ";

		std::getline(std::cin, input);

		if (input == "quit") { break; };

		if (board.move(input.substr(0, input.find(" ")), input.substr(input.find(" ") + 1, input.length())))
		{
			std::wcout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			std::wcout << board.to_string_unicode() << std::endl;

			board.switch_current_turn();
		}
		else { std::wcout << "Invalid move, try again!" << std::endl; }
	}
	std::wcout << "\n Bye!" << std::endl;

	return 0;
}
