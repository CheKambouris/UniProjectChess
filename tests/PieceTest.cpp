#include <gtest/gtest.h>
#include "Piece.h"

TEST(PieceTest, SlideMethod) {
	Bitboard team1 = Bitboard(1, 2);
	Bitboard team2 = Bitboard(2, 3);

	Bitboard start1   = Bitboard(1, 0);
	std::string outcome1 = Chess::Piece::slide(start1, team1, team2, 0, 1).to_string();
	std::string expect1 =
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 1 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0";
	EXPECT_EQ(expect1, outcome1);

	Bitboard start2   = Bitboard(2, 0);
	std::string outcome2 = Chess::Piece::slide(start2, team1, team2, 0, 1).to_string();
	std::string expect2 =
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 1 0 0 0 0 0\n"
		"0 0 1 0 0 0 0 0\n"
		"0 0 1 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0";
	EXPECT_EQ(expect2, outcome2);

	Bitboard start3 = Bitboard(5, 2);
	std::string outcome3 = Chess::Piece::slide(start3, team1, team2, -1, 0).to_string();
	std::string expect3 =
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 1 1 1 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0";
	EXPECT_EQ(expect3, outcome3);
}