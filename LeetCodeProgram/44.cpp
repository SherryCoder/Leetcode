#include<iostream>
#include<string>
#include<vector>
using namespace std;
//?可以匹配任意的单个字符，*可以匹配任何的字符串序列，可以是0个或多个字符串，匹配需要是全匹配而不是部分匹配
//这题可以用两个标号来记录s中的位置和p中的位置，但是对于下标的越界判断比较繁琐


//这题比较难
//也可以用动态规划来做，记s串的前i个字符和p串的前j个字符能否匹配为dp[i][j].
//						如果p和s都为空，匹配成功dp[0][0]=true.
//						如果p为空，但是s不为空，那么匹配失败.dp[i][0] = false
//						如果p不为空，s为空，那么如果p[i-1]=='*'，那么dp[0][i]受到dp[0][i-1]的影响，否则dp[0][i]=false.

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