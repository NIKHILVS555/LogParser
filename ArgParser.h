#include <string>
#include <algorithm>
#include <ctime>
using namespace std;
class ArgParser
{
	int Pid;
	int Tid;
	time_t starttime;
	time_t endtime;
	string filename;
	public:
	void getCmdOption(char ** begin, char ** end);
	bool cmdOptionExists(char** begin, char** end, const std::string& option);
	int getPid();
	int getTid();
	time_t getstarttime();
	time_t getendtime();
	string getfilename();
	time_t ParseTime(string );
};
