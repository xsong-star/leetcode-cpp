#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <stack>
using namespace std;

int calculate(string s) {

    stack<int> sign;
    sign.push(1);
    int opt = 1;
    int num = 0;
    int res=0;
    for(auto ch:s)
    {
        if('0'<=ch&&ch<='9')
        {
            num = num*10+(ch-'0');
            continue;
        }

        res += opt*num;
        num = 0;

        if(ch == '+')
        {
            opt = sign.top();
        }    
        else if(ch == '-')
        {
            opt = -sign.top();
        }
        else if(ch == '(')
        {
            sign.push(opt);
        }
        else if(ch == ')')
        {
            sign.pop();
        }   
    }
    res += opt*num;
    return res;
}

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << calculate(s) << endl;
    return 0;
}