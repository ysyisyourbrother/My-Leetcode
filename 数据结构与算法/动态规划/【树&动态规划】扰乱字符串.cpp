#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
/*简单的说，就是s1和s2是scramble的话，
那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，
同样有s21和s22.那么要么s11和s21是scramble的并且s12和s22是scramble的；
要么s11和s22是scramble的并且s12和s21是scramble的。
就拿题目中的例子 rgeat 和 great 来说，rgeat 可分成 rg 和 eat 两段， 
great 可分成 gr 和 eat 两段，rg 和 gr 是scrambled的， eat 和 eat 当然是scrambled。
*/
//递归解法： 
bool isScramble1(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;
    if (s1 == s2) return true;
    string str1 = s1, str2 = s2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 != str2) return false;
    
    for (int i = 1; i < s1.size(); ++i) {
	    string s11 = s1.substr(0, i);
	    string s12 = s1.substr(i);
	    string s21 = s2.substr(0, i);
	    string s22 = s2.substr(i);
	    if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
	    s21 = s2.substr(s1.size() - i);
	    s22 = s2.substr(0, s1.size() - i);
	    if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
    }
    return false;
}
bool isScramble2(string s1, string s2)
{
	int n1 = s1.size();
	int n2 = s2.size();
	if (n1 == 0 && n2 == 0)
		return true;
	if (n1 == 0 || n2 == 0)
		return false;
	if (n1 != n2)
		return false;

	vector<vector<vector<bool>>> dp(n1 + 1, vector<vector<bool>>(n2 + 1, vector<bool>(n1 + 1, false)));
	for (int i = 0; i<n1; i++)
		for (int j = 0; j<n2; j++)
			if (s1[i] == s2[j])
				dp[i][j][1] = true;

	for (int len = 2; len <= n1; len++)
	{
		for (int i = 0; i<n1 - len + 1; i++)
			for (int j = 0; j<n2 - len + 1; j++)
				for (int k = 1; k<len; k++)
					dp[i][j][len] = dp[i][j][len] || (dp[i][j][k] && dp[i + k][j + k][len - k])
					|| (dp[i][j + len - k][k] && dp[i + k][j][len - k]);
	}
	return dp[0][0][n1];
}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<isScramble(a,b);
 } 
