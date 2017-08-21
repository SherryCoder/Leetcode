#include<iostream>
#include<unordered_map>
using namespace std;
//哈希表
//两个字符串s和t，在s找找含有t中所有字符的窗口，用一个hash表，记录所有t中的字符串
//在s中查找t中的字符，找到后，减少左边的界限
//参考网上

string minWindow(string s, string t) {
	unordered_map<char,int> hash;
	int num = t.size();
	int left = 0;
	int len = INT_MAX;
	int start = 0;
	for(int i = 0;i < t.size();i++){
		hash[t[i]]++;
	}
	for(int i = 0;i < s.size();i++){
		if(hash[s[i]]-- > 0){
			num--;
		}
		while(num==0){
			len = (i - left + 1) < len ? (i-(start = left) + 1) : len;
			if(hash[s[left++]]++ == 0) num++;
		}
	}
	return len == INT_MAX?"":s.substr(start,len);
}

