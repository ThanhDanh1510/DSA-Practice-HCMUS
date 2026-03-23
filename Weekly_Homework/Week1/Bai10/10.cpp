#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Cau truc luu tru ket qua thong ke
struct LogStats {
    int info = 0, warn = 0, error = 0;
    string firstErr = "NONE";
    string lastErr = "NONE";
};

// MODULE 1: Trich xuat Timestamp (19 ky tu dau)
string parseTimestamp(const string& line) {
    if (line.length() < 19) return "";
    return line.substr(0, 19);
}

// MODULE 2: Trich xuat Log Level
string parseLevel(const string& line) {
    size_t start = line.find('[');
    size_t end = line.find(']');
    if (start != string::npos && end != string::npos && end > start) {
        return line.substr(start + 1, end - start - 1);
    }
    return "UNKNOWN";
}

// MODULE 3: Thuc thi phan tich file
LogStats analyzeLogFile(string path) {
    ifstream f(path);
    LogStats stats;
    if (!f.is_open()) {
        cerr << "Error: Cannot open " << path << endl;
        return stats;
    }

    string line;
    while (getline(f, line)) {
        if (line.empty()) continue;

        string level = parseLevel(line);
        string ts = parseTimestamp(line);

        if (level == "INFO") stats.info++;
        else if (level == "WARN") stats.warn++;
        else if (level == "ERROR") {
            stats.error++;
            if (stats.firstErr == "NONE") stats.firstErr = ts;
            stats.lastErr = ts;
        }
    }
    f.close();
    return stats;
}

// MODULE 4: Ghi bao cao ra file
void writeSummary(string path, const LogStats& stats) {
    ofstream f(path);
    if (!f.is_open()) return;

    f << "INFO=" << stats.info 
      << "/ WARN=" << stats.warn 
      << "/ ERROR=" << stats.error 
      << " / first_error=" << stats.firstErr 
      << " / last_error=" << stats.lastErr << endl;
    
    f.close();
}

int main() {
    // Pipeline MO: Thuc thi tung buoc
    LogStats result = analyzeLogFile("log.txt");
    writeSummary("summary.txt", result);

    cout << "Log analysis complete. Summary saved to summary.txt" << endl;
    return 0;
}