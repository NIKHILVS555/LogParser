#include<string>
#include "DateTime.h"
using namespace std;
class Log
{
public:
	int Pid;
	int Tid;
	Date LogDate;
	Time LogTime;
	string Message;
	char Lglevel;
void setPid(int);
int  getPid();
void setTid(int);
int  getTid();
void setDate(Date);
Date  getDate();
void setTime(Time);
Time  getTime();
void setMessage(string);
string  getMessage();
void setlglevel(char);
char  getlglevel();
Log(int pid, int tid, Date dt, Time tt, string msg, char lglvl);
};
