#include<iostream>
#include<vector>
using namespace std;
//���ַ�
//�ڶ�ά����������һ�����֡�����һ���е��Ѷȵ���Ŀ������һ��ʼȴ��ƫ��
//�����׾��û�ȥ�ö��ַ�������һ������n���������б�ʾn/col n%colû���뵽
//��һ�ַ����������бȽ����һ��Ԫ�غ�target�Ĵ�С�����С��target�Ͱ������������ӣ����������target�Ϳ�ʼ����j

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