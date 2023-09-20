#include <bits/stdc++.h>
#include "LinkedList.cpp "
#include "../header/Bill.h"
#include "TicketPrice.cpp"
#include "InfoFlight.cpp"
#include "BookingData.cpp"
using namespace std;

fstream out;
Bill::Bill()
{

}
Bill::~Bill()
{
    delete [] employee;
}
void Bill ::PrintBill(Login *data, InfoFlight *info, Passenger psg, TicketPrice *t, NumberTicket *num, BookingData *b, int indexFlight)
{
    system("cls");
    box(40,3,50,6,11,1,FindFlight,0);
    t->mainTicketPrice(t,info);
    long long res = num->getFirst(num, indexFlight);
    int pivot = 0, First=0;
    int check = 0, tmpres = res;
    if (t->getOption() == 1)
    {
        First = 0;
        pivot = 69;
    }
    else if (t->getOption() == 2)
    {
        First = 70;
        pivot = 89;
    }
    else
    {
        First = 90;
        pivot = 100;
    }
    int tmpc=countticket,co=1,ktr=0;
    int tempCountTicket = countticket;
    while(tmpc>0)
    {
        ThuongGia[indexFlight] = 0;
        PhoThong[indexFlight] = 0;
        PhoThongDB[indexFlight] = 0;
        b->InputBookingData(b,info,info->getFlightChoose()-1);
        if(checkSeatClass == 0)
        {
            if(t->getGate()== 1)
            {
                if(PhoThong[indexFlight] + tempCountTicket > 70)
                {
                    system("cls");
                    box(40,3,50,6,11,1,Notify,0);
                    textcolor(4);
                    cout<<"\n";
                    cout<<le<<"Hạng phổ thông còn "<<70-PhoThong[indexFlight]<<" vé"<<endl;
                    cout <<le<< "Số lượng còn lại không đủ\n";
                    textcolor(3);
                    cout<<"\n"<<le;
                    return;
                }
            }
            else if(t->getGate()== 2)
            {
                if(PhoThongDB[indexFlight] + tempCountTicket > 20)
                {
                    system("cls");
                    box(40,3,50,6,11,1,Notify,0);
                    textcolor(4);
                    cout<<"\n";
                    cout<<le<<"Hạng phổ thông đặc biệt còn "<<20-PhoThongDB[indexFlight]<<" vé"<<endl;
                    cout <<le<< "Số lượng còn lại không đủ\n";
                    textcolor(3);
                    cout<<"\n"<<le;
                    return;
                }
            }
            else if(t->getGate()== 3)
            {
                if(ThuongGia[indexFlight] + tempCountTicket  > 10)
                {
                    system("cls");
                    box(40,3,50,6,11,1,Notify,0);
                    textcolor(4);
                    cout<<"\n";
                    cout<<le<<"Hạng thương gia còn "<<10-ThuongGia[indexFlight]<<" vé"<<endl;
                    cout <<le<< "Số lượng còn lại không đủ\n";
                    textcolor(3);
                    cout<<"\n"<<le;
                    return;
                }
            }
        }
        if (ktr==0)
        for (int j = First; j < pivot; j++)
        {
        res += j;
 
            for (int i = 0; i < 100; i++)
            {
                if (b->get_ticketid(b, i) == -1)
                {
                    check = 0;
                    break;
                }
                else if (res == b->get_ticketid(b, i))
                {
                    check++;
                    break;
                }
            }
        if (check == 0)
        {
            pos = j;
            break;
        }
        else
            res = tmpres;
    } 
    else {
        pos++;
        res++;
    }
    ktr++;
    posID = pos;
    system("cls");
    num->setTicketID(indexFlight, pos, res);
    box(40,3,50,6,11,1,inputPassengerInfo,0);
    textcolor(7);
    cout<<"\n";
    
    cout<<le<<"Nhập thông tin của hành khách thứ "<<co<<endl;
    tempCountTicket --;
    tmpc--;co++;
    textcolor(3);
    psg.InputPassengerInfo();
    psg.SavePassengerInfo(info,num);
    gotoXY(50,27);
    system("pause");
    system("cls");
}
    out.open("../database/Transaction.txt", ios::out | ios::app);
    system("cls");
    setIdEmployee(posEmployee);
    srand(time(NULL));
    ProcessBill();
    time_t hientai = time(0);
    char *dt = ctime(&hientai);
    tm *ltm = localtime(&hientai);
    cout<< "Ngày giao dịch: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    cout<<"Vào lúc "<< 1 + ltm->tm_hour << ":"<< 1 + ltm->tm_min << ":"<<1 + ltm->tm_sec << endl<<endl;
    cout << "Thông Tin Giao Dịch \n\n";
    cout << "Nhân viên\t\t\t"
         << "Mã giao dịch\t\t\t" << endl;
    cout <<setw(34)<<left<< employee[30 - getIdEmployee()].nameEmployee;

    out<<"Ngày giao dịch: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
    out<<"Vào lúc "<< 1 + ltm->tm_hour << ":"<< 1 + ltm->tm_min << ":"<<1 + ltm->tm_sec << endl<<endl;
    out << "Thông Tin Giao Dịch \n\n";

    out << "Nhân viên\t\t\t"
        << "Mã giao dịch\t\t\t" << endl;
    out <<setw(22)<<left <<employee[30 - getIdEmployee()].nameEmployee;

    string tmp = "qwertyuiopasdfghjklzxcvbnm0123456789";
    int cnt = 0;
    string MaDon = "";
    while (cnt <= 10)
    {
        MaDon += tmp[rand() % (tmp.length() + 1)];
        cnt++;
    }
    cout << MaDon << "\t\t\t" << endl;
    out << MaDon << "\t\t\t" << endl;
    cout << "-------------------------------------------------------------------------\n";
    cout << "Chi Tiết Thanh Toán \n\n";
    cout << "Khởi hành: " << info->getDeparture(info, indexFlight) << endl;
    cout << "Đến: " << info->getDestination(info, indexFlight) << endl;
    cout << "Ngày: " << info->getDate(info, indexFlight) << endl
         << endl;

    cout << "Số vé\t\t\t"
         << "Mã hành trình\t\t\t"
         << "Số lượng\t\t\t"
         << "Đơn giá\t\t\t"
         << "Loại tiền" << endl;

    out << "-------------------------------------------------------------------------\n";
    out << "Chi Tiết Thanh Toán \n\n";
    out << "Khởi hành: " << info->getDeparture(info, indexFlight) << endl;
    out << "Đến: " << info->getDestination(info, indexFlight) << endl;
    out << "Ngày: " << info->getDate(info, indexFlight) << endl
        << endl;
    out << "Số vé\t\t\t"
        << "Mã hành trình\t\t\t"
        << "Số lượng\t\t\t"
        << "Đơn giá\t\t\t"
        << "Loại tiền" << endl;

        int tmpc2=countticket;
    while(tmpc2>0)
    {
    cout << num->getTicketID(indexFlight, pos-tmpc2+1) << "\t\t\t";
    cout << num->getFlyingcode(info, indexFlight) << "\t\t\t\t";
    cout << 1 << "\t\t\t\t" << t->getTicketprice(t, info) << "\t\t\t";
    cout << "VND\n";

    out <<setw(16)<<left<< num->getTicketID(indexFlight, pos-tmpc2+1);
    out <<setw(24)<<left<< num->getFlyingcode(info, indexFlight);
    out <<setw(20)<<left<< 1;
    out<<setw(16)<< t->getTicketprice(t, info);
    out <<setw(20)<<left<< "VND\n";
    out << endl;
    tmpc2--;
}

    cout << endl;
    cout<<"Tổng tiền:    \t\t\t"<<(countticket)*t->getTicketprice(t,info)<<"VND\n";
    out<<"Tổng tiền:        \t\t\t"<<(countticket)*t->getTicketprice(t,info)<<"VND\n";
    cout << "Trạng thái thanh toán:\t\t Đã thanh toán\n\n";
    out << "Trạng thái thanh toán:\t\t Đã thanh toán\n\n";
    cout << "Chi tiết giao dịch đã được lưu vào file Transaction.txt\n";
 cout << "______________________________________________________________________" << endl;
     out << "______________________________________________________________________\n" << endl;
}
void Bill::ProcessBill()
{
    int i = 0;
    ifstream file("../database/Employee.txt");
    employee = new Bill[30];
    while (!file.eof())
    {
        string tmp;
        getline(file, tmp);
        employee[i].nameEmployee += tmp;
        i++;
    }
    file.close();
}

 
