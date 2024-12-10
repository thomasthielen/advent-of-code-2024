#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

using ull = unsigned long long;

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    vector<int> disk_map;
    fstream file ("test.txt");
    string line;
    if (file.is_open()) {
        bool reading_file;
        while(getline(file,line)) {
            for (const char& c : line) {
                disk_map.push_back(c - '0');
            }
        }
        file.close();
    }

    ull checksum = 0;
    int pos = 0;
    int id = 0;
    int inv_pos = disk_map.size() - 1;
    int inv_id = ceil(disk_map.size() / 2);
    for (int i = 0; i < disk_map.size(); ++i) {
        // files
        if (i % 2 == 0) {
            int loop_end = disk_map[i];
            for (int j = 0; j < loop_end; ++j) {
                checksum += pos * id;
                pos++;
            }
            id++;
        // free space
        } else {
            for (int j = 0; j < disk_map[i]; ++j) {
                if (inv_pos < i) // stops the free spaces from moving already used files
                    break;
                if (disk_map[inv_pos] <= 0) {
                    inv_pos -= 2;
                    inv_id -= 1;
                }
                checksum += pos * inv_id;
                pos++;
                disk_map[inv_pos]--;
            }
        }
    }

    cout << "\nResult: " << checksum;    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\nCalculation time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;
}