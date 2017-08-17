#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//循环找出同构的词，按照字典排序
//这题是给你一个字符串，让你将其中同构（也就是组成的单词相同）的单词组成一组，最后返回，每组要按照字典升序排列。
//用到了哈希表，也就是哈希表的下标使用string，然后相应的位置存储相应的同构string
//这边还用到了迭代器，也是我之前不常用的东西

 //vector<vector<string>> groupAnagrams(vector<string>& strs) {
	// vector<vector<string>> ret;
	// if(strs.empty()){
	//	return ret;
	// }
	// sort(strs.begin(),strs.end());
	// map<string,vector<string>> strmap;    //这边这个哈希表的定义很关键
	// for(int i = 0;i < strs.size();i++){
	//	string str = strs[i];
	//	sort(str.begin(),str.end());
	//	strmap[str].push_back(strs[i]);
	// }

	// for(map<string,vector<string>>::iterator itr = strmap.begin();itr!=strmap.end();itr++){
	//	 ret.push_back(itr->second);
	// }
	// return ret;
 // }