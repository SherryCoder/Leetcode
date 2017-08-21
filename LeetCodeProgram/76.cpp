#include<iostream>
#include<unordered_map>
using namespace std;
//��ϣ��
//�����ַ���s��t����s���Һ���t�������ַ��Ĵ��ڣ���һ��hash����¼����t�е��ַ���
//��s�в���t�е��ַ����ҵ��󣬼�����ߵĽ���
//�ο�����

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

