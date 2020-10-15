#include "Knight.h"

using namespace Chess;

Knight::Knight(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Knight::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	legal_moves += this->get_location().north(2).east() .inter(!allies);
	legal_moves += this->get_location().north(2).west() .inter(!allies);
	legal_moves += this->get_location().west(2) .north().inter(!allies);
	legal_moves += this->get_location().west(2) .south().inter(!allies);
	legal_moves += this->get_location().south(2).east() .inter(!allies);
	legal_moves += this->get_location().south(2).west() .inter(!allies);
	legal_moves += this->get_location().east(2) .north().inter(!allies);
	legal_moves += this->get_location().east(2) .south().inter(!allies);
	return legal_moves;
}

char Knight::get_piece_character() const {
	return 'N';
}