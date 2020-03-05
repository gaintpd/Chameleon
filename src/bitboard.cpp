/*
  Chameleon, a UCI Chinese Chess (also called Xiangqi) engine derived from Stockfish 7
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

#include <algorithm>

#include "bitboard.h"
#include "bitcount.h"
#include "misc.h"

bool Bitboard::more_than_one() const
{
  uint32_t c = 0;
  if (bb[0])
  {
    if (bb[0] & (bb[0] - 1)) return true;
    ++c;
  }

  if (bb[1])
  {
    if (c)  return true;
    if (bb[1] & (bb[1] - 1)) return true;
    ++c;
  }

  return c > 1;
}

bool Bitboard::equal_to_two() const
{
  uint32_t c = 0;
  uint64_t t = bb[0];

  while (t) {
    t &= t - 1;
    ++c;
    if (c > 2) return false;
  }

  t = bb[1];
  while (t) {
    t &= t - 1;
    ++c;
    if (c > 2) return false;
  }

  return c == 2;
}
