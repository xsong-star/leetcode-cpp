#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

vector<vector<string>> partition(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,true));
    for(int i = n-1;i>=0;--i)
    {
        for(int j = i+1;j<n;++j)
        {
            dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
        }
    }

    vector<vector<string>> res;
    vector<string> tmp;

    function<void(int)> dfs = [&](int idx)
    {
        if(idx == n)
        {
            res.push_back(tmp);
            return;
        }

        for(int k = idx;k<n;k++)
        {
            if(dp[idx][k])
            {
                tmp.push_back(s.substr(idx,k-idx+1));
                dfs(k+1);
                tmp.pop_back();
            }
        }
    };
    dfs(0);
    return res;
}

int main()
{
    vector<vector<string>> res;
    string s = "abbc";
    res = partition(s);
    for_each(res.begin(),res.end(),[](vector<string> t){
        for_each(t.begin(),t.end(),[](string s){
            cout << s << " ";
        });
        cout<<endl;
    });
    return 0;
}