/*////////////////////////////////////////////////////////
    TIC-TAC-TOE
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    The implementation of the main logic of the game 
    (minimax algorithm).

*/////////////////////////////////////////////////////////

#include "tictactoe.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

/* Player Class Implementation */
Player::Player(char c, bool isMax)
{
    sign = c;
    this->isMax = isMax;
}
Player::Player(bool isMax)
{
    this->isMax = isMax;
}
void Player::setSign(char c)
{
    sign = c;
}
void Player::setOpponent(Player* p)
{
    opponent = p;
}
Player* Player::getOpponent()
{
    return opponent;
}
char Player::getSign()
{
    return sign;
}
bool Player::getMax()
{
    return isMax;
}
/* Methods for Boards */
void display(List<char>& b)
{
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << '|' << b[i] << '|';
    }
    std::cout << std::endl;
    for (int i = 3; i < 6; i++) {
        std::cout << '|' << b[i] << '|';
    }
    std::cout << std::endl;
    for (int i = 6; i < 9; i++) {
        std::cout << '|' << b[i] << '|';
    }
    std::cout << std::endl;
}
void setBoard(List<char>& b)
{
    for (int i = 49; i < 58; i++) {
        char val = i;
        b.push_back(val);
    }
}
void updateBoard(List<char>& b, Player p, int i)
{
    b[i] = p.getSign();
}
List<int> emptySpots(List<char> board)
{
    List<int> empty;
    for (int i = 0; i < board.size(); i++) {
        if (board[i] != 'X' && board[i] != 'O') empty.push_back(i);
    }

    return empty;
}
bool isCell(List<char> b, int cell)
{
    List<int> a = emptySpots(b);
    bool isFree = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == cell) {
            isFree = true;
            break;
        }
    }
    return isFree;
}
bool isWin(List<char> b, Player p)
{
    if (
        b[0] == p.getSign() && b[1] == p.getSign() && b[2] == p.getSign() ||
        b[3] == p.getSign() && b[4] == p.getSign() && b[5] == p.getSign() ||
        b[6] == p.getSign() && b[7] == p.getSign() && b[8] == p.getSign() ||
        b[0] == p.getSign() && b[3] == p.getSign() && b[6] == p.getSign() ||
        b[1] == p.getSign() && b[4] == p.getSign() && b[7] == p.getSign() ||
        b[2] == p.getSign() && b[5] == p.getSign() && b[8] == p.getSign() ||
        b[0] == p.getSign() && b[4] == p.getSign() && b[8] == p.getSign() ||
        b[2] == p.getSign() && b[4] == p.getSign() && b[6] == p.getSign() 
    ) {
        return true;
    }
    else {
        return false;
    }
}
bool isDraw(List<char> b)
{
    if (emptySpots(b).size() == 0) return true;
    return false;
}
bool isGameOver(List<char> b)
{
    if (emptySpots(b).size() == 0) return true;
    else if (isWin(b, Player('X', true))) return true;
    else if (isWin(b, Player('O', false))) return true;
    else return false;
}
/* Minimax Implementation */
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int score(List<char> b, Player p)
{
    if (p.getMax() && isWin(b, p)) return 100;
    else if (!p.getMax() && isWin(b, p)) return -100;
    else return 0;
}
int minimax(List<char> b, Player p)
{
    List<int> available = emptySpots(b);
    List<char> newBoard = b;
    List<int> scoreList;

    if (isGameOver(b)) {
        return score(b, p);
    }
    
    if (p.getMax()) {
        int minEva = INT_MAX;
        for (int i = 0; i < available.size(); i++) {
            newBoard[available[i]] = p.getOpponent()->getSign();
            int eva = minimax(newBoard, *p.getOpponent());
            scoreList.push_back(eva);
            newBoard[available[i]] = ' ';
        }
        
        for (int i = 0; i < scoreList.size(); i++) {
            minEva = min(minEva, scoreList[i]);
        }
        return minEva;
    }
    else {
        int maxEva = INT_MIN;
        for (int i = 0; i < available.size(); i++) {
            newBoard[available[i]] = p.getOpponent()->getSign();
            int eva = minimax(newBoard, *p.getOpponent());
            scoreList.push_back(eva);
            newBoard[available[i]] = ' ';
        }
        
        for (int i = 0; i < scoreList.size(); i++) {
            maxEva = max(maxEva, scoreList[i]);
        }
        return maxEva;
    }
}
int calMax(List<char> b, Player p)
{
    List<int> available = emptySpots(b);
    List<int> scoreList;
    List<char> newBoard = b;

    if (available.size() == 9) {
        std::srand(time(NULL));
        return std::rand() % 9;
    }

    for (int i = 0; i < available.size(); i++) {
        newBoard[available[i]] = p.getSign();
        int score = minimax(newBoard, p);
        scoreList.push_back(score);
        newBoard[available[i]] = ' ';
    }
    int maxIndex = 0;
    int maxScore = INT_MIN;
    for (int i = 0; i < scoreList.size(); i++) {
        if (scoreList[i] > maxScore) {
            maxScore = scoreList[i];
            maxIndex = i;
        }
    }
    return available[maxIndex];
}