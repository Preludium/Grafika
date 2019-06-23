#include "scoreboard.h"


ScoreBoard::ScoreBoard()
{
    this->score = 0; 
}


void ScoreBoard::updateScore(int value)
{
    this->score += value;
}


void ScoreBoard::updateName()
{
    std::cout << "Type your nick: ";
    std::cin >> this->name;
}


void ScoreBoard::showScore()
{
    std::cout << this->score << std::endl;
}


void ScoreBoard::showScoreBoard()
{
    std::cout << this->name << "\t" << this->score << std::endl;
}