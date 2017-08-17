#include<vector>
#include<iostream>
#include<string>
using namespace std;

//给定两个string字符串代表两个非负的整数num1和num2，返回num1和num2的乘积，num1和num2的长度都小于110
//num1*num2 num1是被乘数，num2是乘数
//就是模仿乘法竖式计算来写程序
//不是自己做出来的

string multiply(string num1, string num2) {
	if(num1.empty()|num2.empty()){
		return string();
	}
	if(num1 == "0"|| num2 == "0")
		return "0";
	string result = "";
	int carry = 0;
	reverse(num1.begin(),num1.end());      //因为是从低位到高位的思想，先将字符串翻转，计算完成后，再翻转回来
	reverse(num2.begin(),num2.end());

	for(int i = 0;i < num1.length();i++){  //num1是乘数，也就是竖式的下面的数字，num2是被乘数
		int pos = i;                       //pos来记录乘数的处理起始位置
		for(int j = 0;j < num2.length();j++){
			int temp = (num1[i]-'0')*(num2[j]-'0') + carry;
			if(pos < result.length()){              //证明pos位有数字
				temp += (result[pos] - '0');
				result[pos] = temp %10 + '0';
			}else{                                 //pos位没有数字
				result.append(1,temp%10+'0');
			}
			carry = temp/10;
			pos++;
		}
		if(carry > 0){
			result.append(1,carry + '0');
		}
		carry = 0;
	}
	reverse(result.begin(),result.end());
	return result;
}

//int main(){
//	string result = "";
//	cout<< result.length()<<endl;
//	return 0;
//}