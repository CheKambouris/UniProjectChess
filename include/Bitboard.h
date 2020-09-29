#pragma once

#include <cstdint>
#include <stdexcept>
// As simple wrapper for uint64 for use with 8x8 game boards
class Bitboard
{
private:
	uint64_t bb;

public:
	Bitboard(uint64_t bitboard);
	/** Returns a copy shifted north */
	Bitboard north() const;
	/** Returns a copy shifted south */
	Bitboard south() const;
	/** Returns a copy shifted east */
	Bitboard east(int times = 1) const;
	/** Returns a copy shifted west */
	Bitboard west(int times = 1) const;
	/** Returns a Bitboard which only contains all bits in common between this and the other */
	Bitboard inter(const Bitboard &bb) const;
	/** Returns a Bitboard which contains all bits in either this and the other */
	Bitboard unions(const Bitboard &bb) const;
	/** Returns whether or not this Bitboard has a single bit or not */
	bool has_one_bit() const;
	/** Returns a Bitboard which contains only the least significant bit from this one */
	Bitboard Bitboard::lsb() const;
};