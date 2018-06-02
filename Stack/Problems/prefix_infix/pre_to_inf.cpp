#include<bits/stdc++.h>
using namespace std;
class convert
{
private:
  string infix;
  string prefix;
public:
  convert(string str);
};
convert::convert(string pre)
{
  prefix=pre;
  int length=prefix.length();
  stack<string>s;
  length--;
  while(length >= 0)
    {
      if(isalpha(prefix[length]))
	{
	  string temp(1,prefix[length]);
	  s.push(temp);
	  //s.push(to_string(prefix[length]));
	}
      else
	{
	  string alpha2=s.top();s.pop();
	  string alpha1=s.top();s.pop();
	  string temp="(";
	  temp=temp+alpha1+prefix[length]+alpha2+")";
	  s.push(temp);
	}
      length--;
    }
  cout<<s.top()<<endl;;
}

int main()
{
  convert("*+AB-CD");
}
