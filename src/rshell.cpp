#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<cstring> 
#include<algorithm>
#include<iterator>
#include<sstream>

using namespace std;

bool run_test(char command[]);
bool run_word_test(char command[]);
bool test_word(const char command[]);
bool test_check_brackets(const char command[], bool &brackets);
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
				if(str.at(i) == '#')  //Removes all part of the command after the comment
				{
					str = str.substr(0,i);
				}
			}
			while(str.at(0) == ' ')
			{
				str = str.substr(1,str.size()-1);
			}
			if(str.at(str.size() - 1 ) == ' ')
			{
				str = str.substr(0,str.size()- 1);
			}
			bool extra_brac = false;
			bool testBool_brac = false;
			bool testBool = false;
			char c_line[100];
			char *command_line[64];
			strcpy(c_line,str.c_str());
			c_line[str.size()] = '\0';
			testBool_brac = test_check_brackets(c_line, extra_brac);
			
			if(testBool_brac && extra_brac)
			{
				run_test(c_line);
			}
			else if(!testBool_brac && !extra_brac)
			{
				testBool = test_word(c_line);
				if(testBool)
				{
					run_word_test(c_line);
				}
				else
				{
					parse_line(c_line, command_line);
					run_line(command_line);
				}
			}
		}

	}
	  return 0;
}


void parse_line(char c_line[], char *command_line[])
{
	while(*c_line != '\0')
	{
		while(*c_line == ' ' || *c_line == '\n' || *c_line == '\t')
		{
			*c_line++ = '\0';
		}
		*command_line++ = c_line;
		while(*c_line != '\0' && *c_line != ' ' && *c_line != '\n' && *c_line != '\t')
		{
			c_line++;
		}
		*command_line = NULL;
	}
	return;
}

bool test_word(const char command[])
{
	int i = 0;
	if(command[i] == 't' && command[i + 1] == 'e')
	{
		if(command[i + 3] == 't')
		{
			return true;
		}
	}
	return false;
}

bool run_word_test(char command[])
{
	bool file = false;
	bool dir = false;
	bool exist = false;
	int i = 3;
	char fix_command[100];
	i++;
	for(; command[i] == ' '; ++i){} // to skip all the spaces between test and the flag
	if(command[i] == '-' && command[i + 1] == 'f')
	{
		file = true;
		i++;
		i++;
	}
	else if(command[i] == '-' && command[i + 1] == 'd')
	{
		dir = true;
		i++;
		i++;
	}
	else if(command[i] == '-' && (command[i + 1] != 'e' && command[i + 1] != ' '))
	{
		cout << "Invalid Flag\n";
		return false;
	}
	else if(command[i] == '-' && (command[i + 1] == 'e' || command[i + 1] == ' '))
	{
		exist = true;
		i++;
		i++;
	}
	else
	{
		cout << "Error missing Flag\n";
		return false;
	}
	for(; command[i] == ' '; ++i){} // skip all spaces between flag and argument

	if(command[i] != '\0')
	{
		int j = 0;
		for(; command[i] != '\0' && command[i] != ' '; ++i)
		{
			fix_command[j] = command[i];
			j++;
		}
		fix_command[j] = '\0';
	}
	if(exist)
	{
		struct stat exist;
		if(stat(fix_command, &exist) == 0)
		{
			cout << "(True)\n";
			return true;
		}
		else
		{
			cout << "(False)\n";
			return false;
		}
	}
	else if(file)
	{
		struct stat file;
		stat(fix_command, &file);
		if(S_ISREG(file.st_mode) != 0)
		{
			cout << "(True)\n";
			return true;
		}
		else
		{
			cout << "(False)\n";
			return false;
		}
	}
	else if(dir)
	{
		struct stat dir;
		stat(fix_command, &dir);
		if(S_ISDIR(dir.st_mode) != 0)
		{
			cout << "(True)\n";
			return true;
		}
		else
		{
			cout << "(False)\n";
			return false;
		}
	}
	return false;
}



bool test_check_brackets(const char command[], bool &brackets)
{
	bool endBracket = true;
	int i = 0;
	if(command[i] == '[')
	{
		i++;
		if(command[i] == ' ')
		{
			for(; command[i] != '\0'; i++)
			{
				if(command[i] == ']')
				{
					endBracket = false;
					if(command[i - 1] == ' ')
					{
						brackets = true;
						return true;
					}
					else
					{
						brackets = true;
						cout << "Need a space before ]\n";
						return false;
					}
				}
			}
			if(endBracket)
			{
				cout << "Missing ]\n";
				brackets = true;
				return false;
			}

		}
		else
		{
			brackets = true;
			cout << "Need a space after [\n";
			return false;
		}
	}
	return false;
}

bool run_test(char command[])
{
	bool file = false;
	bool dir = false;
	bool exist = false;

	int i = 1;
	for(; command[i] == ' '; i++){} // gets rid of spaces between [ and flag

	if(command[i] == '-')
	{
		i++;
		if(command[i] == 'f')
		{
			file = true;
			i++;
		}
		else if(command[i] == 'd')
		{
			dir = true;
			i++;
		}
		else if(command[i] == 'e' || command[i] == ' ')
		{
			exist = true;
			i++;
		}
		else
		{
			cout << "Error, invalid flag\n";
			return false;
		}
	}
	else if(command[i] != '-')
	{
		cout << "Error, missing flag\n";
		return false;
	}

	char fix_command[100];
	for(; command[i] == ' '; i++){} // to skip all the spaces between the flag and the argument
	if(command[i] != '\0')
	{
		int j = 0;
		for(; command[i] != '\0' && command[i] != ' '; i++)
		{
			fix_command[j] = command[i];
			j++;
		}
		fix_command[j] = '\0';

	}
	else
	{
		cout << "Invalid argument with flag\n";
		return false;
	}
	if(exist)
	{
		struct stat exist;
		if(stat(fix_command, &exist) == 0)
		{
			cout << "(True)\n";
			return true;
		}
		else
		{
			cout << "(False)\n";
			return false;
		}
	}
	else if(file)
	{
		struct stat file;
		stat(fix_command, &file);
		if(S_ISREG(file.st_mode) != 0)
		{
			cout << "(True)\n";
			return true;
		}
		else
		{
			cout << "(False)\n";
			return false;
		}
	}
	else if(dir)
	{
		struct stat dir;
		stat(fix_command, &dir);
		if(S_ISDIR(dir.st_mode) != 0)
		{
			cout << "(True)\n";
			return true;
		}
		else
		{
			cout << "(False)\n";
			return false;
		}
	}
	return false;
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
