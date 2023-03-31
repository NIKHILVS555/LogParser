#include "Log.h"
void Log::setPid(int pid)
{
	Pid = pid;
}
int Log::getPid()
{
	return Pid;
}
void Log::setTid(int tid)
{
        Tid = tid;
}
int Log::getTid()
{
        return Tid;
}
void Log::setDate(time_t dt)
{
        LogDate = dt;
}
time_t Log::getDate()
{
        return LogDate;
}
/*void Log::setTime(time dt)
{
        LogTime = dt;
}
time Log::getTime()
{
        return LogTime;
}*/
void Log::setMessage(string msg)
{
        Message = msg;
}
string Log::getMessage()
{
        return Message;
}
void Log::setlglevel(char lvl)
{
        Lglevel = lvl;
}
char Log::getlglevel()
{
        return Lglevel;
}
	

Log::Log(int pid, int tid, time_t dt, string msg, char lglvl)
{
	Pid = pid;
	Tid = tid;
	LogDate = dt;
	Message = msg;
	Lglevel = lglvl;
}
