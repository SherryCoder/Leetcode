#include<iostream>
#include<vector>
using namespace std;

//������46����ȫ���в�࣬����������������nums���Ǻ����ظ�Ԫ�صģ���������� 46����������ͻ����ظ������С�
//������ķ����ǽ������������Ҳ�ǿ�������46���ϵģ������Ƚ���һ��Ԫ�غ���������Ԫ�ؽ��н����������������Ժ󣬹̶���һ��Ԫ�أ����ڶ���Ԫ��
//������������Ԫ�ؽ��н��������������Ŀ���ڽ�����ʱ��Ҫ�ж�һ�㣬���ǵ�k��Ԫ�غ��������i��Ԫ�ؽ��н�����ʱ�򣬵�i��Ԫ���Ƿ��k~i-1���
//Ԫ���ظ�������ظ����Ͳ���Ҫ�����ˡ�

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