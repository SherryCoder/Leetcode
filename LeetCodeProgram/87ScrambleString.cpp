#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//ƴ���ַ���������һ���ַ���������ͨ���ݹ�Ľ���ָ�������ǿ��Ӵ��γ�һ��������
//�������ַ���s1,s2,�ж�s2�ǲ���s1��sramblestring
bool isScramble(string s1, string s2) {
	if(s1 == s2){
		return true;
	}
	vector<int>table(256,0);
	//unodered_map<char,int>table;
	int len = s1.size();
	for(int i = 0;i < len;i++){
		table[(s1[i]-'a')]++;
		table[(s2[i]-'a')]--;
	}
	for(int i = 0;i < 26;i++){
		if(table[i]!=0)
			return false;
	}
	for(int i = 1;i <= len-1;i++){
		//��iΪ���ģ��Ƚ�s1(0~i-1) s2(0~i-1)�� s1(i~len-1) ��s2(i~len-1)
		if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))){
			return true;
		}
		//�ڶ�������iΪ���ȣ��Ƚ�s1��ǰi���ַ���s2�ĺ�i���ַ����Ƚ�s1��i��ʼ��len-i���ַ���s2��0��ʼ��len-i���ַ�
		if(isScramble(s1.substr(0,i) , s2.substr(len - i)) && isScramble(s1.substr(i),s2.substr(0,len-i))){
			return true;
		}
	}
	return false;
}
//int main(){
//	//��Ȼͨ���˲��ԣ����Ƕ������µİ��У�����ǳ�ʱ��
//	string s1 = "bcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcde"; 
//	string s2 = "cebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebd";
//	bool res = isScramble(s1,s2);
//	cout<<res<<endl;
//	return 0;
//}