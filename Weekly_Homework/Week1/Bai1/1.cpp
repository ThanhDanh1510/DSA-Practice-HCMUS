#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string trim (string s) {
    int left=0,right = s.length() - 1;
    while (left <= right && isspace(s[left])) left++;
    while (right >= left && isspace(s[right])) right--;

    if (left > right) return "";
    return s.substr(left, right - left + 1);
}

bool readLines(string path, vector<string> & lines){
    ifstream fIn(path);
    if (!fIn.is_open()){
        cerr << "Khong the mo file" << '\n';
        return false;
    } 

    string line;
    while (getline(fIn, line)) {
        lines.push_back(line);
    }

    fIn.close();
    return true;
}

bool writeOutput(string path, int non_empty, int empty) {
    ofstream fOut(path);
    if (!fOut.is_open()){
        cerr << "Khong the mo file" << '\n';
        return false;
    } 

    fOut << "non_empty=" << non_empty << " / empty=" << empty;

    fOut.close();
    return true;
}

int main(){
    vector<string> lines;
    int non_empty = 0, empty = 0;

    if (!readLines("text.txt", lines)) {
        return 1;
    }

    for (const string& line : lines) {
        string t = trim(line);
        if (t.empty()) {
            empty++;
        } else {
            non_empty++;
        }
    }

    if (!writeOutput("output.txt", non_empty, empty)) {
        cout << "Khong ghi duoc file output\n";
        return 1;
    }

    cout << "Done!\n";
    return 0;
}