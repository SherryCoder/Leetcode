#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//和39题有些类似，从给定的候选数组中，挑出和为target的数字，但是跳出来的数字只可以在数组中出现一次，这是与39题不同的地方。
//也是用DFS，和39基本类似，不同的在于在递归的时候不需要将当前元素传入，并且要判断重复。

void DFS(vector<int>&candidates , int target,vector<vector<int>>&res , vector<int>&path , int start){
	if(target < 0) return;
	else if(target == 0) res.push_back(path);
	else{
		for(int i = start;i < candidates.size();i++){
			if(candidates[i] == candidates[i-1] && i > start) continue;    //判断重复
			path.push_back(candidates[i]);
			DFS(candidates,target - candidates[i],res,path,i+1);
			path.pop_back();
		}
	}
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

	vector<vector<int>> result;
	vector<int> path;
	if(candidates.size() <= 0) return result;
	sort(candidates.begin(),candidates.end());
	DFS(candidates,target,result,path,0);
	return result;
}

//
//int main(){
//	
//}