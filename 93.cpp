#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

vector<string> restoreIpAddresses(string s)
{
    int n = s.size();
    vector<int> segment_(4);
    vector<string> res;

    function<void(int,int)> dfs = [&](int curId,int curPos)
    {
        if(curId == 4)
        {
            if(curPos == n)
            {
                string iAddr;
                for(int i = 0;i<4;i++)
                {
                    iAddr += to_string(segment_[i]);
                    if(i!=3)
                        iAddr += '.';
                }
                res.emplace_back(iAddr);
            }
            return;
        }

        //如果还没找到  就遍历完
        if(curPos == n)
            return;
        
        //如果这位数字是0
        if(s[curPos] == '0')
        {
            segment_[curId] = 0;
            dfs(curId+1,curPos+1);
        }

        //枚举所有可能递归
        int addr = 0;
        for(int endPos = curPos;endPos<n;endPos++)
        {
            addr = addr*10+(s[endPos]-'0');
            if(addr>0&&addr<=255)
            {
                segment_[curId] = addr;
                dfs(curId+1,endPos+1);
            }
            else
                break;
        }
    };
    dfs(0,0);
    return res;
}

int main()
{
    vector<string> res;
    string s("25525511135");
    res = restoreIpAddresses(s);
    for_each(res.begin(),res.end(),[](string t){ cout<<t<<" ";});
    cout<<endl;
    return 0;
}