#pragma once

#include <vector>
#include <stdexcept>
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

	private:
		Bitboard m_location;
		Color m_color;

	public:
		Piece(Bitboard location, Color color): m_location(location), m_color(color) {
			if(!location.has_one_bit())
			{
				throw std::invalid_argument("Passed in 'location' has more than one bit set. ");
			}
		}
		virtual ~Piece();
		
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
		
		Color get_color() const { return m_color; }
		void set_color(Color color) { m_color = color; }

		const Bitboard& get_location() const { return m_location; }
		void set_location(Bitboard location)
		{
			if(location.has_one_bit())
			{
				m_location = location;
			}
			else
			{
				throw std::invalid_argument("Passed in 'location' has more than one bit set. ");
			}
		}
	};
} // namespace Chess