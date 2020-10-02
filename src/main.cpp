#include "Pieces.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace Chess;

int main(int argc, char const *argv[])
{
	Board pieces = Board();

	for(auto &&piece: pieces.getBoard()) {
		std::cout << piece->get_location_notation() << std::endl;
	}
	return 0;
}
