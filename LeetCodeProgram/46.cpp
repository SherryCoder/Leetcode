#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
//求全排列  用了递归求，用到了深度优先遍历DFS

void DFS(vector<int>&nums,vector<int>&visited,vector<vector<int>>&result){
	if(nums.size() == visited.size()){
		result.push_back(visited);
		return;
	}
	vector<int>::iterator isVisited;
	for(int i =0;i < nums.size();i++){
		isVisited = find(visited.begin(),visited.end(),nums[i]);
		if(isVisited == visited.end()){
			visited.push_back(nums[i]);
			DFS(nums,visited,result);
			visited.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> result;
	   if(nums.empty()){
			return result;
	   }
	   vector<int> visited;
	   DFS(nums,visited,result);
	   return result;
 }
//
//int main(){
//	int A[3] = {1,2,3};
//	vector<int>nums(A,A+3);
//	vector<vector<int>> result;
//	result = permute(nums);
//	for(int i = 0;i < result.size();i++){
//		for(int j = 0;j < 3;j++){
//			cout<<result[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//}