#include<iostream>
#include<vector>
using namespace std;

//这题和上一个的不同在于：这题是要求按照步数跳，能够跳到的最远的距离，而上一题是要得到能够跳到的重点的最少跳数。
//使用一个步进指针，一个上界指针。步进指针i，上界指针reach。

//难度：较难  因为对于上界的概念啊什么的没有，这边用的是贪心的方法，跟45题一样，这两题都是我自己没有想到的
bool canJump(vector<int>& nums) {
	int reach = nums[0];                               //reach控制的是当前可以到达的上界
	for(int i = 1;i <= reach&& i < nums.size();i++){   //i代表的是当前位置号码nums[i]是当前可以跳出的步数，所以i+nums[i]就是当前可以到达的位置号码。
		if(i+nums[i] > reach) reach = i+nums[i];
	}
	return reach >= (nums.size()-1) ? true:false;
}