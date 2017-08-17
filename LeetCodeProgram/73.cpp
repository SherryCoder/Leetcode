#include<iostream>
#include<vector>
using namespace std;
//�ռ临�Ӷ�
//�����Ǹ���һ������m*n��������Ϊ0��Ԫ�����ڵ����ж���Ϊ0.
//��һ�ֿռ临�Ӷ�ΪO(m+n)�ķ����ܺ���
//�ڶ����ǿռ临�Ӷ�ΪO(1)Ҳ����û�п��ٶ���Ŀռ䣬�Ͳ�̫�����ˡ����ǲο������ϵĽ���˼·
//��ԭ����������Ԫ�ض���Ϊ0��һ����Ϊ����һ�Ĵ�����飬��������0����Ϣ��Ӧ�����С��������ĺ���0������Ϊ0���ٸ�������flag���飬������0������Ϊ0

//�ռ临�Ӷ�ΪO(m+n)
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

//�ռ临�Ӷ�ΪO(1)
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