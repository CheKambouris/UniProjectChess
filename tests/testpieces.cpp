#include <assert.h>
#include <memory>
#include <vector>

#include "Pieces.h"

using namespace Chess;

int main() {
	// ----- Bitboard -----
	// Equality test
	Bitboard bb1;
	Bitboard bb2;
	assert(bb1 == bb2);
	// North test
	bb1 = Bitboard(1 << 8);
	bb2 = Bitboard(1).north();
	assert(bb1 == bb2);
	// South test
	bb1 = bb1.south();
	bb2 = Bitboard(1);
	assert(bb1 == bb2);

	// ----- Pieces -----
	// Pawn
	Pawn pawn = Pawn(Bitboard(1 << 8), Piece::Color::White);
	std::vector<Action> history;
	assert(pawn.get_moves(0, 0, history) == pawn.get_location().north());
}