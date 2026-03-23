#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Record {
    string id;
    double score;
};

// Ham trim ho tro
string trim(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

// Kiem tra missing token
bool isMissing(string s) {
    s = trim(s);
    if (s.empty()) return true;
    for (char &c : s) c = tolower(c);
    return (s == "na" || s == "nan" || s == "n/a");
}

// MODULE 1: Nap du lieu vao vector
bool loadRecords(string path, vector<Record>& list) {
    ifstream f(path);
    if (!f.is_open()) return false;
    string line, id, valStr;
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, valStr, ',');
        if (!isMissing(valStr)) {
            list.push_back({trim(id), stod(valStr)});
        }
    }
    f.close();
    // Sap xep danh sach theo ID de chuan bi cho Two Pointers
    sort(list.begin(), list.end(), [](const Record& a, const Record& b) {
        return a.id < b.id;
    });
    return true;
}

// MODULE 2: Merge bang ky thuat Hai con tro
void mergeAndReport(const vector<Record>& listA, const vector<Record>& listB, string outPath) {
    ofstream fOut(outPath);
    if (!fOut.is_open()) return;

    int i = 0, j = 0;
    int joinedCount = 0;
    int onlyA = 0, onlyB = 0;

    while (i < listA.size() && j < listB.size()) {
        if (listA[i].id == listB[j].id) {
            double diff = listA[i].score - listB[j].score;
            fOut << listA[i].id << "," << fixed << setprecision(6) 
                 << listA[i].score << "," << listB[j].score << "," << diff << "\n";
            joinedCount++;
            i++; j++;
        } else if (listA[i].id < listB[j].id) {
            onlyA++;
            i++;
        } else {
            onlyB++;
            j++;
        }
    }

    // Cong them cac phan tu con du lai o cuoi danh sach
    onlyA += (listA.size() - i);
    onlyB += (listB.size() - j);

    cout << "Joined rows: " << joinedCount << endl;
    cout << "IDs only in one file: " << (onlyA + onlyB) << endl;
    fOut.close();
}

int main() {
    vector<Record> listA, listB;

    if (loadRecords("fileA.csv", listA) && loadRecords("fileB.csv", listB)) {
        mergeAndReport(listA, listB, "merged.csv");
    } else {
        cerr << "Error: File input fail!" << endl;
        return 1;
    }

    return 0;
}