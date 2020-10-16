#include "Bitboard.h"

Bitboard::Bitboard() : bb(0) {}

Bitboard::Bitboard(uint64_t bitboard) : bb(bitboard) {}

Bitboard Bitboard::north(int times) const {
	Bitboard rval = bb << 8 * times;
	if (!rval.has_one_bit() || !this->has_one_bit() || rval < bb) {
		return 0;
	}
	return rval;
}

Bitboard Bitboard::south(int times) const {
	Bitboard rval = bb >> 8 * times;
	if(!rval.has_one_bit() || !this->has_one_bit() || rval > bb) {
		return 0;
	}
	return rval; 
}

Bitboard Bitboard::east(int times) const {
	Bitboard rval = bb << times;
	if (!rval.has_one_bit() || !this->has_one_bit() || rval.get_row() != this->get_row()) {
		return 0;
	} else {
		return rval;
	}
}

Bitboard Bitboard::west(int times) const {
	Bitboard rval = bb >> times;
	if (!rval.has_one_bit() || !this->has_one_bit() || rval.get_row() != this->get_row()) {
		return 0;
	} else {
		return rval;
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
	std::string row;
	for (int i = 0; i < (int)bits.size(); ++i) {
		row += std::to_string(bits[i]);
		if ((i + 1) % 8) {
			row += ' ';
		} else {
			row += '\n';
			board.insert(0, row);
			row.clear();
		}
	}
	board.erase(board.end()-1);
	return board;
}

Bitboard Bitboard::operator!() const { return bb ^ UINT64_MAX; }

void Bitboard::operator+=(const Bitboard& other) {
	this->bb = this->unions(other).bb;
}

bool Bitboard::operator==(const Bitboard& other) const {
	return this->bb == other.bb;
}

bool Bitboard::operator!=(const Bitboard& other) const {
	return this->bb != other.bb;
}

Bitboard::operator uint64_t() const {
	return bb;
}