#include<iostream>
#include<vector>
using namespace std;

//һ������洢һ�������������һ
//���ע���õ���һ�����ǵ�����
vector<int> plusOne(vector<int>& digits) {
	vector<int>::iterator it;
	vector<int> res;
	int addNum = 1;
	for(int i = digits.size() - 1;i >=0; i--){
		int tmp = (addNum + digits[i]) % 10;
		it = res.begin();
		addNum = (addNum + digits[i])/10;
		res.insert(it,tmp);
	}
	if(addNum!=0){
		it = res.begin();
		res.insert(it,addNum);
	}
	return res;
}


