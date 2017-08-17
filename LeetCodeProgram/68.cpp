#include<iostream>
#include<vector>
using namespace std;
//У���ı������ı�У��Ϊn�У�ÿһ�ж���n���ַ�������ÿһ�г������һ�����ⶼ�����˶���ģ�һ���е����뵥��֮��Ŀո�Ӧ����
// ���ȷֲ��ģ��������ʹ֮���ȷֲ�����ô��߷ָ�Ŀո�Ӧ�ñ��ұߵĶ࣬�������һ�У�����룬���ҵ���֮�䲻��Ҫ������µĿո�,����֮��һ���ո�Ϳ���
//�������Լ��������Ŀ����Ҫ���»ع�*****��
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	int cnt = 0,left = 0;
	vector<string> res;
	for(int i = 0;i < words.size();i++){
		cnt += words[i].size();
		if(cnt + i - left  > maxWidth || i + 1 == words.size()){
			if(cnt + i - left > maxWidth) cnt -= words[i--].size();
			string str = words[left];
			for(int j = left + 1;j <= i;j++ ){
				int m = maxWidth - cnt;   //������ٸ��ո�
				int n = i - left;         //�ж��ٸ���϶���Բ�ո�
				if(i+1 == words.size()) str +=" ";  //�����һ�����־������һ�������ˣ�Ҳ����֤�������һ�У����Բ���Ҫ���' ' 
				else str.append(m/n + (j-left-1<m%n),' '); //���m/n + (j-left)<m%n���ո�******(ֵ��ѧϰ)
				str += words[j];
			}
			str.append(maxWidth-str.size(),' ');   //��һ�е�ĩβ���maxWidth-str.size���ո���Ҫ��������һ������
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