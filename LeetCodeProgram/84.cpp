#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//ջ����������һ����������˵��������߽������Լ������ұ߽���Ŀǰջ����Ԫ��
//����������
//������ջ�����ʣ�ջ�Ǻ���ȳ������ԣ�pop��ȡ��ջ�����ϲ��Ԫ�أ�Ҳ����������ջ��Ԫ��
// top�ǲ鿴ջ���ϲ�Ԫ��
// push�ǽ�һ���µ�Ԫ�طŵ�ջ�����ϲ�
int largestRectangleArea(vector<int>& heights) {
	if(heights.empty()){
		return 0;
	}
	if(heights.size() == 1){
		return heights[0];
	}
	stack<int> area;
	int maxArea = 0;
	heights.push_back(0);  //�ھ�������������һ��0����Ϊ�������ջ�е�Ԫ�ض���ջ��������е�Ԫ��һֱ���ǵ����ģ���ôջ�е�Ԫ�ؾ�һֱ���治���ջ��
	for(int i = 0;i < heights.size();i++){
		if(area.empty() || heights[area.top()] < heights[i]){
			area.push(i);
		}
		else{
			while(!area.empty() && heights[i] <= heights[area.top()]){    //������ջ��Ԫ�ش���ջ����Ԫ�أ���Ҫ��ջ����Ԫ�س�ջ
				int h = heights[area.top()];
				area.pop();
				int w = area.empty() ? i:i-(area.top()+1);               //ջ����������Ԫ��֮������о��������Ǵ������ǵĸ߶ȵģ�����ÿ�ν�ջ�е�Ԫ�ص�������Ҫ���������Ԫ��Ϊ�߶ȣ������������
				maxArea = max(maxArea,h*w);                              //����һ�����Ľ��ͣ������Ԫ�ص�����ջ��Ԫ��Ϊ�գ���ô�ʹ��������Ԫ��֮ǰ��Ԫ�ض�С�ڸ�Ԫ�أ��������Ŀ�Ⱦ��������±걾��
			}
			area.push(i);
		}
	}
	return maxArea;
}

//����ɨ�跨
//�������ľ��θ߶�һ����ĳ�����ĸ߶���һ���ģ�����ö��ÿ��������
//������������������쵽��Զ,
int largestRectangleArea_leftright(vector<int>&heights){
	if(heights.empty()){
		return 0;
	}
	int len = heights.size();
	int maxArea = 0;
	int*left = new int[len];
	int*right = new int[len];

	//��������,��ν���������죬���ǿ�һ������������ߣ��������ڵ��м��������ߣ����û�о���1���������Լ�

	left[0]= 1;
	for(int i = 1;i < len;i++){
		if(heights[i] < heights[i-1])
			left[i] = 1;
		else{
			int j = i -1;
			while(j >= 0 && heights[j] >= heights[i]){
				j = j - left[j];         //�������һ�������������ڶ��棬Ҳ���ǣ��ұ����ڵ�С�ĸ����Ϳ����ˡ�
			}
			left[i] = i - j;
		}
	}

	//�������죬��ν���������죬��ָ�����ұ������ڽ��ľ������ж��ٸ����������Լ�
	right[len-1] = 1;
	for(int i = len - 2;i >= 0; i--){
		if(heights[i] > heights[i+1]){
			right[i] = 1;
		}else{
			int j = i + 1;
			while(j < len && heights[j] >= heights[i]){
				j = j + right[j];      //j������Ǳ�i�ߵ����ұߵľ��������±�
			}
			right[i] = j - i;			//right�д洢���ǽ�����i��i�ߵľ������ĸ���
		}
	}
	maxArea = heights[0];
	for(int i = 0;i < len;i++){
		maxArea = max(heights[i]*(left[i]+right[i]-1),maxArea);
	}
	return maxArea;
}