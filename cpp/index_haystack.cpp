#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int result = -1;
        for (size_t i = 0; i < (haystack.length() - needle.length() + 1); i++) {
            for (size_t j = 0; j < needle.length(); j++) {
                std::cout << "chars:  " << haystack[i+j] << needle[j]  << std::endl;
                if ((haystack[i+j] == needle[j]) && j+1 == needle.length()) {
                    result = i;
                    return result;

                }
                else if (haystack[i+j] == needle[j]) {
                    continue;
                }
                else {
                    break;
                }
            }

        }
        return result;
    }
};

int main() {
    Solution solution;
    std::string haystack = "hello";
    std::string needle = "ll";
    int index = solution.strStr(haystack, needle);
    std::cout << "Index: " << index << std::endl; // Expected output: 2

    haystack = "aaaaa";
    needle = "bba";
    index = solution.strStr(haystack, needle);
    std::cout << "Index: " << index << std::endl; // Expected output: -1

    haystack = "";
    needle = "";
    index = solution.strStr(haystack, needle);
    std::cout << "Index: " << index << std::endl; // Expected output: 0

    return 0;
}