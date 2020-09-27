#include <cstdint>
#include <stdexcept>

class BitBoard {
private:
	uint64_t bb;
public:
	BitBoard(uint64_t bitboard): bb(bitboard) { }
	/** Returns a copy shifted north */
	BitBoard north() const { return bb << 8; }
	/** Returns a copy shifted south */
	BitBoard south() const { return bb >> 8; }
	/** Returns a copy shifted east */
	BitBoard east (int times = 1) const {return bb << times; }
	/** Returns a copy shifted west */
	BitBoard west (int times = 1) const {return bb >> times; }
	/** Returns a BitBoard which only contains all bits in common between this and the other */
	BitBoard inter(const BitBoard& bb) const { return bb.bb & this->bb; }
	/** Returns a BitBoard which contains all bits in either this and the other */
	BitBoard unions(const BitBoard& bb) const { return bb.bb | this->bb; }
	bool has_one_bit() const { throw std::logic_error("Not yet implemented. "); }
};