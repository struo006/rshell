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
		char userName[100] = "";
		if(getlogin_r(userName, sizeof(userName)-1) != 0) //Getting username, and returns null if cant be found
		{
			perror("Error getting username");
		}
		cout << userName << '@';
		char hostName[100] = "";
		if(gethostname(hostName, sizeof(hostName)-1) != 0) // Getting host name, returns numm if it cannot be found
		{
			perror("Error getting hostname");
		}
		cout << hostName;
		cout << "$"; 
		vector <string> line;
		getline(cin,str);  //Gets a command
		if(str == "exit")  //If the command is exit the program stops		
		{
			 break;		
		}
		for(int i = 0; i < str.size(); i++)
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
		istringstream iss(str);
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(line)); //uses a string stream to parse string elements and put them into the vector of strings
		
		for(int i = 0; i < line.size(); i++)
		{
			cout << line.at(i) << endl;
		}

	}
	  return 0;
}
