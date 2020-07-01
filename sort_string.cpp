#include<algorithm>
static bool compare1(const string a,const string b)
{
    if (a.size() < 1 || b.size() < 1)
    {
        return 0;
    }
    
    //比较的是两个字符串的和
    string a1 = "";
    string b1 = "";
    a1 = a + b;
    b1 = b + a;
    return a1.compare(b1) > 0;
}

static bool compare_char(const char a,const char b)
{

    return a > b;
}

class Solution {
public:
    

    string largestNumber(vector<int>& nums) {
        // int -> char
        vector<string> str;
        str.clear();
        int count = 0;
        if (nums.size() == 1)
        {
            return to_string(nums[0]);
        }
        for(int i = 0;i < nums.size();i++ )
        {
            string tmp = "";
            if (nums[i] == 0)
            {
                count++;
            }

            tmp =to_string(nums[i]);
            str.push_back(tmp);
        }

        if (count == (nums.size()))
        {
            //返回是字符串
            return "0";
        }
        // sort
        sort(str.begin(),str.end(),compare1);

        string result = "";
        for(int i = 0;i < str.size();i++)
        {
            result +=str[i];
            //cout<<str[i];
        }

        //sort(&result[0],&result[result.size() - 1],compare_char);
        if (result[0] == '0')
        {
            return "0";
        }
        return result;
    }


};
