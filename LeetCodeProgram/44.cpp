#include<iostream>
#include<string>
#include<vector>
using namespace std;
//?����ƥ������ĵ����ַ���*����ƥ���κε��ַ������У�������0�������ַ�����ƥ����Ҫ��ȫƥ������ǲ���ƥ��
//��������������������¼s�е�λ�ú�p�е�λ�ã����Ƕ����±��Խ���жϱȽϷ���


//����Ƚ���
//Ҳ�����ö�̬�滮��������s����ǰi���ַ���p����ǰj���ַ��ܷ�ƥ��Ϊdp[i][j].
//						���p��s��Ϊ�գ�ƥ��ɹ�dp[0][0]=true.
//						���pΪ�գ�����s��Ϊ�գ���ôƥ��ʧ��.dp[i][0] = false
//						���p��Ϊ�գ�sΪ�գ���ô���p[i-1]=='*'����ôdp[0][i]�ܵ�dp[0][i-1]��Ӱ�죬����dp[0][i]=false.

bool isMatch(string s, string p) {
	int ss = 0,pp = 0,lastmatch = 0,starpos = -1;
	while(ss<s.length()){
		if(pp < p.length()){
			if(s[ss]==p[pp] || p[pp]=='?'){
				ss++;
				pp++;
				continue;
			} 
			if(p[pp]=='*'){
				if(pp+1 == p.length()){
					return true;
				}
				lastmatch = ss;
				starpos = pp++;
				continue;
			}
			if(starpos > -1 && starpos!=p.length()){
				ss = ++lastmatch;
				pp = starpos+1;
				continue;
			}
			return false;
		}else if(pp == p.length()){
			if(starpos > -1){
				ss = ++lastmatch;
				pp = starpos + 1;
			}else{
				return false;
			}
		}
	}
	while(pp<p.length() && p[pp]=='*') pp++;
	if(ss == s.length() && pp == p.length())
		return true;
	return false;
}

bool isMatch_t(string s, string p) {
	vector<vector<bool>> dp;
	dp.resize(s.size()+1);
	for(int i = 0;i < s.size() + 1;i++){
		dp[i].resize(p.size()+1,false);
	}
	dp[0][0] = true;
	for(int i = 1; i < p.size()+1;i++){
		if(p[i-1]=='*'){
			dp[0][i] = dp[0][i-1];
		}
	}
	for(int i = 1;i < s.size() + 1;i++){
		for(int j = 1;j < p.size() + 1;j++){
			if(s[i-1]==p[j-1] || p[j-1] == '?'){
				dp[i][j] = dp[i-1][j-1];
			}else if(p[j-1] == '*'){
				for(int k = 0;k < i;k++){
					if(dp[k][j-1] == true){
						dp[i][j] = true;
						break;
					}
				}
			}else{
				dp[i][j] = false;
			}
		}
	}

	return dp[s.size()][p.size()];
}

//int main(){
//	string s = "aaab";
//	string p = "***a";
//	cout<<p.length()<<endl;
//	cout<<p.size()<<endl;
//	bool result = isMatch(s,p);
//	cout<<result<<endl;
//	return 0;
//}