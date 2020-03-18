//剑指offer
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        int i = 0;
        if (str.empty())
        {
            return result;
        }
        permution(str,i,result);
        sort(result.begin(), result.end());
        vector<string>::iterator it;
        for (it = result.begin(); (it+1) != result.end();)
        {
            if (*it == *(it + 1))
            {
                it = result.erase(it);
            }
            else
                it++;
        }
        return result;
    }
    void permution(string str, int i, vector<string>& result)
    {
        if (i==str.length()-1)
        {
            result.push_back(str);
        }
        for (int j = i; j < str.length();j++)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            permution(str, i + 1, result);
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
};

//关于重复的字符串的处理 没有看明白