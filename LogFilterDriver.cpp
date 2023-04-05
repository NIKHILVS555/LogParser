#include "LogFilterDriver.h"
#include <iostream>
list<Log> LogFilterDriver::FilterLog(int pid, int tid,Time starttime, Time endtime)
{

	list<Log> FilterLog;
	auto logs = fileHandle.getLogs();
	for (auto itr = logs.begin();itr != logs.end();itr++)
	{
	
		//std::cout <<itr->Pid << itr->Tid<<endl;	
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
		if( starttime.hour != -1 && endtime.hour != -1)
		{
		    if (itr->LogTime < starttime || itr->LogTime > endtime)
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
