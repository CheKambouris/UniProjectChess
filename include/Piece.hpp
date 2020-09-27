#pragma once

#include <vector>
#include "Bitboard.h"
#include "Action.h"

namespace Chess
{
	class Piece
	{
	public:
		enum Color
		{
			Black = -1,
			White = 1
		};

	protected:
		Bitboard m_location;
		Color m_color;

	public:
		Piece(Bitboard location, Color color) : m_location(location), m_color(color) {}
		/** Get valid moves of the target piece. 
		 * @param allies A bitboard which contains the location of all allies. 
		 * @param enemies A bitboard which contains the location of all enemies. 
		 * @param history The history of all moves made this game. 
		 * @returns Valid locations in which this piece can move
		 */
		virtual Bitboard get_moves(Bitboard allies, Bitboard enemies, const std::vector<Action> &history) const = 0;
		/** Get the piece's character. 
		 * @return The character that represents this piece in chess notation. 
		 */
		virtual char get_piece_character() const = 0;
	};
} // namespace Chess