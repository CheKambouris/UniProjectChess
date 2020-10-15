#include "Queen.h"

using namespace Chess;

Queen::Queen(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Queen::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
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
	while (this->get_location().north(moves).west(moves).inter(!allies)) {
		legal_moves += this->get_location().north(moves).west(moves).inter(!allies);
		++moves;
	}
	moves = 1;
	while (this->get_location().north(moves).east(moves).inter(!allies)) {
		legal_moves += this->get_location().north(moves).east(moves).inter(!allies);
		++moves;
	}
	moves = 1;
	while (this->get_location().south(moves).east(moves).inter(!allies)) {
		legal_moves += this->get_location().south(moves).east(moves).inter(!allies);
		++moves;
	}
	moves = 1;
	while (this->get_location().south(moves).west(moves).inter(!allies)) {
		legal_moves += this->get_location().south(moves).west(moves).inter(!allies);
		++moves;
	}
	return legal_moves;
}

char Queen::get_piece_character() const {
	return 'Q';
}