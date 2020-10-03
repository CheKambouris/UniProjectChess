#pragma once

#include "Pieces.h"
#include <vector>
#include <memory>

using namespace Chess;

class Board
{
private:
	std::vector<std::unique_ptr<Piece>> board;
	Piece::Color current_turn;
public:
	Board();
	const std::vector<std::unique_ptr<Piece>>& get_pieces();
	Piece::Color get_current_turn();
	void switch_current_turn();
};