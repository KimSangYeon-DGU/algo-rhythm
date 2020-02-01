class Solution {
public:
    int findComplement(int num)
    {
        //std::cout << reverseBinary(cvtFromDecToBin(num)) << "\n";
        return cvtFromBinToDec(reverseBinary(cvtFromDecToBin(num)));
    }
    
    string cvtFromDecToBin(int num)
    {
        string ret = "";
        vector<char> binary;
        int curNum = num;
        while (true) 
        {
            if (curNum == 1)
            {
                binary.push_back('1');
                break;
            }
            else if (curNum == 2)
            {
                binary.push_back('0');
                binary.push_back('1');
                break;
            }
            if (curNum % 2 == 0)
                binary.push_back('0');
            else
                binary.push_back('1');
            curNum = curNum / 2;
        }
        
        int binLength = binary.size();
        for (int i = binLength - 1; i >= 0; i--)
            ret += binary[i];
        return ret;
    }

    string reverseBinary(string binary)
    {
        string ret = "";
        int binLength = binary.size();
        for (int i = 0; i < binLength; i++)
        {
            if (binary[i] == '0')
                ret += '1';
            else
                ret += '0';
        }
        return ret;
    }
    
    int cvtFromBinToDec(string binary)
    {
        int binLength = binary.size();
        int nth = 0;
        int ret = 0;
        for (int i = binLength-1; i >= 0; i--)
        {
            if (binary[i] == '1')
                ret += pow(2, nth);
            nth++;
        }
        return ret;
    }  
};
