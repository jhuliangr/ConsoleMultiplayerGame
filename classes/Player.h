#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player
{
private:
    int score;
    std::pair<int, int> position;
    bool wasdMapping = true;

public:
    // Constructor
    Player(int initialScore = 0, std::pair<int, int> initialPosition = {0, 0}, bool useWasdMapping);


    // Getters
    int getScore() const;
    std::pair<int, int> getPosition() const;

    // Setters
    void addScorePoint();
    void setPosition(std::pair<int, int> newPosition);
    void move(Direction direction);
    void controlMapping(char key);
};
#endif