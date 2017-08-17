/*�������˼��������ϣ��ҵ���ǰ���е���һ�����У�����Ѿ��������һ��
���У��ʹ�ͷ��ʼѭ����
���� 6 5 4 8 7 5 1
���ȴ���������1��ʼ��飬����8 7 5 1�ǵݼ���
�����Ҫ�ҵ���һ�����У��ҵ�������λ���ǹؼ�
��Ϊ���������ʹ���������ø���
�����ҵ���4 
��Ҫ�ҳ���4��������Щ��������С��ֵ���������ߵ���
�������оͳ��� 6 5 5 8 7 4 1
��� 8 7 4 1 ��һ����������
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int len = nums.size() - 1;
	int index = len;

	while(nums[index] <= nums[index-1]){
		index--;
	}

	if(index == 0){
		sort(nums.begin(),nums.end());
		return;
	}
	int second = INT_MAX;
	int secondIndex = INT_MAX;
	for(int i = len ; i  >= index;i--){
		if(nums[i] > nums[index-1]){
			//if(nums[i]<second){
			//	secondIndex = i;
			//	second = nums[i];
			//}
			secondIndex = i;
			second = nums[i];
			break;
		}
	}
	int temp = nums[index - 1];
	nums[index - 1] = nums[secondIndex];
	nums[secondIndex] = temp;
	sort(nums.begin()+index,nums.end());
	return;
}

//int main(){
//	int num[7]={6,5,4,8,7,5 ,1};
//	vector<int> nums(num,num+7);
//	nextPermutation( nums);
//	for(int i = 0;i < nums.size();i++){
//		cout<<nums[i]<<" ";
//	}
//	cout<<endl;
//	return 0;
//}