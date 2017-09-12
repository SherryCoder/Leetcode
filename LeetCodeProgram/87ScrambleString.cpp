#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//拼凑字符串，给定一个字符串，可以通过递归的将其分割成两个非空子串形成一个二叉数
//给两个字符串s1,s2,判断s2是不是s1的sramblestring
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
		//以i为中心，比较s1(0~i-1) s2(0~i-1)和 s1(i~len-1) 和s2(i~len-1)
		if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))){
			return true;
		}
		//第二种是以i为长度，比较s1的前i个字符和s2的后i个字符，比较s1从i开始的len-i个字符和s2从0开始的len-i个字符
		if(isScramble(s1.substr(0,i) , s2.substr(len - i)) && isScramble(s1.substr(i),s2.substr(0,len-i))){
			return true;
		}
	}
	return false;
}
//int main(){
//	//虽然通过了测试，但是对于如下的案列，这个是超时的
//	string s1 = "bcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcdebcde"; 
//	string s2 = "cebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebdcebd";
//	bool res = isScramble(s1,s2);
//	cout<<res<<endl;
//	return 0;
//}