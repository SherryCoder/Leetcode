//判断给定的一个棋盘是否是有效的Sudoku 
//Sudoku就是指每一行只能出现1-9中的每个数字一次，每一列也只能出现1-9中的每个数字一次
//并且在棋盘的子9宫格中，1-9也只能出现一次
//因此要遍历每行每列的元素，并且还要检查每个3*3宫格
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {

	if(board.empty()){
		return false;
	}
	for(int i = 0;i < 9;i++){
		unordered_map<char,bool>row;
		unordered_map<char,bool>col;
		unordered_map<char,bool>sub_nine;
		for(int j = 0;j < 9;j++){
			if(board[i][j]!='.'){                        //examine by row
				if(row[board[i][j]] == true){
					return false;
				}
				row[board[i][j]] = true;
			}
			if(board[j][i]!='.'){						//examine by column
				if(col[board[j][i]] == true){
					return false;
				}
				col[board[j][i]] = true;
			}
			if(board[i/3*3+j/3][i%3*3+j%3]!='.'){     //examin by sub nine board , should figure out when ith sub-nine board how to express each pixel
				if(sub_nine[board[i/3*3+j/3][i%3*3+j%3]] == true){
					return false;
				}
				sub_nine[board[i/3*3+j/3][i%3*3+j%3]] = true;
			}
		}
	}
	return true;
}


//别人的解法：直接看某行，某列中某个数字是否已经存在了
bool isValidSudoku_others(vector<vector<char>>& board) {
	int row[9][9] = {0},col[9][9] = {0},sub_board[9][9] = {0};
	for(int i = 0;i < board.size();i++){
		for(int j = 0;j < board[i].size();j++){
			if(board[i][j]!='.'){
				int num = board[i][j] - '0' - 1;
				int k = i/3*3 + j / 3;
				if(row[i][num]|col[j][num]|sub_board[k][num])
					return false;
				row[i][num] = col[j][num] = sub_board[k][num] = 1;
			}
		}
	}
	return true;
}
//int main(){
//	
//}