#include"Log.h"
#include<list>
#include <stdlib.h>
class LogFile
{	
   list<Log> Logs;
	public:
   list<Log>getLogs();
   void setLogs(list<Log>);
   Log ParseLog(string);
   bool readLogFile(string);
   time_t ParseDateTime(string);
};
