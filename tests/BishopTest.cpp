#include <gtest/gtest.h>
#include "Bishop.h"

TEST(BishopTest, MoveMethod) {
	Chess::Bishop bishop = Chess::Bishop(Bitboard(1), Chess::Piece::White);
	std::string outcome1 = bishop.get_moves(0, 0, std::vector<Chess::Action>()).to_string();
	std::string expect1 =
		"0 0 0 0 0 0 0 1\n"
		"0 0 0 0 0 0 1 0\n"
		"0 0 0 0 0 1 0 0\n"
		"0 0 0 0 1 0 0 0\n"
		"0 0 0 1 0 0 0 0\n"
		"0 0 1 0 0 0 0 0\n"
		"0 1 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0";
	EXPECT_EQ(outcome1, expect1);

	bishop.set_location(bishop.get_location().north().east());
	std::string outcome2 = bishop.get_moves(0, 0, std::vector<Chess::Action>()).to_string();
	std::string expect2 =
		"0 0 0 0 0 0 0 1\n"
		"0 0 0 0 0 0 1 0\n"
		"0 0 0 0 0 1 0 0\n"
		"0 0 0 0 1 0 0 0\n"
		"0 0 0 1 0 0 0 0\n"
		"1 0 1 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"1 0 1 0 0 0 0 0";
	EXPECT_EQ(outcome2, expect2);
	Bitboard enemy_location = Bitboard(2, 2);
	std::string outcome3 = bishop.get_moves(0, enemy_location, std::vector<Chess::Action>()).to_string();
	std::string expect3 =
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"1 0 1 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"1 0 1 0 0 0 0 0";
	EXPECT_EQ(outcome3, expect3);
	Bitboard ally_location = enemy_location;
	std::string outcome4 = bishop.get_moves(ally_location, 0, std::vector<Chess::Action>()).to_string();
	std::string expect4 =
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"1 0 0 0 0 0 0 0\n"
		"0 0 0 0 0 0 0 0\n"
		"1 0 1 0 0 0 0 0";
	EXPECT_EQ(outcome4, expect4);
}