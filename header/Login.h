#ifndef Login_h
#include<string>
using namespace std;
#define Login_h
class Login
{
    private:
        string username, password;
        int numOfEmployee,IdEmployee;
    public:
        Login *next;
        Login();
        ~Login();
        Login(Login *a);
        Login(string username, string password);
        string getUsername();
        string getPassword();
        int getNumOfEmployee();
        int getIdEmployee();
        void setNumOfEmployee(int x);
        void setIdEmployee(int x);
        

};

#endif