#pragma once

#include <unistd.h>
#define CLEARCOMMAND "clear"

#include <iostream>
#include <functional>

#include <termio.h>
#include <fcntl.h>

#include <thread>
#include <chrono>

#include "Piece.hpp"
#include "Board.hpp"
#include "Menu.hpp"

class Game
{
public:
    Game(int);

    void startNonBlocking();
    void endNonBlocking();

    // display the main menu
    void runMenu();
    void addPieceMenu();
    void changeThemeMenu();
    void adjustBoardSizeMenu();
    void pauseMenu();

    // run the game
    void run();

    // returns the pressed key;
    static char takeInput();

    void addToPieces(std::string piece);

    static void updateHighScore(int score);
    static int readHighScore();

    void handleInput(char);

private:
    struct termios oldt, newt;
    int oldf;

    Board board;
    int sleepTime; // wait time in ms between each frame.
    int gameSpeed;
    int score;

    bool isPlaying;
};