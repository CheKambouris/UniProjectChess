#pragma once

#include <cstdint>
#include <math.h>

// As simple wrapper for uint64 for use with 8x8 game boards
class Bitboard
{
private:
	uint64_t bb;

public:
	Bitboard();
	Bitboard(uint64_t bitboard);
	/** @return A copy of the bitboard shifted north. Empty if out of range. */
	Bitboard north() const;
	/** @return A copy of the bitboard shifted south. Empty if out of range. */
	Bitboard south() const;
	/** @return A copy of the bitboard shifted east. Empty if out of range or if on a different row (If has one bit). */
	Bitboard east(int times = 1) const;
	/** @return A copy of the bitboard shifted west. Empty if out of range or if on a different row (If has one bit). */
	Bitboard west(int times = 1) const;
	/** @return A Bitboard which only contains all bits in common between this and the other */
	Bitboard inter(const Bitboard &bb) const;
	/** @return A Bitboard which contains all bits in either this and the other */
	Bitboard unions(const Bitboard &bb) const;
	/** @return Whether or not this Bitboard has a single bit or not */
	bool has_one_bit() const;
	/** @return A Bitboard which contains only the least significant bit from this one */
	Bitboard lsb() const;
	/** @returns The index of the most significant bit. Not efficient. */
	uint bitscan_reverse() const;
	/** @returns The index of the column of the bit in the Bitboard if there is one bit, 0 if there is not one bit. */
	uint get_column() const;
	/** @returns The index of the row of the bit in the Bitboard if there is one bit, 0 if there is not one bit. */
	uint get_row() const;
	/** @returns This Bitboard but all 1's are now 0's and vice versa. */
	Bitboard operator!();
	/** Equivalent to making the Bitboard on the left equal to the intersection of the two Bitboards. */
	void operator+=(const Bitboard& other);
};