#pragma once

#include "Piece.h"

namespace Chess
{
	class Rook: public Piece
	{
	public:
		Rook(Bitboard location, Color color);
		Bitboard get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const override;
		char get_piece_character() const override;
		Piece* clone() override;
	};
}