#include <gtest/gtest.h>

#include "Pieces.h"

TEST(KingTest, MoveMethod) {
	Chess::King w_king(Bitboard(1).east().north(), Chess::Piece::White);
	Chess::King b_king(1, Chess::Piece::Black);
	std::vector<Chess::Action> history;

	Bitboard expect1;
	expect1 += w_king.get_location().north().west();
	expect1 += w_king.get_location().north();
	expect1 += w_king.get_location().north().east();
	expect1 += w_king.get_location().east();
	expect1 += w_king.get_location().south().east();
	expect1 += w_king.get_location().south();
	expect1 += w_king.get_location().south().west();
	expect1 += w_king.get_location().west();

	Bitboard expect2;
	expect2 += b_king.get_location().north();
	expect2 += b_king.get_location().north().east();
	expect2 += b_king.get_location().east();

	EXPECT_EQ(w_king.get_moves(0, 0, history), expect1);
	EXPECT_EQ(b_king.get_moves(0, 0, history), expect2);
}