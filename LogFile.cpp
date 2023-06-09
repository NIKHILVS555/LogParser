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
Time LogFile::ParseTime(string strTime)
{
	int hh = atoi(strTime.substr(0, 2).c_str());
        int mm = atoi(strTime.substr(3, 2).c_str());
        int ss = atoi(strTime.substr(6, 2).c_str());
        int ms = atoi(strTime.substr(9, 3).c_str());
        return Time(hh,mm,ss,ms);
}
Date LogFile::ParseDate(string strDate)
{
	int dd = atoi(strDate.substr(0, 2).c_str());
        int mm = atoi(strDate.substr(3, 2).c_str());
        return Date(dd,mm,1970);

}
Log LogFile::ParseLog(string line)
{
	stringstream ss(line);
	string word;
	int pos =1;
        Date dt;
	Time tt;
	int pid, tid;
	char lglvl;
	string lgmsg;
	while(ss>>word)
	{
		if (pos == 1)
		{
			string tmp;
			ss>>tmp;
                        dt = ParseDate(word);
			tt = ParseTime(tmp);
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
     Log newlog(pid,tid,dt,tt,lgmsg,lglvl);
    /* newlog.setPid(pid);
     newlog.setTid(tid);
     newlog.setlglevel(lglvl);
     newlog.setDate(dt);
     newlog.setMessage(lgmsg);*/

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
   {
      cout<<"File open failed";
	   return false;
   }

}
