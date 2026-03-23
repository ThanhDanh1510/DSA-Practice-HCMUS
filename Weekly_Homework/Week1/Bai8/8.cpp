#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// 1. Module lam sach chuoi
string trim(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

// 2. Module kiem tra missing (tolower thu cong)
bool isMissing(string s) {
    s = trim(s);
    if (s.empty()) return true;
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') c += 32; 
    }
    return (s == "na" || s == "nan" || s == "n/a");
}

// 3. Module kiem tra so thuc hop le bang tay
bool isValidReal(const string& s) {
    if (s.empty()) return false;
    int i = 0, n = s.length(), dotCount = 0, digitCount = 0;
    
    if (s[i] == '+' || s[i] == '-') i++;
    
    for (; i < n; i++) {
        if (s[i] == '.') {
            if (++dotCount > 1) return false;
        } else if (s[i] >= '0' && s[i] <= '9') {
            digitCount++;
        } else return false;
    }
    return digitCount > 0;
}

// 4. Module chuyen doi chuoi thanh double (Manual stod)
double manualStod(const string& s) {
    double res = 0.0, sign = 1.0;
    int i = 0, n = s.length();

    if (s[i] == '-') { sign = -1.0; i++; }
    else if (s[i] == '+') { i++; }

    // Phan nguyen
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        res = res * 10.0 + (s[i] - '0');
        i++;
    }
    // Phan thap phan
    if (i < n && s[i] == '.') {
        i++;
        double factor = 0.1;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            res += (s[i] - '0') * factor;
            factor /= 10.0;
            i++;
        }
    }
    return res * sign;
}

// 5. Module doc cau hinh
bool readConfig(string path, double &lo, double &hi) {
    ifstream f(path);
    if (!f.is_open()) return false;
    f >> lo >> hi;
    f.close();
    return true;
}

// 6. Thuc thi loc va ghi ket qua
void processFilter(string inPath, string outPath, double lo, double hi) {
    ifstream fIn(inPath);
    ofstream fOut(outPath);
    if (!fIn.is_open() || !fOut.is_open()) return;

    string line, id, valStr;
    int kept = 0, dropped = 0;

    while (getline(fIn, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, valStr, ',');
        
        valStr = trim(valStr);
        if (isMissing(valStr)) {
            dropped++;
        } else if (isValidReal(valStr)) {
            double value = manualStod(valStr);
            if (value >= lo && value <= hi) {
                fOut << trim(id) << "," << fixed << setprecision(6) << value << "\n";
                kept++;
            } else dropped++;
        } else {
            dropped++;
        }
    }
    fOut << "kept=" << kept << "/ dropped=" << dropped << endl;
}

int main() {
    double lo, hi;
    if (!readConfig("config.txt", lo, hi)) return 1;
    processFilter("data.csv", "filtered.csv", lo, hi);
    return 0;
}