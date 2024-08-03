#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <windows.h>

using namespace std;

// Function to set the console to UTF-8
void setConsoleUTF8() {
    SetConsoleOutputCP(CP_UTF8);
}

// Function to read verses from a file
vector<string> readVersesFromFile(const string& filename) {
    vector<string> verses;
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            verses.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return verses;
}

// Function to read search words from a file
vector<string> readWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            words.push_back(line);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return words;
}

// Function to search for words in verses and print matching verses
void searchWordsInVerses(const vector<string>& verses, const vector<string>& words) {
    unordered_map<string, vector<string>> wordVerseMap;

    for (const auto& verse : verses) {
        for (const auto& word : words) {
            if (verse.find(word) != string::npos) {
                wordVerseMap[word].push_back(verse);
            }
        }
    }

    for (const auto& word : words) {
        cout << "Verses containing the word \"" << word << "\":" << endl;
        if (wordVerseMap.find(word) != wordVerseMap.end()) {
            for (const auto& verse : wordVerseMap[word]) {
                cout << verse << endl;
            }
        } else {
            cout << "No verses found for the word \"" << word << "\"." << endl;
        }
        cout << endl;
    }
}

int main() {
    setConsoleUTF8();  // Set console to UTF-8

    string versesFilename, wordsFilename;
    cout << "Enter the filename of the Bible verses: ";
    cin >> versesFilename;
    cin.ignore();  // To ignore the leftover newline character

    cout << "Enter the filename of the words to search for: ";
    cin >> wordsFilename;
    cin.ignore();  // To ignore the leftover newline character

    vector<string> verses = readVersesFromFile(versesFilename);
    vector<string> words = readWordsFromFile(wordsFilename);

    // Debugging: Print the number of verses and words loaded
    cout << "Loaded " << verses.size() << " verses from the file." << endl;
    cout << "Loaded " << words.size() << " words to search for." << endl;

    // Debugging: Print the first few verses and words to check content
    if (!verses.empty()) {
        cout << "First verse loaded: " << verses[0] << endl;
    }
    if (!words.empty()) {
        cout << "First word to search for: " << words[0] << endl;
    }

    searchWordsInVerses(verses, words);

    return 0;
}
