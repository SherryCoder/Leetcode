#include<iostream>
#include<vector>
using namespace std;
//����������
//�����Ǹ���һ�����飬��������������0,1,2������0,1,2��˳��������ͬ���������ڲ�����
//����������ɨ��ķ����������ɾ���AC
//��������ó����ռ�Ļ���ɨ��һ�εĻ�����Ҫ�������������redEnd��blueBegin������ֳ�������
//ɨ�����εķ���
void sortColors(vector<int>& nums) {
	int redCnt = 0, whiteCnt = 0, blueCnt = 0;
	for(int i = 0;i < nums.size();i++){
		if(nums[i] == 0){
			redCnt++;
		}
		if(nums[i] == 1){
			whiteCnt++;
		}
		if(nums[i] == 2){
			blueCnt++;
		}
	}
	for(int i = 0;i < redCnt;i++){
		nums[i] = 0;
	}
	for(int i = redCnt;i < redCnt+whiteCnt;i++){
		nums[i] = 1;
	}
	for(int i = redCnt+whiteCnt; i < redCnt+whiteCnt + blueCnt;i++){
		nums[i] = 2;
	}
	return;
}

//void swap(int ,int i)

//ֻ��ɨ��һ�Σ������ռ�ķ���
void setColors(vector<int>& nums){
	int len = nums.size();
	int redEnd = -1;
	int blueBegin = len;
	int i = 0;
	while(i < blueBegin){
		if(nums[i] == 0 && i!=redEnd){
			redEnd++;
			swap(redEnd,i);
		}
		else if(nums[i] == 2 && i!=blueBegin){
			blueBegin--;
			swap(blueBegin,i);
		}else{
			i++;
		}
	}
}