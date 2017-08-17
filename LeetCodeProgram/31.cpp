/*本题的意思是排列组合，找到当前排列的下一个排列，如果已经到达最后一个
排列，就从头开始循环。
例如 6 5 4 8 7 5 1
首先从最后的数字1开始检查，发现8 7 5 1是递减的
如果想要找到下一个排列，找到递增的位置是关键
因为在这里才能使得其增长得更大。
所以找到了4 
需要找出比4大但是在这些大数中最小的值，并将两者调换
整个排列就成了 6 5 5 8 7 4 1
最后将 8 7 4 1 做一个递增排序
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int len = nums.size() - 1;
	int index = len;

	while(nums[index] <= nums[index-1]){
		index--;
	}

	if(index == 0){
		sort(nums.begin(),nums.end());
		return;
	}
	int second = INT_MAX;
	int secondIndex = INT_MAX;
	for(int i = len ; i  >= index;i--){
		if(nums[i] > nums[index-1]){
			//if(nums[i]<second){
			//	secondIndex = i;
			//	second = nums[i];
			//}
			secondIndex = i;
			second = nums[i];
			break;
		}
	}
	int temp = nums[index - 1];
	nums[index - 1] = nums[secondIndex];
	nums[secondIndex] = temp;
	sort(nums.begin()+index,nums.end());
	return;
}

//int main(){
//	int num[7]={6,5,4,8,7,5 ,1};
//	vector<int> nums(num,num+7);
//	nextPermutation( nums);
//	for(int i = 0;i < nums.size();i++){
//		cout<<nums[i]<<" ";
//	}
//	cout<<endl;
//	return 0;
//}