#include<iostream>
#include<string>
#include<vector>
using namespace std;
//(����)
//��������һ����ά�ľ����У�Ѱ���Ƿ����ָ�����ַ��������ԴӾ���Ԫ�����ڵ�λ���ң��������ң�
//��ô���Ƕ�ά�������󣬲��ҵ��ҵ�һ����Ԫ����ʱ�����������Ԫ���������ҡ�
//�ο������ϵġ�������Ҫע����ǣ���Ҫһ����������¼����Щ�Ǳ����ʹ��ĵ�Ԫ����Ϊÿ����Ԫֻ���Ա�����һ�Ρ�

bool dfs(vector<vector<char>>&board,string word,int i,int j,int start,vector<vector<int>>visited){
	if(start == word.size()) return true;
	int row = board.size();
	int col = board[0].size();
	if(i < 0 || j < 0 || i >= row || j >= col) return false;
	if(visited[i][j]) return false;
	if(board[i][j]!=word[start]) return false;

	visited[i][j] = 1;
	if(dfs(board,word,i,j+1,start + 1,visited)){
		return true;
	}
	if(dfs(board,word,i+1,j,start+1,visited)){
		return true;
	}
	if(dfs(board,word,i-1,j,start+1,visited)){
		return true;
	}
	if(dfs(board,word,i,j-1,start+1,visited)){
		return true;
	}
	visited[i][j] = 0;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	int row = board.size();
	int col = board[0].size();
	int len = word.size();
	if(len > row*col ){
		return false;
	}
	vector<vector<int>> visited(row,vector<int>(col,0));
	for(int i = 0;i < row;i++){
		for(int j = 0;j < col;j++){
			if(dfs(board,word,i,j,0,visited)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	char b[][4]= {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	vector<vector<char>> board(3,vector<char>(4));
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 4;j++){
			board[i][j] = b[i][j];
			//cout<<board[i][j]<<" ";
		}
		//cout<<endl;
	}
	string word = "ABCCED";
	bool result = exist(board,word);
	cout<<result<<endl;
	return 0;
}