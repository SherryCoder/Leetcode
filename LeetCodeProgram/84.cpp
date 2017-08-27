#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//栈方法，对于一个矩形条来说，它的左边界是它自己本身，右边界是目前栈顶的元素
//这题好难理解
//利用了栈的性质，栈是后进先出的特性，pop是取出栈中最上层的元素，也就是最早入栈的元素
// top是查看栈的上层元素
// push是将一个新的元素放到栈的最上层
int largestRectangleArea(vector<int>& heights) {
	if(heights.empty()){
		return 0;
	}
	if(heights.size() == 1){
		return heights[0];
	}
	stack<int> area;
	int maxArea = 0;
	heights.push_back(0);  //在矩形条的最后加上一个0，是为了让最后栈中的元素都出栈，如果所有的元素一直都是递增的，那么栈中的元素就一直保存不会出栈了
	for(int i = 0;i < heights.size();i++){
		if(area.empty() || heights[area.top()] < heights[i]){
			area.push(i);
		}
		else{
			while(!area.empty() && heights[i] <= heights[area.top()]){    //当欲入栈的元素大于栈顶的元素，需要将栈顶的元素出栈
				int h = heights[area.top()];
				area.pop();
				int w = area.empty() ? i:i-(area.top()+1);               //栈中两个相邻元素之间的所有矩形条都是大于他们的高度的，所以每次将栈中的元素弹出后，需要计算以这个元素为高度，向左的最大面积
				maxArea = max(maxArea,h*w);                              //接上一条语句的解释，如果将元素弹出后，栈的元素为空，那么就代表在这个元素之前的元素都小于该元素，所以它的宽度就是它的下标本身
			}
			area.push(i);
		}
	}
	return maxArea;
}

//左右扫描法
//最大面积的矩形高度一定跟某个条的高度是一样的，挨个枚举每个矩形条
//看其向左、右最多能延伸到多远,
int largestRectangleArea_leftright(vector<int>&heights){
	if(heights.empty()){
		return 0;
	}
	int len = heights.size();
	int maxArea = 0;
	int*left = new int[len];
	int*right = new int[len];

	//向左延伸,所谓的向左延伸，就是看一个矩形条的左边，挨个紧邻的有几个比它高，如果没有就是1，算上了自己

	left[0]= 1;
	for(int i = 1;i < len;i++){
		if(heights[i] < heights[i-1])
			left[i] = 1;
		else{
			int j = i -1;
			while(j >= 0 && heights[j] >= heights[i]){
				j = j - left[j];         //这边用了一个迭代，类似于动规，也就是，找比相邻的小的个数就可以了。
			}
			left[i] = i - j;
		}
	}

	//向右延伸，所谓的向右延伸，是指向右找比其大的邻近的矩形条有多少个，算上了自己
	right[len-1] = 1;
	for(int i = len - 2;i >= 0; i--){
		if(heights[i] > heights[i+1]){
			right[i] = 1;
		}else{
			int j = i + 1;
			while(j < len && heights[j] >= heights[i]){
				j = j + right[j];      //j代表的是比i高的最右边的矩形条的下标
			}
			right[i] = j - i;			//right中存储的是紧邻着i比i高的矩形条的个数
		}
	}
	maxArea = heights[0];
	for(int i = 0;i < len;i++){
		maxArea = max(heights[i]*(left[i]+right[i]-1),maxArea);
	}
	return maxArea;
}