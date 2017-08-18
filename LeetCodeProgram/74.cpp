#include<iostream>
#include<vector>
using namespace std;
//二分法
//在二维矩阵中搜索一个数字。这是一个中等难度的题目，但我一开始却想偏了
//很容易觉得会去用二分法，但是一个数字n，它的行列表示n/col n%col没有想到
//第一种方法，是逐行比较最后一个元素和target的大小，如果小于target就把行数继续增加，如果大于了target就开始操作j

bool searchMatrix(vector<vector<int>>& matrix,int target){
	if(matrix.empty()){
		return false;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int i = 0,j = col - 1;
	while(i < row && j >= 0){
		if(matrix[i][j] == target){
			return true;
		}else if(matrix[i][j] < target){
			i++;
		}else{
			j--;
		}
	}
	return false;
}

bool searchMatrix_binary(vector<vector<int>>& matrix, int target){
	if(matrix.empty()){
		return false;
	}
	if(matrix.size()==1 && matrix[0].size()==1){
		return target == matrix[0][0];
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int left = 0;
	int right = row*col - 1;
	while(left < right){
		if(left + 1 == right){
			int lrow = left/col;
			int lcol = left%col;
			int rrow = right/col;
			int rcol = right%col;
			if(matrix[lrow][lcol] == target || matrix[rrow][rcol] == target){
				return true;
			}else{
				return false;
			}
		}
		int mid = (left + right)/2;
		int midrow = mid/col;
		int midcol = mid%col;
		if(matrix[midrow][midcol] < target){
			left = mid;
		}
		if(matrix[midrow][midcol] > target){
			right = mid;
		}
		if(matrix[midrow][midcol] == target){
			return true;
		}
	}
	return false;
}
//int main(){
//	vector<vector<int>> matrix;
//	bool res = searchMatrix(matrix,1);
//	cout<<res<<endl;
//	return 0;
//}