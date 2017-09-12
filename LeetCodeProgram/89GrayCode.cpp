#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//�������ƴ�תΪ������,����Ľⷨ��û��
int binaryToint(string binary){
	int len = binary.size();
	int res = 0;
	for(int i = len-1 ; i >= 0 ; i--){
		int val = binary[i]-'0';
		int j = len-1-i;
		while(j){
			val = val*2;
			j--;
		}
		res += val;
	}
	return res;
}

//�ݹ�
//��ʼ������n = 0ʱ����0��Ȼ�����2 00-01-11-10
//����3 000 - 001 - 011-010- 110-111-101-100 ������λ���ǶԳƵ�
vector<int> grayCode(int n) {
	if(n == 0){
		vector<int>a;
		a.push_back(0);
		return a;
	}
	vector<int>pre_res = grayCode(n-1);
	vector<int> result(pre_res);
	int high = 1;
	int j = n-1;
	while(j){
		high = high*2;
		j--;
	}
	for(int i = pre_res.size()-1;i>=0;i--){
		int val = pre_res[i]+ high;
		result.push_back(val);
	}
	return result;
}


//int main(){
//	vector<int>result = grayCode(3);
//	for(int i = 0;i < result.size();i++){
//		cout<<result[i]<<" ";
//	}
//	return 0;
//}