#include<iostream>
#include<string.h>
#include<vector>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<cstring> 
#include<boost/tokenizer.hpp>
#include<algorithm>
#include<iterator>
#include<sstream>

using namespace std;
using namespace boost;

 int main()
{	
	string str;	
	string arg = "";
	 while(1)
	{		
		cout << "$"; 
		vector <string> line;
		getline(cin,str);
		if(str == "exit")		
		{
			 break;		
		}
		for(int i = 0; i < str.size(); i++)
		{
			if(str.at(i) == '#')
			{
				str = str.substr(0,i);
			}
		}
		istringstream iss(str);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(line));
		
		for(int i = 0; i < line.size(); i++)
		{
			cout << line.at(i) << endl;
		}
	}
	  return 0;
}
