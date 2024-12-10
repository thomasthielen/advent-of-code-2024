#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;

using ull = unsigned long long;

list<vector<ull>> equations;

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    fstream file ("input.txt");
    string line;
    if (file.is_open()) {
        while(getline(file,line)) {
            vector<ull> v;
            string num = "";
            for (const char& c : line) {
                if (isdigit(c)) {
                    num += c;
                } else if (num.size() > 0) {
                    v.push_back(stoll(num));
                    num = "";
                }
            }
            if (num.size() > 0) {
                v.push_back(stoi(num));
            }
            equations.push_back(v);
        }
        file.close();
    }

    ull sum = 0;
    for (vector<ull> v : equations) {
        ull test_value = v[0];
        int operator_count = v.size() - 2;
        set<ull> interim_totals = {v[1]};

        for (int i = 2; i < operator_count + 2; ++i) {
            set<ull> next_interim_totals;
            for (ull left_operand : interim_totals) {
                if (left_operand + v[i] <= test_value)
                    next_interim_totals.insert(left_operand + v[i]);
                if (left_operand * v[i] <= test_value)
                    next_interim_totals.insert(left_operand * v[i]);
            }
            interim_totals = next_interim_totals;
        }

        if(interim_totals.find(test_value) != interim_totals.end()) {
            sum += test_value;
        }
    }
    cout << "\nResult: " << sum;    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\nCalculation time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds" << std::endl;
}