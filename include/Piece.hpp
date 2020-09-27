#include <vector>
#include "BitBoard.h"
#include "Action.h"

namespace Chess {

class Piece {
public:
	enum Color {
		Black = -1,
		White = 1
	};
protected:
	BitBoard m_location;
	Color m_color;
public:
	Piece(BitBoard location, Color color): m_location(location), m_color(color) { }
	/** Get valid moves of the target piece. 
	 * @param allies A bitboard which contains the location of all allies. 
	 * @param enemies A bitboard which contains the location of all enemies. 
	 * @param history The history of all moves made this game. 
	 * @returns Valid locations in which this piece can move
	*/
	virtual BitBoard get_moves(BitBoard white, BitBoard black, const std::vector<Action>& history) const = 0;
	/** Get the piece's character. 
	 * @return The character that represents this piece in chess notation. 
	 */
	virtual char get_piece_character() const = 0;
};
}