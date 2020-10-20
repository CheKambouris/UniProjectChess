#include "Rook.h"

using namespace Chess;

Rook::Rook(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Rook::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	legal_moves += Piece::slide(get_location(), allies, enemies,  1,  0); // Left
	legal_moves += Piece::slide(get_location(), allies, enemies, -1,  0); // Right
	legal_moves += Piece::slide(get_location(), allies, enemies,  0,  1); // Up
	legal_moves += Piece::slide(get_location(), allies, enemies,  0, -1); // Down
	return legal_moves;
}

char Rook::get_piece_character() const {
	return 'R';
}