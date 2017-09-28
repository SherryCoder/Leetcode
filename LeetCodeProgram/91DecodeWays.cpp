#include<iostream>
#include<vector>
#include<string>
using namespace std;

//�ݹ鳬ʱ
int numDecodings_wrong(string s) {
	int len = s.size();
	if(len == 0 || s[0]=='0') return 0;
	if(len ==1 ){
		return 1;
	}
	if(len == 2){
		if((s[0] == '1'&& s[1] >'0' ) || (s[0] == '2' && s[1] <'7' && s[1] > '0')){
			return 2;
		}else if((s[0]>'0'&& s[1] > '0') || (s[0] > '0' && s[0] < '3' && s[1] =='0')){
			return 1;
		}else{
			return 0;
		}
	}
	int result = 0;
//	for(int i = 0;i < s.size()-2;i++){
	int i = 0;
	if(s[i] == '0') return 0;
	result += numDecodings_wrong(s.substr(i+1));
	if((s[i] == '1'&& s[i+1] >='0' ) || (s[i] == '2' && s[i+1] <'7' && s[i+1] >= '0')){
		//result++;
		result += numDecodings_wrong(s.substr(i+2));
	}
	//}
	return result;
}

// ��̬�滮���ο�����
//��һ������dp��¼��dp���ַ����ĳ���һ��
// �����ǰ��s[i]��Ϊ0������dp[i] = dp[i-1],��s[i]��������
// �����ǰ��s[i]��s[i-1]�ܹ�����1-26�е����֣���ôdp[i] += dp[i-2]
int valid(char a,char b){
	return a=='1'|| a=='2'&& b<'7';
}
int checkzero(char ch){
	return ch!='0';
}
int numDecodings(string s) {
	if(s.size() == 0 || s[0] == '0') return 0;
	if(s.size() == 1) return 1;
	vector<int>dp(s.size(),0);
	dp[0] = 1;
	dp[1] = checkzero(s[1]) + valid(s[0],s[1]);
	for(int i = 2;i < s.size();i++){
		if(checkzero(s[i])){
			dp[i] = dp[i-1];
		}
		if(valid(s[i-1],s[i])){
			dp[i] += dp[i-2];
		}
	}
	return dp[s.size()-1];
}

//int main(){
//	string s = "17";
//	int result = numDecodings(s);
//	cout<<result<<endl;
//	return 0;
//}