/**
 * This file have been took from our Teacher's github : https://github.com/erelsgl/ariel-cpp-5778.git.
 * It was not allowed to change this file. Since we use vector and not the Object Coordinate, we only change this.
 */

#include "../include/DummyPlayers.h"

const std::vector<std::size_t> XYPlayer::play(const Board& board) {
	for (uint x=0; x<board.size(); ++x) {
		for (uint y=0; y<board.size(); ++y) {
			std::vector<std::size_t> c{x,y};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
}

const std::vector<std::size_t> YXPlayer::play(const Board& board) {
	for (uint y=0; y<board.size(); ++y) {
		for (uint x=0; x<board.size(); ++x) {
			std::vector<std::size_t> c{x,y};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
}

/**
 * The illegal player tries to put a char on a cell owned by the other player.
 */
const std::vector<std::size_t> IllegalPlayer::play(const Board& board) {
	char charOfOtherPlayer = (
		myChar=='X'? 'O': 'X'
		);
	for (uint y=0; y<board.size(); ++y) {
		for (uint x=0; x<board.size(); ++x) {
			std::vector<std::size_t> c{x,y};
			if (board[c]==charOfOtherPlayer) {
				return c;
			}
		}
	}
	return {0,0};  // did not find an illegal square - play on the top-left
}

const std::vector<std::size_t> ExceptionPlayer::play(const Board& board) {
	throw std::string("hahaha");
}
