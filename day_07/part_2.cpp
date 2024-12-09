#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;

using ull = unsigned long long;

list<vector<ull>> equations;

vector<int> increase_by_one(vector<int> operators, int index) {
    if (index >= operators.size()) {
        cout << "\nError at operator increase\n";
    }
    if (operators[index] == 2) {
        operators[index] = 0;
        return increase_by_one(operators, index + 1);
    }
    operators[index]++;
    return operators;
}

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    fstream file ("test.txt");
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
        vector<int> operators = {0,1,2}; // +, *, ||
        int places = v.size() - 2;
        int total_loops = pow(operators.size(), places);

        vector<int> placed_operators;

        for (int i = 0; i < places; ++i) {
            placed_operators.push_back(operators[0]);
        }

        for (int i = 0; i < total_loops; ++i) {
            ull total_value = v[1];
            // calculate the total value via all operators
            for (int place = 0; place < placed_operators.size(); ++place) {
                switch(placed_operators[place]) {
                    case 0: // +
                        total_value += v[2+place];
                        break;
                    case 1: // *
                        total_value *= v[2+place];
                        break;
                    case 2: { // ||
                        string tv_string = to_string(total_value);
                        string to_be_concatenated = to_string(v[2+place]);
                        string concatenation = tv_string + to_be_concatenated;
                        total_value = stoll(concatenation);
                        break;}
                    default:
                        cout << "\nError at operator recognition\n";
                        break;
                }
                if (total_value > test_value) {
                    break;
                }
            }
            // compare the total value
            if (total_value == test_value) {
                sum += total_value;
                break;
            }
            // change the operators (except in the last iteration)
            if (i < total_loops - 1) {
                placed_operators = increase_by_one(placed_operators, 0);
            }
        }
    }
    cout << "\nResult: " << sum;    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\nCalculation time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds" << std::endl;
}