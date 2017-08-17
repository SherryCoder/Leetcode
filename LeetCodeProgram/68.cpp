#include<iostream>
#include<vector>
using namespace std;
//校正文本，将文本校正为n行，每一行都是n个字符，并且每一行除了最后一行以外都是两端对齐的，一行中单词与单词之间的空格应该是
// 均匀分布的，如果不能使之均匀分布，那么左边分割的空格应该比右边的多，对于最后一行，左对齐，并且单词之间不需要再添加新的空格,单词之间一个空格就可以
//（并非自己解出的题目，需要重新回顾*****）
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	int cnt = 0,left = 0;
	vector<string> res;
	for(int i = 0;i < words.size();i++){
		cnt += words[i].size();
		if(cnt + i - left  > maxWidth || i + 1 == words.size()){
			if(cnt + i - left > maxWidth) cnt -= words[i--].size();
			string str = words[left];
			for(int j = left + 1;j <= i;j++ ){
				int m = maxWidth - cnt;   //插入多少个空格
				int n = i - left;         //有多少个间隙可以插空格
				if(i+1 == words.size()) str +=" ";  //如果下一个数字就是最后一个数字了，也就是证明是最后一行，所以不需要添加' ' 
				else str.append(m/n + (j-left-1<m%n),' '); //添加m/n + (j-left)<m%n个空格******(值得学习)
				str += words[j];
			}
			str.append(maxWidth-str.size(),' ');   //像一行的末尾添加maxWidth-str.size个空格，主要是针对最后一行来的
			res.push_back(str);
			left = i+1,cnt = 0;
		}
	}
	return res;
}


//int main(){
//	vector<string> test;
//	test.push_back("this");
//	test.push_back("is");
//	test.push_back("just");
//	test.push_back("is");
//	test.push_back("funy");
//	vector<string> res = fullJustify(test,10);
//	return 0;
//}