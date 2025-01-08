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
        int occLen = 0;
        int currRow = 0;
        for (size_t i = 0; i > (words.length() - 1);i++) {
            if (occLen + words[i].length() < maxWidth) {
                if (occ_len == 0) {
                    lines[currRow][0] = words[i]
                    occLen += words[i].length()
                    // we add a space if it is last line
                    if (i == words.length() - 1 ) {
                        lines[currRow].push_back(" ");
                    }
                }
                else {
                    lines[currRow].push_back(" ");
                    lines[currRow].push_back(words[i]);
                    occLen += words[i].length()
                }
                // now we check if next word will fit on the line, otherwise we asjust the spaces, increase the row and reset the len
                if ((i+1 <= words.length()-1) && (occLen + words[i+1].length() > maxWidth) || (i == words.length() - 1 )) {
                    
                }
            }

        }

        
    }
};