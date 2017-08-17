/**
search for range:��һ����������������ѰĿ�����ֵķ�Χ
����2 3 3 4 5 5 6 ���target��3����ô���صľ���[1,2]
Ҫ��ʱ�临�Ӷ���O(logn)������Ҫ�õ����ֲ���

д�����ʱ��һ��ʼ�޴����֣��������������±꣬һ���ǿ���ͷ��һ������β��ÿ������м�Ԫ�غ�target��ȣ��Ӷ�֪��ȡ�İ�ߵ�����
�����ʱ��������С��Χ��ͨ��ͷ�±�++����β�±ꡪ����
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