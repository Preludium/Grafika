#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>

class ScoreBoard
{
    private:
        int score;
        std::string name;
    
    public:
        ScoreBoard();
        void updateScore(int);
        void updateName();
        void showScore();
        void showScoreBoard();

        bool operator<(const ScoreBoard& other)
        {
            return (this->score < other.score);            
        }
};

#endif // SCOREBOARD_H
