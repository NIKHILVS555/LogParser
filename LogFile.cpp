#include"LogFile.h"
#include<fstream>
#include<sstream>
list<Log> LogFile::getLogs()
{
	return Logs;
}
void LogFile::setLogs(list<Log> newData)
{
   Logs = newData;
}
time_t LogFile::ParseDateTime(string strTime)
{
	return time(0);
}
Log LogFile::ParseLog(string line)
{
	stringstream ss(line);
	string word;
	int pos =1;
        time_t dt;
	int pid, tid;
	char lglvl;
	string lgmsg;
	while(ss>>word)
	{
		if (pos == 1)
		{
			string tmp;
			ss>>tmp;
			word +=" "+ tmp;
                        dt = ParseDateTime(word);
			pos ++;
			continue;
		}
		if (pos == 2)
		{
		       pid = atoi(word.c_str());
	               pos ++;
		       continue;	       
		}
		if(pos == 3)
		{
		       tid = atoi(word.c_str());
                       pos ++;
                       continue;
		}
		if ( pos == 4)
		{
			lglvl = word[0];
			pos ++;
			continue;
		}
               if (pos == 5)
	       {
		       string msg = word;
		       while(ss>>word)
		       {
			       msg +=word;
		       }
                      lgmsg = msg;
		      break;
	       }
	}
     Log newlog;
     newlog.setPid(pid);
     newlog.setTid(tid);
     newlog.setlglevel(lglvl);
     newlog.setDate(dt);
     newlog.setMessage(lgmsg);

     return newlog;
}
bool LogFile::readLogFile(string filename)
{
   fstream newfile;
   list<Log> newLogList;
   newfile.open(filename,ios::in);
   if (newfile.is_open())
   { 
      string tp;
      while(getline(newfile, tp))
      { 
         //cout << tp << "\n";  
         Log newlog = ParseLog(tp);
         newLogList.push_back(newlog);
      }
      newfile.close();
      setLogs(newLogList);
      return true;
   }
   else
	   return false;

}
