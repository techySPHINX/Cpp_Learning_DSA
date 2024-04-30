#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Employee
{
    int id;
    static int count; // static variable is bydefault zero initialized

public:
    void setData(void)
    {
        cout << "Enter the id:" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of the employee is " << id << "and this is Employee no: " << count << endl;
    }

    static void getCount(void)
    {
        cout << "The value of count is: " << count << endl;
    }
};

int Employee::count = 1000; // static variable need to be shared and default value is 0

int main()
{
    Employee jagan, Harish, Rohan;
    // jagan.id = 1;
    // jagan.count =1; //can not so thsi as id and count are private

    jagan.setData();
    jagan.getData();
    Employee::getCount();

    Harish.setData();
    Harish.getData();
    Employee::getCount();

    Rohan.setData();
    Rohan.getData();
    Employee::getCount();

    return 0;
}
