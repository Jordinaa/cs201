#include "sentiment.h"


// loads sentiment data from txt file and stores it in vector
vector<Word> load_sentiment_words(const string &filename){
    // open sentiment file using provided filename
    ifstream file(filename);
    // create a vector to store sentiment words and their values
    vector<Word> sentiment_words;
    string line;

    // read file line by line
    while (getline(file, line)){
        // create string stream from current line
        istringstream iss(line);
        // declare string var to store word
        string word;
        // create float val to store value
        float value;
        // read the word and sentiment value from the current line
        if (getline(iss, word, ',') && iss >> value){
            // if the word and sent val are sucessfully read add to sent_words vec
            sentiment_words.push_back({word, value});
        }
    }
    return sentiment_words;}

// creates new vec containing only pos or neg sent words based on specified threshold
vector<Word> filter_sentiment_words(const vector<Word> &sentiment_words, float threshold, bool positive){
    vector<Word> filtered_words;
    // iters. through each word in the sent vec
    for (const auto &word : sentiment_words){
        // if positive flag it true and sentinent value is great than the threshold add word to filtered vec
        if (positive && word.value > threshold){
            filtered_words.push_back(word);
        }
        // if positive flag is false and sent value is less than the neg value add word to filtered word vec
        else if (!positive && word.value < -threshold){
            filtered_words.push_back(word);
        }
    }
    return filtered_words;
}

// returns the sent. value of a given word if it is not in the sent words vec it returns 0 
float get_sentiment_value(const string &word, const vector<Word> &sentiment_words) {
    // loop through each sentiment word in the sent_words vec
    for (const Word &sentiment_word : sentiment_words) {
        // check if the current sent. word matches the input word
        if (sentiment_word.word == word) {
            // if the word matches return the sent. value of the current sent. word
            return sentiment_word.value;
        }
    }
    // if the input word was not found in the sent word vec, return 0.0f
    return 0.0f;
}

// this function calulates the sentiment value for input text it reads line by line then word by word
// and then strips any non alphanumeric chars and converts the rest to lowercase and calcs sent._val 
// by using the get_sent_val function it returns the total sum of the sent. vals
float calculate_sentiment(istream &input, const vector<Word> &sentiment_words){
    // initalizes total sent. to float with value 0
    float total_sentiment = 0.0f;
    // declare string and storing each line into this
    string line;

    // read each line from input stream
    while (getline(input, line)){
        // creates a string stream object iss and initalizes it the with the content from the line variable declared above
        istringstream iss(line);
        // stores each word from the line 
        string word;
        // read each word from the line using stream stream 
        while (iss >> word){
            // declare a var that alphanumeric characters of the word
            string stripped_word;
            // copies only alpha. chars from word to stripped_word
            copy_if(word.begin(), word.end(), back_inserter(stripped_word), ::isalnum);
            // converts all chars in stripped word to lowercase
            transform(stripped_word.begin(), stripped_word.end(), stripped_word.begin(), ::tolower);
            // call get_sent._val function to obtain the sent value of the stripped_word var
            float sentiment_value = get_sentiment_value(stripped_word, sentiment_words);
            // add the sentinent value to the total_sentiment
            total_sentiment += sentiment_value;
        }
    }

    return total_sentiment;
}

// this functions processes a the file based on the users choice to make it more positive or negative
string process_review(const string &input_file, const vector<Word> &sentiment_words, char choice){
    // opens input file and creates an ifstream object as well as other vars
    ifstream file(input_file);  
    stringstream ss;            
    string line;                
    // create a filtered lists of pos. and neg. sentiment words
    // this one creates positive with 1.5 has the threshold for placing variables into pos word vec
    vector<Word> positive_words = filter_sentiment_words(sentiment_words, 1.5f, true);
    // this one creates negative words with -1.5 has the threshold for placing vars into neg word vec
    vector<Word> negative_words = filter_sentiment_words(sentiment_words, 1.5f, false);
    // random number generator i found this on stack overflow
    // https://stackoverflow.com/questions/38367976/do-stdrandom-device-and-stdmt19937-follow-an-uniform-distribution
    random_device rd;           
    mt19937 gen(rd());     
    // reach each line from input file 
    while (getline(file, line)){
        // create string stream object iss and init. it with content of line
        istringstream iss(line);  
        string word;              
        // read each word from line using string stream
        while (iss >> word){  
            string stripped_word;  
            string punctuation;    
            // Split the word and punctuation - strips it
            // review3.txt didn't work so had to add a bullet flag so it will iterate through and not stop
            bool is_bullet = false;
            for (char c : word){
                // checks if char is alphanumerical 
                if (isalnum(c)){
                    stripped_word.push_back(tolower(c));
                }
                else{
                    punctuation.push_back(c);
                    // checks if char is bullet point
                    if (c == '-' && punctuation.length() == 1 && stripped_word.empty()) {
                        is_bullet = true;
                    }
                }
            }
            // if the word is a bullet treat it separately
            if (is_bullet) {
                ss << '-';
                stripped_word.clear();
                // erase function found on different stackoverflow websites 
                punctuation.erase(0, 1); // Remove hyphen from punctuation
            }
            // gets sentiment value of current word - should be replaced based on the users choice
            float sentiment_value = get_sentiment_value(stripped_word, sentiment_words);

            bool should_replace = (choice == 'n' && sentiment_value > 1.0f) || (choice == 'p' && sentiment_value < -1.0f);
            // check if current word should be replaced based on users choice 
            if (should_replace){
                vector<Word> &replacement_words = (choice == 'n') ? negative_words : positive_words;
                // selects the list of replacement words based on user input 
                int random_index = rand() % replacement_words.size();

                Word replacement_word = replacement_words[random_index];
                // print the original word its sent. value - replacement word and its sent. value 
                cout << setw(15) << left << word << setw(10) << left << sentiment_value << setw(15) << left << (replacement_word.word + punctuation) << setw(8) << left << replacement_word.value << endl;
                // add replaced word to stringstream
                ss << replacement_word.word;
            }
            else{
                // word should not be replaced add original word to the stringstream
                ss << stripped_word;
            }
            // add punctuation EXTRA CREDIT and space to stringstream
            ss << punctuation << ' ';
        }
        // add newline char to stringstream
        cout << endl;
        ss << '\n';
    }
    // returns modified sent. as a string 
    return ss.str();
}
