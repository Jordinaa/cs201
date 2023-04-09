#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

class Hangman {
public:
    Hangman(const string& wordsFile);
    void play();

private:
    vector<string> words;
    string chosenWord;
    string guessWord;
    int remainingGuesses;

    void loadWords(const string& wordsFile);
    void chooseRandomWord();
    void displayGameState();
    bool guessLetter(char letter);
};