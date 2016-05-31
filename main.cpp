//CIS 31
//Project 2: Water Bill Calculator

#include <iostream>
#include <string>
using namespace std;

int main()
{
  
 //Constant Variables
    const double FIRST_RATE = 2.75;  //First Tier Rate for both seasons
    const double LOW_RATE = 2.89;    //Second Tier Rate for low season after basic HCF
    const double HIGH_RATE =3.38;    //Second Tier Rate for high season after basic HCF
    const int HIGH_HCF = 44;         //HCF allowed for first tier rate during high season
    const int LOW_HCF = 31;          //HCF allowed for first tier rate during low season
    
 //Qualifiers to make sure that valid info was inputted.
    
    cout<< "Initial meter reading: ";
    int initialMeter;
    cin>> initialMeter;
    
if (initialMeter <0)
    {   cout<<"---\n";
        cout<< "The initial meter reading must be nonnegative.\n";
        return 1;
    }

    cout<< "Final meter reading: ";
    int finalMeter;
    cin>> finalMeter;

if (finalMeter<initialMeter)
    {   cout<<"---\n";
        cout<<  "The final reading must be at least as large as the initial reading.\n";
        return 1;
    }
    
    cin.ignore(100000,'\n');
    
    cout<< "Customer name: ";
    string customerName;
    getline(cin,customerName);
    
if (customerName=="")
    {
        cout<< "---\n";
        cout<< "You must enter a customer name.\n";
        return 1;
    }
    
    cout<< "Month number (1=Jan, 2=Feb, etc.): ";
    int monthNum;
    cin>> monthNum;
    
if (monthNum<1 || monthNum>12)
        {cout<<"---\n";
        cout<< "The month number must be in the range 1 through 12.\n";
                return 1;
        }
    
//Calculations

    int waterUsed = finalMeter - initialMeter;
    int secWater;      //HCF used with second tier rate.
    double firstBill;  //Amount for first tier water
    double secondBill; //Amount for second tier water
    double billAmount;

    //High Season
    if (monthNum >= 4 && monthNum <=10)
    {
        if (waterUsed <= HIGH_HCF)
            billAmount = waterUsed * FIRST_RATE;
        else
        {
            secWater = waterUsed - HIGH_HCF;
            firstBill = FIRST_RATE * HIGH_HCF;
            secondBill = secWater * HIGH_RATE;
            billAmount = firstBill + secondBill;
        }
     }
    
    //Low Season
    else
    {
        if (waterUsed <= LOW_HCF)
            billAmount = waterUsed * FIRST_RATE;
        else
        {
            secWater = waterUsed - LOW_HCF;
            firstBill = FIRST_RATE * LOW_HCF;
            secondBill = secWater * LOW_RATE;
            billAmount = firstBill + secondBill;
        }
    }

    //Last Line Output
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<< "---\n";
    cout<< "The bill for "<< customerName << " is $" << billAmount << endl;
}





































