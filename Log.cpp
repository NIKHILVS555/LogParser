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
void Log::setDate(Date dt)
{
        LogDate = dt;
}
Date Log::getDate()
{
        return LogDate;
}
void Log::setTime(Time dt)
{
        LogTime = dt;
}
Time Log::getTime()
{
        return LogTime;
}
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
	

Log::Log(int pid, int tid, Date dt, Time tt, string msg, char lglvl)
{
	Pid = pid;
	Tid = tid;
	LogDate = dt;
	LogTime = tt;
	Message = msg;
	Lglevel = lglvl;
}
