#include "Bishop.h"

using namespace Chess;

Bishop::Bishop(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Bishop::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	int moves = 0;
	while(this->get_location().north(moves).west(moves).inter(!allies)) {
		legal_moves += this->get_location().north(moves).west(moves).inter(!allies);
	}
	moves = 0;
	while (this->get_location().north(moves).east(moves).inter(!allies)) {
		legal_moves += this->get_location().north(moves).east(moves).inter(!allies);
	}
	moves = 0;
	while (this->get_location().south(moves).east(moves).inter(!allies)) {
		legal_moves += this->get_location().south(moves).east(moves).inter(!allies);
	}
	moves = 0;
	while (this->get_location().south(moves).west(moves).inter(!allies)) {
		legal_moves += this->get_location().south(moves).west(moves).inter(!allies);
	}
	return legal_moves;
}

char Bishop::get_piece_character() const {
	return 'B';
}