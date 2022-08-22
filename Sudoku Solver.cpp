#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<pair<char,int>>>&board, int row, int col, int num){
    for (int i=0;i<9;i++){
        if (board[i][col].first==num+'0'){
            return false;
        }
    }
    for (int i=0;i<9;i++){
        if (board[row][i].first==num+'0'){
            return false;
        }
    }
    int x=row/3;
    int y=col/3;
    for (int i=x*3;i<3*(x+1);i++){
       for (int j=y*3;j<3*(y+1);j++){
            if (board[i][j].first==num+'0'){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<pair<char,int>>>&board, int row, int col){
    if (row>=9){
        return true;
    }
    if (col>=9){
        return solve(board,row+1,0);
    }
    if (board[row][col].second==1){
        return solve(board,row,col+1);
    }
    for (int i=1;i<=9;i++){
        if (isSafe(board,row,col,i)){
            board[row][col]={i+'0',0};
            if (solve(board,row,col+1)){
                return true;
            }
            board[row][col]={'.',0};
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>&board) {
    vector<vector<pair<char,int>>>board_temp;
    for (int i=0;i<9;i++){
        vector<pair<char,int>>temp;
        if (temp.size()!=0){
            temp.clear();
        }
        for (int j=0;j<9;j++){
            if (board[i][j]=='.'){
                temp.push_back({board[i][j],0});
            }
            else{
                temp.push_back({board[i][j],1});
            }
        }
        board_temp.push_back(temp);
    }
    bool x=solve(board_temp,0,0);
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            board[i][j]=board_temp[i][j].first;
        }
    }
}

int main()
{   
    vector<vector<char>>dp;
    for (int i=0;i<9;i++){
        vector<char>v;
        for (int j=0;j<9;j++){
            char l;
            cin>>l;
            v.push_back(l);
        }
        dp.push_back(v);
    }
    solveSudoku(dp);
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
