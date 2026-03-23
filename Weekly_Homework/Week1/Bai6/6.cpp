#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void countWords(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    vector<string> words;
    string word;

    while (inputFile >> word) {
        words.push_back(word);
    }
    inputFile.close();

    map<string, int> wordCount;
    for (const auto& w : words) {
        wordCount[w]++;
    }

    int total_words = words.size();
    int unique_words = wordCount.size();

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    outputFile << "total_words=" << total_words
               << " / unique_words=" << unique_words;

    outputFile.close();
}

int main() {
    countWords("words.txt", "output.txt");
    return 0;
}