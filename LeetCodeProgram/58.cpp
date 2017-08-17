#include<iostream>
using namespace std;
//这题真的很简单，写easy是没有错了。。
//找到一个字符串里面最后一个单词的长度，先反转，再从头遍历，其实也可以不反转，从后面直接向前面遍历的，我是为了方便

int lengthOfLastWord(string s) {
	reverse(s.begin(),s.end());
	if(s.size()<=0)
		return 0;
	int i = 0;
	while(s[i]==' '){
		i++;
	}
	if(i == s.size()){
		return 0;
	}
	int count = 0;
	//for(;i < s.size();i++){
	//	if(s[i]!=' '){
	//		count++;
	//	}else{
	//		break;
	//	}
	//}
	while( i < s.size()&&s[i]!=' '){
		i++;
		count++;
	}
	return count;
}

//int main(){
//	string s = "heoo test he";
//	int result = lengthOfLastWord(s);
//	cout<<result<<endl;
//}