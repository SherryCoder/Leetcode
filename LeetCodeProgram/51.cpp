#include<iostream>
#include<vector>
using namespace std;
//N�ʺ����⣬��һ��N*N�������Ϸ���N���ʺ�Ҫ��֤ͬһ�С�ͬһ�С�ͬһ���Խ���ֻ��һ���ʺ�
//���õ���һ��һ�еļӻʺ󡣼��[row,col]�ɲ����Է��ûʺ�������Է��þͽ������������������Է��þͽ�������������
//�ڵ�row+1�У����������е����������ܹ����ûʺ���ô��ǰ�����޽�ģ���Ҫ����һ�η��õĻʺ�ȡ������Ҳ���ǻ��ݡ�

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
			solve(row+1,n,result,m); //��ߵݹ�row+1�У���ʱ�����check�����е�(row+1,col)��ʧ�ܵĻ����ͻ᷵�أ����ʱ���Ҫ��row,col�������������ܹ�һ
									//ֱ�ݹ���ȥ���ͻ�����߾ͷ��أ�Ȼ���ȥִ��col+1
			m[row][col] = '.';		//��ߣ���������˳ɹ������Ӻ�һֱ��row=n��ʱ��ͻ��з��أ���ô�ͻ������İ�ǰ����ΪQ��������Ϊ.
									//�����Ļ����������һ��Q��0,col+1��ʼ
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
//	vector<string> m(10,string(10,'.'));  //��ʼ����һ����ά�����̣����̵ĳ���ΪN
//	
//	return 0;
//}