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
	std::string render();
};