#include<string>
#include <iostream>
using namespace std;
#ifndef DATETIME_FILE_H
#define DATETIME_FILE_H 1
class Time
{
public:
  int hour;
  int min;
  int sec;
  int millisec;

  Time( int h ,int mn,  int s, int ms)
  {

	  hour = h;
	  min = mn;
	  sec = s;
	  millisec = ms;
  }
  void setTime(int h, int mn, int s , int ms)
  {
	  hour = h;
          min = mn;
          sec = s;
          millisec = ms;

  }
  int operator >(Time x)
  {
	long time1 = millisec+ sec*1000+ min*60*1000 + hour*60*60*1000;
	long time2 = x.millisec+ x.sec*1000+ x.min*60*1000 + x.hour*60*60*1000;
//	cout << x. getTime();
	if(time1>time2)
	{
  //        cout<< time1 <<" greater "<< time2<<endl;		
	return 1;
	}
	else
	{
	return 0;
	cout << "else"<<endl;
	}
  }
  int operator <(Time x)
  {
        long time1 = min+ sec*1000+ min*60*1000 + hour*60*60*1000;
        long time2 = x.min+ x.sec*1000+ x.min*60*1000 + x.hour*60*60*1000;
        if(time1<time2)
        return 1;
        else
        return 0;
  }
  std::string getTime()
  {
	 //return ""+hour+":"+min+":"+sec+":"+millisec;
	 char buffer[50]= {0};
         sprintf(buffer, "%.2d:%.2d:%.2d.%.3d", hour, min, sec, millisec);
	 return std::string(buffer);

  }
  bool operator!=(const Time &right) const
  {
    if (hour == right.hour && min == right.min && sec == right.sec && millisec != right.millisec)
    {
    	    return false;
    }
    else
    {
    	return true;
    }
  }
  Time()
  {
  }
};
class Date
{
	public:
	int year;
	int month;
	int day;
	Date(int d, int m, int y)
	{
		year = y;
		month = m;
		day = d;
	}
	std::string getDate()
	{
		//return ""+year+"/"+month+"/"+day;
		char buffer[50]= {0};
         	sprintf(buffer, "%.2d-%.2d", day, month);
         	return std::string(buffer);
	}
	Date()
	{
	}

};


#endif
