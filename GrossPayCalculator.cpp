#include <iostream>
#include <string>

using namespace std;

string incorrectEmpType(string employment_type)
{
   string type;

   if(employment_type != "F" && employment_type != "P")
   {
      cout<<"Incorrect Employment Type! F = Full-time, P = Part-time: "<<endl;
      cin>>type;

      type = incorrectEmpType(type);

      return type;
   }

   return employment_type;
}

string textRequired(string ans, string text)
{
   string value;

   if(!ans.length())
   {
      cout<<text<<endl;
      getline(cin, value);
      value = textRequired(value, text);
      return value;
   }

   return ans;
}

void displayResult(string name, double rate, double hours, double ot)
{
   double basic_pay = rate * hours;
   double ot_pay = ot * (rate * 1.25);
   double gross_pay = basic_pay + ot_pay;

   cout<<"\n------------------------------------"<<endl;
   cout<<"\nEmployee Name: "<<name<<endl;
   cout<<"\nBasic Pay: "<<basic_pay<<endl;
   cout<<"\nOvertime Pay: "<<ot_pay<<endl;
   cout<<"\n------------------------------------"<<endl;
   cout<<"\nGross Pay: "<<gross_pay<<endl;
}

void displayResult(string name, double salary)
{
   cout<<"\n------------------------------------"<<endl;
   cout<<"\nEmployee Name: "<<name<<endl;
   cout<<"\nMonthly Salary: "<<salary<<endl;
}

int main()
{
   string employee_name, employment_type, try_again;
   double rate = 0.0, hours = 0, ot = 0.0, monthly_pay = 0.0;

   cout<<"Please input the correct data for Gross Pay computation.\n"<<endl;

   cout<<"Employee Name:"<<endl;
   getline(cin, employee_name);
   employee_name = textRequired(employee_name, "Input Employee Name:");

   cout<<"Employment Type? F = Full-time, P = Part-time: "<<endl;
   getline(cin, employment_type);
   employment_type = incorrectEmpType(employment_type);

   if(employment_type == "P")
   {
      cout<<"Rate per hour: "<<endl;
      cin>>rate;

      cout<<"Hours worked: "<<endl;
      cin>>hours;

      cout<<"Overtime hours: "<<endl;
      cin>>ot;

      displayResult(employee_name, rate, hours, ot);
   }

   if(employment_type == "F")
   {
      cout<<"Monthly salary: "<<endl;
      cin>>monthly_pay;

      displayResult(employee_name, monthly_pay);
   }
}