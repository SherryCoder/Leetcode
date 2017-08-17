#include <iostream>
#include <vector>
//这题是给你一个数n，然后它有n!中排列，给你一个数字k，要求你返回第k个排序
//这个题目不可以用穷举，会超时而且空间的利用也大啊。可以通过求首字母的位置来求
//这题对我来说，非常难了


using namespace std;

string getPermutation(int n, int k) {
	vector<int> permutation(n+1,1);   //阶乘表，用来记录n的阶乘
	for(int i = 1;i <=n ;i++){
		permutation[i] = permutation[i-1]*i;
	}
	vector<char> digits(9,'1');
	for(int i = 1;i < 9;i++){
		digits[i]+=i;
	}

	int num = n-1;
	string result;
	while(num){
		int t = (k-1)/permutation[num--];   //求在序列中的首元素序号
		k = k - t*permutation[num + 1];    //求下一个位置的序号
		result.push_back(digits[t]);
		digits.erase(digits.begin() + t);
	}
	result.push_back(digits[0]);
	return result;
}

//int main(){
//	string result;
//	result = getPermutation(4,8);
//	for(int i = 0;i < result.size();i++){
//		cout<< result[i]<<" ";
//	}
//	//cout<<result<<endl;
//	return 0;
//}