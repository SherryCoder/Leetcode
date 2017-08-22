#include<iostream>
#include<vector>
using namespace std;
//(���ݡ��������dfs)
//����������77��󣬾��Ե�ʮ�ּ��ˣ���77�������Ҫ��������е���ϵĳ��ȣ������������еĿ��������
//��ˣ�ֻҪ�ı�k��ȡֵ�Ϳ�����

void dfs(vector<vector<int>>&result,vector<int>&nums,int k,vector<int>&oneSolution,int start){
	if(oneSolution.size() == k){
		result.push_back(oneSolution);
		return;
	}
	for(int i = start;i < nums.size();i++){
		oneSolution.push_back(nums[i]);
		dfs(result,nums,k,oneSolution,i+1);
		oneSolution.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int>oneSolution;
	result.push_back(oneSolution);
	for(int k = 1;k <= nums.size();k++){
		dfs(result,nums,k,oneSolution,0);
	}
	return result;
}

//int main(){
//	int n[] = {1,2,3};
//	vector<int> nums(n,n+3);
//	vector<vector<int>> result;
//	result = subsets(nums);
//	for(int i = 0;i < result.size();i++){
//		for(int j = 0;j < result[i].size();j++){
//			cout<<result[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//}