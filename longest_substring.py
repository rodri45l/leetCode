class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        temp_str = ""
        if len(s) == 0:
            return 0
        elif len(s) == 1:
            return 1
        for char in s:
            if char in temp_str:
                length_str = len(temp_str)
                if length_str > max_len:
                    max_len = length_str
                    print(f"{temp_str} - {max_len}")
                temp_str = temp_str[temp_str.index(char) + 1 :] + char
            else:
                temp_str += char
        if len(temp_str) > max_len:
            return len(temp_str)
        return max_len


if __name__ == "__main__":
    s = Solution()
    # print(s.lengthOfLongestSubstring("abcabcbb"))  # 3
    # print(s.lengthOfLongestSubstring("bbbbb"))  # 1
    print(s.lengthOfLongestSubstring("pwwkew"))  # 3
    # print(s.lengthOfLongestSubstring(""))  # 0
    # print(s.lengthOfLongestSubstring(" "))  # 1
