#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>
#include <iomanip>

using namespace std;

struct Word{
    string word;
    double value;
};


vector<Word> load_sentiment_words(const string &filename);
vector<Word> filter_sentiment_words(const vector<Word> &sentiment_words, float threshold, bool is_positive);
float get_sentiment_value(const string &word, const vector<Word> &sentiment_words);
float calculate_sentiment(istream &input, const vector<Word> &sentiment_words);
string process_review(const string &input_file, const vector<Word> &sentiment_words, char choice);