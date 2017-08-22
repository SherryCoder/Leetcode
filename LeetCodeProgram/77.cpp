#include<iostream>
#include<vector>
using namespace std;
//(回溯、深度优先)
//参考网上，自己这题居然没有做出来。。
//重做

void dfs(vector<vector<int>>&result,int n ,int k,int start,vector<int>oneSolution){
	if(oneSolution.size() == k){
		result.push_back(oneSolution);
		return;
	}
	for(int i = start;i <= n;i++){
		oneSolution.push_back(i);
		dfs(result,n,k,i+1,oneSolution);
		oneSolution.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;
	if(n < k || k == 0){
		return result;
	}
	vector<int> oneSolution;
	dfs(result,n,k,1,oneSolution);
	return result;
}

//动态规划的方法
vector<vector<int>> combine_dp(int n , int k){
	vector<vector<int>> result;
	if(n <= 0 || n < k)
		return result;
	if(k == 1){
		for(int  i = 0;i < n;i++){
			vector<int> tmp(1,i+1);
			result.push_back(tmp);
		}
		return result;
	}
	if(n == k){
		vector<int> tmp;
		for(int i = 0;i < n;i++){
			tmp.push_back(i+1);
		}
		result.push_back(tmp);
		return result;
	}

	vector<vector<int>> tmp = combine_dp(n-1,k-1);
	for(int i = 0;i < tmp.size();i++){
		tmp[i].push_back(n);
		result.push_back(tmp[i]);
	}
	tmp = combine_dp(n-1,k);
	for(int i = 0;i < tmp.size();i++){
		result.push_back(tmp[i]);
	}
	return result;
}

//int main(){
//	vector<vector<int>> result;
//	result = combine(4,2);
//	for(int i = 0;i < result.size();i++){
//		for(int j = 0; j < result[i].size();j++){
//			cout<<result[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
//}