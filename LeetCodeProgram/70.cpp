#include<iostream>
#include<stack>
using namespace std;
//������ǽ�unix�е�·�����л��������ݽṹ��ջ��
//ʹ��/���зָ����ǿջ���.�Ͳ����в����������..����ջ����Ԫ�أ��ͳ�ջһ��Ԫ�أ�����ͽ�Ԫ����ջ


string simplifyPath(string path) {
	stack<string> simplePath;
	while(!path.empty()){
		int start = path.find_first_of("/");   //�ҵ���һ��'/'
		path = path.substr(start+1);
		int end = path.find_first_of("/");     //�ҵ��ڶ���'/'
		if(end == -1)
			end = path.length();
		string pathstr = path.substr(0,end);
		path = path.substr(end);
		if(!pathstr.compare("") || !pathstr.compare(".")){
			continue;
		}
		else if(!pathstr.compare("..")){
			if(!simplePath.empty()){
				simplePath.pop();
			}
		}
		else{
			string slashstr = "/";
			slashstr += pathstr;
 			simplePath.push(slashstr);
		}
	}
	string result="";
	while(!simplePath.empty()){
		string frag =  simplePath.top();;
		frag += result;
		result = frag;
		simplePath.pop();
	}
	if(result.length() == 0){					//����������path�в�������·������ô�ͷ���'/'
		result = "/";          
	}
	return result;
}

//int main(){
//	string result = simplifyPath("/");
//	for(int i = 0;i < result.length();i++){
//		cout<<result[i];
//	}
//	cout<<endl;
//	return 0;
//}