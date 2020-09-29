#include "Bitboard.h"

Bitboard::Bitboard(uint64_t bitboard) : bb(bitboard) {}

Bitboard Bitboard::north() const { return bb << 8; }

Bitboard Bitboard::south() const { return bb >> 8; }

Bitboard Bitboard::east(int times = 1) const { return bb << times; }

Bitboard Bitboard::west(int times = 1) const { return bb >> times; }

Bitboard Bitboard::inter(const Bitboard &bb) const { return bb.bb & this->bb; }

Bitboard Bitboard::unions(const Bitboard &bb) const { return bb.bb | this->bb; }

bool Bitboard::has_one_bit() const { return true; }