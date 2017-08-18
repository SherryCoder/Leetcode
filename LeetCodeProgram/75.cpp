#include<iostream>
#include<vector>
using namespace std;
//（快速排序）
//这题是给定一个数组，里面有三个数，0,1,2，按照0,1,2的顺序将所有相同的数字相邻并排序。
//可以用两遍扫描的方法，很轻松就能AC
//但是如果用常数空间的话，扫描一次的话，就要借助到两个标记redEnd和blueBegin将数组分成三部分
//扫描两次的方法
void sortColors(vector<int>& nums) {
	int redCnt = 0, whiteCnt = 0, blueCnt = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == 0){
			redCnt++;
		}
		if(nums[i] == 1){
			whiteCnt++;
		}
		if(nums[i] == 2){
			blueCnt++;
		}
	}
	for(int i = 0;i < redCnt;i++){
		nums[i] = 0;
	}
	for(int i = redCnt;i < redCnt+whiteCnt;i++){
		nums[i] = 1;
	}
	for(int i = redCnt+whiteCnt; i < redCnt+whiteCnt + blueCnt;i++){
		nums[i] = 2;
	}
	return;
}

//void swap(int ,int i)

//只需扫描一次，常数空间的方法
void setColors(vector<int>& nums){
	int len = nums.size();
	int redEnd = -1;
	int blueBegin = len;
	int i = 0;
	while(i < blueBegin){
		if(nums[i] == 0 && i!=redEnd){
			redEnd++;
			swap(redEnd,i);
		}
		else if(nums[i] == 2 && i!=blueBegin){
			blueBegin--;
			swap(blueBegin,i);
		}else{
			i++;
		}
	}
}