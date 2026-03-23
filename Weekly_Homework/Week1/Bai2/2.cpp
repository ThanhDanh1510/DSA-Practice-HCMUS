#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string trim(string s) {
    int l = 0, r = s.length() - 1;

    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;

    if (l > r) return "";
    return s.substr(l, r - l + 1);
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

int main() {
    string line;
    if (!getline(cin, line)) return 0;

    vector<string> fields = splitCSV(line);

    cout << fields.size() << ", ";

    for (int i = 0; i < fields.size(); i++) {
        cout << "'" << fields[i] << "'";
        
        //Tránh thêm dấu '/' dư thừa ở trường cuối cùng
        if (i < fields.size() - 1) {
            cout << " / ";
        }
    }

    cout << endl;

    return 0;
}