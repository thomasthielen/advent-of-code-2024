#include <cmath>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;

using ull = unsigned long long;

list<vector<ull>> equations;

int main() {
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
        int num_of_operators = v.size() - 2;
        int num_of_different_operator_assignments = pow(2, num_of_operators);
        for (int i = 0; i < num_of_different_operator_assignments; ++i) {
            ull total_value = v[1];
            for (int j = 0; j < num_of_operators; ++j) {
                if ((i >> j) & 1) {
                    total_value += v[j+2];
                } else {
                    total_value *= v[j+2];
                }
            }
            if (total_value > test_value) {
                continue;
            }
            if (total_value == test_value) {
                sum += total_value;
                break;
            }
        }
    }
    cout << "Result: " << sum;
}