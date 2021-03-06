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

#ifndef ENDGAME_H_INCLUDED
#define ENDGAME_H_INCLUDED

#include <map>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>

#include "position.h"
#include "types.h"

// EndgameType lists all supported endgames
enum EndgameType
{
  // Evaluation functions
  KNNK,  // KNN vs K
  KXK,   // Generic "mate lone king" eval
  KBNK,  // KBN vs K
  KPK,   // KP vs K
  KRKP,  // KR vs KP
  KRKB,  // KR vs KB
  KRKN,  // KR vs KN

  // Scaling functions
  SCALING_FUNCTIONS,

  KBPsK,   // KB and pawns vs K
  KRPKR,   // KRP vs KR
  KRPKB,   // KRP vs KB
  KRPPKRP, // KRPP vs KRP
  KPsK,    // K and pawns vs K
  KBPKB,   // KBP vs KB
  KBPPKB,  // KBPP vs KB
  KBPKN,   // KBP vs KN
  KNPK,    // KNP vs K
  KNPKB,   // KNP vs KB
  KPKP     // KP vs KP
};

// Endgame functions can be of two types depending on whether they return a
// Value or a ScaleFactor.
template<EndgameType E> using
eg_type = typename std::conditional < (E < SCALING_FUNCTIONS), Value, ScaleFactor >::type;

// Base and derived templates for endgame evaluation and scaling functions
template<typename T>
struct EndgameBase
{
  virtual ~EndgameBase() = default;
  virtual Color strong_side() const = 0;
  virtual T operator()(const Position &) const = 0;
};

template<EndgameType E, typename T = eg_type<E>>
struct Endgame : public EndgameBase<T>
{
  explicit Endgame(Color c) : strongSide(c), weakSide(~c) {}
  Color strong_side() const
  {
    return strongSide;
  }
private:
  Color strongSide, weakSide;
};

// The Endgames class stores the pointers to endgame evaluation and scaling
// base objects in two std::map. We use polymorphism to invoke the actual
// endgame function by calling its virtual operator().
class Endgames
{
private:
  template<typename T>
  using Map = std::map<Key, std::unique_ptr<EndgameBase<T>>>;
  template<typename T>
  Map<T> &map()
  {
    return std::get<std::is_same<T, ScaleFactor>::value>(maps);
  }
public:
  template<typename T>
  EndgameBase<T> *probe(Key key)
  {
    return map<T>().count(key) ? map<T>()[key].get() : nullptr;
  }
private:
  std::pair<Map<Value>, Map<ScaleFactor>> maps;
};

#endif // #ifndef ENDGAME_H_INCLUDED
