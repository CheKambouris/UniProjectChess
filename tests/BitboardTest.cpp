#include <gtest/gtest.h>
#include "Bitboard.h"

TEST(BitboardTest, EqualsOperator) {
	Bitboard bb1 = Bitboard(1 << 8);
	Bitboard bb2 = Bitboard(1 << 8);
	EXPECT_EQ(bb1, bb2);
}

TEST(BitboardTest, NorthProperty) {
	Bitboard bb1 = Bitboard(1);
	Bitboard bb2 = Bitboard(1 << 8);
	EXPECT_EQ(bb1.north(), bb2);
}

TEST(BitboardTest, SouthProperty) {
	Bitboard bb1 = Bitboard(1);
	Bitboard bb2 = Bitboard(1 << 8);
	EXPECT_EQ(bb1.south(), bb2);
}