#include"LogFile.h"
class LogFilterDriver
{
	LogFile fileHandle;
	public:
	list<Log> FilterLog(int, int , Time, Time );
	void ProcessFile(string);
};
