#include "King.h"

using namespace Chess;

King::King(Bitboard location, Color color) : Piece(location, color) {}

Bitboard King::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard moves;
	moves += this->get_location().north().inter(!allies);
	moves += this->get_location().south().inter(!allies);
	moves += this->get_location().east().inter(!allies);
	moves += this->get_location().west().inter(!allies);
	moves += this->get_location().north().east().inter(!allies);
	moves += this->get_location().north().west().inter(!allies);
	moves += this->get_location().south().east().inter(!allies);
	moves += this->get_location().south().west().inter(!allies);
	return moves;
}

char King::get_piece_character() const {
	return 'K';
}