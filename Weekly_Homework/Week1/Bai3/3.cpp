#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string trim(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
       if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

bool isMissingToken(string t) {
    t = trim(t);
    t = toLower(t);
    if (t == "" || t == "na" || t == "nan" || t == "n/a")
        return true;
    return false;
}

bool openInputFile(ifstream &file, string filename) {
    file.open(filename);
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file " << filename << endl;
        return false;
    }
    return true;
}

int main() {
    ifstream file;
    string fileName = "data.csv";

    if (!openInputFile(file, fileName)) {
        return 1;
    }

    string line;
    int index = 0;

    while (getline(file, line)) {
        if (isMissingToken(line)) {
            cout << index << " ";
        }
        index++;
    }

    file.close();
    return 0;
}