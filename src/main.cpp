#include "Pieces.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace Chess;


std::vector<std::unique_ptr<Piece>> createBoard()
{
	std::vector<std::unique_ptr<Piece>> pieces;
	pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 0, Piece::Color::White)));
	pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 1, Piece::Color::White)));
	pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 2, Piece::Color::White)));
	pieces.push_back(std::make_unique<Queen>(Queen  (uint64_t(1) << 3, Piece::Color::White)));
	pieces.push_back(std::make_unique<King>(King    (uint64_t(1) << 4, Piece::Color::White)));
	pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 5, Piece::Color::White)));
	pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 6, Piece::Color::White)));
	pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 7, Piece::Color::White)));

	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 8, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 9, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 10, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 11, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 12, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 13, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 14, Piece::Color::White)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 15, Piece::Color::White)));

	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 48, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 49, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 50, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 51, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 52, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 53, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 54, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Pawn>(Pawn    (uint64_t(1) << 55, Piece::Color::Black)));

	pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 56, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 57, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 58, Piece::Color::Black)));
	pieces.push_back(std::make_unique<King>(King    (uint64_t(1) << 59, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Queen>(Queen  (uint64_t(1) << 60, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Bishop>(Bishop(uint64_t(1) << 61, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Knight>(Knight(uint64_t(1) << 62, Piece::Color::Black)));
	pieces.push_back(std::make_unique<Rook>(Rook    (uint64_t(1) << 63, Piece::Color::Black)));

	return pieces;
}


int main(int argc, char const *argv[])
{
	std::vector<std::unique_ptr<Piece>> pieces = createBoard();
	for(auto &&piece: pieces) {
		std::cout << piece->get_location_notation() << std::endl;
	}
	return 0;
}
