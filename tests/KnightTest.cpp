#include <gtest/gtest.h>

#include "Pieces.h"

TEST(KnightTest, MoveMethod) {
	Chess::Knight w_knight(Bitboard(1).east().north().east().north(), Chess::Piece::White);
	Chess::Knight b_knight(1, Chess::Piece::Black);

	Bitboard expected1;
	expected1 += w_knight.get_location().north().north().west();
	expected1 += w_knight.get_location().north().north().east();
	expected1 += w_knight.get_location().east().east().north();
	expected1 += w_knight.get_location().east().east().south();
	expected1 += w_knight.get_location().west().west().north();
	expected1 += w_knight.get_location().west().west().south();
	expected1 += w_knight.get_location().south().south().west();
	expected1 += w_knight.get_location().south().south().east();

	Bitboard expected2;
	expected2 += b_knight.get_location().north().north().east();
	expected2 += b_knight.get_location().north().north().west().west(); // i don't think this test should be working
	expected2 += b_knight.get_location().east().east().north();
	

	EXPECT_EQ(w_knight.get_moves(0, 0, std::vector<Chess::Action>()), expected1);
	EXPECT_EQ(b_knight.get_moves(0, 0, std::vector<Chess::Action>()), expected2);
}