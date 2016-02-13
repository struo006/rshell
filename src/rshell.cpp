#include<iostream>
#include<string.h>
#include<string>
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

void parse_line(char c_line[], char *command_line[]);
void run_line(char *command_line[]);

 int main()
{	
	string str;	
	string arg = "";
	 while(1)
	{
		str = "";	
		char userName[100] = "";
		if(getlogin_r(userName, sizeof(userName)-1) != 0) //Getting username, and returns null if cant be found
		{
			perror("Error getting username");
		}
		cout << '['  << userName << '@';
		char hostName[100] = "";
		if(gethostname(hostName, sizeof(hostName)-1) != 0) // Getting host name, returns numm if it cannot be found
		{
			perror("Error getting hostname");
		}
		cout << hostName << ']';
		cout << "$"; 
		getline(cin,str);  //Gets a command
		if(str == "exit")  //If the command is exit the program stops		
		{
			 break;		
		}
		if(str.size() != 0 && str.at(0) == '#')
		{
			str = "";
		}
		if(str != "")
		{
			for(unsigned i = 0; i < str.size(); i++)
			{
				if(str.at(i) == ';')  //Looks for semicolons and adds a space in order to make parsing easier
				{
					str.insert(i, " ");
					i++;
				}
				if(str.at(i) == '#')  //Removes all part of the command after the comment
				{
					str = str.substr(0,i);
				}
			}
			while(str.find("  ") != string::npos)
			{
				str.erase(str.find(" "));
			}
			if(str.at(str.size() - 1 ) == ' ')
			{
				str = str.substr(0,str.size()-1);
			}
			char c_line[64];
			char *command_line[64];
			strcpy(c_line,str.c_str());
			c_line[str.size()] = '\0';
			
			parse_line(c_line, command_line);
			run_line(command_line);
		}

	}
	  return 0;
}

int k = 0;

void parse_line(char c_line[], char *command_line[])
{
	while(*c_line != '\0')
	{
		while(*c_line == ' ' || *c_line == '\n' || *c_line == '\t')
		{
			*c_line++ = '\0';
		}
		if(*c_line == ';')
		{
			run_line(command_line);
			//for(int i = 0; i < 64; i++)
			//{
			//	command_line[i] = new char[16];
			//}
			//command_line = new char*[64];
			//for(int i = 0; i < 64; i++)
			//{
			//	delete [] command_line[i];
			//}
			//delete [] command_line;
			c_line++;
		}
		*command_line++ = c_line;
		while(*c_line != '\0' && *c_line != ' ' && *c_line != '\n' && *c_line != '\t')
		{
			c_line++;
		}
		*command_line = '\0';
	}
	return;
}

void run_line(char *command_line[])
{
	pid_t pid;
	int status;
	if((pid = fork()) < 0)
	{
		perror("forking failed");
	}
	else if(pid == 0)
	{
		if(execvp(*command_line,command_line) < 0)
		{
			perror("execvp failed");
			exit(1);
		}
	}
	else
	{
		while(wait(&status) != pid)
		;
	}
	return;
}
