#pragma once

#include <cstdint>
#include <stdexcept>

class Bitboard
{
private:
	uint64_t bb;

public:
	Bitboard(uint64_t bitboard) : bb(bitboard) {}
	/** Returns a copy shifted north */
	Bitboard north() const { return bb << 8; }
	/** Returns a copy shifted south */
	Bitboard south() const { return bb >> 8; }
	/** Returns a copy shifted east */
	Bitboard east(int times = 1) const { return bb << times; }
	/** Returns a copy shifted west */
	Bitboard west(int times = 1) const { return bb >> times; }
	/** Returns a BitBoard which only contains all bits in common between this and the other */
	Bitboard inter(const Bitboard &bb) const { return bb.bb & this->bb; }
	/** Returns a BitBoard which contains all bits in either this and the other */
	Bitboard unions(const Bitboard &bb) const { return bb.bb | this->bb; }
	bool has_one_bit() const { throw std::logic_error("Not yet implemented. "); }
};