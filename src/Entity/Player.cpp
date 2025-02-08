#include "Player.hpp"

Player::Player(glm::vec2 startingPosition) {
	this->position = startingPosition;
	this->size = { 32, 32 };
}

Player::~Player() {}

void Player::update() {}

void Player::render() {}