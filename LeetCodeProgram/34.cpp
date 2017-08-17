/**
search for range:在一个递增的数组中找寻目标数字的范围
例如2 3 3 4 5 5 6 如果target是3，那么返回的就是[1,2]
要求时间复杂度是O(logn)，所以要用到二分查找

写程序的时候一开始无从下手，可以设置两个下标，一个是控制头，一个控制尾，每次求出中间元素和target相比，从而知道取哪半边的数组
当相等时，可以缩小范围，通过头下标++或者尾下标——。
**/

#include<iostream>
#include<vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {

	int len = nums.size();
	vector<int> result;
	result.push_back(-1);
	result.push_back(-1);
	if(len <= 0){
		return result;
	}else if(len == 1){
		if(nums[0]!=target){
			return result;
		}else{
			result.clear();
			result.push_back(0);
			result.push_back(0);
			return result;
		}
	}
	int leftIndex = 0;
	int rightIndex = len -1;
	while(nums[leftIndex] < nums[rightIndex]){
		int mid = leftIndex + (rightIndex-leftIndex)/2;
		if(nums[mid] > target){
			rightIndex = mid - 1;
		}else if(nums[mid] < target){
			leftIndex = mid + 1;
		}else{
			if(nums[leftIndex] < target) leftIndex++;
			if(nums[rightIndex] > target) rightIndex--;
		}
	}
	if(nums[leftIndex]==target){
		result[0] = leftIndex;
		result[1] = rightIndex;
	}
	return result;
}

//int main(){
//	int num = {1};
//	vector<int>nums(1,1);
//	for(int i = 0;i < nums.size();i++){
//		cout<<nums[i]<<" ";
//	}
//	cout<<endl;
//	int target = 1;
//	vector<int>result(2);
//	result = searchRange( nums,target);
//	cout<<result[0]<<"   "<<result[1]<<endl;
//	return 0;
//}