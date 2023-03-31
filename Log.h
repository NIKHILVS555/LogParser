#include<string>
#include <ctime>
using namespace std;
class Log
{
public:
	int Pid;
	int Tid;
	time_t LogDate;
	//time LogTime;
	string Message;
	char Lglevel;
void setPid(int);
int  getPid();
void setTid(int);
int  getTid();
void setDate(time_t);
time_t  getDate();
/*void setTime(time);
time  getTime();*/
void setMessage(string);
string  getMessage();
void setlglevel(char);
char  getlglevel();
Log(int pid, int tid, time_t dt, string msg, char lglvl);
};
