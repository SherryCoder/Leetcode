#include<iostream>
#include<stack>
using namespace std;
//这道题是将unix中的路径进行化简处理（数据结构：栈）
//使用/进行分割，如果是空或者.就不进行操作，如果是..并且栈中有元素，就出栈一个元素，否则就将元素入栈


string simplifyPath(string path) {
	stack<string> simplePath;
	while(!path.empty()){
		int start = path.find_first_of("/");   //找到第一个'/'
		path = path.substr(start+1);
		int end = path.find_first_of("/");     //找到第二个'/'
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
	if(result.length() == 0){					//如果所输入的path中并不包含路径，那么就返回'/'
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