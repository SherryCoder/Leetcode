/**2017/6/22
* 求一个括号字符串中，最长的匹配括号对长度
比如()()()(最长的长度就是6
求解这个问题，需要用到的是栈这个数据结构  
从头到尾扫描字符串，当遇到(就将其index存入栈，当遇到)就查看栈中是否有元素，有的话就可以匹配
1、栈空了  这时就要开始新的计数，将有效首元素下标更新
2、栈非空，又分两种情况
	（1）、栈中只剩下一个元素，这样匹配完之后就是这一段的匹配结束，用index - validindex+1
	（2）、栈中不止一个元素，这时还可以有更多的匹配，此时长度更新为index - 栈.top
**/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
      stack<int> leftParentIndex;
	  int maxLength = 0;
	  int validIndex = 0;
	  for(int index = 0;index < s.length();index++){
		  if(s[index]=='('){
			  leftParentIndex.push(index);
		  }else{
			  if(leftParentIndex.empty()){
					validIndex = index + 1;
			  }else{
				  leftParentIndex.pop();
				  if(leftParentIndex.empty()){
						maxLength = max(maxLength,index-validIndex+1);
				  }else{
						maxLength = max(maxLength,index-leftParentIndex.top());
				  }
			  }
		  }
	  }
	  return maxLength;
}

//int main(){
//	string s = "()()())(()()()())";
//	int maxlen = longestValidParentheses(s);
//	cout<<maxlen<<endl;
//
//}