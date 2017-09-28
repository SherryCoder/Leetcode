#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��������һ���ں��ظ�Ԫ�ص�����������Ӽ�����Ҫ���ǵ��ظ�Ԫ�ص�����
//�ȶ�����������򣬳�ʼ�������һ���ռ���ÿ�α���һ���ظ�Ԫ�أ�������ӵ�result��
//���һ��Ԫ�ء�����Ԫ�ء�����ֱ�������ظ�Ԫ����ӽ�����
//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//	vector<vector<int>> result = { {} };     //c++11֧�����ֳ�ʼ������
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

// ���ϵĽⷨ�����ݣ�������һ��ʼ���õķ��������ǻ����ǿ�û����ĳ�������
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
	//��һ������ʼ���Ƚ����������ѹ�������ٽ��������Ϊ��㣬����β�������Ӵ���������������̫ɧ����Ҫѧϰ��������
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) {   //�ܺõı������ظ��Ӽ������ҽ��ظ�Ԫ�صļ��뿼����
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
			}
	}
};