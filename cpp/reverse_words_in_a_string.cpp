class Solution {
public:
    string reverseWords(string s) {
        std::string result = "";
        int word_end = -1;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (word_end == -1) {
                if (s[i] == ' ') {
                    continue; // Skip trailing or intermediate spaces
                } else {
                    if (i == 0){
                        result += s.substr(0, 1);
                    }
                    else {
                        word_end = i; // Mark the end of a word
                    }
                    
                }
            } else {
                if (s[i] == ' ') {
                    // Add the word to the result
                    result += s.substr(i + 1, word_end - i) + " ";
                    word_end = -1; // Reset word_end to find the next word
                } else if (i == 0) {
                    // Handle the first word (when i reaches 0)
                    result += s.substr(i, word_end - i + 1);
                }
            }
        }

        // Trim trailing space if any
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};