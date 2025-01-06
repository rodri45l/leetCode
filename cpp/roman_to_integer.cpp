// https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
#include <string>
#include <ostream>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        if (s.empty()) {
                    return 0;
                }
        int result = 0;
        for (size_t i = 0; i < s.length() - 1; i++) {
        if (roman_map[s[i]] >= roman_map[s[i + 1]]) {
            result += roman_map[s[i]];
        } else {
            result -= roman_map[s[i]];
        }
    }
    result += roman_map[s[s.length() - 1]]; // Add the last numeral
    return result;
    }
};

int main() {
Solution solution;
std::string roman = "LVIII"; // Example input
int result = solution.romanToInt(roman);
std::cout << "The integer value of " << roman << " is " << result << std::endl;
return 0;
}