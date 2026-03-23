#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Stats {
    int count = 0;
    double minV = 0, maxV = 0, meanV = 0;
};

// 1. Module lam sach chuoi
string trim(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

// 2. Module kiem tra missing (Quy dinh chung)
bool isMissing(string s) {
    s = trim(s);
    if (s.empty()) return true;
    for (char &c : s) if (c >= 'A' && c <= 'Z') c += 32; // tolower thu cong
    return (s == "na" || s == "nan" || s == "n/a");
}

// 3. Module chuyen doi chuoi thanh double thu cong
double stringToDouble(string s) {
    double val = 0.0;
    int i = 0, n = s.length();
    double sign = 1.0;

    if (s[i] == '-') { sign = -1.0; i++; }
    else if (s[i] == '+') { i++; }

    // Phan nguyen
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        val = val * 10.0 + (s[i] - '0');
        i++;
    }

    // Phan thap phan
    if (i < n && s[i] == '.') {
        i++;
        double divisor = 10.0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            val += (s[i] - '0') / divisor;
            divisor *= 10.0;
            i++;
        }
    }
    return val * sign;
}

// 4. Module kiem tra so thuc hop le bang tay
bool isValidReal(string s) {
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

// 5. Module xu ly file va thong ke
void process(string inPath, string outPath) {
    ifstream fIn(inPath);
    if (!fIn.is_open()) { cerr << "Loi mo file!" << endl; return; }

    vector<double> data;
    int missing = 0;
    string line;

    while (getline(fIn, line)) {
        line = trim(line);
        if (line.empty()) continue;
        if (isMissing(line)) missing++;
        else if (isValidReal(line)) data.push_back(stringToDouble(line));
        else missing++;
    }
    fIn.close();

    // Tinh toan thong ke
    Stats res;
    res.count = data.size();
    ofstream fOut(outPath);
    fOut << fixed << setprecision(2) << "count=" << res.count << "/missing=" << missing << "/";

    if (res.count > 0) {
        res.minV = res.maxV = data[0];
        long double sum = 0;
        for (double v : data) {
            if (v < res.minV) res.minV = v;
            if (v > res.maxV) res.maxV = v;
            sum += v;
        }
        res.meanV = (double)(sum / res.count);
        fOut << "min=" << res.minV << "/max=" << res.maxV << "/mean=" << res.meanV << endl;
    } else {
        fOut << "min=N/A/max=N/A/mean=N/A" << endl;
    }
    fOut.close();
}

int main() {
    process("data.csv", "output.txt");
    return 0;
}