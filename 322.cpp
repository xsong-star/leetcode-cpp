#include <vector>
#include <iostream>
using namespace std;

int coinchange(vector<int>&coins,int amount)
{
    if(amount == 0)
        return 0;
    int n = coins.size();
    vector<int> dp(amount+1,amount+1);
    dp[0] = 0;
    for(int i = 1; i <= amount;i++)
        for(int j = 0;j < n; j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    return dp[amount]>amount?-1:dp[amount];
}

int main()
{
    vector<int> nums{1,2,3};
    cout << coinchange(nums,3) << endl;
    return 0;
}