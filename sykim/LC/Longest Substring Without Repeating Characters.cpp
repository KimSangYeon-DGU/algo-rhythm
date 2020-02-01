class Solution {
public:
    int character[126];
    void reset()
    {
        for (int i = 0; i < 126; i++)
        {
            character[i] = 0;
        }
    }
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int maxStrLen = 0;
        for (int i = 0; i < len; i++)
        {
            int start = i;
            int strLen = 0;
            while (start < len)
            {
                if (character[s[start]-' '] == 0)
                {
                    character[s[start]-' ']++;
                    start++;
                    strLen++;
                }
                else
                {
                    reset();
                    break;
                }
            }
            
            if (maxStrLen < strLen)
                maxStrLen = strLen;
        }
        return maxStrLen;
    }
};
