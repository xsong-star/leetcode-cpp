#include <vector>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    int ws = word.size();
    function<bool(int,int,int)> judge = [&](int i,int j,int k)->bool
    {
        if(i == n || j== n || i == m || j == m||i<0||j<0)
            return false;
        if(k == ws)
            return true;
        if(board[i][j] != word[k])
            return false;
        char t = board[i][j];
        board[i][j] = '0';
        bool ret =  judge(i+1,j,k+1)||judge(i,j+1,k+1)||judge(i-1,j,k+1)||judge(i,j-1,k+1);
        board[i][j] = t;
        return ret;
    };

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(judge(i,j,0))
                return true;
        }
    }
    return false;
}


int main()
{
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word("SEE");
    cout << exist(board,word) << endl;
    return 0;
}