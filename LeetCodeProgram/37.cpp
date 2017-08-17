#include<iostream>
#include<vector>

using namespace std;
//与36题的背景相似，都是sudoku问题，这题是给你一个board，让你在空格子里面填数字，使得最后的棋盘能够满足sudoku的规则
//借鉴网上的思路，和N-QueenI和N-QueenII是差不多的，用DFS和Backtracing的思路

class Solution{
private:
	bool isOver;  //用来判断是否已经填满了整个棋盘
public:
	//深度优先遍历
	void dfs(vector<vector<char>>&board,int i,int j,int n){
		if(j>=9){
			dfs(board,i+1,0,n);
		}else if(i==n){
			this->isOver = true;
			return;
		}else if(board[i][j] != '.'){
			dfs(board,i,j+1,n);
		}else{
			for(int k = 1;k < n+1;k++){
				board[i][j] = (char)(k+'0');
				if(isValidSudoku(board,i,j,n)){
					dfs(board,i,j+1,n);
				}
				if(this->isOver) return;   //找到一个完整的符合条件的棋盘就返回
				board[i][j] = '.';
			}
		}
		return;
	}

	//判断i,j位置所在的行、列、3*3矩形是否符合sudoku要求
	bool isValidSudoku(vector<vector<char>>& board,int i,int j,int n) {
		for(int k = 0; k < n ;k++){
			if(k !=j && board[i][k] == board[i][j]){
				return false;
			}
		}

		for(int k = 0; k < n ;k++){
			if(k!=i && board[k][j]==board[i][j])
				return false;
		}

		int k_i = i/3;
		int k_j = j/3;
		for(int x = k_i*3;x < k_i*3+3;x++){
			for(int y = k_j*3;y < k_j*3+3;y++){
				if((x!=i||y!=j)&&board[x][y] == board[i][j]){
					return false;
				}
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		if(board.empty()) return;
		this->isOver = false;
		dfs(board,0,0,9);
		return;
	}
};