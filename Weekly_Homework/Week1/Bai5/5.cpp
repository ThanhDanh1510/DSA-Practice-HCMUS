#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Record {
    string id;
    double total;
    string rank;
};

string trim(string s) {
    int l = 0, r = s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

bool isMissingToken(string token) {
    token = trim(token);
    if (token.empty()) {
        token = "missing";
        return true;
    }

    for (char& c : token) {
        c = tolower(c);
    }
    if (token == "na" || token == "nan" || token == "n/a") 
    {
        token = "missing";
        return true;
    }
    else if (token == "0") {
        token = "no missing";
        return false;
    }

    return false;
}

vector<string> splitCSV(const string& line)
{
    vector<string> cells;
    if (line.empty()) {
        cells.push_back(""); // Thêm chuỗi rỗng nếu cell trống
        return cells;
    } 

    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ','))
    {
        cells.push_back(trim(cell)); // Thêm cell đã được trim
    }

    if (line.back() == ',')
        cells.push_back("");

    return cells;
}


double parseScore(string s)
{
    if (isMissingToken(s))
        return 0;

    return stod(s);
}

string computeRank(double total)
{
    if (total >= 24)
        return "Gioi";
    else if (total >= 18)
        return "Kha";
    else if (total >= 12)
        return "TrungBinh";
    else
        return "Yeu";
}

Record parseRow(const vector<string>& cells) {
    Record rec;
    // Xu ly ID
    rec.id = (cells.size() > 0) ? trim(cells[0]) : "";
    if (rec.id.empty()) rec.id = "UNKNOWN";

    // Tinh tong 3 mon (math, lit, sci)
    double sum = 0;
    for (size_t i = 1; i <= 3; ++i) {
        if (i < cells.size() && !isMissingToken(cells[i])) {
            try {
                sum += stod(cells[i]);
            } catch (...) {
                sum += 0; // Loi parse coi nhu 0
            }
        }
    }
    rec.total = sum;
    rec.rank = computeRank(sum);
    return rec;
}

bool readCSV(string path, vector<Record>& records)
{
    ifstream file(path);

    if (!file.is_open())
        return false;

    string line;

    getline(file, line); // bỏ header

    while (getline(file, line))
    {
        vector<string> cells = splitCSV(line);

        if (cells.size() >= 4)
        {
            Record r = parseRow(cells);
            records.push_back(r);
        }
    }

    file.close();
    return true;
}

void writeResult(string path, vector<Record>& records)
{
    ofstream file(path);

    if (!file.is_open()) {
        cerr << "Cannot write file\n";
        return;
    }

    file << fixed << setprecision(2);

    int gioi = 0, kha = 0, tb = 0, yeu = 0;

    file << "id,total,rank\n";

    for (auto& r : records)
    {
        file << r.id << "," << r.total << "," << r.rank << "\n";

        if (r.rank == "Gioi") gioi++;
        else if (r.rank == "Kha") kha++;
        else if (r.rank == "TrungBinh") tb++;
        else if (r.rank == "Yeu") yeu++;
    }

    file << "Summary,Gioi=" << gioi
         << ",Kha=" << kha
         << ",TrungBinh=" << tb
         << ",Yeu=" << yeu << "\n";
}

int main()
{
    vector<Record> records;

    if (!readCSV("scores.csv", records))
    {
        cout << "Cannot open file\n";
        return 1;
    }

    writeResult("result.csv", records);

    cout << "Done!" << endl;

    return 0;
}