#include<iostream>
#include<vector>
using namespace std;

//�������˼�Ǹ���һ�����ݣ������Σ���������������װ����ˮ��ˮ��װ���п�϶�ĵط���

//solution:�ȴ����ҵ�ɨ��һ�����飬�ҳ�ÿ��������ߵ����߶ȣ�Ȼ���ٴ�������ɨ��һ�����飬�ҳ�ÿ�������ұߵ����߶�
//         Ȼ���ټ���ÿ�������Ϸ���װ����ˮmin(maxleft - maxright) - height[i]

int trap(vector<int>& height) {
	if(height.empty()) return 0;
	vector<int>maxleft(height.size());
	vector<int>maxright(height.size());
	int maxheight = 0;
	for(int i = 0;i < height.size();i++){
		maxleft[i] = maxheight;
		if(height[i] > maxheight){
			maxheight = height[i];
		}
	}
	maxheight = 0;
	for(int i = height.size()-1;i >= 0;i--){
		maxright[i] = maxheight;
		if(height[i] > maxheight){
			maxheight = height[i];
		}
	}
	int sumwater = 0;
	for(int i = 0;i < height.size();i++){
		int water = min(maxleft[i],maxright[i]) - height[i];
		if(water > 0){
			sumwater += water;
		}
	}

	return sumwater;
}