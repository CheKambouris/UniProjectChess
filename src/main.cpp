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
"This is a chess game that utilises something based on Algebraic Chess Notation for input\n"
"In order to move a piece, selected the piece by declaring its character, then its location "
"(eg: Bishop at b1 would be Bb1) note that it is case sensitive. Then put in the location\n"
"Once you have constructed your move command, simply press enter. (Example command: Ra1 a7)\n"
"When taking pieces, don't put the piece character that you're taking. "
"When moving a pawn, they do not have a piece character. Just use the location. \n"
"When checkmated, you must give up as the game won't end for you. Type \"help\" for commands\n"
"Piece Characters:\n"
"King: K, Queen: Q, Bishop: B, Knight: K, Rook: R";

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
