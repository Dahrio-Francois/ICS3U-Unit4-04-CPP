// Copyright (c) 2022 St. Mother Teresa HS All rights reserved.
//
// Created by: Dahrio Francois
// Created on: April 2022
// This program lets the user try and guess the correct number between 0 and 9


#include <iostream>
#include <random>
#include <string>


int main() {
    // this function lets the user guess a random number between 0 and 9
    int guessCounter = 1;
    int guessedNumberAsInteger = 0;
    int someRandomNumber;
    std::string guessedNumberAsString;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    someRandomNumber = idist(rgen);

    // input
    while (true) {
        std::cout << "Guess a number between 0 and 9: ";
        std::cin >> guessedNumberAsString;
        // process
        try {
            guessedNumberAsInteger = std::stoi(guessedNumberAsString);
            if (guessedNumberAsInteger == someRandomNumber) {
                // output
                std::cout << "\nYou guessed correct after "
                << guessCounter << " guesses.";
                break;
            } else if (guessedNumberAsInteger < 0 ||
            guessedNumberAsInteger > 9) {
                // output
                std::cout << "\nNot between 0 and 9.";
                guessCounter = guessCounter + 1;
            } else if (guessedNumberAsInteger != someRandomNumber) {
                // output
                std::cout << "\nYou guessed wrong! Try again.";
                guessCounter = guessCounter + 1;
            } else {
                // output
                std::cout << "\nUndefined.";
                guessCounter = guessCounter + 1;
            }
        } catch (std::invalid_argument) {
            std::cout << "\nThat was not a valid integer.\n";
            guessCounter = guessCounter + 1;
        }
    }
    std::cout << "\nDone." << std::endl;
}
