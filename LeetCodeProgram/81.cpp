#include<iostream>
#include<vector>
using namespace std;
//��������
//һ����ת���������飬�������������ظ�Ԫ�س���
//��33��û���ظ�Ԫ�س��ֲ�࣬�������������ظ���Ԫ�س��֣�Ҫ�����м�Ԫ�غ��ұ�Ԫ�رȽ�ʱ�Ĳ���
//�вο�����
bool search(vector<int>& nums, int target) {
	int l= 0;
	int mid;
	int r = nums.size() - 1;
	while(l<=r){
		mid = (l+r)>>1;
		if( nums[mid] == target ) return true;
		if(nums[mid] < nums[r]){
			if(target <= nums[r] && target > nums[mid]){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}else if(nums[mid] > nums[r]){
			if(target < nums[mid] && target >= nums[l])
				r = mid - 1;
			else
				l = mid + 1;
		}else{
			r--;      //����ǻ������Ĵ���,Ҳ�������������ظ���Ԫ�زŻ�������������
		}
	}
	return false;
}

//int main(){
//	int data[] = {1,1,3,1};
//	vector<int>num(data,data + 4);
//	bool result = search(num,3);
//	cout<<result<<endl;
//	return 0;
//}