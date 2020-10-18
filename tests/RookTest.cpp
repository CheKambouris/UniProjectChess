#include <gtest/gtest.h>
#include "Rook.h"

TEST(RookTest, MoveProperty) {
	Chess::Rook rook = Chess::Rook(Bitboard(1), Chess::Piece::White);
	std::string outcome1 = rook.get_moves(0, 0, std::vector<Chess::Action>()).to_string();
	std::string expect1 =
		"1 0 0 0 0 0 0 0"
		"1 0 0 0 0 0 0 0"
		"1 0 0 0 0 0 0 0"
		"1 0 0 0 0 0 0 0"
		"1 0 0 0 0 0 0 0"
		"1 0 0 0 0 0 0 0"
		"1 0 0 0 0 0 0 0"
		"0 1 1 1 1 1 1 1";
	EXPECT_EQ(outcome1, expect1);

	rook.set_location(rook.get_location().north().east());
	std::string outcome2 = rook.get_moves(0, 0, std::vector<Chess::Action>()).to_string();
	std::string expect2 =
		"0 1 0 0 0 0 0 0"
		"0 1 0 0 0 0 0 0"
		"0 1 0 0 0 0 0 0"
		"0 1 0 0 0 0 0 0"
		"0 1 0 0 0 0 0 0"
		"0 1 0 0 0 0 0 0"
		"1 0 1 1 1 1 1 1"
		"0 1 0 0 0 0 0 0";
	EXPECT_EQ(outcome2, expect2);

	std::string outcome3 = rook.get_moves(0, Bitboard(1).north().north().east(), std::vector<Chess::Action>()).to_string();
	std::string expect3 =
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 1 0 0 0 0 0 0"
		"1 0 1 1 1 1 1 1"
		"0 1 0 0 0 0 0 0";
	EXPECT_EQ(outcome3, expect3);

	std::string outcome4 = rook.get_moves(Bitboard(1).north().north().east(), 0, std::vector<Chess::Action>()).to_string();
	std::string expect4 =
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"0 0 0 0 0 0 0 0"
		"1 0 1 1 1 1 1 1"
		"0 1 0 0 0 0 0 0";
	EXPECT_EQ(outcome4, expect4);
}