#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // If the input vector is empty, return an empty string.
        }

        // Step 1: Find the minimum length among the strings
        int min_len = INT_MAX;
        for (const string& word : strs) {
            int len = word.length(); // Get the length of the current string
            if (len < min_len) {     // Update min_len if the condition is met
                min_len = len;
            }
        }

        // Step 2: Compare characters up to min_len
        string prefix = "";
        for (size_t i = 0; i < min_len; ++i) {
            char current_char = strs[0][i]; // Use the first string as reference
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != current_char) {
                    return prefix; // If a mismatch is found, return the prefix
                }
            }
            prefix += current_char; // Add the current character to the prefix
        }

        return prefix; // Return the longest common prefix
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"float", "fly", "flu"};
    cout << "Longest Common Prefix: " << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
