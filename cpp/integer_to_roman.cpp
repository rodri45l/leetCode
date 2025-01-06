// https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
#include <string>
#include <ostream>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::string intMagToRoman(int num, int magnitude) {
        std::unordered_map<int, std::string> roman_map = {
            {1000, "M"},
            {900, "CM"}, 
            {500, "D"}, 
            {400, "CD"}, 
            {100, "C"}, 
            {90, "XC"}, 
            {50, "L"}, 
            {40, "XL"}, 
            {10, "X"}, 
            {9, "IX"}, 
            {5, "V"}, 
            {4, "IV"}, 
            {1, "I"}
        };

        if (num == 9) {
            return roman_map[9 * magnitude];
        } else if (num >= 5) {
            return roman_map[5 * magnitude] + std::string(num - 5, roman_map[magnitude][0]);
        } else if (num == 4) {
            return roman_map[4 * magnitude];
        } else {
            return std::string(num, roman_map[magnitude][0]);
        }
    }
    std::string intToRoman(int num) {
        // Extract digits by place value
        int thousands = num / 1000;           // Thousands place
        int hundreds = (num / 100) % 10;      // Hundreds place
        int tens = (num / 10) % 10;           // Tens place
        int units = num % 10;                 // Units place

        // Sum up Roman numerals for each place value
        std::string result = "";
        if (thousands > 0) {
            result += intMagToRoman(thousands, 1000);
        }
        if (hundreds > 0) {
            result += intMagToRoman(hundreds, 100);
        }
        if (tens > 0) {
            result += intMagToRoman(tens, 10);
        }
        if (units > 0) {
            result += intMagToRoman(units, 1);
        }

        return result;
    }
};

int main() {
    Solution solution;
    int num;
    num = 3749;

    std::string roman = solution.intToRoman(num);
    std::cout << "Roman numeral: " << roman << std::endl;

    return 0;
}