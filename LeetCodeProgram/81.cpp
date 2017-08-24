#include<iostream>
#include<vector>
using namespace std;
//二分搜索
//一个旋转的有序数组，允许数组中有重复元素出现
//和33题没有重复元素出现差不多，差别在于如果有重复的元素出现，要考虑中间元素和右边元素比较时的差异
//有参考网络
bool search(vector<int>& nums, int target) {
	int l= 0;
	int mid;
	int r = nums.size() - 1;
	while(l<=r){
		mid = (l+r)>>1;
		if( nums[mid] == target ) return true;
		if(nums[mid] < nums[r]){
			if(target <= nums[r] && target > nums[mid]){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}else if(nums[mid] > nums[r]){
			if(target < nums[mid] && target >= nums[l])
				r = mid - 1;
			else
				l = mid + 1;
		}else{
			r--;      //这边是会遇到的错误,也是这题允许有重复的元素才会引起的这个错误
		}
	}
	return false;
}

//int main(){
//	int data[] = {1,1,3,1};
//	vector<int>num(data,data + 4);
//	bool result = search(num,3);
//	cout<<result<<endl;
//	return 0;
//}