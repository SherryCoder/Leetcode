#include<iostream>
#include<vector>
using namespace std;
//˫ָ��
//�������������Ƴ�Ԫ�أ�ʹ��һ��Ԫ�����������Σ�26��Ľ��װ汾

int removeDuplicates(vector<int>& nums) {
	if(nums.empty()){
		return 0;
	}
	if(nums.size() < 3){
		return nums.size();
	}
	int i = 0;//�����������е�Ԫ��
	int j = 1;
	int cnt = 0;
	for(int k = 1;k < nums.size();k++){
		if(nums[k] == nums[i] && cnt < 1){
			nums[++i] = nums[k];
			cnt++;
		}
		else if(nums[k] == nums[i] && cnt >=1){
			continue;
		}
		else if(nums[k] > nums[i]){
			nums[++i] = nums[k];
			cnt = 0;
		}
	}
	return i+1 ;
}

//int main(){
//	int test[] = {1,2,2,2,2,2,4};
//	vector<int>nums(test,test + 7);
//	int result = removeDuplicates(nums);
//	cout<<result<<endl;
//	for(int i = 0;i < result;i++){
//		cout<<nums[i]<<" ";
//	}
//	return 0;
//}