#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int right_limit;
int bottom_limit;

bool check_boundaries(pair<int,int> coord) {
    return coord.first >= 0 && coord.first < right_limit 
        && coord.second >= 0 && coord.second < bottom_limit;
}

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    vector<vector<char>> matrix;
    map<char,vector<pair<int,int>>> frequencies;

    fstream file ("input.txt");
    string line;
    if (file.is_open()) {
        while(getline(file,line)) {
            vector<char> v;
            for (const char& c : line) {
                v.push_back(c);
            }
            matrix.push_back(v);
        }
        file.close();
    }
    for (int row = 0; row < matrix.size(); ++row) {
        for (int column = 0; column < matrix[0].size(); ++column) {
            char c = matrix[row][column];
            if (c == '.') 
                continue;
            if (frequencies.find(c) != frequencies.end()) {
                frequencies[c].push_back(make_pair(row, column));
            } else {
                frequencies[c].push_back(make_pair(row, column));
            }
        }
    }

    right_limit = matrix[0].size();
    bottom_limit = matrix.size();
    set<pair<int,int>> antinodes;

    int sum = 0;

    map<char,vector<pair<int,int>>>::iterator it;
    for (it = frequencies.begin(); it != frequencies.end(); it++) {
        vector<pair<int,int>> antennas = it->second;
        for (int i = 0; i < antennas.size() - 1; ++i) {
            for (int j = i+1; j < antennas.size(); ++j) {
                pair<int,int> step = make_pair(antennas[i].first - antennas[j].first, 
                                               antennas[i].second - antennas[j].second);
                pair<int,int> antinode_1 = make_pair(antennas[i].first + step.first,
                                                   antennas[i].second + step.second);
                pair<int,int> antinode_2 = make_pair(antennas[j].first - step.first,
                                                   antennas[j].second - step.second);
                if (check_boundaries(antinode_1)) {
                    sum += antinodes.insert(antinode_1).second;
                }
                if (check_boundaries(antinode_2)) {
                    sum += antinodes.insert(antinode_2).second;
                }
            }
        }
    }

    cout << "\nResult: " << sum;    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\nCalculation time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;
}