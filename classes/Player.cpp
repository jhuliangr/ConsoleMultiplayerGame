#include "Player.h"
#include "../globals/globals.h"

// Constructor
Player::Player(int initialScore, std::pair<int, int> initialPosition)
    : score(initialScore), position(initialPosition) {}

// Getters
int Player::getScore() const
{
    return score;
}

std::pair<int, int> Player::getPosition() const
{
    return position;
}

// Setters
void Player::addScorePoint()
{
    score++;
}

void Player::setPosition(std::pair<int, int> newPosition)
{
    position = newPosition;
}

void Player::move(Direction direction)
{
    switch (direction)
    {
    case Direction::UP:
        if (position.first > 1)
        {
            position.first--;
        }
        break;
    case Direction::DOWN:
        if (position.first < HEIGHT - 2)
        {
            position.first++;
        }
        break;
    case Direction::LEFT:
        if (position.second > 1)
        {
            position.second--;
        }
        break;
    case Direction::RIGHT:
        if (position.second < WIDTH - 3)
        {
            position.second++;
        }
        break;
    }
};