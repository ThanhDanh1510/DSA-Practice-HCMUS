#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// MODULE 1: Doc du lieu tu file
bool loadWords(string path, vector<string>& wordList) {
    ifstream fIn(path);
    if (!fIn.is_open()) {
        cerr << "Loi: Khong the mo file " << path << endl;
        return false;
    }

    string word;
    while (fIn >> word) {
        wordList.push_back(word);
    }
    
    fIn.close();
    return true;
}

// MODULE 2: Dem tu duy nhat bang cach sap xep
int countUniqueUsingSort(vector<string> wordList) {
    if (wordList.empty()) return 0;

    // Sap xep de cac tu giong nhau dung canh nhau
    sort(wordList.begin(), wordList.end());

    int count = 1; // Luon co it nhat 1 tu neu vector khong rong
    for (size_t i = 1; i < wordList.size(); ++i) {
        if (wordList[i] != wordList[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<string> allWords;
    
    if (loadWords("words.txt", allWords)) {
        int total = allWords.size();
        int unique = countUniqueUsingSort(allWords);
        
        cout << "total_words=" << total << " / unique_words=" << unique << endl;
    }

    return 0;
}