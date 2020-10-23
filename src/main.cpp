#include <algorithm>
#include <codecvt>
#include <iostream>
#include <memory>
#include <locale>
#include <string>
#include <vector>

#include "Board.h"
#include "Pieces.h"

using namespace Chess;

const std::string COMMANDS = 
"quit: Exit the program\n"
"ff: Surrender and exit, giving your enemy the satisfaction in knowing that they're better than you\n"
"instructions: Shows the same instructions that are shown in the beginning of the game.\n"
"help: Shows this message. ";

const std::string INSTRUCTIONS =
"INSTRUCTIONS - The following chess game can be interfaced using "
"command-line input, following algebraic chess notation. As such, "
"pieces can be moved by first typing their location (eg. Bishop at b1 would be Bb1) "
"and then destination on the board (a full move command would look like Bb1 c4). \n"
"Do not put the piece character of the piece you are taking in front of the location. "
"(eg. instead of doing Ba1 Bc3, just write Ba1 c3)\n"
"Note that this is case sensitive. To identify pieces, the following notation is used:\n"
"King: K, Queen: Q, Bishop: B, Knight: K, Rook: R, Pawn: No char, just use location";

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, ""); // allows it to use wcout properly, but seems to break normal cout
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	Board board;
	board.init();
	std::wcout << converter.from_bytes(INSTRUCTIONS) << std::endl << std::endl;
	std::wcout << board.to_string_unicode() << std::endl;
	while (1) {
		std::wcout << "(" << (board.get_current_turn() == Piece::White? "White": "Black") << "'s turn) >>> ";

		std::string input;
		std::getline(std::cin, input);

		if (input == "help") { 
			std::wcout << L"----- COMMANDS -----" << std::endl;
			std::wcout << converter.from_bytes(COMMANDS) << std::endl; 
			continue;
		};
		if (input == "instructions") {
			std::wcout << converter.from_bytes(INSTRUCTIONS) << std::endl;
			continue;
		};
		if (input == "quit") {
			break; 
		};
		if (input == "ff") {
			auto winner = board.get_current_turn() == Piece::White ? L"Black": L"White";
			std::wcout <<  winner << " wins, congrats " << winner << std::endl;
			break;
		}
		if(input == "show") {
			std::wcout << board.to_string_unicode() << std::endl;
			continue;
		}

		if (board.move(input)) {
			std::wcout << board.to_string_unicode() << std::endl;

			board.switch_current_turn();
		}
		else {
			std::wcout << converter.from_bytes(board.get_move_error()) << std::endl;
		}
	}
	return 0;
}
