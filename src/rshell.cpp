#include<iostream>
#include<string.h>
#include<vector>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<cstring> 

using namespace std;

 int main()
{	
	string str;	
	string arg = '';
	 while(1)
	{		
		cout << "$"; 
		getline(cin, str); 
		if(str == "exit")		
		{
			 break;		
		}
		else		
		{
			execvp(str.c_str(), arg.c_str());					}	
	}
	  return 0;
}
