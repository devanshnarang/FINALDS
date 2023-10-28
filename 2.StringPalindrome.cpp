#include<iostream>
using namespace std;
string isPalindrome(string S)
{

    string P = S;
    for (int i = 0; i < S.size(); i++)
	{
		if (S[i]==S[S.size()-1-i])
		{
			continue;
		}
		else{
			return "NO";
		}
	}
	return "YES";
}
int main()
{
	string a="ELEPHANT";
	cout<<"Is ELEPHANT a palindrome: "<<isPalindrome(a)<<endl;
	string b="NAMAN";
	cout<<"Is NAMAN a palindrome: "<<isPalindrome(b)<<endl;
   return 0;
}