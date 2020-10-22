#include "Board.h"
#include <algorithm>
#include <map>

using namespace Chess;

std::map<std::string, std::wstring> chess_piece_dict = {
	{"WK", L"\u2654"},
	{"BK", L"\u265A"},
	{"WQ", L"\u2655"},
	{"BQ", L"\u265B"},
	{"WB", L"\u2657"},
	{"BB", L"\u265D"},
	{"WN", L"\u2658"},
	{"BN", L"\u265E"},
	{"WR", L"\u2656"},
	{"BR", L"\u265C"},
	{"WP", L"\u2659"},
	{"BP", L"\u265F"},
};

Board::Board() {}

Board::Board(const Board& board) {
	*this = board;
}
/** Sets all black and white pieces back to their position and resets it to whites turn */
void Board::init() {
	m_current_turn = Piece::Color::White;
	m_pieces.clear();
	m_pieces.push_back(std::make_unique<Rook>(Rook    (Bitboard(0, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(Bitboard(1, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(Bitboard(2, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Queen>(Queen  (Bitboard(3, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<King>(King    (Bitboard(4, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(Bitboard(5, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(Bitboard(6, 0), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Rook>(Rook    (Bitboard(7, 0), Piece::Color::White)));

	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(0, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(1, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(2, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(3, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(4, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(5, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(6, 1), Piece::Color::White)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(7, 1), Piece::Color::White)));

	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(0, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(1, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(2, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(3, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(4, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(5, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(6, 6), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Pawn>(Pawn    (Bitboard(7, 6), Piece::Color::Black)));

	m_pieces.push_back(std::make_unique<Rook>(Rook    (Bitboard(0, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(Bitboard(1, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(Bitboard(2, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Queen>(Queen  (Bitboard(3, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<King>(King    (Bitboard(4, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Bishop>(Bishop(Bitboard(5, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Knight>(Knight(Bitboard(6, 7), Piece::Color::Black)));
	m_pieces.push_back(std::make_unique<Rook>(Rook    (Bitboard(7, 7), Piece::Color::Black)));
}

const std::vector<std::unique_ptr<Piece>>& Board::get_pieces() { return m_pieces; }

Piece::Color Board::get_current_turn() { return m_current_turn; }

void Board::switch_current_turn() { m_current_turn = (Piece::Color)((int)m_current_turn * -1); }

std::string Board::to_string() 
{
	std::string str_board =
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               \n"
		"               ";
	for(auto &&piece: m_pieces) {
		int col = piece->get_location().get_column();
		int row = piece->get_location().get_row();
		int row_index = 16 * (7 - row);
		int col_index = col * 2;
		int index = row_index + col_index;
		std::string piece_char(1, piece->get_piece_character()? piece->get_piece_character(): 'P');
		str_board.replace(index, 1, piece_char);
	}
	return str_board;
}
std::wstring Board::to_string_unicode() {
	std::wstring wstr_board =
		L"               \n"
		L"               \n"
		L"               \n"
		L"               \n"
		L"               \n"
		L"               \n"
		L"               \n"
		L"               ";
	for (auto&& piece : m_pieces) {
		int col = piece->get_location().get_column();
		int row = piece->get_location().get_row();
		int row_index = 16 * (7 - row);
		int col_index = col * 2;
		int index = row_index + col_index;

		std::string piece_char(1, piece->get_piece_character() ? piece->get_piece_character() : 'P');
		piece_char.insert(0, std::string(1, piece->get_color() == Piece::White ? 'W' : 'B'));
		std::wstring piece_symbol = chess_piece_dict[piece_char];

		wstr_board.replace(index, 1, piece_symbol);
	}
	return wstr_board;
}

bool Board::move(std::string from, std::string to) {
	// check if piece exists on the board
	std::unique_ptr<Piece>& selected_piece = *std::find_if(m_pieces.begin(), m_pieces.end(),
		[&from](const std::unique_ptr<Piece>& piece) { 
			std::string piecechar(1, piece->get_piece_character());
			std::string piece_notation = piecechar.c_str() + piece->get_location_notation();
			return piece_notation == from; 
		}).base();

	if (selected_piece == *m_pieces.end()) return false;

	// check if piece belongs to current player
	if (selected_piece->get_color() != m_current_turn) return false ;

	// check if destination is has a piece in it already
	std::unique_ptr<Piece>& piece_in_destination = *std::find_if(m_pieces.begin(), m_pieces.end(),
		[&to](const std::unique_ptr<Piece>& piece) { return piece->get_location_notation() == to; }).base();


	// move selected piece from origin to destination
	Bitboard destination_bitboard = get_bitboard_notation(to);
	Bitboard ally_locations = get_team_locations(selected_piece->get_color());
	Bitboard enemy_locations = get_team_locations(selected_piece->get_color());
	
	for(auto &&piece: m_pieces) {
		if(piece->get_color() == selected_piece->get_color()) {
			ally_locations += piece->get_location();
		}
		else {
			enemy_locations += piece->get_location();
		}
	}

	Bitboard legal_moves = selected_piece->get_moves(ally_locations, enemy_locations, std::vector<Action>());

	if (destination_bitboard.inter(legal_moves)) {
		if (piece_in_destination != *m_pieces.end()) {
			m_pieces.erase(std::remove(m_pieces.begin(), m_pieces.end(), piece_in_destination), m_pieces.end());
		}
		selected_piece->set_location(destination_bitboard);
		return true;
	}
	else {
		return false;
	}
}

Bitboard Board::get_bitboard_notation(std::string str_location) {
	str_location = str_location.substr(str_location.length()-2);

	int rank = (int)str_location[0] - 'a';
	int file = str_location[1] - '1';

	Bitboard rval((uint64_t)1 << (8 * file + rank));

	return rval;
}

Bitboard Board::get_team_locations(Piece::Color color) {
	Bitboard team_locations;
	for (auto&& piece : m_pieces) {
		if (piece->get_color() == color) {
			team_locations += piece->get_location();
		}
	}
	return team_locations;
}

Bitboard Board::get_team_moves(Piece::Color color) {
	Bitboard team_moves;
	for(auto &&piece: m_pieces) {
		if(piece->get_color() == color) {
			team_moves += piece->get_moves(
				get_team_locations(color), 
				get_team_locations((Piece::Color)-color), 
				std::vector<Action>()
			);
		}
	}
	return team_moves;
}

Board Board::operator=(const Board& other) const {
	Board new_board;
	new_board.m_current_turn = other.m_current_turn;
	for (auto&& piece : other.m_pieces) {
		new_board.m_pieces.push_back(std::unique_ptr<Piece>(piece->clone()));
	}
	return new_board;
}