# Text-Based Game

This is a simple text-based game where the player controls a character within a grid-based world. The goal is to navigate the character to reach a specific destination while avoiding obstacles.
This project will use me to practice **C++**, **git** and **docker** basics.

## Getting Started

### Run instruction
    You can run the program by: (g++ required)
    1. clone the repo from git and run: 
            g++ -o game main.cpp helper.cpp player.cpp
            ./game
    
    2. run using **docker** 
        docker run -it yonatanecs/cpp-game


### Gameplay

    Use the WASD to move the character within the grid.
    Reach the destination ('$') to win the game.
    Avoid walls ('#') and obstacles ('@').

### Customize the Game

You can customize the game by modifying the source code. Some possible enhancements include:

    Adding more levels with different grid configurations.
    Introducing additional features to the enemie monsters.
    

