#include <string>
#include <vector>
#include <iostrem>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int total_len = 0;
        for (const std::string &word : words) {
            total_len += word.length();
        }
        int rows = (total_len + maxWidth - 1)/ maxWidth;
        std::vector<std::vector<std::string>> lines(rows, std::vector<std::string>(1, ""));
        
        for (const std::string &word : words) {
            total_len += word.length();
        }

        
    }
};