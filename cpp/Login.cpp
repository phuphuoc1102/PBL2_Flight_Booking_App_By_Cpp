#include <bits/stdc++.h>
#include <string.h>
#include "../header/Login.h"
using namespace std;
Login::Login()
{
    username = "";
    password = "";
    numOfEmployee = 0;
    next = NULL;
}
Login::~Login()
{
    delete [] next;
}
Login::Login(Login *a)
{
    username = a->getUsername();
    password = a->getPassword();
    numOfEmployee = a->getNumOfEmployee(); 	
}
string Login:: getUsername()
{
    return this -> username;
}
void Login:: setNumOfEmployee(int x)
{
    this -> numOfEmployee = x;
}
Login :: Login(string username, string password)
{
    this->username = username;
    this -> password = password;
    this -> setNumOfEmployee(getNumOfEmployee() + 1);
    this->next = NULL;
}
string Login:: getPassword()
{
    return this -> password;
}
int Login::getNumOfEmployee()
{
    return this -> numOfEmployee;
}
int Login::getIdEmployee()
{
    return this -> IdEmployee;
}
void Login::setIdEmployee(int x)
{
    IdEmployee = x;
}

