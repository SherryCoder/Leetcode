#include<iostream>
#include<vector>
using namespace std;

//这道题和46道的全排列差不多，但是它所给的数组nums中是含有重复元素的，所以如果像 46题那样解题就会有重复的排列。
//这题给的方法是交换，这个交换也是可以用在46题上的，就是先将第一个元素和其他所有元素进行交换，都交换完了以后，固定第一个元素，将第二个元素
//和其后面的所有元素进行交换。对于这个题目，在交换的时候要判断一点，就是第k个元素和它后面第i个元素进行交换的时候，第i个元素是否和k~i-1间的
//元素重复，如果重复，就不需要交换了。

bool check_same(vector<int>&nums,int start,int end,int target){
	for(int i = start;i <= end;i++){
		if(nums[i]==nums[target]){
			return true;
		}
	}
	return false;
}

void swap(vector<int>&nums,int a,int b){
	int tmp = nums[a];
	nums[a] = nums[b];
	nums[b] = tmp;
	return;
}

void DFS(vector<int>&nums,int k,int n,vector<vector<int>>&result){
	if(k == n){
		result.push_back(nums);
		return;
	}else{
		for(int i = k;i <= n;i++){
			if(check_same(nums,k,i-1,i)) continue;
			swap(nums,k,i);
			DFS(nums,k+1,n,result);
			swap(nums,k,i);
		}
	}
	return;
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>>result;
	DFS(nums,0,nums.size()-1,result);
	return result;
}