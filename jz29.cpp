#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static constexpr int desti[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n == 0)
        return {};
    int m = matrix[0].size();
    if (m == 0)
        return {};   
    vector<int> res(m*n);
    vector<vector<bool>> visited_(n,vector<bool>(m,false));
    int row = 0,col = 0;
    int des = 0;
    for(int i = 0;i<m*n;i++)
    {
        res[i] = matrix[row][col];
        visited_[row][col] = true;

        int newRow = desti[des][0] + row;
        int newCol = desti[des][1] + col;
        if(0>newRow||newRow>=n||0>newCol||newCol>=m||visited_[newRow][newCol]==true)
            des = (des+1)%4;
        row = desti[des][0] + row;
        col = desti[des][1] + col;
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = spiralOrder(matrix);
    for_each(res.begin(),res.end(),[](int x){ cout<<x<<" ";});
    cout<<endl;
    return 0;
}