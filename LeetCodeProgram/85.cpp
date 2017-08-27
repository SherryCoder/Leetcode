#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//在只有0 ，1的矩形中求取矩形面积最大值
//是84题的一个扩展
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
	vector<int> hist(w+1,0);   //结尾加一个0，收割作用
	for(int i = 0; i< h;i++){
		for(int j = 0;j < w;j++)
			hist[j] = (hist[j]+1)*(matrix[i][j]-'0');
		maxArea = max(maxArea,largestRectangleArea(hist));
	}
	return maxArea;
}