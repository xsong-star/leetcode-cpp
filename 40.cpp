#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n = candidates.size();
    sort(candidates.begin(),candidates.end());

    vector<vector<int>> res;
    vector<int> tmp;

    function<void(int,int)> bt = [&](int idx,int t)->void
    {
        if(t == 0)
        {
            res.push_back(tmp);
            return;
        } 

        for(int i = idx;i<n&&t-candidates[i]>=0;i++)
        {
            if(i>idx&&candidates[i]==candidates[i-1])
                continue;
            tmp.push_back(candidates[i]);
            bt(i+1,t-candidates[i]);
            tmp.pop_back();
        }
    };
    bt(0,target);
    return res;
}
int main()
{
    vector<int> candidates{10,1,2,7,6,1,5};
    vector<vector<int>> res = combinationSum2(candidates,8);
    for_each(res.begin(),res.end(),[](vector<int> tmp){for_each(tmp.begin(),tmp.end(),[](int x){cout<<x<<" ";});cout<<endl;});
    return 0;
}