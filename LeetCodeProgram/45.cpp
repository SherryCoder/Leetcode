#include<iostream>
#include<vector>
using namespace std;
//������Ǹ���һ���Ǹ����������飬�㵱ǰ���ڵ�����index�����������ⲽ�ܹ������������
//�����ټ����������������β��
// ������뷨����Ȼ������̰�ģ������ڵ�ǰindex�¿��������num(index)�ķ�Χ�ڣ�ѡ������num[i+index]+i���ǵ�ǰ��������һ���Ĳ�������
//���������ģ���ǰ����i��1<=i<=num[index]

int jump(vector<int>& nums) {
	int minStep = 0;
	//int index = 0;
	int len = nums.size();
	int tmp;
	int steps = 0;
	int next;
	for(int index = 0;index < len -1 ;){
		tmp = 0;
		next = 0;
		if(index + nums[index] >= len - 1){
			return steps + 1;
		}
		for(int i = 1;i <= nums[index];i++){
			if(nums[index + i] + i > tmp){
				next = i;
				tmp = nums[index + i] + i;
			}
		}
		steps++;
		index = index + next;
	}
	return steps;
}