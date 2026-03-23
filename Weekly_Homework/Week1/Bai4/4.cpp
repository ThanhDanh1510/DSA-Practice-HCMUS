#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

string trim(const string &s) {
    int start = s.find_first_not_of(" \t\n\r");
    int end = s.find_last_not_of(" \t\n\r");

    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

bool isMissingToken(string token) {
    token = trim(token);

    if (token.empty()) return true;

    transform(token.begin(), token.end(), token.begin(), ::tolower);

    return (token == "na" || token == "nan");
}

vector<string> splitCSV(const string& line)
{
    vector<string> cells;
    stringstream ss(line);
    string cell;

    while (getline(ss, cell, ',')) {
        cells.push_back(trim(cell));
    }

    if (!line.empty() && line.back() == ',')
        cells.push_back("");

    return cells;
}

bool readCSV1Col(string path, vector<double>& data, int& missing)
{
    ifstream fileInput(path);
    if (!fileInput.is_open()) {
        cerr << "Error opening file\n";
        return false;
    }

    string line;
    while (getline(fileInput, line))
    {
        vector<string> cells = splitCSV(line);
        if (!cells.empty())
        {
            string token = cells[0];

            if (isMissingToken(token))
            {
                missing++;
            }
            else
            {
                try {
                    double value = stod(token);
                    data.push_back(value);
                }
                catch (...) {
                    missing++;
                }
            }
        }
    }

    return true;
}

struct Stats {
    int count = 0;
    int missing = 0;
    double min = 0;
    double max = 0;
    double mean = 0;
};

Stats computeStats(const vector<double>& data, int missing)
{
    Stats stats;
    stats.count = data.size();
    stats.missing = missing;

    if (stats.count == 0) return stats;

    long double sum = 0;
    stats.min = data[0];
    stats.max = data[0];

    for (double value : data)
    {
        sum += value;
        stats.min = min(stats.min, value);
        stats.max = max(stats.max, value);
    }

    stats.mean = sum / stats.count;

    return stats;
}

int main() {
    vector<double> data;
    int missing = 0;

    if (!readCSV1Col("data.csv", data, missing))
        return 1;

    Stats stats = computeStats(data, missing);

    ofstream fileOutput("output.txt");
    if (!fileOutput.is_open()) {
        cerr << "Cannot open output file\n";
        return 1;
    }

    fileOutput << fixed << setprecision(2);

    fileOutput << "count=" << stats.count
               << " / missing=" << stats.missing
               << " / ";

    if (stats.count == 0) {
        fileOutput << "min=N/A / max=N/A / mean=N/A";
    } else {
        fileOutput << "min=" << stats.min
                   << " / max=" << stats.max
                   << " / mean=" << stats.mean;
    }

    return 0;
}