#include<iostream>
using namespace std;
//这题是判断一个字符串是否是合法的数字，这个数字可能是小数，含有.可能是2.0e+12这种，含有e的数字，所以在判断的时候要将每一个条件都考虑到
//这题是参考人家的一个方法，就是用i来表示遍历这个字符串，用ncount来判断数字， e的前面可以有小树，但是e的后面不可以有

bool isNumber(string s) {
	int i = 0 , len = s.size();
	while(s[i]==' ') i++;
	if(s[i]=='+' || s[i]== '-') i++;
	int ncount = 0;
	while(i < len &&s[i]>='0'&& s[i] <='9') 
	{i++;ncount++;}
	if(i <len && s[i]=='.')i++;
	while(i < len && s[i]>='0' && s[i] <= '9') {i++;ncount++;}
	if(ncount == 0) return false;
	if(i < len &&s[i]=='e'){
		i++;
		if(i < len &&(s[i]=='+' || s[i]=='-'))
			i++;
		int count = 0;
		while(i<len && s[i]>='0' && s[i]<='9'){
			i++;
			count++;
		}
		if(count == 0) return false;
	}

	while(i < len && s[i]==' ') i++;
	return i==len;
}
//
//int main(){
//	bool result = isNumber(".");
//	cout<<result<<endl;
//	return 0;
//}