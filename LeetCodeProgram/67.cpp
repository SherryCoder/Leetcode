#include<iostream>
using namespace std;
//二进制加法问题
string addBinary(string a,string b){
	string res;
	int len_a = a.length();
	int len_b = b.length();
	if(!len_a&& !len_b)
		return a;
	if(!len_a){
		return b;
	}
	if(!len_b){
		return a;
	}
	int len = len_a;
	if(len_a > len_b){
		len = len_b;
	}
	int carry = 0;
	int i,j;
	for(i = len_a-1,j = len_b-1;i >= len_a - len && j >= len_b - len;i--,j--){
		int sum = (a[i]-'0' + b[j]-'0' + carry)%2;
		carry = (a[i]-'0' + b[j]-'0' + carry)/2;
		res.push_back(sum+'0');
	}
	if(len_a > len_b){
		while(i>=0){
			int sum = (a[i]-'0' + carry)%2;
			carry = (a[i]-'0'+carry )/2;
			res.push_back(sum+'0');
			i--;
		}
		if(carry){
			res.push_back(carry+'0');
		}
	}else{
		while(j>=0){
			int sum = (b[j]-'0' + carry) % 2;
			carry = (b[j] - '0'+ carry) / 2;
			res.push_back(sum + '0');
			j--;
		}
		if(carry){
			res.push_back(carry + '0');
		}
	}
	string result;
	for(int i = res.length() - 1;i >= 0;i--){
		result.push_back(res[i]);
	}
	return result;
}

//int main(){
//	string a,b;
//	a = "1101";
//	b = "11";
//	string res = addBinary(a,b);
//	for(int i = 0;i < res.length();i++){
//		cout<<res[i];
//	}
//	return 0;
//}