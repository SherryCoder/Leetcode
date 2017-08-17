#include <iostream>
#include <vector>
//�����Ǹ���һ����n��Ȼ������n!�����У�����һ������k��Ҫ���㷵�ص�k������
//�����Ŀ����������٣��ᳬʱ���ҿռ������Ҳ�󰡡�����ͨ��������ĸ��λ������
//���������˵���ǳ�����


using namespace std;

string getPermutation(int n, int k) {
	vector<int> permutation(n+1,1);   //�׳˱�������¼n�Ľ׳�
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
		int t = (k-1)/permutation[num--];   //���������е���Ԫ�����
		k = k - t*permutation[num + 1];    //����һ��λ�õ����
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