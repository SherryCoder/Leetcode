#include<iostream>
#include<vector>
using namespace std;
//空间复杂度
//这题是给定一个矩阵m*n，将其中为0的元素所在的行列都置为0.
//第一种空间复杂度为O(m+n)的方法很好想
//第二种是空间复杂度为O(1)也就是没有开辟额外的空间，就不太好想了。我是参考的网上的解题思路
//将原矩阵中所有元素都不为0的一行作为方案一的存放数组，将列中有0的消息反应到该行。将其他的含有0的行置为0，再根据这行flag数组，将含有0的列置为0

//空间复杂度为O(m+n)
//void setZeroes(vector<vector<int>>& matrix) {
//	int row = matrix.size();
//	if(row <= 0)
//		return;
//	int column = matrix[0].size();
//	vector<int> rowColArray(row+column,0);
//	for(int i = 0;i < row;i++){
//		for(int j = 0;j < column;j++){
//			if(matrix[i][j] == 0){
//				rowColArray[i] = 1;
//				rowColArray[row + j] = 1;
//			}
//		}
//	}
//	for(int i = 0;i < row;i++){
//		if(rowColArray[i]==1){
//			for(int j = 0;j < column;j++){
//				matrix[i][j]=0;
//			}
//		}
//	}
//	for(int j = 0;j < column;j++){
//		if(rowColArray[row + j] == 1){
//			for(int i = 0;i < row;i++){
//				matrix[i][j] = 0;
//			}
//		}
//	}
//	return;
//}

//空间复杂度为O(1)
void setZeroes(vector<vector<int>>& matrix) {
	int row = matrix.size();
	if(row <= 0){
		return;
	}
	int col = matrix[0].size();
	int flagRow = -1;
	for(int i = 0;i < row;i++){
		int nonZeroCnt = 0;
		for(int j = 0;j < col;j++){
			if(matrix[i][j] != 0){
				nonZeroCnt++;
			}
		}
		if(nonZeroCnt == col){
			flagRow = i;
			break;
		}
	}
	if(flagRow == -1){
		for(int i = 0;i < row;i++){
			for(int j = 0;j < col;j++){
				matrix[i][j] = 0;
			}
		}
		return;
	}
	for(int j = 0;j < col;j++){
		for(int i = 0;i < row;i++){
			if(matrix[i][j]==0){
				matrix[flagRow][j] = 0;
			}
		}
	}

	for(int i = 0;i < row;i++){
		if(i == flagRow){
			continue;
		}
		for(int j = 0;j < col;j++){
			if(matrix[i][j] == 0){
				for(int k =0;k < col;k++){
					matrix[i][k] = 0;
				}
				continue;
			}
		}
	}

	for(int j = 0;j < col;j++){
		if(matrix[flagRow][j] == 0){
			for(int i = 0;i < row;i++){
				matrix[i][j] = 0;
			}
		}
	}
	return;
}