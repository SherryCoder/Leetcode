#include<iostream>
#include<vector>
using namespace std;

//一个数组存储一个整数，将其加一
//这边注意用到的一个点是迭代器
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


