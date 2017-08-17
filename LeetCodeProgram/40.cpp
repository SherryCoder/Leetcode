#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��39����Щ���ƣ��Ӹ����ĺ�ѡ�����У�������Ϊtarget�����֣�����������������ֻ�����������г���һ�Σ�������39�ⲻͬ�ĵط���
//Ҳ����DFS����39�������ƣ���ͬ�������ڵݹ��ʱ����Ҫ����ǰԪ�ش��룬����Ҫ�ж��ظ���

void DFS(vector<int>&candidates , int target,vector<vector<int>>&res , vector<int>&path , int start){
	if(target < 0) return;
	else if(target == 0) res.push_back(path);
	else{
		for(int i = start;i < candidates.size();i++){
			if(candidates[i] == candidates[i-1] && i > start) continue;    //�ж��ظ�
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