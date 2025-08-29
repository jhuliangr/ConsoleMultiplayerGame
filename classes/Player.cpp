#include "Player.h"
#include "../globals/globals.h"

// Constructor
Player::Player(int initialScore, std::pair<int, int> initialPosition, bool useWasdMapping)
    : score(initialScore), position(initialPosition), wasdMapping(useWasdMapping) {}

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

void Player::controlMapping(char key)
{
    switch (wasdMapping)
    {
    case true:
        if (key == 'a' || key == 'A')
        {
            Player::move(Direction::LEFT);
        }
        if (key == 'd' || key == 'D')
        {
            Player::move(Direction::RIGHT);
        }
        if (key == 'w' || key == 'W')
        {
            Player::move(Direction::UP);
        }
        if (key == 's' || key == 'S')
        {
            Player::move(Direction::DOWN);
        }
        break;
    default:
        // Player 2 sprite
        if (key == 75)
        { // left
            player2.move(Direction::LEFT);
        }
        if (key == 77)
        { // right

            player2.move(Direction::RIGHT);
        }
        if (key == 72)
        { // up

            player2.move(Direction::UP);
        }
        if (key == 80)
        { // down
            player2.move(Direction::DOWN);
        }
    }
}