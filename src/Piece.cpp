#include "Piece.h"

using namespace Chess;

Piece::Piece(Bitboard location, Color color): m_location(location), m_color(color) {
	if(!location.has_one_bit()) {
		throw std::invalid_argument("Passed in 'location' has more than one bit set. ");
	}
}

Piece::~Piece() { };

Piece::Color Piece::get_color() const { return m_color; }

void Piece::set_color(Color color) { m_color = color; }

const Bitboard& Piece::get_location() const { return m_location; }

void Piece::set_location(Bitboard location) {
	if(location.has_one_bit()) {
		m_location = location;
	} else {
		throw std::invalid_argument("Passed in 'location' has more than one bit set. ");
	}
}

std::string Piece::get_location_notation() const {
	std::string loc;
	// if(get_piece_character() != '\0') {
	// 	loc += get_piece_character();
	// }
	loc += 'a' + get_location().get_column();
	loc += std::to_string(get_location().get_row() + 1);
	return loc;
}

Bitboard Piece::slide(Bitboard start, Bitboard obstacles, Bitboard enemies, Bitboard(*direction)(Bitboard, int)) {
	Bitboard rval;
	for(int i = 1; direction(start, i).inter(!obstacles); ++i) {
		rval += direction(start, i);
		if (direction(start, i).inter(enemies)) break;
	}
	return rval;
}