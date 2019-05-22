/*
  Chameleon, a UCI chinese chess playing engine derived from Stockfish
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2017 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad
  Copyright (C) 2017 Wilbert Lee

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "types.h"

namespace PSQT
{
#define S(mg, eg) make_score(mg, eg)

	// Bonus[PieceType][Square / 2] contains Piece-Square scores. For each piece
	// type on a given square a (middlegame, endgame) score pair is assigned. Table
	// is defined for files A..D and white side: it is symmetric for black side and
	// second half of the files.
	const Score Bonus[PIECE_TYPE_NB][SQUARE_NB] =
	{ { },
	{
		// Pawn
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(3, 0), S(3, 0), S(9, 0), S(11, 0), S(13,  0), S(11, 0), S(9, 0), S(3, 0), S(3, 0),

		S(19, 0), S(27, 0), S(31, 0), S(44, 0), S(49,  0), S(44, 0), S(31, 0), S(27, 0), S(19, 0),
		S(29, 0), S(36, 0), S(39, 0), S(49, 0), S(51,  0), S(49, 0), S(39, 0), S(36, 0), S(29, 0),
		S(29, 0), S(39, 0), S(54, 0), S(64, 0), S(64,  0), S(64, 0), S(54, 0), S(39, 0), S(29, 0),
		S(29, 0), S(39, 0), S(59, 0), S(74, 0), S(79,  0), S(74, 0), S(59, 0), S(39, 0), S(29, 0),
		S(9, 0), S(9, 0), S(9, 0), S(11, 0), S(13,  0), S(11, 0), S(9, 0), S(9, 0), S(9, 0)
	},
	{
		// Advisor
		S(0, 0), S(0, 0), S(0, 0), S(27, 0), S(0,  0), S(27, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(30, 0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(27, 0), S(0,  0), S(27, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),

		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0)
	},
	{
		// Bishop
		S(0, 0), S(0, 0), S(25,0), S(0, 0), S(0,  0), S(0, 0), S(25, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(23, 0), S(0, 0), S(0, 0), S(0, 0), S(28, 0), S(0, 0), S(0, 0), S(0, 0), S(23, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(25, 0), S(0, 0), S(0,  0), S(0, 0), S(25,0), S(0, 0), S(0, 0),

		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0)
	},
	{
		// Knight
		S(88, 0), S(85, 0), S(90, 0), S(88, 0), S(90,  0), S(88, 0), S(90, 0), S(85, 0), S(88, 0),
		S(85, 0), S(90, 0), S(92, 0), S(93, 0), S(78,  0), S(93, 0), S(92, 0), S(90, 0), S(85, 0),
		S(90, 0), S(92, 0), S(94, 0), S(95, 0), S(92,  0), S(95, 0), S(94, 0), S(92, 0), S(90, 0),
		S(90, 0), S(94, 0), S(98, 0), S(95, 0), S(98,  0), S(95, 0), S(98, 0), S(94, 0), S(90, 0),
		S(90, 0), S(98, 0), S(101,0), S(106,0), S(108, 0), S(106,0), S(101,0), S(98, 0), S(90, 0),

		S(90, 0), S(100, 0), S(99, 0), S(106, 0), S(108,  0),S(106, 0),S(99, 0), S(100, 0), S(90, 0),
		S(93, 0), S(108, 0), S(100, 0),S(107,0),  S(100,  0),S(107,0), S(100, 0),S(108, 0), S(93, 0),
		S(90, 0), S(98, 0),  S(93, 0), S(103, 0), S(99,  0), S(103, 0),S(93, 0), S(98, 0),  S(90, 0),
		S(90, 0), S(96, 0),  S(103, 0),S(97, 0),  S(94,  0), S(97, 0), S(103, 0),S(96, 0),  S(90, 0),
		S(90, 0), S(90, 0),  S(90, 0), S(96, 0),  S(90,  0), S(96, 0), S(90, 0), S(90, 0), S(90, 0)
	},
	{
		// Cannon
		S(96, 0), S(96, 0), S(97, 0), S(99, 0), S(99,  0), S(99, 0), S(97, 0), S(96, 0), S(96, 0),
		S(96, 0), S(97, 0), S(98, 0), S(98, 0), S(98,  0), S(98, 0), S(98, 0), S(97, 0), S(96, 0),
		S(97, 0), S(96, 0), S(100, 0), S(99, 0), S(110, 0), S(99, 0), S(100, 0), S(96, 0), S(97, 0),
		S(96, 0), S(70, 0), S(96, 0), S(96, 0), S(96,  0), S(96, 0), S(96, 0), S(70, 0), S(96, 0),
		S(95, 0), S(90, 0), S(99, 0), S(96, 0), S(102,  0), S(96, 0), S(99, 0), S(90, 0), S(95, 0),

		S(96, 0), S(96, 0), S(96, 0), S(96, 0), S(100, 0),S(96, 0), S(96, 0), S(96, 0), S(96, 0),
		S(96, 0), S(90, 0), S(99, 0), S(98, 0), S(98,  0), S(98, 0), S(99, 0), S(90, 0), S(96, 0),
		S(97, 0), S(97, 0), S(96, 0), S(91, 0), S(92,  0), S(91, 0), S(96, 0), S(97, 0), S(97, 0),
		S(98, 0), S(98, 0), S(96, 0), S(92, 0), S(89,  0), S(92, 0), S(96, 0), S(98, 0), S(98, 0),
		S(100, 0), S(100, 0), S(96, 0), S(91, 0), S(90,  0), S(91, 0), S(96, 0), S(100, 0), S(100, 0)
	},
	{
		// Rook
		S(194, 0), S(206, 0), S(204, 0), S(212, 0), S(200,  0), S(212, 0), S(204, 0), S(206, 0), S(194, 0),
		S(200, 0), S(208, 0), S(206, 0), S(212, 0), S(200,  0), S(212, 0), S(206, 0), S(208, 0), S(200, 0),
		S(198, 0), S(208, 0), S(204, 0), S(212, 0), S(212,  0), S(212, 0), S(204, 0), S(208, 0), S(198, 0),
		S(204, 0), S(209, 0), S(204, 0), S(212, 0), S(214,  0), S(212, 0), S(204, 0), S(209, 0), S(204, 0),
		S(208, 0), S(212, 0), S(212, 0), S(214, 0), S(218,  0), S(214, 0), S(212, 0), S(212, 0), S(208, 0),

		S(208, 0), S(211, 0), S(211, 0), S(214, 0), S(218,  0), S(214, 0), S(211, 0), S(211, 0), S(208, 0),
		S(206, 0), S(213, 0), S(213, 0), S(216, 0), S(216,  0), S(216, 0), S(213, 0), S(213, 0), S(206, 0),
		S(206, 0), S(208, 0), S(207, 0), S(214, 0), S(216,  0), S(214, 0), S(207, 0), S(208, 0), S(206, 0),
		S(206, 0), S(212, 0), S(209, 0), S(216, 0), S(233,  0), S(216, 0), S(209, 0), S(212, 0), S(206, 0),
		S(206, 0), S(208, 0), S(207, 0), S(213, 0), S(214,  0), S(213, 0), S(207, 0), S(208, 0), S(206, 0)
	},
	{
		// King
		S(0, 0), S(0, 0), S(0, 0), S(11, 0), S(15,  0), S(11, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(2, 0), S(2,  0), S(2, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(1, 0), S(1,  0), S(1, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),

		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		S(0, 0), S(0, 0), S(0, 0), S(0, 0), S(0,  0), S(0, 0), S(0, 0), S(0, 0), S(0, 0)
	}
	};
#undef S
	Score psq[COLOR_NB][PIECE_TYPE_NB][SQUARE_NB];

	// init() initializes piece square tables: the white halves of the tables are
	// copied from Bonus[] adding the piece value, then the black halves of the
	// tables are initialized by flipping and changing the sign of the white scores.
	void init()
	{
		for (PieceType pt = PAWN; pt <= KING; ++pt)
		{
			PieceValue[MG][make_piece(BLACK, pt)] = PieceValue[MG][pt];
			PieceValue[EG][make_piece(BLACK, pt)] = PieceValue[EG][pt];

			Score v = make_score(PieceValue[MG][pt], PieceValue[EG][pt]);

			for (Square s = SQ_A0; s <= SQ_I9; ++s)
				psq[BLACK][pt][~s] = -(psq[WHITE][pt][s] = v + 2 * Bonus[pt][s]);
		}
	}

} // namespace PSQT