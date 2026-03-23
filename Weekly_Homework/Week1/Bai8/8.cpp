#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// Ham xoa khoang trang dau va cuoi
string trim(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

// Ham kiem tra missing token
bool isMissing(string s) {
    s = trim(s);
    if (s.empty()) return true;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return (s == "na" || s == "nan" || s == "n/a");
}

// Ham doc cau hinh tu file config.txt
bool readConfig(string path, double &lo, double &hi) {
    ifstream f(path);
    if (!f.is_open()) {
        cerr << "Error: Cannot open config file!" << endl;
        return false;
    }
    f >> lo >> hi;
    f.close();
    return true;
}

// Ham thuc hien loc va ghi du lieu
void processFilter(string inPath, string outPath, double lo, double hi) {
    ifstream fIn(inPath);
    ofstream fOut(outPath);
    
    if (!fIn.is_open() || !fOut.is_open()) {
        cerr << "Error: File I/O fail!" << endl;
        return;
    }

    string line, id, valStr;
    int kept = 0, dropped = 0;

    while (getline(fIn, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, valStr, ',');

        if (isMissing(valStr)) {
            dropped++;
            continue;
        }

        try {
            double value = stod(valStr);
            if (value >= lo && value <= hi) {
                fOut << trim(id) << "," << fixed << setprecision(6) << value << "\n";
                kept++;
            } else {
                dropped++;
            }
        } catch (...) {
            dropped++;
        }
    }

    fOut << "kept=" << kept << "/ dropped=" << dropped << endl;
    fIn.close(); fOut.close();
}

int main() {
    double lo, hi;
    if (!readConfig("config.txt", lo, hi)) return 1;

    processFilter("data.csv", "filtered.csv", lo, hi);

    cout << "Processing completed!" << endl;
    return 0;
}