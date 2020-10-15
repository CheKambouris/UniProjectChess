#include "Rook.h"

using namespace Chess;

Rook::Rook(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Rook::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	int moves = 1;
	while (this->get_location().north(moves).inter(!allies)) {
		legal_moves += this->get_location().north(moves).inter(!allies);
		++moves;
	}
	moves = 1;
	while (this->get_location().east(moves).inter(!allies)) {
		legal_moves += this->get_location().east(moves).inter(!allies);
		++moves;
	}
	moves = 1;
	while (this->get_location().south(moves).inter(!allies)) {
		legal_moves += this->get_location().south(moves).inter(!allies);
		++moves;
	}
	moves = 1;
	while (this->get_location().west(moves).inter(!allies)) {
		legal_moves += this->get_location().west(moves).inter(!allies);
		++moves;
	}
	return legal_moves;
}

char Rook::get_piece_character() const {
	return 'R';
}