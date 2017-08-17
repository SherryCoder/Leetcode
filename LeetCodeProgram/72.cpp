#include<iostream>
#include<vector>
using namespace std;
//(��̬�滮)
//������������word1��word2�����㽫word1���word2����Ҫ�����ٵĲ���
//ֻ���Խ������ֲ�����insert delete,replace��ĸ
//��ʾ�����Ƕ�̬�滮
//�����Ŀ�вο����˸��Ľ���˼·������û�вο�
//�ö�̬�滮������m*n�ľ��󣬾����е�λ��(i.j)�ʹ���word1[0,i]��i����ӵ�һ���ַ���ʼ�Ĵ����ȵ�word2[0.j]����̾���
//��ˣ�����λ��(i,j)�����ֵ��﷽ʽ����board[i-1][j]+1����board[i][j-1]+1�任�����ߴ�board[i-1][j-1]ȡ����word1[i-1]word2[j-1]�಻��ȱ任��
//һ��ʼ��ʱ����Ҫ��ʼ���߽�board[i][0]��board[0][j]
int minDistance(string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();
	vector<vector<int>> board(len1+1);
	for(int i = 0;i <= len1;i++){
		board[i].resize(len2+1,0);
	}
	for(int i = 0;i <= len1;i++){
		board[i][0] = i;
	}
	for(int j = 0; j <= len2;j++){
		board[0][j] = j;
	}
	for(int i = 1;i <= len1;i++){
		for(int j = 1;j <= len2;j++){
			int upStep = board[i-1][j] + 1;
			int leftStep = board[i][j-1] + 1;
			int step = (word1[i-1]==word2[j-1])?0:1;
			int diaStep = board[i-1][j-1] + step;
		
			int min = upStep;
			if(leftStep < min){
				min = leftStep;
			}
			if(diaStep < min){
				min = diaStep;
			}
			board[i][j] = min;
		}
	}
	return board[len1][len2];
}

int main(){
	string word1 = "tet";
	string word2 = "eest";
	int result = minDistance(word1,word2);
	cout<<result<<endl;
	return 0;
}
