#include <gtest/gtest.h>
#include "Pieces.h"

TEST(PawnTest, MoveMethod) {
	Chess::Pawn w_pawn(Bitboard(0, 1), Chess::Piece::White);
	Chess::Pawn b_pawn(Bitboard(0, 5), Chess::Piece::Black); // at a6
	Bitboard w_expect_moves1;
	w_expect_moves1 += w_pawn.get_location().north();
	w_expect_moves1 += w_pawn.get_location().north(2);
	EXPECT_EQ(w_pawn.get_moves(0, 0, std::vector<Chess::Action>()), w_expect_moves1);

	Bitboard black_piece_location = w_pawn.get_location().north().east();

	Bitboard w_expect_moves2;
	w_expect_moves2 += Bitboard(w_pawn.get_location().north());
	w_expect_moves2 += Bitboard(w_pawn.get_location().north(2));
	w_expect_moves2 += w_pawn.get_location().north().east(); // Test attack
	EXPECT_EQ(w_pawn.get_moves(0, black_piece_location, std::vector<Chess::Action>()), w_expect_moves2);

	Bitboard b_expect_moves = Bitboard(b_pawn.get_location().south());
	EXPECT_EQ(b_pawn.get_moves(0, 0, std::vector<Chess::Action>()), b_expect_moves);
}