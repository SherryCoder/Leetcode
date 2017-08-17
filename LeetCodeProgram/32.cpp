/**2017/6/22
* ��һ�������ַ����У����ƥ�����ŶԳ���
����()()()(��ĳ��Ⱦ���6
���������⣬��Ҫ�õ�����ջ������ݽṹ  
��ͷ��βɨ���ַ�����������(�ͽ���index����ջ��������)�Ͳ鿴ջ���Ƿ���Ԫ�أ��еĻ��Ϳ���ƥ��
1��ջ����  ��ʱ��Ҫ��ʼ�µļ���������Ч��Ԫ���±����
2��ջ�ǿգ��ַ��������
	��1����ջ��ֻʣ��һ��Ԫ�أ�����ƥ����֮�������һ�ε�ƥ���������index - validindex+1
	��2����ջ�в�ֹһ��Ԫ�أ���ʱ�������и����ƥ�䣬��ʱ���ȸ���Ϊindex - ջ.top
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