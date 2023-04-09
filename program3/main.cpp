#include "sentiment.h"

// interesting project. Took forever

int main(){
    vector<Word> sentiment_words = load_sentiment_words("sentiment.txt");
    char continue_choice;
    // continues to process files until user decides to quit
    do{
        string input_file;
        // get input file name from user
        cout << "Please enter the input file you would like to use: ";
        cin >> input_file;
        // open input file and check for errors
        ifstream test_file(input_file);
        if (!test_file){
            cerr << "Error: Cannot open the input file." << endl;
            return 1;
        }
        // calculate the sentiment of the input file
        float original_sentiment = calculate_sentiment(test_file, sentiment_words);
        // read input file content and display it
        test_file.clear();
        test_file.seekg(0);
        string file_content((istreambuf_iterator<char>(test_file)), istreambuf_iterator<char>());
        cout << endl << "The original text is: \n" << file_content << endl;
        cout << endl << "The original sentiment of this file is: " << original_sentiment << endl;

        char choice;
        // continue processing the current file until the user decides to quit
        do{
            cout << "What would you like to do? \n" << endl;
            cout << "p: change negative to positive" << endl;
            cout << "n: change positive to negative" << endl;
            cout << "q: quit" << endl;
            cin >> choice;

            if (choice != 'q'){
                if (choice == 'n'){
                    cout << "Okay! I will edit the file: " << input_file << " to be more negative" << endl;
                } else if (choice == 'p'){
                    cout << "Okay! I will edit the file: " << input_file << " to be more positive" << endl;
                }
                // process the review based on user's choice
                string output = process_review(input_file, sentiment_words, choice);

                // print the new changed review to the terminal
                cout << "After this change, the new file is: \n" << output << endl;

                // calculate the new sentiment value after replacing the words
                istringstream output_ss(output);
                test_file.clear();
                // found on stackoverflow and went into more looking and found this
                // https://cplusplus.com/reference/istream/istream/seekg/
                test_file.seekg(0);
                float new_sentiment = calculate_sentiment(output_ss, sentiment_words);
                cout << "New sentiment value: " << new_sentiment << endl;

                // save the processed review to an output file
                string output_file = input_file.substr(0, input_file.find_last_of('.')) + "Output.txt";
                ofstream out_file(output_file);
                if (out_file){
                    out_file << output;
                }
                out_file.close();
                cout << "Processed review saved to " << output_file << endl;
                cout << "Would you like to try a new file? " << endl;
                cout << "y: yes" << endl;
                cout << "n: no" << endl;
                cin >> continue_choice;
                break;
            }
        } while (choice != 'q' && continue_choice == 'y');

    } while (continue_choice == 'y');

    return 0;
}
