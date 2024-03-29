#pragma once

#include <vector>
#include <functional>
#include <string>
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
		Piece(Bitboard location, Color color);

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
		
		Color get_color() const;

		void set_color(Color color);

		const Bitboard& get_location() const;

		void set_location(Bitboard location);

		std::string get_location_notation() const;
		/** @returns A bitboard where every bit is set along a line in the direction defined by step_x and step_y
		 * stopping BEFORE a bit in obstacles bitboard or stopping ON a bit in the enemies bitboard */
		static Bitboard slide(Bitboard start, Bitboard obstacles, Bitboard enemies, int8_t step_x, int8_t step_y);

		virtual Piece* clone() = 0;
	};
} // namespace Chess