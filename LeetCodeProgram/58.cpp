#include<iostream>
using namespace std;
//������ĺܼ򵥣�дeasy��û�д��ˡ���
//�ҵ�һ���ַ����������һ�����ʵĳ��ȣ��ȷ�ת���ٴ�ͷ��������ʵҲ���Բ���ת���Ӻ���ֱ����ǰ������ģ�����Ϊ�˷���

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