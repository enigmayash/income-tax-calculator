#include <iostream>
using namespace std;

#include <string.h>
#include <stdio.h>
double endsal = 0;
double totalsal=0 ;


// base class
class oldregime
{
public:
  char name[65], address[100], occup[90];
  int id;
  void in()
  {
    cout << " Enter id" << endl;
    cin >> id;
    cout << " Enter name" << endl;
    cin >> name;
    cout << " Enter address" << endl;
    cin >> address;
    cout << " Enter occupation" << endl;
    cin >> occup;
  }
  void show()
  {
    cout << "ID: " << id << endl;
    cout << "NAME: " << name << endl;
    cout << "ADDRESS: " << address << endl;
  }

}; // end of base class

class salary : public oldregime
{
public: 
  int c;
  double msal, othersal;
  
  void getsal()

  {
    in();
    cout << " Enter the amount main source of income " << endl;
    cin >> msal;
    cout << " Do you have other sourcees of income" << endl;
    cout << "If yes enter 1 else 0" << endl;
    cin >> c;
    if (c == 1)
    {
      cout << "Enter amount of income from other sources" << endl;
      cin >> othersal;
    }
    else
    {
      othersal = 0;
    }
    totalsal = msal + othersal;
    cout<<fixed;
    
    cout << "Gross income in rupees: " << totalsal << endl;
  }
  void output()
  {
    show();
  }

}; // end of salary class

class deduct 
{
public:
  void deduction()
  {
    double ded = 0, pfc, tf, lic, ssy, ppf;
    cout << "DEDUCTIONS" << endl<<endl;
    cout<<"Only 1,50,000 rupees of deductions is allowed by the government of India, hence only amount of 1,50,000 rupees will be deducted if it over the limit"<<endl;
    cout << "Provident fund contribution\nProvident fund contribution is the amount deposited by employer and employee under the retirement benefit scheme\nEnter if any, else enter 0" << endl;
    cin >> pfc;
    cout << "Tuition fees\nSchool fees or college fees applicable only for a maximum of 2 children\nEnter if any, else enter 0" << endl;
    cin >> tf;
    cout << "Enter Life insurance policies if any, else enter 0" << endl;
    cin >> lic;
    cout << "If you are under sukanya samridhi yojana\nApplicable to parents who have given birth to girl child after the year 2015\nEnter amount, else enter 0" << endl;
    cin >> ssy;
    cout << "Public provident fund\nPublic provident fund is a long term investment option\nEnter if any, else enter 0" << endl;
    cin >> ppf;
    ded = pfc + ppf + tf + lic + ssy;
    cout<<"Total amount of dedeuctions calculated in rupees: "<<ded<<endl;
    if (ded > 150000)
    {
      
      ded = 150000;
    }
    endsal = totalsal - ded;
    cout<<fixed;
  cout<<"End salary after deduction: "<<endsal<<endl;
    
  }
}; // end of class deduct

//Individual methods
double age35()
{
  double tax;
  if (endsal <250000)
  {
    tax = 0;
  }
  else if (endsal > 250000 && endsal <= 500000)
  {
    tax = endsal * 0.05;
  }
  else if (endsal > 500000 && endsal <= 1000000)
  {
    tax = 250000 * 0.05 + (endsal - 500000) * 0.2;
  }
  else
  {
    tax = 250000 * 0.05 + 500000 * 0.2 + (endsal - 1000000) * 0.3;
  }
  return tax;
}
double age60()
{
  double tax;
  if (endsal <300000)
  {
    tax = 0;
  }
  else if (endsal > 300000 && endsal <= 500000)
  {
    tax = endsal * 0.05;
  }
  else if (endsal > 500000 && endsal <= 1000000)
  {
    tax= 250000 * 0.05 + (endsal - 500000) * 0.2;
  }
  else
  {
    tax = (250000 * 0.05) + 500000 * 0.2 + (endsal - 1000000) * 0.3;
  }
  
  return tax;
}
double age80()
{
  double tax;
  if (endsal <= 500000)
  {
    tax = 0;
  }
  else if (endsal > 500000 && endsal <= 1000000)
  {
    tax = endsal * 0.2;
  }

  else
  {
    tax = 500000 * 0.2 + (endsal - 500000) * 0.3;
  }
  return tax;
}

//Main method
int main()
{
  double temp;
  deduct d;
  salary s;
  double tax;
  int choice;
  s.getsal();
  d.deduction();
  cout<<"Choose your age range:";
  cout << "1.If you are less than 60 2.If you are above 60 3.If you are above 80 4.exit " << endl;
  cout << " Enter choice" << endl;
  cin >> choice;

  switch (choice)
  {
  case 1:
    tax = age35();

    break;
  case 2:
    tax = age60();
    break;
  case 3:
    tax = age80();
    break;
  case 4:
    exit(0);
    break;
  default:
    cout << " Invalid choice " << endl;
  }
 
  s.output();
  cout<<fixed;

  cout << "Tax payable in rupees: " << tax << endl;
 
  return 0;
}
//End of main method
//End of program
