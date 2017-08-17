#include<iostream>
#include<vector>

using namespace std;
//��36��ı������ƣ�����sudoku���⣬�����Ǹ���һ��board�������ڿո������������֣�ʹ�����������ܹ�����sudoku�Ĺ���
//������ϵ�˼·����N-QueenI��N-QueenII�ǲ��ģ���DFS��Backtracing��˼·

class Solution{
private:
	bool isOver;  //�����ж��Ƿ��Ѿ���������������
public:
	//������ȱ���
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
				if(this->isOver) return;   //�ҵ�һ�������ķ������������̾ͷ���
				board[i][j] = '.';
			}
		}
		return;
	}

	//�ж�i,jλ�����ڵ��С��С�3*3�����Ƿ����sudokuҪ��
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