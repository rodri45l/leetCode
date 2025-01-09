#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string joinLine(const std::vector<std::string>& line) {
        std::string result;
        size_t totalLength = 0;
        for (const auto& word : line) totalLength += word.size() + 1; // Word length + space.
        result.reserve(totalLength);
        for (const std::string& word : line) {
            result += word;
            result += " ";
        }

        // Remove the trailing space (if necessary)
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
    std::vector<std::string> getWords(int i, std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> currentLine;
        int currLength = 0;
        while (i < words.size() && currLength + words[i].length() <= maxWidth) {
            currentLine.push_back(words[i]);
            currLength += words[i].length() + 1;
            i++;
        }
        return std::move(currentLine);
    }
    std::string createLine(std::vector<std::string>& line, int maxWidth, bool lastLine) {
        int currentLen = line.size() - 1;
        for (const std::string &word : line) {
            currentLen += word.length();
        }
        // case 1 regular line
        int spaceToFill = maxWidth - currentLen;
        int regularSpaces;
        int extraSpaces;
        if(line.size() == 1) {
            regularSpaces = 0;
        }
        else {
            regularSpaces = spaceToFill /(line.size() - 1);
            extraSpaces = spaceToFill%(line.size() - 1);
        }
        if (lastLine || line.size() == 1) {
            line[line.size()-1] += std::string(spaceToFill,' ');
        }
        else {
        for (int i = 0; i <= line.size() - 2; i++) {
            line[i] += std::string(regularSpaces, ' '); // Add regular spaces
            if (extraSpaces > 0) { // Distribute extra spaces
                line[i] += " "; // Add one extra space
                extraSpaces--;
            }
        }
        }
        return joinLine(line);


                      }
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> ans;
        bool lastLine = false;
        int i = 0;
        while (i < words.size()) {
            std::vector<std::string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            bool lastLine = (i >= words.size());
            ans.push_back(createLine(currentLine, maxWidth, lastLine));
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    std::vector<std::string> result = solution.fullJustify(words, maxWidth);

    for (const std::string& line : result) {
        std::cout << "\"" << line << "\"" << std::endl;
    }

    return 0;
}