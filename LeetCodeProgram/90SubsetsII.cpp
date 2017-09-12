#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	int len = nums.size();
	if(len <= 0){
		vector<int>tmp;
		vector<vector<int>>a;
		a.push_back(tmp);
		return a;
	}
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;
	res = subsetsWithDup(nums);
	for(int i = 0;i < len;i++){
		
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
	vector<vector<int>> result = {{}};

}
int main(){
	
}