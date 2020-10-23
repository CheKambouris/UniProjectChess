#pragma once

#include "Pieces.h"
#include <vector>
#include <memory>
#include <string>

namespace Chess {
	class Board
	{
	private:
		std::vector<std::unique_ptr<Piece>> m_pieces;
		Piece::Color m_current_turn;
		std::string m_move_error;
		void set_this_to_board(const Board& board);
	public:
		Board();
		Board(const Board&);
		void init();
		const std::vector<std::unique_ptr<Piece>>& get_pieces() const;
		Piece::Color get_current_turn() const;
		void switch_current_turn();
		/** @returns A visual for the board using characters for pieces */
		std::string to_string() const;
		/** @returns A visual for the board using unicode symbols for pieces */
		std::wstring to_string_unicode() const;
		/** Attempts to move given an order in Algebraic Chess Notation
		 * @returns Whether the move succeeded or failed, get the reason
		 * failure via the error string */
		bool move(std::string move);
		/** Essentially a danger map for the team of the opposite colour. 
		 * @returns All places where all pieces of a colour can move to */
		Bitboard get_team_moves(Piece::Color color) const;
		Bitboard get_team_locations(Piece::Color color) const;
		std::string get_move_error() const;
		/** @returns Bitboard representation of the location specified in ACN*/
		static Bitboard get_bitboard_notation(std::string str_location);
		Board operator=(const Board& other) const;
	};
}