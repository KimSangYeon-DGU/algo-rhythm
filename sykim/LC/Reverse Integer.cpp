#include <cmath>

class Solution {
public:
    int reverse(int x) {
        int sgn = 1;
        int rvs = 0;
        
        if (x < 0)
            sgn = 0; // Negative
        
        int q, r;
        q = 1;

        vector<int> digits;
        
        // Split whole number into each digit.
        while (q != 0)
        {
            r = x % 10;
            q = x / 10;

            digits.push_back(r);

            x = q;
        }
        
        int size = digits.size();
        int posMax = 2147483647;
        int negMax = 2147483648;
        
        // Generate a reverse value.
        for (auto d : digits)
        {
            size--;
            rvs += d * pow(10, size);
            
            // Overflow Check!
            // when we divide reversed value by each maximum value,
            // if it returns more than 0, it overflowed.
            if (sgn == 1 && rvs / posMax != 0)
            {
                rvs = 0;
                break;
            }
            else if (sgn == 0 && rvs / negMax != 0)
            {
                rvs = 0;
                break;
            }
        }
        
        return rvs;
    }
};
