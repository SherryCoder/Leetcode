#include<iostream>
#include<vector>
using namespace std;

//�������һ���Ĳ�ͬ���ڣ�������Ҫ���ղ��������ܹ���������Զ�ľ��룬����һ����Ҫ�õ��ܹ��������ص������������
//ʹ��һ������ָ�룬һ���Ͻ�ָ�롣����ָ��i���Ͻ�ָ��reach��

//�Ѷȣ�����  ��Ϊ�����Ͻ�ĸ��ʲô��û�У�����õ���̰�ĵķ�������45��һ���������ⶼ�����Լ�û���뵽��
bool canJump(vector<int>& nums) {
	int reach = nums[0];                               //reach���Ƶ��ǵ�ǰ���Ե�����Ͻ�
	for(int i = 1;i <= reach&& i < nums.size();i++){   //i������ǵ�ǰλ�ú���nums[i]�ǵ�ǰ���������Ĳ���������i+nums[i]���ǵ�ǰ���Ե����λ�ú��롣
		if(i+nums[i] > reach) reach = i+nums[i];
	}
	return reach >= (nums.size()-1) ? true:false;
}