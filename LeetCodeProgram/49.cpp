#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//ѭ���ҳ�ͬ���Ĵʣ������ֵ�����
//�����Ǹ���һ���ַ��������㽫����ͬ����Ҳ������ɵĵ�����ͬ���ĵ������һ�飬��󷵻أ�ÿ��Ҫ�����ֵ��������С�
//�õ��˹�ϣ��Ҳ���ǹ�ϣ����±�ʹ��string��Ȼ����Ӧ��λ�ô洢��Ӧ��ͬ��string
//��߻��õ��˵�������Ҳ����֮ǰ�����õĶ���

 //vector<vector<string>> groupAnagrams(vector<string>& strs) {
	// vector<vector<string>> ret;
	// if(strs.empty()){
	//	return ret;
	// }
	// sort(strs.begin(),strs.end());
	// map<string,vector<string>> strmap;    //��������ϣ��Ķ���ܹؼ�
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