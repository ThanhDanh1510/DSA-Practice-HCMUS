#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Loại bỏ khoảng trắng thừa ở hai đầu chuỗi
string trim(string s) {
    int l = 0, r = (int)s.length() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (r >= l && isspace(s[r])) r--;
    if (l > r) return "";
    return s.substr(l, r - l + 1);
}

// Kiểm tra một chuỗi có phải là số thực hợp lệ hay không
bool isNumeric(string s) {
    s = trim(s);
    if (s.empty()) return false;

    bool hasDot = false;
    for (int i = 0; i < s.length(); i++) {
        // 1. Kiểm tra dấu âm ở đầu chuỗi
        if (s[i] == '-' && i == 0) continue;

        // 2. Kiểm tra dấu chấm thập phân (chỉ xuất hiện 1 lần)
        if (s[i] == '.') {
            if (hasDot) return false; // Đã có dấu chấm trước đó rồi
            hasDot = true;
            continue;
        }

        // 3. Nếu không phải số thì trả về false
        if (s[i] < '0' || s[i] > '9') return false;
    }
    
    // Trường hợp đặc biệt: chuỗi chỉ có mỗi dấu "-" hoặc mỗi dấu "."
    if (s == "-" || s == ".") return false;

    return true;
}

// Tách một dòng CSV thành vector các ô dữ liệu
vector<string> parseCSVLine(const string& line) {
    vector<string> result;
    stringstream ss(line);
    string cell;
    while (getline(ss, cell, ',')) {
        result.push_back(trim(cell));
    }
    return result;
}

// Kiểm tra xem danh sách các ô có thỏa điều kiện là Header hay không
// Logic: Nếu tất cả các ô đều KHÔNG phải là số, ta coi đó là Header
bool checkIsHeader(const vector<string>& cells) {
    if (cells.empty()) return false;
    for (const string& cell : cells) {
        if (isNumeric(cell)) return false; 
    }
    return true;
}

// Hàm bao quát toàn bộ quy trình đọc và phân tích file
void analyzeCSVHeader(const string& filename) {
    ifstream fIn(filename);
    
    // Kiểm tra mở file
    if (!fIn.is_open()) {
        cerr << "Loi: Khong the mo file " << filename << endl;
        return;
    }

    string firstLine;
    // Đọc dòng đầu tiên
    if (getline(fIn, firstLine)) {
        vector<string> cells = parseCSVLine(firstLine);
        
        if (checkIsHeader(cells)) {
            cout << "has_header=1" << endl;
            cout << "Column names: ";
            for (size_t i = 0; i < cells.size(); ++i) {
                cout << "'" << cells[i] << "'" << (i == cells.size() - 1 ? "" : ", ");
            }
            cout << endl;
        } else {
            cout << "has_header=0" << endl;
        }
    } else {
        // File rỗng
        cout << "has_header=0 (File rong)" << endl;
    }

    fIn.close();
}

int main() {
    string targetFile = "data.csv";
    analyzeCSVHeader(targetFile);

    return 0;
}