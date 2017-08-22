#include<iostream>
#include<vector>
using namespace std;
//(回溯、深度优先dfs)
//这题在做过77题后，就显得十分简单了，第77题给定了要求组合数中的组合的长度，这题是求所有的可能组合数
//因此，只要改变k的取值就可以了

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