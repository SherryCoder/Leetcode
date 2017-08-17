#include<iostream>
#include<vector>
using namespace std;
//(动态规划)
//给你两个单词word1和word2，计算将word1变成word2所需要的最少的步骤
//只可以进行三种操作：insert delete,replace字母
//提示给的是动态规划
//这道题目有参考别人给的解题思路，代码没有参考
//用动态规划，构建m*n的矩阵，矩阵中的位置(i.j)就代表word1[0,i]（i代表从第一个字符开始的串长度到word2[0.j]的最短距离
//因此，对于位置(i,j)有三种到达方式，从board[i-1][j]+1或者board[i][j-1]+1变换来或者从board[i-1][j-1]取决于word1[i-1]word2[j-1]相不相等变换来
//一开始的时候是要初始化边界board[i][0]和board[0][j]
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
