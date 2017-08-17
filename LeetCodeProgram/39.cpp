#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//先排序，递归的将剩下的元素一一加到结果集合中，并用目标减去加入的元素，将剩下的元素（包括当前加入的元素）放入到下一层递归中解决子问题，start记录
//选到了第几个值  深度优先的方法，要进行回溯操作。

void DFS(vector<int>&candidates,int target,int start,vector<int>&path,vector<vector<int>>&result){
	int len = candidates.size();
	if(target == 0){
		result.push_back(path);
		return;
	}
	for(int i = start;i < len;i++){
		if(candidates[i] > target){
			return;
		}
		path.push_back(candidates[i]);
		DFS(candidates,target-candidates[i],i,path,result);
		path.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	if(candidates.size()<=0){
		return result;
	}
	vector<int> path;
	sort(candidates.begin(),candidates.end());
	DFS(candidates,target,0,path,result);
	return result;
}

//int main(){
//    int target = 7;  
//    vector<int> vec;  
//    vec.push_back(2);  
//    vec.push_back(3);  
//    vec.push_back(6);  
//    vec.push_back(7);  
//  
//    vector<vector<int> > result = combinationSum(vec,target);  
//    // 输出  
//    for(int i = 0;i < result.size();++i){  
//        for(int j = 0;j < result[i].size();++j){  
//            cout<<result[i][j]<<" ";  
//        }  
//        cout<<endl;  
//    }  
//    return 0; 
//}