#include<iostream>
#include<vector>
using namespace std;
//这题就是给你一个非负的整数数组，你当前所在的数组index决定了你在这步能够跳的最大步数，
//问最少几步可以跳到数组的尾部
// 这题的想法很自然就是用贪心，就是在当前index下看，在这个num(index)的范围内，选出最大的num[i+index]+i就是当前步加上下一步的步数最大的
//步数是最大的，当前就跳i步1<=i<=num[index]

int jump(vector<int>& nums) {
	int minStep = 0;
	//int index = 0;
	int len = nums.size();
	int tmp;
	int steps = 0;
	int next;
	for(int index = 0;index < len -1 ;){
		tmp = 0;
		next = 0;
		if(index + nums[index] >= len - 1){
			return steps + 1;
		}
		for(int i = 1;i <= nums[index];i++){
			if(nums[index + i] + i > tmp){
				next = i;
				tmp = nums[index + i] + i;
			}
		}
		steps++;
		index = index + next;
	}
	return steps;
}