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
	string arg = "";
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
			char* char_command = new char[str.size()];
			char* args[2];
			args[0] = char_command;
			args[1] = NULL;
			execvp(args[0], args);	
			if(execvp(args[0], args) == -1)
			{
				perror("failed to execute");
			}	

		}
	}
	  return 0;
}
