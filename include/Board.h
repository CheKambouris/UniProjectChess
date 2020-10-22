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
		void set_this_to_board(const Board& board);
	public:
		Board();
		Board(const Board&);
		void init();
		const std::vector<std::unique_ptr<Piece>>& get_pieces();
		Piece::Color get_current_turn();
		void switch_current_turn();
		std::string to_string();
		std::wstring to_string_unicode();
		bool move(std::string from, std::string to);
		Bitboard get_team_moves(Piece::Color color);
		Bitboard get_team_locations(Piece::Color color);
		static Bitboard get_bitboard_notation(std::string str_location);
		Board operator=(const Board& other) const;
	};
}