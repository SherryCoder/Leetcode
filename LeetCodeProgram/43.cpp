#include<vector>
#include<iostream>
#include<string>
using namespace std;

//��������string�ַ������������Ǹ�������num1��num2������num1��num2�ĳ˻���num1��num2�ĳ��ȶ�С��110
//num1*num2 num1�Ǳ�������num2�ǳ���
//����ģ�³˷���ʽ������д����
//�����Լ���������

string multiply(string num1, string num2) {
	if(num1.empty()|num2.empty()){
		return string();
	}
	if(num1 == "0"|| num2 == "0")
		return "0";
	string result = "";
	int carry = 0;
	reverse(num1.begin(),num1.end());      //��Ϊ�Ǵӵ�λ����λ��˼�룬�Ƚ��ַ�����ת��������ɺ��ٷ�ת����
	reverse(num2.begin(),num2.end());

	for(int i = 0;i < num1.length();i++){  //num1�ǳ�����Ҳ������ʽ����������֣�num2�Ǳ�����
		int pos = i;                       //pos����¼�����Ĵ�����ʼλ��
		for(int j = 0;j < num2.length();j++){
			int temp = (num1[i]-'0')*(num2[j]-'0') + carry;
			if(pos < result.length()){              //֤��posλ������
				temp += (result[pos] - '0');
				result[pos] = temp %10 + '0';
			}else{                                 //posλû������
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