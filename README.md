## Overview

Chameleon is a free, powerful UCI chess engine derived from Stockfish. It is not a complete chess program and requires a UCI-compatible GUI (e.g. CChessGUI, BHGui or Shayu Xiangqi) in order to be used comfortably. Read the documentation for your GUI of choice for information about how to use Chameleon with it.

## Files

This distribution of Chameleon consists of the following files:

  * Readme.md, the file you are currently reading.

  * LICENSE, a text file containing the GNU General Public License version 3.

  * src, a directory containing the full source code, including a sln
    that can be used to compile Chameleon on Windows systems.

## UCI parameters

Currently, Chameleon has the following UCI options:

  * #### Contempt
    A positive value for contempt favors middle game positions and avoids draws.

  * #### Threads
    The number of CPU threads used for searching a position. For best performance, set 
    this equal to the number of CPU cores available.

  * #### Hash
    The size of the hash table in MB.

  * #### Clear Hash
    Clear the hash table.

  * #### Ponder
    Let Chameleon ponder its next move while the opponent is thinking.

  * #### MultiPV
    Output the N best lines (principal variations, PVs) when searching.
    Leave at 1 for best performance.

  * #### Move Overhead
    Assume a time delay of x ms due to network and GUI overheads. This is useful to 
    avoid losses on time in those cases.

  * #### Minimum Thinking Time
    Search for at least x ms per move. 

  * #### Slow Mover
    Lower values will make Chameleon take less time in games, higher values will 
    make it think longer.
    
  * #### Nodes Time
    Tells the engine to use nodes searched instead of wall time to account for 
    elapsed time. Useful for engine testing.

### Improving the code

If you want to help improve the code, there are several valuable ressources:

* [In this wiki,](https://www.chessprogramming.org) many techniques used in
Stockfish are explained with a lot of background information.

* [The section on Stockfish](https://www.chessprogramming.org/Stockfish)
describes many features and techniques used by Stockfish. However, it is
generic rather than being focused on Stockfish's precise implementation.
Nevertheless, a helpful resource.

* The latest source can always be found on [GitHub](https://github.com/Etercyber/Chameleon/).
Discussions about Stockfish take place in the [FishCooking](https://groups.google.com/forum/#!forum/fishcooking) 
group and engine testing is done on [Fishtest](http://tests.stockfishchess.org/tests).
If you want to help improve Stockfish, please read this [guideline](https://github.com/glinscott/fishtest/wiki/Creating-my-first-test)
first, where the basics of Stockfish development are explained.

## Terms of use

Chameleon is free, and distributed under the **GNU General Public License version 3**
(GPL v3). Essentially, this means that you are free to do almost exactly
what you want with the program, including distributing it among your
friends, making it available for download from your web site, selling
it (either by itself or as part of some bigger software package), or
using it as the starting point for a software project of your own.

The only real limitation is that whenever you distribute Stockfish in
some way, you must always include the full source code, or a pointer
to where the source code can be found. If you make any changes to the
source code, these changes must also be made available under the GPL.

For full details, read the copy of the GPL v3 found in the file named
*LICENSE*.
