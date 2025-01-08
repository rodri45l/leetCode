#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s; // Special case: single row
        std::vector<std::string> fake_matrix(numRows, "");
        int direction = 1; // 1 is DOWN, -1 is UP
        int currRow = 0;
        std::string result = "";
        for (const char character : s){
            fake_matrix[currRow] += character;
            currRow += direction;
            if (currRow == 0 || currRow == numRows - 1) {
                direction *= -1;
            }
            }
        for (const std::string &row : fake_matrix) {
            result += row;
        }
        
        return result;
        
    }
};

int main() {
    Solution solution;

    // Test cases
    std::string s1 = "PAYPALISHIRING";
    // P   A   H   N
    // A P L S I I G
    // Y   I   R 
    int numRows1 = 3;
    std::cout << "Test Case 1: " << solution.convert(s1, numRows1) << std::endl;

    std::string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    std::cout << "Test Case 2: " << solution.convert(s2, numRows2) << std::endl;

    std::string s3 = "A";
    int numRows3 = 1;
    std::cout << "Test Case 3: " << solution.convert(s3, numRows3) << std::endl;

    std::string s4 = "HELLO";
    int numRows4 = 2;
    std::cout << "Test Case 4: " << solution.convert(s4, numRows4) << std::endl;

    return 0;
}