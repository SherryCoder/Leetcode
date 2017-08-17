//本题的题意：对一个N*N的图像顺时针方向旋转90度，求旋转后的矩阵
//可以知道旋转后和旋转前的对应关系是result[i][j] = matrix[row-1-j][i]，直接这样赋值，去求得result就可以了
//然后用求得的result再赋值给matrix，找到这个对应关系就还听简单的。

#include<iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int col = matrix.size();
	int row = matrix[0].size();
	vector<vector<int>> result;
	result.resize(col);
	for(int i = 0;i < col;i++){
		result[i].resize(row);
	}
	for(int i = 0;i < col;i++){
		for(int j = 0; j < row;j++){
			result[i][j] = matrix[row-1-j][i];
		}
	}
	for(int i = 0;i<col;i++){
		for(int j = 0;j < row;j++){
			matrix[i][j] = result[i][j];
		}
	}
	return;
}