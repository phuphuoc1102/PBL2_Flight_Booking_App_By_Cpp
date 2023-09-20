#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
#include "Bill.cpp"
#include "Checkin.cpp"
#include "../header/BookingData.h"
#include "Summary.cpp"
using namespace std;
void process();
void setInputCheckArr();
void setInputCheckArr()
{
    checkArr = new int *[11];
    for (int i = 1; i <= 11; i++)
            checkArr[i] = new int[11];
}
void process()
{
    system("chcp 65001");
    system("cls");
    textcolor(3);
    Login *user;
    Bill a; 
    Passenger p;
    TicketPrice *t;
    LinkedList listUser(user);
    InfoFlight *info;
    NumberTicket *num;
    Checkin *c;
    BookingData *b;
    Summary *sum;
    box(40,3,80,15,11,1,Null,0);
    gotoXY(65,4);
    cout << "ĐỒ ÁN LẬP TRÌNH TÍNH TOÁN";
    gotoXY(72,6);
    cout << "Đề tài 706";
    gotoXY(55,8);
    textcolor(10);
    cout << "XÂY DỰNG ỨNG DỤNG QUẢN LÍ ĐẶT VÉ VÀ CHECKIN ";
    gotoXY(58,9);
    cout << "   CỦA HÃNG HÀNG KHÔNG ITF AIRLINE";
    gotoXY(50,11);
    textcolor(3);
    cout << "Giảng viên hướng dẫn : ";
    textcolor(7);
    cout << "GVC.ThS. TRẦN HỒ THỦY TIÊN";
    gotoXY(50,13);
    textcolor(3);
    cout << "Sinh viên thực hiện : ";
    textcolor(7);
    gotoXY(50,14);
    cout << "CHÂU HOÀNG PHI";
    textcolor(7);
    cout << "\t\tLớp : 21TCLC_KHDL\tNhóm : 21Nh15A";
    textcolor(7);
    gotoXY(50,15);
    cout << "PHẠM PHÚ PHƯỚC";
    textcolor(7);
    cout << "\t\tLớp : 21TCLC_KHDL\tNhóm : 21Nh15A";
    gotoXY(55,20);
    system("pause");
    LoginToSystem();
    system("cls"); 
    int **checkArr;
    info->InputDataFlight(info);
    t-> inputTicketPrice(t);
    num->InputNumberTicket(num);
    for(int i = 0 ; i <= 10 ; i++)
    {
        for(int j = 0 ; j <= 100 ; j++)
        {
            checkinArr[i][j] = 0;
            CheckArr[i][j] = 0;
        }
    }
    
    for(int i = 0 ; i < 10 ; i++)
    {
        amountOfTicket[i] = 0;
        tmpTotalMoney[i] = 0;
        cntCheckinPassenger[i] = 0; 
    }
                    
    system("cls");
    if(dn == 1)
    {
        while(true)
        {
            box(50,3,50,6,11,1,Title,0);
            menu(Option,5);
            
            switch(choose)
            {
                case 1 :      
                    info -> mainInputDataInfoFlight(info);
                    a.PrintBill(user,info,p,t,num,b,info->getFlightChoose() -  1);
                    cout<<setw(26)<<right;
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    box(50,3,50,6,11,1,checkin,0);
                    c->CheckinFunc(c,num,info,p,t,b);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    box(50,3,50,6,11,1,SummaryFunc,0);
                    sum->SummaryFunc(sum,info,c,num,t);
                    cout << endl << endl << endl;
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    tmp1 = 0;
                    indexPassword = 0;
                    indexUser = 0;
                    LoginToSystem(); 
                    system("cls");
                    break;
                case 5:    
                    system("cls");
                    cout << "Cảm ơn!\n";
                    exit(0);
            }
        }
    }
    out.close();
    cout << endl;
    
}