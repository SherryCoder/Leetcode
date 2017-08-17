#include<iostream>
#include<vector>
using namespace std;
//N皇后问题，在一个N*N的棋盘上放置N个皇后，要保证同一行、同一列、同一个对角线只有一个皇后
//采用的是一行一行的加皇后。检查[row,col]可不可以放置皇后，如果可以放置就接着增加行数，不可以放置就接着增加列数。
//在第row+1行，尝试了所有的列数都不能够放置皇后，那么当前就是无解的，需要将上一次放置的皇后取消掉，也就是回溯。

bool check(int row,int col,int n,vector<string>&m){
	if(row == 0){
		return true;
	}
	for(int i = 0;i < row;i++){
		if(m[i][col] == 'Q')
			return false;
	}
	int i = row - 1;
	int j = col - 1;
	while(i>=0 && j >=0){
		if(m[i][j]=='Q')
			return false;
		i--;
		j--;
	}
	i = row - 1;
	j = col + 1;
	while(i >= 0 && j < n){
		if(m[i][j]=='Q')
			return false;
		i--;
		j++;
	}
	return true;
}


void solve(int row,int n, vector<vector<string>>&result,vector<string>&m){
	if(row == n){
		result.push_back(m);
		return;
	}
	for(int col = 0;col < n;col++){
		if(check(row,col,n,m)){
			m[row][col] = 'Q';
			solve(row+1,n,result,m); //这边递归row+1行，这时候如过check了所有的(row+1,col)都失败的话，就会返回，这个时候就要把row,col撤销，如果这边能够一
									//直递归下去，就会在这边就返回，然后会去执行col+1
			m[row][col] = '.';		//这边，如果在有了成功的例子后，一直到row=n的时候就会有返回，那么就会慢慢的把前面置为Q的重新置为.
									//这样的话方便下面第一个Q从0,col+1开始
		}
		
	}
}

vector<vector<string>> solveNQueens(int n) {
	vector<string> m(n,string(n,'.'));
	vector<vector<string>> result;
	solve(0,n,result,m);
	return result;
}

//int main(){
//	vector<string> m(10,string(10,'.'));  //初始化了一个二维的棋盘，棋盘的长度为N
//	
//	return 0;
//}