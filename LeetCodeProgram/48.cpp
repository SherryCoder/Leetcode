//��������⣺��һ��N*N��ͼ��˳ʱ�뷽����ת90�ȣ�����ת��ľ���
//����֪����ת�����תǰ�Ķ�Ӧ��ϵ��result[i][j] = matrix[row-1-j][i]��ֱ��������ֵ��ȥ���result�Ϳ�����
//Ȼ������õ�result�ٸ�ֵ��matrix���ҵ������Ӧ��ϵ�ͻ����򵥵ġ�

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