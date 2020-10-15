#pragma once

#include "Pieces.h"
#include <vector>
#include <memory>
#include <string>

using namespace Chess;

class Board
{
private:
	std::vector<std::unique_ptr<Piece>> m_pieces;
	Piece::Color m_current_turn;
public:
	Board();
	const std::vector<std::unique_ptr<Piece>>& get_pieces();
	Piece::Color get_current_turn();
	void switch_current_turn();
	std::string to_string();
	std::wstring to_string_unicode();
	bool move(std::string from, std::string to);
	static Bitboard get_bitboard_notation(std::string str_location);
};