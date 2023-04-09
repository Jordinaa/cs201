#include "hangman.h"

Hangman::Hangman(const string& wordsFile) {
    loadWords(wordsFile);
    srand(static_cast<unsigned>(time(0)));
}

void Hangman::loadWords(const string& wordsFile) {
    ifstream file(wordsFile);
    string word;

    while (file >> word) {
        words.push_back(word);
    }
}

void Hangman::chooseRandomWord() {
    int randomIndex = rand() % words.size();
    chosenWord = words[randomIndex];
    guessWord = string(chosenWord.size(), '?');
}

void Hangman::displayGameState() {
    cout << "Current word: " << guessWord << endl;
    cout << "Remaining guesses: " << remainingGuesses << endl;
}

bool Hangman::guessLetter(char letter) {
    bool found = false;

    for (size_t i = 0; i < chosenWord.size(); ++i) {
        if (chosenWord[i] == letter) {
            guessWord[i] = letter;
            found = true;
        }
    }

    return found;
}

void Hangman::play() {
    chooseRandomWord();
    remainingGuesses = 6;

    while (remainingGuesses > 0 && guessWord != chosenWord) {
        displayGameState();
        cout << "Guess a letter: ";
        char letter;
        cin >> letter;

        if (!guessLetter(letter)) {
            --remainingGuesses;
        }
    }

    displayGameState();

    if (guessWord == chosenWord) {
        cout << "Congratulations! You guessed the word correctly!" << endl;
    } else {
        cout << "You ran out of guesses. The word was: " << chosenWord << endl;
    }
}
