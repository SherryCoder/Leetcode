#include<iostream>
#include<vector>
using namespace std;

//本题的意思是给了一组数据，代表海拔，让求这组数据能装多少水，水是装在有空隙的地方的

//solution:先从左到右的扫描一遍数组，找出每个柱子左边的最大高度，然后再从右往左扫描一遍数组，找出每个柱子右边的最大高度
//         然后再计算每个柱子上方能装多少水min(maxleft - maxright) - height[i]

int trap(vector<int>& height) {
	if(height.empty()) return 0;
	vector<int>maxleft(height.size());
	vector<int>maxright(height.size());
	int maxheight = 0;
	for(int i = 0;i < height.size();i++){
		maxleft[i] = maxheight;
		if(height[i] > maxheight){
			maxheight = height[i];
		}
	}
	maxheight = 0;
	for(int i = height.size()-1;i >= 0;i--){
		maxright[i] = maxheight;
		if(height[i] > maxheight){
			maxheight = height[i];
		}
	}
	int sumwater = 0;
	for(int i = 0;i < height.size();i++){
		int water = min(maxleft[i],maxright[i]) - height[i];
		if(water > 0){
			sumwater += water;
		}
	}

	return sumwater;
}