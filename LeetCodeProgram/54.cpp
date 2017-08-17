#include<iostream>
#include<vector>
using namespace std;

//这是一道螺旋遍历一个矩阵，输出的问题
//每次的遍历分为向右、向下、向左、向上，遍历的总次数是min（row,col）/2,并且如果较小的那个边是奇数，最后的遍历还要分出来讨论

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	if(matrix.empty()){
		return result;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int count = min(row,col)/2;
	int mod = min(row,col)%2;
	

	for(int i = 0;i < count;i++){
		for(int j = i;j < col - i - 1;j++){
			result.push_back(matrix[i][j]);
		}
		for(int j = i;j < row - i -1 ;j++){
			result.push_back(matrix[j][col - i - 1]);
		}
		for(int j = col - i - 1;j >= i+1;j--){
			result.push_back(matrix[row - i - 1][j]);
		}
		for(int j = row - i -1;j >= i+1;j--){
			result.push_back(matrix[j][i]);
		}
	}
	if(mod == 1){
		if(row == col){
			result.push_back(matrix[count][count]);
		}else if(row > col){
			for(int i = count;i < row - count ;i++ ){
				result.push_back(matrix[i][count]);
			}
		}else{
			for(int i = count;i < col - count ;i++){
				result.push_back(matrix[count][i]);
			}
		}
	}
	return result;
}