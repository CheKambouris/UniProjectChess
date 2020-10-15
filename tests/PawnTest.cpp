#include <gtest/gtest.h>
#include "Pieces.h"

TEST(PawnTest, MoveMethod) {
	Chess::Pawn w_pawn(Bitboard(1).north(), Chess::Piece::White); // at a2
	Chess::Pawn b_pawn(Bitboard((uint64_t)1 << 8 * 6).south(), Chess::Piece::Black); // at a6
	Bitboard w_expect_moves1;
	w_expect_moves1 += w_pawn.get_location().north();
	w_expect_moves1 += w_pawn.get_location().north().north();
	Bitboard w_expect_moves2;
	w_expect_moves2 += Bitboard(w_pawn.get_location().north());
	w_expect_moves2 += Bitboard(w_pawn.get_location().north().north());
	w_expect_moves2 += w_pawn.get_location().north().east(); // Test attack
	Bitboard b_expect_moves;
	b_expect_moves += Bitboard(b_pawn.get_location().south());

	Bitboard black_piece_location = w_pawn.get_location().north().east();

	EXPECT_EQ(w_pawn.get_moves(0, 0, std::vector<Chess::Action>()), w_expect_moves1);
	EXPECT_EQ(w_pawn.get_moves(0, black_piece_location, std::vector<Chess::Action>()), w_expect_moves2);
	EXPECT_EQ(b_pawn.get_moves(0, 0, std::vector<Chess::Action>()), b_expect_moves);
}