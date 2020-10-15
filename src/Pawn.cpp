#include "Pawn.h"

using namespace Chess;

Pawn::Pawn(Bitboard location, Color color) : Piece(location, color) { }

Bitboard Pawn::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const {
	Bitboard legal_moves;
	auto front = get_color() == Color::White? &Bitboard::north: &Bitboard::south;
	legal_moves += (get_location().*front)().inter(!allies);
	legal_moves += (get_location().*front)().west().inter(enemies);
	legal_moves += (get_location().*front)().east().inter(enemies);
	if ((this->get_color() == Piece::White && this->get_location().get_row() == 1) ||
		(this->get_color() == Piece::Black && this->get_location().get_row() == 6)) {
		if ((get_location().*front)().inter(!allies) != 0) {
			legal_moves += ((get_location().*front)().*front)().inter(!allies); // Double push
		}
	}
	// Todo: En passant
	return legal_moves;
}

char Pawn::get_piece_character() const
{
	return '\0';
}