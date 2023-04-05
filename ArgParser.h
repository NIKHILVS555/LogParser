#include <string>
#include <algorithm>

#include "DateTime.h"
//extern class Time;
//extern class Date;
using namespace std;
class ArgParser
{
	int Pid;
	int Tid;
	Time starttime;
	Time endtime;
	string filename;
	public:
	void getCmdOption(char ** begin, char ** end);
	bool cmdOptionExists(char** begin, char** end, const std::string& option);
	int getPid();
	int getTid();
	Time getstarttime();
	Time getendtime();
	string getfilename();
	Time ParseTime(string );
	ArgParser();
};
