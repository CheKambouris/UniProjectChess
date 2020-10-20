#include "Bishop.h"

using namespace Chess;

Bishop::Bishop(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Bishop::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	legal_moves += Piece::slide(get_location(), allies, enemies,  1,  1);
	legal_moves += Piece::slide(get_location(), allies, enemies,  1, -1);
	legal_moves += Piece::slide(get_location(), allies, enemies, -1, -1);
	legal_moves += Piece::slide(get_location(), allies, enemies, -1,  1);
	return legal_moves;
}

char Bishop::get_piece_character() const {
	return 'B';
}