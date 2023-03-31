#include"LogFile.h"
class LogFilterDriver
{
	LogFile fileHandle;
	public:
	list<Log> FilterLog(int, int , time_t, time_t );
	void ProcessFile(string);
};
