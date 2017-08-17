#include<vector>
#include<iostream>
using namespace std;

//����һ����������飬�ҳ���һ��ʧ�ٵ�������  Ҫ���������ʱ��ΪO(n)���ҳ���ռ�ʹ���ǳ����ռ�
//�������⣬���һ��N�������飬����Ԫ��Ӧ������1,2,3,...N��ɣ���ô���Զ��������һ��ɨ�裬����ֵ��1~N���Ԫ�طŵ�i-1��λ��
//��������ĵ�i(��0��ʼ����)��λ�ã�ֵӦ����i+1�������ĺ����ֻҪ���μ��ÿ��λ�úͶ�Ӧ��Ԫ���Ƿ���������Ĺ���Ϳ���

int firstMissingPositive(vector<int>& nums) {
	for(int i = 0;i < nums.size();i++){
		while(nums[i] > 0 && nums[i] <=nums.size() && nums[i]!=nums[nums[i]-1]){
			int tmp = nums[i];
			nums[i] = nums[tmp-1];
			nums[tmp-1] = tmp;
		}
	}

	for(int i = 0;i < nums.size();i++){
		if(nums[i]!=i+1)
			return i + 1;
	}
	return nums.size() + 1;

}

//int main(){
//	int a[] = {2,1};
//	vector<int>nums(a,a+sizeof(a)/sizeof(a[0]));
//	int result = firstMissingPositive(nums);
//	cout<<result<<endl;
//	return 0;
//}