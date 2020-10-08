#include "Bitboard.h"

Bitboard::Bitboard() : bb(0) {}

Bitboard::Bitboard(uint64_t bitboard) : bb(bitboard) {}

Bitboard Bitboard::north() const { return bb << 8; }

Bitboard Bitboard::south() const { return bb >> 8; }

Bitboard Bitboard::east(int times) const {
	Bitboard rval = bb << times;
	if(!has_one_bit() || rval.get_row() != this->get_row()) {
		return rval;
	} else {
		return 0;
	}
}

Bitboard Bitboard::west(int times) const {
	Bitboard rval = bb << times;
	if(!has_one_bit() || rval.get_row() != this->get_row()) {
		return rval;
	} else {
		return 0;
	}
}

Bitboard Bitboard::inter(const Bitboard &bb) const { return bb.bb & this->bb; }

Bitboard Bitboard::unions(const Bitboard &bb) const { return bb.bb | this->bb; }

bool Bitboard::has_one_bit() const { return bb && !(bb & (bb-1)); }

Bitboard Bitboard::lsb() const { return bb & (-bb); }

uint Bitboard::bitscan_reverse() const { return log2(bb); }

uint Bitboard::get_column() const {
	if(!has_one_bit()) {
		return 0;
	}
	return bitscan_reverse() % 8;
}

uint Bitboard::get_row() const {
	if(!has_one_bit()) {
		return 0;
	}
	return bitscan_reverse() / 8;
}

std::string Bitboard::to_string() const { // I know this function is gross, pls fix it somewhen. 
	std::string board;
	std::bitset<64> bits(bb);
	for (int i = 0; i < (int)bits.size(); ++i) {
		board += std::to_string(bits[i]);
		if ((i + 1) % 8) {
			board += ' ';
		} else if (i + 1 < (int)bits.size()) {
			board += '\n';
		}
	}
	return board;
}

Bitboard Bitboard::operator!() { return !bb; }

void Bitboard::operator+=(const Bitboard& other) {
	this->bb = this->unions(other).bb;
}

bool Bitboard::operator==(const Bitboard& other) {
	return this->bb == other.bb;
}