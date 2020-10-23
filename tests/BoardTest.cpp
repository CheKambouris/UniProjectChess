#include "Board.h"
#include <gtest/gtest.h>
// Note: move is tested in the .sh test in input_tests
TEST(BoardTest, GetBitboardFromNotation) {
	Bitboard result1 = Chess::Board::get_bitboard_notation("a1");
	Bitboard expect1 = Bitboard(1);
	Bitboard result2 = Chess::Board::get_bitboard_notation("e1");
	Bitboard expect2 = Bitboard(1).east(4);
	Bitboard result3 = Chess::Board::get_bitboard_notation("e2");
	Bitboard expect3 = expect2.north();
	EXPECT_EQ(result1, expect1);
	EXPECT_EQ(result2, expect2);
	EXPECT_EQ(result3, expect3);
}