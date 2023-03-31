log.o:Log.cpp
	gcc -c -o log.o Log.cpp -lstdc++
logfile.o:LogFile.cpp
	gcc -c -o logfile.o LogFile.cpp  -lstdc++
ArgParser.o:ArgParser.cpp
	gcc -c -o ArgParser.o ArgParser.cpp  -lstdc++
LogFilterDriver.o:LogFilterDriver.cpp
	gcc -c -o LogFilterDriver.o LogFilterDriver.cpp -lstdc++
LogFilter:Log.cpp LogFile.cpp ArgParser.cpp LogFilterDriver.cpp main.cpp
	gcc Log.cpp LogFile.cpp ArgParser.cpp LogFilterDriver.cpp main.cpp -lstdc++ -o LogFilter
