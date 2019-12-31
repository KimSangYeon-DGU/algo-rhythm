class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        
        rtrim(s);

        int len = s.size();
        for (int i = len-1; i >= 0; i--)
        {
            if (s[i] == ' ')
                break;
            ret++;
        }
        
        return ret;
    }
    
    void rtrim(string& s, const char* t = " ")
    {
        s.erase(s.find_last_not_of(t) + 1);
    }
};
