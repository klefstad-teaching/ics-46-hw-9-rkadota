#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << "Error: " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    return is_adjacent(str1, str2);
}

bool is_adjacent(const string& word1, const string& word2) {
    int word1_len = word1.length();
    int word2_len = word2.length();
    int dif = abs(word1_len - word2_len);

    if (dif > 1) {
        cout << "Diff great than 1" << endl;
        return false;
    }

    if (dif == 0) {
        int count = 0;
        int differences = 0;
        for (auto character: word1) {
            if (character != word2[count]) {
                ++differences;
            }
            if (differences > 1) {return false;}
            ++count;
        }

        return true;
    }

    else {
        string longest;
        string shortest;
        if (word1_len > word2_len) {
            longest = word1;
            shortest = word2;
        }
        else {
            longest = word2;
            shortest = word1;
        }

        int count = 0;
        int differences = 0;

        for (auto character: shortest) {
            if (longest[count] != character) {
                // cout << count << endl;
                // cout << differences << endl;
                // cout << "Run " << longest[count] << " " << character << endl;
                count += 2;
                ++differences;

            if (differences > 1) {
                cout << differences << "FF";
                return false;
            }
            continue;
        }
            ++count;
        }

        if (differences == 0 || differences == 1) {
            return true;
        }
        else {return false;}
    }
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    vector<string> thing;
    return thing;
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    for (string word; in >> word;) {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder) {
    for (auto word: ladder) {
        cout << word << " ";
    }
    cout << endl;
}

void verify_word_ladder() {

}