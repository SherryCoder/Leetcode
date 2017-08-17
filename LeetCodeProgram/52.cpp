#include<iostream>
#include<vector>
using namespace std;

//��51������N�ʺ�������һ���ģ�ֻ����������Ƿ��ؽ�ø�������һ���Ƿ������еĽ⣬ֻҪ����һ�¾Ϳ�����

bool check(int row,int col,int n,vector<string>m){
	if(row == 0){
		return true;
	}
	for(int i = 0;i < row;i++){
		if(m[i][col]=='Q'){
			return false;
		}
	}
	int i = row - 1;
	int j = col - 1;
	while(i>=0&&j>=0){
		if(m[i][j] == 'Q'){
			return false;
		}
		i--;
		j--;
	}
	i = row - 1;
	j = col + 1;
	while(i >= 0 && j < n){
		if(m[i][j] == 'Q')
			return false;
		i--;
		j++;
	}
	return true;
}

void solve(int row,int n ,int &result,vector<string>&m){
	if(row == n){
		result++;
		return;
	}
	for(int col = 0; col < n;col++){
		if(check(row,col,n,m)){
			m[row][col] = 'Q';
			solve(row+1,n,result,m);
			m[row][col] = '.';
		}
	}
	return;
}

int totalNQueens(int n) {
    int result = 0;
	vector<string>m(n,string(n,'.'));
	solve(0,n,result,m);
	return result;
}

//int main(){ 
//		
//	cout<<totalNQueens(1)<<endl;;
//	return 0;
//}