#include<vector>
#include<iostream>
using namespace std;

//给定一个乱序的数组，找出第一个失踪的正整数  要求程序运行时间为O(n)并且程序空间使用是常数空间
//按照题意，如果一个N长的数组，它的元素应该是由1,2,3,...N组成，那么可以对数组进行一个扫描，将数值在1~N间的元素放到i-1的位置
//例如数组的第i(从0开始算起)个位置，值应该是i+1，这样拍好序后，只要依次检查每个位置和对应的元素是否符合这样的规则就可以

int firstMissingPositive(vector<int>& nums) {
	for(int i = 0;i < nums.size();i++){
		while(nums[i] > 0 && nums[i] <=nums.size() && nums[i]!=nums[nums[i]-1]){
			int tmp = nums[i];
			nums[i] = nums[tmp-1];
			nums[tmp-1] = tmp;
		}
	}

	for(int i = 0;i < nums.size();i++){
		if(nums[i]!=i+1)
			return i + 1;
	}
	return nums.size() + 1;

}

//int main(){
//	int a[] = {2,1};
//	vector<int>nums(a,a+sizeof(a)/sizeof(a[0]));
//	int result = firstMissingPositive(nums);
//	cout<<result<<endl;
//	return 0;
//}