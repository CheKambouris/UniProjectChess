#pragma once

#include <vector>
#include <stdexcept>
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

		static Bitboard slide(Bitboard start, Bitboard obstacles, Bitboard enemies, Bitboard(*direction)(Bitboard, int));
	};
} // namespace Chess