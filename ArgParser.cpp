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
		if ( strcmp(*itr, "-st")==0)
                        starttime = ParseTime(*(++itr));
		 if ( strcmp(*itr, "-et")==0)
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
Time ArgParser::getstarttime()
{
	return starttime;
}
Time ArgParser::getendtime()
{
	return endtime;
}
Time ArgParser::ParseTime(string stime)
{

	int hh = atoi(stime.substr(0, 2).c_str());
        int mm = atoi(stime.substr(3, 2).c_str());
        int ss = atoi(stime.substr(6, 2).c_str());
        int ms = atoi(stime.substr(9, 3).c_str());	
	return Time(hh,mm,ss,ms);

}
ArgParser::ArgParser()
{
        Pid = 0;
        Tid = 0;
        starttime.setTime(-1,-1,-1,-1);
        endtime.setTime(-1,-1,-1,-1);
        filename = "mytext.txt";
}
