#pragma once

#include "Piece.hpp"

namespace Chess
{
	class King: public Piece
	{
	public:
		King(Bitboard location, Color color);
		Bitboard get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const override;
		char get_piece_character() const override;
	};
}