#include "Board.h"
#include <algorithm>

using namespace Chess;

Board::Board()
{
	m_current_turn = Piece::Color::White;

	m_pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 0, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 1, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 2, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Queen>(Queen  (uint64_t(1) << 3, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<King>(King    (uint64_t(1) << 4, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 5, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 6, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 7, Piece::Color::White)));

	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 8, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 9, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 10, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 11, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 12, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 13, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 14, Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 15, Piece::Color::White)));

	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 48, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 49, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 50, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 51, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 52, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 53, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 54, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 55, Piece::Color::Black)));

	m_pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 56, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 57, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 58, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<King>(King    (uint64_t(1) << 59, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Queen>(Queen  (uint64_t(1) << 60, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 61, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 62, Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 63, Piece::Color::Black)));
}

const std::vector<std::unique_ptr<Piece>>& Board::get_pieces() { return m_pieces; }

Piece::Color Board::get_current_turn() { return m_current_turn; }

void Board::switch_current_turn() { m_current_turn = (Piece::Color)((int)m_current_turn * -1); }

std::string Board::to_string() 
{
	std::string rval;
	std::vector<int> visual_board(64, 0);

	for (auto &&p : m_pieces)
	{
		int row = p->get_location().get_row();
		int col = p->get_location().get_column();
		int current_piece = p->get_piece_character();

		if (current_piece == 0) { current_piece = 'P'; }
		
		visual_board[(row * 8) + col] = current_piece;
	}

	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			char current_piece = visual_board[(row * 8) + col];
			rval += current_piece;
			rval += ' ';
			if (current_piece == 0) { rval += ' '; };
		}
		if(row < 7) {
			rval += '\n';
		}
	}
	return rval;
}

bool Board::move(std::string from, std::string to) {
	// check if piece exists on the board
	std::unique_ptr<Piece>& selected_piece = *std::find_if(m_pieces.begin(), m_pieces.end(),
		[&from](const std::unique_ptr<Piece>& piece) { return piece->get_location_notation() == from; }).base();

	if (selected_piece)
	{
		// check if destination is has a piece in it already
		std::unique_ptr<Piece>& piece_in_destination = *std::find_if(m_pieces.begin(), m_pieces.end(),
			[&to](const std::unique_ptr<Piece>& piece) { return piece->get_location_notation() == to; }).base();

		// if so remove piece in destination
		if (piece_in_destination)
		{
			m_pieces.erase(std::remove(m_pieces.begin(), m_pieces.end(), piece_in_destination), m_pieces.end());
		}

		// move selected piece from origin to destination
		selected_piece->set_location(get_bitboard_notation(to));
		return true;
	}

	return false;
}

Bitboard Board::get_bitboard_notation(std::string str_location) {
	str_location = str_location.substr(str_location.length()-2);

	int row = (int)str_location[0] - 'a';
	int col = str_location[1] - '1';

	return 1 << (8 * row + col);
}