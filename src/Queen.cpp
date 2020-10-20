#include "Queen.h"

using namespace Chess;

Queen::Queen(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Queen::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	legal_moves += Piece::slide(get_location(), allies, enemies,  1,  1);
	legal_moves += Piece::slide(get_location(), allies, enemies,  1, -1);
	legal_moves += Piece::slide(get_location(), allies, enemies, -1, -1);
	legal_moves += Piece::slide(get_location(), allies, enemies, -1,  1);

	legal_moves += Piece::slide(get_location(), allies, enemies,  1,  0);
	legal_moves += Piece::slide(get_location(), allies, enemies, -1,  0);
	legal_moves += Piece::slide(get_location(), allies, enemies,  0,  1);
	legal_moves += Piece::slide(get_location(), allies, enemies,  0, -1);

	return legal_moves;
}

char Queen::get_piece_character() const {
	return 'Q';
}