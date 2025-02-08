#include "Player.hpp"

#include "Core/Game.hpp"

Player::Player(glm::vec2 startingPosition) {
	this->position = startingPosition;
	this->size = { 32, 32 };
}

Player::~Player() {}

void Player::update(Game* game) {
}

void Player::render(Game* game) {
	SDL_FRect rect = { this->position.x, this->position.y, this->size.x, this->size.y };
	SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(game->renderer, &rect);
}