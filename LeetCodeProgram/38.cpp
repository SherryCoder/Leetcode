#include<iostream>
using namespace std;

//按照给定的序列找规律，其实就是读出n-1的字符串。其实就是用循环，从1还是生成第二个，再从第二个生成第三个。。。直到生成第n个
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