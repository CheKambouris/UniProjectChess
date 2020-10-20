#include <gtest/gtest.h>
#include "Bitboard.h"

// Keep in mind that Bitboards fill from left to right, bottom to top.
// But binary numbers are from right to left. 7 over bit-shifted
// to the right is equivalent of moving it to the left 7 times.

TEST(BitboardTest, NorthProperty) {
	Bitboard bb1 = Bitboard(1);
	Bitboard bb2 = Bitboard(1 << 8);
	EXPECT_EQ(bb1.north(), bb2);
	Bitboard bb3 = Bitboard(1 << 62);
	EXPECT_EQ(bb3, Bitboard(0));
	Bitboard bb4 = Bitboard((uint64_t)1 << 8 * 17);
	EXPECT_EQ(bb4, Bitboard(0));
}

TEST(BitboardTest, SouthProperty) {
	Bitboard bb1 = Bitboard(1 << 8);
	Bitboard bb2 = Bitboard(1);
	EXPECT_EQ(bb1.south(), bb2);
	EXPECT_EQ(bb2.south(), Bitboard(0));
}

TEST(BitboardTest, EastProperty) {
	Bitboard bb1 = Bitboard(1);
	Bitboard bb2 = Bitboard(1 << 1); // 00001 -> 00010
	Bitboard bb3 = Bitboard(1 << 7); // = 10000000 (one column)
	Bitboard bb4 = Bitboard(0b10101);

	EXPECT_EQ(bb1.east(), bb2);
	EXPECT_EQ(bb3.east(), Bitboard(0));
	EXPECT_EQ(bb4.east(), Bitboard(0));
}

TEST(BitboardTest, WestProperty) {
	Bitboard bb1 = Bitboard(1 << 1);
	Bitboard bb2 = Bitboard(1);
	Bitboard bb3 = Bitboard(0b10101);

	EXPECT_EQ(bb1.west(), bb2);
	EXPECT_EQ(bb2.west(), Bitboard(0));
	EXPECT_EQ(bb3.east(), Bitboard(0));
}

TEST(BitboardTest, InterMethod) {
	Bitboard bb1 = Bitboard(0b11101);
	Bitboard bb2 = Bitboard(0b01010);
	Bitboard bb3 = Bitboard(0b01000);
	EXPECT_EQ(bb1.inter(bb2), bb3);
}

TEST(BitboardTest, UnionsMethod) {
	Bitboard bb1 = Bitboard(0b11101);
	Bitboard bb2 = Bitboard(0b01010);
	Bitboard bb3 = Bitboard(0b11111);
	EXPECT_EQ(bb1.unions(bb2), bb3);
}

TEST(BitboardTest, HasOneBitProperty) {
	Bitboard bb1 = Bitboard(0b11101);
	Bitboard bb2 = Bitboard(0b01000);
	Bitboard bb3 = Bitboard(0b11111);
	EXPECT_FALSE(bb1.has_one_bit());
	EXPECT_TRUE(bb2.has_one_bit());
	EXPECT_FALSE(bb3.has_one_bit());
}

TEST(BitboardTest, LSBProperty) {
	Bitboard bb1 	= Bitboard(0b11101);
	Bitboard bb1LSB = Bitboard(0b00001);
	Bitboard bb2 	= Bitboard(0b11000);
	Bitboard bb2LSB = Bitboard(0b01000);
	Bitboard bb3 	= Bitboard(0b10100);
	Bitboard bb3LSB = Bitboard(0b00100);
	EXPECT_EQ(bb1.lsb(), bb1LSB);
	EXPECT_EQ(bb2.lsb(), bb2LSB);
	EXPECT_EQ(bb3.lsb(), bb3LSB);
}

TEST(BitboardTest, BitScanReverseMethod) {
	Bitboard bb1 = Bitboard(0b00000001);
	uint bb1expect = 0;
	Bitboard bb2 = Bitboard(0b00001000);
	uint bb2expect = 3;
	Bitboard bb3 = Bitboard(0b00101000);
	uint bb3expect = 5;
	EXPECT_EQ(bb1.bitscan_reverse(), bb1expect);
	EXPECT_EQ(bb2.bitscan_reverse(), bb2expect);
	EXPECT_EQ(bb3.bitscan_reverse(), bb3expect);
}

TEST(BitboardTest, GetColumnProperty) {
	Bitboard bb1 = Bitboard(1);
	Bitboard bb2 = Bitboard(1 << 1);
	Bitboard bb3 = Bitboard(0b000010001);
	EXPECT_EQ(bb1.get_column(), 0);
	EXPECT_EQ(bb2.get_column(), 1);
	EXPECT_EQ(bb3.get_column(), 0);
}

TEST(BitboardTest, GetRowProperty) {
	Bitboard bb1 = Bitboard(1);
	Bitboard bb2 = Bitboard(1 << 8);
	Bitboard bb3 = Bitboard(1 << 16);
	Bitboard bb4 = Bitboard(0b000010001);
	EXPECT_EQ(bb1.get_row(), 0);
	EXPECT_EQ(bb2.get_row(), 1);
	EXPECT_EQ(bb3.get_row(), 2);
	EXPECT_EQ(bb4.get_row(), 0);
}

TEST(BitboardTest, ToStringProperty) {
	Bitboard bb1 = Bitboard(1 << 8); //Equivalent to 1.north
	std::string bb1string =
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"1 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0";
	EXPECT_EQ(bb1.to_string(), bb1string);
}

TEST(BitboardTest, EqualsOperator) {
	Bitboard bb1 = Bitboard(1 << 8);
	Bitboard bb2 = Bitboard(1 << 8);
	EXPECT_TRUE(bb1 == bb2);
	EXPECT_FALSE(bb1 == Bitboard());
}

TEST(BitboardTest, NotOperator) {
	Bitboard bb1(0);
	Bitboard bb2(1);
	Bitboard bb1expect(UINT64_MAX);
	Bitboard bb2expect(UINT64_MAX - 1);
	EXPECT_EQ(!bb1, bb1expect);
	EXPECT_EQ(!bb2, bb2expect);
}