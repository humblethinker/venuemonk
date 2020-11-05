#include <iostream>
using namespace std;

int isleap(int n) //function to check if the given year is a leap year or not
{
	if(n%400==0)
	return 1;
	else if(n%4==0&&n%100!=0)
	return 1;
	else
	return 0;
}
int main() {
	int inity=1901, endy=2000;
	int day=2, ans=0; /* Day denotes the weekday enumerated from Sunday as 0 onwards, 
	                 since 1 Jan 1900 was Monday i.e. 1 therefore 1 Jan 1901 will be 1+365%7=2*/
	int months[]={-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
	//Array for getting number of days in month enumerated by by numbers from 1 to 12
	for(int i=inity; i<=endy; ++i)
	{
		for(int j=1; j<=12; ++j)
		{
			if(day==0)
			++ans;
			if(months[j]==31)
			day+=3;          //increment of 31%7=3 
			else if(j!=2)
			day+=2;         //increment of 30%7=2
			else if(isleap(i))
			day+=1;        //increment of 29%7=1
			day=day%7;
		}
	}
	cout<<"The number of required Sundays : "<<ans;
	return 0;
}