#include <bits/stdc++.h>
#include "../header/NumberTicket.h"
#include "../header/Bill.h"
NumberTicket::  NumberTicket(){
  first=0;
  last=0;    
}
NumberTicket::  ~NumberTicket(){
   delete [] num;
}
int NumberTicket:: getFirst(NumberTicket *num,int i)
{
    return num[i].first;
}
int NumberTicket:: getLast(NumberTicket *num,int i){
    return num[i].last;
}
void NumberTicket::setTicketID(int i,int j,int x)
{
    this->ticketID[i][j] = x;
}
int NumberTicket :: getTicketID(int i,int j)
{
    return this->ticketID[i][j];
}
void NumberTicket:: InputNumberTicket(NumberTicket *&num){
    ifstream fileNum("../database/NumberTicket.txt");
    num=new NumberTicket[15];
     char c;
     fileNum>>c;
     vector <string> dsach;
     string str1;
     while (getline(fileNum, str1, '-'))
     {
        dsach.push_back(str1);
     }
     int count=0;
     while (count<dsach.size())
     {
        num[nu].first=atol(dsach[count+1].c_str());
        num[nu].last=atol(dsach[count+2].c_str());
        nu++;
        count+=3;
     }
    fileNum.close();
}
