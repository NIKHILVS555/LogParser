#include "LogFilterDriver.h"

list<Log> LogFilterDriver::FilterLog(int pid, int tid,time_t starttime, time_t endtime)
{

	list<Log> FilterLog;
	auto logs = fileHandle.getLogs();
	for (auto itr = logs.begin();itr != logs.end();itr++)
	{
		
		if (pid != 0)
		{
			if ( itr->Pid != pid)
			   continue;
		}
		if (tid != 0)
                {
                        if ( itr->Tid != tid)
                           continue;
                }
		if( starttime != (time_t)(-1) && endtime != (time_t)(-1))
		{
		    if (itr->LogDate< starttime || itr->LogDate > endtime)
		         continue;
		}

		FilterLog.push_back(*itr);
	}

  return FilterLog;

}
void LogFilterDriver::ProcessFile(string filename)
{
	fileHandle.readLogFile(filename);
}
