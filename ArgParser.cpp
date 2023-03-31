#include"ArgParser.h"
#include <iostream>
#include<stdlib.h>
#include <cstring>
void ArgParser::getCmdOption(char ** begin, char ** end)
{
	for(auto itr = begin;itr != end;itr++)
	{
                //std::cout << *itr<<"\n";
		if ( strcmp(*itr, "-p") == 0)
			Pid = atoi(*(++itr));
		if ( strcmp(*itr, "-t") == 0)
                        Tid = atoi(*(++itr));
		if ( strcmp(*itr, "-stime")==0)
                        starttime = ParseTime(*(++itr));
		 if ( strcmp(*itr, "-etime")==0)
                        endtime = ParseTime(*(++itr));
		 if ( strcmp(*itr, "-f") == 0)
                        filename = *(++itr);
	}
       	
}
bool ArgParser::cmdOptionExists(char** begin, char** end, const std::string& option)
{
	return std::find(begin, end, option) != end;
}
string ArgParser::getfilename()
{
	return filename;
}
int ArgParser::getPid()
{
	return Pid;
}
int ArgParser:: getTid()
{
	return Tid;
}
time_t ArgParser::getstarttime()
{
	return starttime;
}
time_t ArgParser::getendtime()
{
	return endtime;
}
time_t ArgParser::ParseTime(string stime)
{
	 return time(0);
}
