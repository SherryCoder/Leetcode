#include<iostream>
using namespace std;

//���ո����������ҹ��ɣ���ʵ���Ƕ���n-1���ַ�������ʵ������ѭ������1�������ɵڶ������ٴӵڶ������ɵ�����������ֱ�����ɵ�n��
string countAndSay(int n) {
	if(n == 0){
		return "";
	}
	string res = "1";
	while(--n){
		string cur = "";
		for(int i = 0;i < res.size();i++){
			int count = 1;
			while(i+1 < res.size() && res[i] == res[i+1]){
				count++;
				i++;
			}
			//cur += char(count)  + res[i];
			cur.push_back(count+'0');
			cur.push_back(res[i]);
		}
		res = cur;
	}
	return res;
}

string coutSay(int n){
	if(n==0){
		return "";
	}
	string res = "1";
	while(n--){
		string cur = "";
		for(int i = 0;i < res.size();i++){
			int count = 1;
			while(i+1 < res.size() && res[i] == res[i+1]){
				count++;
				i++;
			}
			cur.push_back(count+'0');
			cur.push_back(res[i]);
		}
		res = cur;
	}
	return res;
}
//
//int main(){
//	string res = countAndSay(5);
//	for(int i = 0;i < res.size();i++){
//		cout<<res[i];
//	}
//	cout<<endl;
//	cout<<res.size()<<endl;
//	return 0;
//}