#include<iostream>
#include "ArgParser.h"
#include "LogFilterDriver.h"
int main(int argc, char * argv[])
{	
    ArgParser cmdParser;
    LogFilterDriver driver;
    //cout << "Arg count "<<argc; 
    if(cmdParser.cmdOptionExists(argv, argv+argc, "-h"))
    {
        // Do stuff
	cout <<"./LogFilter -p <pid> -t <tid> -f <filename> -st <starttime> -et <endtime>";
    }

    cmdParser.getCmdOption(argv, argv + argc);


    
    driver.ProcessFile(cmdParser.getfilename());
  //  cout<<cmdParser.getPid()<<cmdParser.getTid()<<cmdParser.getstarttime().getTime()<<cmdParser.getendtime().getTime();
    auto logs = driver.FilterLog(cmdParser.getPid(),cmdParser.getTid(),cmdParser.getstarttime(),cmdParser.getendtime());
    for (auto itr = logs.begin();itr != logs.end();itr++)
        {
	 cout<<itr->LogDate.getDate()<<" "<<itr->LogTime.getTime()<<"\t"<<itr->getPid() << " \t "<< itr->getTid()<<"\t"<<itr->Lglevel<<" "<<itr->getMessage()<<"\n";
	}
    //cout <<cmdParser.getPid();
    //cout<<cmdParser.getTid();
    
    return 0;
}
