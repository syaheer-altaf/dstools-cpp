/*////////////////////////////////////////////////////////
    TIC-TAC-TOE
    Author(s): Mohamed Syaheer Altaf
    -----------------------------------------------------
    A simple tic-tac-toe game that employs minimax algorithm
    and exhibits the use of linked list in "XOX.cpp".

*/////////////////////////////////////////////////////////

#include "tictactoe.hpp"
#include <iostream>

int main()
{
    Player ai(true);
    Player human(false);
    Player currentPlayer(true);
    List<char> board;
    setBoard(board);
    int choosePlayer;

    std::system("cls");
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "TIC-TAC-TOE" << std::endl;
    std::cout << "Author(s): Mohamed Syaheer Altaf" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "A simple tic-tac-toe game that employs minimax algorithm\n\n" << std::endl;
    
    while (true) {
        std::cout << "Choose player (1 or 2): ";
        std::cin >> choosePlayer;
        if (choosePlayer == 1 || choosePlayer == 2) break;
        else std::cout << "Incorrect input." << std::endl;
    }
    switch (choosePlayer) {
        case 1:
            human.setSign('X');
            ai.setSign('O');
            human.setOpponent(&ai);
            ai.setOpponent(&human);
            currentPlayer = human;
            break;
        case 2:
            ai.setSign('X');
            human.setSign('O');
            ai.setOpponent(&human);
            human.setOpponent(&ai);
            currentPlayer = ai;
            break;
    }
    while (true) {
        int cell;
        if (currentPlayer.getSign() == ai.getSign()) {
            cell = calMax(board, ai);
            updateBoard(board, ai, cell);
            if (isWin(board, ai)) break;
            if (isDraw(board)) break;
            currentPlayer = human;
        }
        display(board);
        std::cout << "\nChoose a cell: ";
        std::cin >> cell;
        cell = cell - 1;
        if (isCell(board, cell)) updateBoard(board, human, cell);
        else {
            std::cout << "\nThe cell is occupied.\n";
            continue;
        }
        if (isWin(board, human)) break;
        if (isDraw(board)) break;
        currentPlayer = ai;
    }
    display(board);
    if (!isDraw(board)) {
        if (currentPlayer.getSign() == ai.getSign()) std::cout << "\nAI won!\n";
        else std::cout << "\nYou won!\n";
    }
    else {
        std::cout << "\nIt's a draw.\n";
    }
    std::system("pause");
    return 0;
}