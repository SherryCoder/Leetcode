#include<iostream>
using namespace std;
//�������ж�һ���ַ����Ƿ��ǺϷ������֣�������ֿ�����С��������.������2.0e+12���֣�����e�����֣��������жϵ�ʱ��Ҫ��ÿһ�����������ǵ�
//�����ǲο��˼ҵ�һ��������������i����ʾ��������ַ�������ncount���ж����֣� e��ǰ�������С��������e�ĺ��治������

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