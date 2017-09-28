#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//这题是求一个内含重复元素的数组的所有子集，需要考虑到重复元素的问题
//先对数组进行排序，初始化结果是一个空集，每次遍历一段重复元素，将其添加到result中
//添加一个元素、两个元素。。。直至整个重复元素添加结束。
//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//	vector<vector<int>> result = { {} };     //c++11支持这种初始化方法
//	sort(nums.begin(), nums.end());
//	
//	for (int i = 0; i < nums.size(); ) {
//		int cnt = 0;
//		while (i + cnt < nums.size() && nums[i + cnt] == nums[i]) cnt++;
//		int pre_size = result.size();
//		for (int j = 0; j < pre_size; j++) {
//			vector<int> instance = result[j];
//			for (int k = 0; k < cnt; k++) {
//				instance.push_back(nums[i]);
//				result.push_back(instance);
//			}
//		}
//		i += cnt;
//	}
//	return result;
//}

// 网上的解法，回溯，这是我一开始想用的方法，但是回溯那块没有想的出来。。
// 
class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
    }
private:
	//从一个数开始，先将这个数本身压入结果，再将以这个数为起点，到结尾的所以子串计算出（这个代码太骚了我要学习！！！）
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) {   //很好的避免了重复子集，并且将重复元素的加入考虑了
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};