#include<iostream>
#include<vector>
using namespace std;
//螺旋遍历矩阵的另一个题目，这个题目是给定你一个数字n，要求你返回一个N*N的螺旋矩阵
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> result;
	if(n<=0){
		return result;
	}
	if(n==1){
		result.resize(1);
		result[0].resize(1);
		result[0][0] = 1;
		return result;
	}
	vector<int>matrix;
	matrix.resize(n*n);
//	cout<<matrix.size()<<endl;
	for(int i = 0;i < n*n;i++){
		matrix[i] = i+1;
	}
	result.resize(n);
	for(int i = 0;i < n;i++){
		result[i].resize(n);
	}
	int count = n/2;
	int mod = n%2;
	int k =0;
		for(int i = 0;i < count;i++){
			for(int j = i;j < n-i-1;j++){
				result[i][j] = matrix[k];
				k++;
			}
			for(int j = i;j < n-i-1;j++){
				result[j][n-i-1] = matrix[k];
				k++;
			}
			for(int j = n-i-1;j > i;j--){
				result[n-i-1][j] = matrix[k];
				k++;
			}
			for(int j = n-i-1;j >i;j--){
				result[j][i] = matrix[k];
				k++;
			}
		}
		if(mod){
			result[count][count] = matrix[k];
		}


	return result;
}


//int main(){
//	vector<vector<int>>result = generateMatrix(4);
//	for(int i = 0;i < result.size();i++){
//		for(int j = 0;j < result[0].size();j++){
//			cout<<result[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//}