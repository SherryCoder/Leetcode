//�жϸ�����һ�������Ƿ�����Ч��Sudoku 
//Sudoku����ָÿһ��ֻ�ܳ���1-9�е�ÿ������һ�Σ�ÿһ��Ҳֻ�ܳ���1-9�е�ÿ������һ��
//���������̵���9�����У�1-9Ҳֻ�ܳ���һ��
//���Ҫ����ÿ��ÿ�е�Ԫ�أ����һ�Ҫ���ÿ��3*3����
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


//���˵Ľⷨ��ֱ�ӿ�ĳ�У�ĳ����ĳ�������Ƿ��Ѿ�������
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