#include<iostream>
#include "ArgParser.h"
#include "LogFilterDriver.h"
int main(int argc, char * argv[])
{	
    ArgParser cmdParser;
    LogFilterDriver driver;

    if(cmdParser.cmdOptionExists(argv, argv+argc, "-h"))
    {
        // Do stuff
	cout <<"Help me \n";
    }

    cmdParser.getCmdOption(argv, argv + argc);


    
    driver.ProcessFile(cmdParser.getfilename());
    auto logs = driver.FilterLog(cmdParser.getPid(),cmdParser.getTid(),(time_t)(-1),(time_t)(-1));
    for (auto itr = logs.begin();itr != logs.end();itr++)
        {
	 cout<<itr->Pid << " \t "<< itr->Tid<<"\t"<<itr->Message<<"\n";
	}
    cout <<cmdParser.getPid();
    cout<<cmdParser.getTid();
    
    return 0;
}
