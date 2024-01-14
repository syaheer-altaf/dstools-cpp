#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "DSNode.hpp"
#include "DSList.hpp"

using namespace DSTools;

/* Class Declaration */
class Player
{
private:
    char sign;
    bool isMax;
    Player* opponent;
public:
    Player(char, bool);
    Player(bool);
    void setSign(char);
    void setOpponent(Player*);
    Player* getOpponent();
    char getSign();
    bool getMax();
};

/* Method Declarations */
void display(List<char>&);
void setBoard(List<char>&);
void updateBoard(List<char>&, Player, int);
List<int> emptySpots(List<char>);
bool isCell(List<char>, int);
bool isWin(List<char>, Player);
bool isDraw(List<char>);
bool isGameOver(List<char>);
int min(int, int);
int max(int, int);
int score(List<char>, Player);
int minimax(List<char>, Player);
int calMax(List<char>, Player);

#endif