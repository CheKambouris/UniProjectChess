#include "Board.h"
#include <algorithm>
#include <map>
#include <regex>

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
	set_this_to_board(board);
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

void Board::set_this_to_board(const Board& board) {
	m_current_turn = board.m_current_turn;
	m_pieces.clear();
	for (auto&& piece : board.m_pieces) {
		m_pieces.push_back(std::unique_ptr<Piece>(piece->clone()));
	}
}

const std::vector<std::unique_ptr<Piece>>& Board::get_pieces() const { return m_pieces; }

Piece::Color Board::get_current_turn() const { return m_current_turn; }

void Board::switch_current_turn() { m_current_turn = (Piece::Color)((int)m_current_turn * -1); }

std::string Board::to_string() const {
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
std::wstring Board::to_string_unicode() const {
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

bool Board::move(std::string move) {
	// Input validation
	std::smatch from;
	std::smatch to;
	auto match_from = 	std::regex_search(move, from, 	std::regex("^[KQBNR]?[a-h][1-8]"));
	auto match_to = 	std::regex_search(move, to, 	std::regex("[a-h][1-8]$"));
	if (!match_from || !match_to) {
			m_move_error = "Move command is incorrect! ";
			return false;
	}

	Board next_move = *this;
	std::unique_ptr<Piece>& selected_piece = *std::find_if(next_move.m_pieces.begin(), next_move.m_pieces.end(),
		[&from](const std::unique_ptr<Piece>& piece) { 
			std::string piecechar(1, piece->get_piece_character());
			std::string piece_notation = piecechar.c_str() + piece->get_location_notation();
			return piece_notation == from.str(); 
		}).base();

	// check if selected piece exists on the board
	if (selected_piece == *next_move.m_pieces.end()) {
		m_move_error = "The piece you are trying to move does not exist! ";
		return false;
	}
	// check if piece belongs to current player
	if (selected_piece->get_color() != next_move.m_current_turn) {
		m_move_error = "You do not own that piece! ";
		return false;
	}

	// check if destination has a piece in it already
	std::unique_ptr<Piece>& piece_in_destination = *std::find_if(next_move.m_pieces.begin(), next_move.m_pieces.end(),
		[&to](const std::unique_ptr<Piece>& piece) { return piece->get_location_notation() == to.str(); }).base();


	Bitboard destination_bitboard = get_bitboard_notation(to.str());
	Bitboard ally_locations = get_team_locations(selected_piece->get_color());
	Bitboard enemy_locations = get_team_locations((Piece::Color)-selected_piece->get_color());

	Bitboard legal_moves = selected_piece->get_moves(
		ally_locations, 
		enemy_locations, 
		m_move_history
	);

	if (destination_bitboard.inter(legal_moves) == Bitboard(0)) {
		m_move_error = "That is not a legal move for the specified piece! ";
		return false;
	}
	// move selected piece from origin to destination
	selected_piece->set_location(destination_bitboard);
	
	if (piece_in_destination != *m_pieces.end()) {
		next_move.m_pieces.erase(std::remove(
				next_move.m_pieces.begin(), 
				next_move.m_pieces.end(), 
				piece_in_destination
			), next_move.m_pieces.end());
	}
	// check for if the King will be in check and therefore be an invalid move. 
	auto& ally_king = *std::find_if(next_move.m_pieces.begin(), next_move.m_pieces.end(),
		[&](const std::unique_ptr<Piece>& piece) { 
			return piece->get_piece_character() == 'K' && 
				   piece->get_color() == selected_piece->get_color(); 
			}
		).base();

	if(get_team_moves((Piece::Color)-m_current_turn).inter(ally_king->get_location())) {
		m_move_error = "Your king is in check after you move that piece! ";
		return false;
	}
	set_this_to_board(next_move);
	return true;
}

Bitboard Board::get_bitboard_notation(std::string str_location) {
	str_location = str_location.substr(str_location.length()-2);

	int rank = (int)str_location[0] - 'a';
	int file = str_location[1] - '1';

	Bitboard rval((uint64_t)1 << (8 * file + rank));

	return rval;
}

Bitboard Board::get_team_locations(Piece::Color color) const {
	Bitboard team_locations;
	for (auto&& piece : m_pieces) {
		if (piece->get_color() == color) {
			team_locations += piece->get_location();
		}
	}
	return team_locations;
}

Bitboard Board::get_team_moves(Piece::Color color) const {
	Bitboard team_moves;
	for(auto &&piece: m_pieces) {
		if(piece->get_color() == color) {
			team_moves += piece->get_moves(
				get_team_locations(color), 
				get_team_locations((Piece::Color)-color), 
				m_move_history
			);
		}
	}
	return team_moves;
}

std::string Board::get_move_error() const {
	return m_move_error;
}

Board Board::operator=(const Board& other) const {
	return Board(other);
}