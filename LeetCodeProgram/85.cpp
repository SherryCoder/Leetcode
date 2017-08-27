#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//��ֻ��0 ��1�ľ�������ȡ����������ֵ
//��84���һ����չ
int largestRectangleArea(vector<int>& heights) {
	int len = heights.size();
	stack<int> area;
	int maxArea = 0;
	for(int i = 0;i < len;i++){
		if(area.empty() || heights[i] > heights[area.top()]){
			area.push(i);
		}else{
			while(!area.empty() && heights[i] < heights[area.top()]){
				int h = heights[area.top()];
				area.pop();
				int w = area.empty()?i:(i - area.top()-1);
				maxArea = max(maxArea,h*w);
			}
			area.push(i);
		}
	}
	return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix){
	if(matrix.empty() || matrix[0].empty()){
		return 0;
	}
	int h = matrix.size();
	int w = matrix[0].size();
	int maxArea = 0;
	vector<int> hist(w+1,0);   //��β��һ��0���ո�����
	for(int i = 0; i< h;i++){
		for(int j = 0;j < w;j++)
			hist[j] = (hist[j]+1)*(matrix[i][j]-'0');
		maxArea = max(maxArea,largestRectangleArea(hist));
	}
	return maxArea;
}