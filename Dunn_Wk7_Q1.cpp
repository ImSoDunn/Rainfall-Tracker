#include<iostream>
#include<stdlib.h>
#include<string>
#include <iomanip>
using namespace std;

void tableFormat(double actualRainfall[], double avgRainfall[], double rainfallDeviation[]);
void barGraphFormat(double avgRainfall[], double actualRainfall[], double rainfallDeviation[]);
void barAsterisks(int stars);
void displayMonth(int month);

int main()
{
   double actualRainfall[12];
   double avgRainfall[12];
   double rainfallDeviation[12];
   int currentMonth;
   char choice;
   int count=0;

   cout << "Enter average monthly "
       << "rainfalls for each month:" << endl;
   for (int i = 0; i < 12; i++)
   {
       displayMonth(i);
       cout << ": ";
       cin >> avgRainfall[i];
   }
   cout << "Enter the current month (For example: Enter 1 for January) : " << endl;
   cin >> currentMonth;
   cout << "Enter the actual rainfall for each month in the previous year" << endl;
  
   for (int month = currentMonth - 1; count < 12;
       month = (month + 1) % 12, count++)
   {
       displayMonth(month);
       cout << ": ";
       cin >> actualRainfall[month];
   }
   for (int i = 0, j = 0; i < 12; i++, j++)
   {
       if (avgRainfall[i] > actualRainfall[i])
           rainfallDeviation[j] = actualRainfall[i] - avgRainfall[i];
       else
           rainfallDeviation[j] = actualRainfall[i] - avgRainfall[i];
   }
   cout << endl;
   do
   {
       cout << "Enter your choice(T for table or "
           " B for bar-graph or Q for exit program): ";
       cin >> choice;
       cout << endl;
       if (choice == 'T' || choice == 't')
           tableFormat(actualRainfall, avgRainfall, rainfallDeviation);
       else if (choice == 'B' || choice == 'b')
           barGraphFormat(avgRainfall, actualRainfall, rainfallDeviation);
       else if (choice == 'Q' || choice == 'q')
       {
               exit(0);
       }
       cout << endl;
   } while (true);
   return 0;
}

void tableFormat(double rainfall[], double avgRainfall[], double rainfallDeviation[])
{
   cout << endl;
   cout << "___________________________________________"
       "______________________________________" << endl;
   cout << "Month" << setw(20)
       << "Actual Rainfall" << setw(20)
       << "Average Rainfall "<< setw(25)
       << "    Above or Below Average Rainfall"
       << setw(20) << endl;
   cout << "___________________________________________"
       "______________________________________" << endl;
   for (int i = 0; i < 12; i++)
   {
       cout.setf(ios_base::left);
       displayMonth(i);
       cout << "\t" << setw(20) << rainfall[i] << setw(20)
           << avgRainfall[i] << setw(20) << rainfallDeviation[i];
       cout << endl;
   }
   cout << "_____________________________________________"
       "____________________________________" << endl;
}

void barGraphFormat(double avgRainfall[], double rainfall[], double rainfallDeviation[])
{
   cout << "Graph showing the average rainfall "
       "and the actual rainfall for each of the "
       "previous 12 months:" << endl;
   cout << endl;
   cout << "Rainfall-----------------> 0.0   0.5   1.0   1.5   2.0   2.5   3.0   3.5   4.0   5.0   5.5   6.0" << endl << 
                        "                          |*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|*****|" << endl;
   for (int i = 0; i < 12; i++)
   {
       displayMonth(i);
       cout << ":" << " Average Rainfall" << " ";
       int n1 = (int)avgRainfall[i];
       barAsterisks(n1);
       cout << endl;
       displayMonth(i);
       cout << ":" << "  Actual Rainfall" << " ";
       int n = (int)rainfall[i];
       barAsterisks(n);
       cout << endl;
   }
}

void barAsterisks(int stars)
{
   for (int count = 1; count <= stars; count++)
       cout << "************";
}

void displayMonth(int month)
{
    cout.width(8);
   switch (month)
   {
   case 0:
       cout << "January";
       break;
   case 1:
       cout << "February";
       break;
   case 2:
       cout << "March";
       break;
   case 3:
       cout << "April";
       break;
   case 4:
       cout << "May";
       break;
   case 5:
       cout << "June";
       break;
   case 6:
       cout << "July";
       break;
   case 7:
       cout << "August";
       break;
   case 8:
       cout << "September";
       break;
   case 9:
       cout << "October";
       break;
   case 10:
       cout << "November";
       break;
   case 11:
       cout << "December";
       break;
   }
}