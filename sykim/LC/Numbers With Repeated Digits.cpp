// The main idea came from https://leetcode.com/problems/numbers-with-repeated-digits/discuss/258212/Share-my-O(logN)-C%2B%2B-DP-solution-with-proof-and-explanation

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        if (N < 10)
            return 0;
        
        int k = 0;

        for (int i = N; i > 0; i /= 10) k++;

        int digits[k] = {0};

        for (int i = 0, j = N; i < k; i++, j /= 10) digits[k - 1 - i] = j % 10;

        int noRepeatedSum = 0;
        int noRepeated[k - 1] = {0};

        for (int i = 0; i < k - 1; i++)
        {
            noRepeated[i] = i == 0 ? 9 : noRepeated[i - 1] * (10 - i);
            noRepeatedSum += noRepeated[i];
        }

        int count[10] = {0};
        int noRepeatedRes[k] = {0};
        bool repeated = false;

        for (int i = 0; i < k; i++)
        {
            noRepeatedRes[i] = i == 0 ? 9 : noRepeatedRes[i - 1] * (10 - i);
            if (!repeated)
            {
                int diff = 0;
                for (int j = digits[i] + 1; j < 10; j++) diff += count[j] == 0;
                noRepeatedRes[i] -= diff;
                count[digits[i]]++;

                if (count[digits[i]] > 1) repeated = true;
            }
        }
        return N - (noRepeatedSum + noRepeatedRes[k - 1]);
    }
};