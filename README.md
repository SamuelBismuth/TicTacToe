# Connect_4

A repository for the assignments of the course c++.

# This repository includes :

The code with h files and cpp files.
The documentation (doxygen) in the doxygen folder.
The LICENCE  (GNU public)
Our main.
The makefile.
a txt file with our id's.

# How to run :

Type the command line "make all" in your terminal.

# Attention

We put all the h files and cpp files in the main folder because of automatics tests.

# Summary

Board : class for edit the game.
Player : virtual class that represent a player in the game.
DummyPlayers : many example of players that herit of player class.

TicTacToe: class that manage the game.
- this class is introduced with the size of the board.
- method « play  » -> run complete game with 2 players 
first player play as X , the second as O.
- method « board » -> return the final board after that the game is finish.
- method « winner » ->  return the winner.
(if draw the winner is the second player (O))

Champion: class that extend Player.
- method « name » return the name of the student assigner 
- method « play » have to win vs each of four players in DummyPlayers as well as X and O player.

