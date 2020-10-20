#include <gtest/gtest.h>
#include "Queen.h"

TEST(QueenTest, MoveProperty) {
	Chess::Queen queen = Chess::Queen(Bitboard(1), Chess::Piece::White);
	std::string outcome1 = queen.get_moves(0, 0, std::vector<Chess::Action>()).to_string();
	std::string expect1 =
		"1 0 0 0 0 0 0 1\n"	
		"1 0 0 0 0 0 1 0\n"
		"1 0 0 0 0 1 0 0\n"
		"1 0 0 0 1 0 0 0\n"
		"1 0 0 1 0 0 0 0\n"
		"1 0 1 0 0 0 0 0\n"
		"1 1 0 0 0 0 0 0\n"
		"0 1 1 1 1 1 1 1";
	EXPECT_EQ(outcome1, expect1);

	queen.set_location(queen.get_location().north().east().north().east().north().east());
	std::string outcome2 = queen.get_moves(0, 0, std::vector<Chess::Action>()).to_string();
	std::string expect2 =
		"0 0 0 1 0 0 0 1\n"	
		"1 0 0 1 0 0 1 0\n"
		"0 1 0 1 0 1 0 0\n"
		"0 0 1 1 1 0 0 0\n"
		"1 1 1 0 1 1 1 1\n"
		"0 0 1 1 1 0 0 0\n"
		"0 1 0 1 0 1 0 0\n"
		"1 0 0 1 0 0 1 0";
	EXPECT_EQ(outcome2, expect2);

	std::string outcome3 = queen.get_moves(0, Bitboard(1).north().east().north().east(), std::vector<Chess::Action>()).to_string();
	std::string expect3 =
		"0 0 0 1 0 0 0 1\n"	
		"1 0 0 1 0 0 1 0\n"
		"0 1 0 1 0 1 0 0\n"
		"0 0 1 1 1 0 0 0\n"
		"1 1 1 0 1 1 1 1\n"
		"0 0 1 1 1 0 0 0\n"
		"0 0 0 1 0 1 0 0\n"
		"0 0 0 1 0 0 1 0";
	EXPECT_EQ(outcome3, expect3);

	std::string outcome4 = queen.get_moves(Bitboard(1).north().east().north().east().north(), 0, std::vector<Chess::Action>()).to_string();
	std::string expect4 =
		"0 0 0 1 0 0 0 1\n"	
		"1 0 0 1 0 0 1 0\n"
		"0 1 0 1 0 1 0 0\n"
		"0 0 1 1 1 0 0 0\n"
		"0 0 0 0 1 1 1 1\n"
		"0 0 1 1 1 0 0 0\n"
		"0 1 0 1 0 1 0 0\n"
		"1 0 0 1 0 0 1 0";
	EXPECT_EQ(outcome4, expect4);
}