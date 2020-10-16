#include "Rook.h"

using namespace Chess;

Rook::Rook(Bitboard location, Color color) : Piece(location, color) {}

Bitboard Rook::get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action>& history) const {
	Bitboard legal_moves;
	auto direction = +[](Bitboard location, int times) { return location.north(times); };
	legal_moves += Piece::slide(get_location(), allies, enemies, direction);
	direction = +[](Bitboard location, int times) { return location.east(times); };
	legal_moves += Piece::slide(get_location(), allies, enemies, direction);
	direction = +[](Bitboard location, int times) { return location.south(times); };
	legal_moves += Piece::slide(get_location(), allies, enemies, direction);
	direction = +[](Bitboard location, int times) { return location.west(times); };
	legal_moves += Piece::slide(get_location(), allies, enemies, direction);
	return legal_moves;
}

char Rook::get_piece_character() const {
	return 'R';
}