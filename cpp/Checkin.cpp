#include "bits/stdc++.h"
#include "../header/Checkin.h"
#include "../header/lib.h"
using namespace std;
int v = 0;

ifstream InputSummary;
Checkin:: Checkin(){
    this->CheckinRow=0;
    this->CheckinCol=0;
    this->CheckinFlight=0;
}
Checkin:: ~Checkin(){
    delete [] c;
}
void Checkin::SaveCheckinMap(InfoFlight *info, int v)
{
    string fileName = "Seat" + info->getFlyingcode(info, v) + ".txt";
    string filePath = "../database/dataSeat/" + fileName;
    char tmp_filePath[filePath.length() + 1];
    strcpy(tmp_filePath, filePath.c_str());
    fstream CheckMap;
    CheckMap.open(tmp_filePath, ios::out | ios::app);
    CheckMap << "-" << (int)tempSeatRow - 65;
    CheckMap << "-" << tempSeatCol;
    CheckMap << endl;
    CheckMap.close();
}
int Checkin::getCheckinCol(Checkin *c, int i)
{
    return c[i].CheckinCol;
}
int Checkin::getCheckinRow(Checkin *c, int i)
{
    return c[i].CheckinRow;
}
int Checkin::getCheckinArray(Checkin *c, int i, int j)
{
    return c[i].CheckinArray[j];
}
void Checkin::setCheckinCol(Checkin *c, int i, int x)
{
    c[i].CheckinCol = x;
}
void Checkin::setCheckinRow(Checkin *c, int i, int x)
{
    c[i].CheckinRow = x;
}
void Checkin::setCheckinArray(Checkin *&c, int i, int j, int x)
{
    c[i].CheckinArray[j] = x;
}
void Checkin::InputCheckinData(Checkin *&CheckinPtr, InfoFlight *info, int v)
{
    string fileName = "Seat" + info->getFlyingcode(info, v) + ".txt";
    string filePath = "../database/dataSeat/" + fileName;
    char tmp_filePath[filePath.length() + 1];
    strcpy(tmp_filePath, filePath.c_str());
    ifstream fileCheckin(tmp_filePath);
    CheckinPtr = new Checkin[15];
    char c;
    fileCheckin >> c;
    vector<string> ds;
    string str;
    while (getline(fileCheckin, str, '-'))
    {
        ds.push_back(str);
    }
    int count = 0, i = 0;
    for (int w = 1; w <= 100; w++)
    {
        setCheckinArray(CheckinPtr, v, w, 0);
    }
    while (count < ds.size())
    {
        setCheckinArray(CheckinPtr, v, atol(ds[count].c_str()) * 10 + atol(ds[count + 1].c_str()), 1);
        i++;
        count += 2;
    }
    fileCheckin.close();
}
void Checkin ::CheckinFunc(Checkin *c, NumberTicket *num, InfoFlight *info, Passenger psg, TicketPrice *t, BookingData *b)
{
    c = new Checkin[15];
    srand(time(NULL));
    int check = -1;
    box(50, 12, 50, 2, 11, 1, checkinFunction, 0);
    gotoXY(77, 13);
    long long tmpTicketCode;
    cin >> tmpTicketCode;
    long tb[15];
    for (int i = 0; i < 15; i++)
    {
        tb[i] = abs((((num->getFirst(num, i) + num->getLast(num, i))) / 2 - tmpTicketCode));
    }
    long min = tb[0];
    v=0;
    for (int i = 1; i < 15; i++)
    {
        if (min > tb[i])

        {
            min = tb[i];
            v = i;
        }
    }

    b->InputBookingData(b, info, v);
    int m = 0;
    string fileName = "Checkin" + info->getFlyingcode(info, v) + ".txt";
    string filePath = "../database/dataCheckin/" + fileName;
    char tmp_filePath[filePath.length() + 1];
    strcpy(tmp_filePath, filePath.c_str());

    fstream filemark(tmp_filePath, ios::in);
    while (!filemark.eof())
    {
        string str;
        getline(filemark, str);
        a[m] = atoi(str.c_str());
        m++;
    }
    filemark.close();
    int Check = 0;
    for (int i = 0; i < m; i++)
    {
        if (tmpTicketCode == a[i])
        {
            Check = 1;
            break;
        }
    }
    if (Check == 1)
    {
        textcolor(4);
        gotoXY(50, 16); 
        cout << "Số vé đã được Check In trước đó !\n";
        textcolor(3);
    }
    else
    {
        for (int i = 0; i < 100; i++)
        {
            if (b->get_ticketid(b, i) == -1)
            {
                check = 0;
                break;
            }
            if (tmpTicketCode == b->get_ticketid(b, i))
            {
                InputCheckinData(c, info, v);
                check = 1;
                gotoXY(50, 16);
                textcolor(6);
                cout << "Thông tin khách hàng";

                textcolor(3);
                box(50, 18, 50, 2, 11, 1, PassengerNameInput, 0);
                gotoXY(63, 19);
                textcolor(6);
                cout << b->GetName(b, i);
                textcolor(3);

                box(50, 21, 50, 2, 11, 1, PassengerDateOfBirthInput, 0);
                gotoXY(63, 22);
                textcolor(6);
                cout << b->GetDateofbirth(b, i);
                textcolor(3);

                box(50, 24, 50, 2, 11, 1, PassengerSexInput, 0);
                gotoXY(63, 25);
                textcolor(6);
                cout << b->GetSex(b, i);
                textcolor(3);

                box(50, 27, 50, 2, 11, 1, PassengerIDCardInput, 0);
                gotoXY(74, 28);

                textcolor(6);
                cout << b->GetIDcard(b, i);
                textcolor(3);

                box(50, 30, 50, 2, 11, 1, PassengerPhoneNumberInput, 0);
                gotoXY(67, 31);
                textcolor(6); 
                cout << b->GetPhonenumber(b, i);
                cout << endl;
                textcolor(3);
                if (b->get_ticketid(b, i) % 1000 >= 91 && b->get_ticketid(b, i) % 1000 <= 100)
                {
                    row = 65;
                    maxrow = 65;
                    t->setGate(1);
                }
                else if (b->get_ticketid(b, i) % 1000 >= 71 && b->get_ticketid(b, i) % 1000 <= 90)
                {
                    row = 66;
                    maxrow = 67;
                    t->setGate(2);
                }
                else if (b->get_ticketid(b, i) % 1000 >= 1 && b->get_ticketid(b, i) % 1000 <= 70)
                {
                    row = 68;
                    maxrow = 74;
                    t->setGate(3);
                }
                InputSeat(c,info);

                setCheckinArray(c, v, ((int)tempSeatRow - 65) * 10 + tempSeatCol, 1);
                fstream filem(tmp_filePath, ios::out | ios::app);
                filem << b->get_ticketid(b, i) << endl;
                filem.close();
                SaveCheckinMap(info, v);
                //info->setCheckinPassenger(info, i, cntCheckinPassenger[i]);
                box(5, 3, 120, 17, 11, 1, Null, 0);
                gotoXY(10, 7);
                cout << "Hãng chuyên chở/Carrier : ITF AIRLINE";
                gotoXY(10, 10);
                string tmpName = b->GetName(b, i);
                Upcase(tmpName);
                cout << "Họ và tên/Name : " << Upcase(b->GetName(b, i));
                gotoXY(50, 10);
                cout << "Chuyến bay/Flight : " << info->getFlyingcode(info, v);
                gotoXY(80, 10);
                cout << "Ngày/Date: " << info->getDate(info, v);
                gotoXY(10, 13);
                cout << "Nơi đi/From : " << info->getDeparture(info, v);
                gotoXY(50, 13);
                cout << "Cửa/Gate : " << t->getGate();
                gotoXY(80, 13);
                cout << "Giờ lên máy bay/BoardingTime : " << info->getFlyingtime(info, v);
                gotoXY(10, 16);
                cout << "Nơi đến/To : " << info->getDestination(info, v);
                gotoXY(50, 16);
                cout << "Ghế bay/Seat : " << char(tempSeatRow) << "-" << tempSeatCol;
                cout << endl
                     << endl
                     << endl
                     << endl
                     << endl
                     << endl;
                fstream outTicket("../database/Ticket.txt", ios::out | ios::app);
                outTicket << "___________________________________________________________________________________________________________________________________________\n\n";
                outTicket << "\tHãng chuyên chở/Carrier : ITF AIRLINE\n\n\n";
                outTicket << "\tHọ và tên/Name :" << setw(30) << left << Upcase(b->GetName(b, i));
                outTicket << "\tChuyến bay/Flight : " << setw(20) << left << info->getFlyingcode(info, v);
                outTicket << "\tNgày/Date: " << setw(30) << left << info->getDate(info, v) << "\n\n";
                outTicket << "\n\tNơi đi/From : " << setw(30) << left << info->getDeparture(info, v);
                outTicket << "\tCửa/Gate : " << setw(30) << left << t->getGate();
                outTicket << "\tGiờ lên máy bay/BoardingTime : " << info->getFlyingtime(info, v) << "\n\n\n"; //<< setw(30) << left;
                outTicket << "\tNơi đến/To : " << setw(30) << left << info->getDestination(info, v);
                outTicket << "\t\tGhế bay/Seat : " << char(tempSeatRow) << "-" << tempSeatCol << setw(30) << left << "\n";
                outTicket << "\n__________________________________________________________________________________________________________________________________________\n\n";
                outTicket << "-------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                outTicket.close();
                break;
            }
            else
            {
                check = 0;
            }
        }
    }
    if (check == 0)
    {
        textcolor(4);
        gotoXY(65, 16);
        cout << "Số vé không hợp lệ\n";
        textcolor(3);
    }
}
void Checkin::CheckinMap(Checkin *c, InfoFlight *info)
{
    cout << le << "=====================================================================================================================\n";
    cout << le << "|                                                                                                                   |" << endl
         << le << "|                                                                                                                   |" << endl;
    cout << le << "|\t\t\t\t\t\t\t"
         << "  CHECKIN MAP "
         << "\t\t\t\t\t\t    |" << endl
         << le << "|                                                                                                                   |\n";
    cout << le << "|\tKhởi hành: " << info->getDeparture(info, v);
    gotoXY(111, 5);
    cout << "                                             |\n";
    cout << le << "|\tĐến: " << info->getDestination(info, v);
    gotoXY(111, 6);
    cout << "                                             |\n";
    cout << le << "|\tNgày: " << info->getDate(info, v) << "\t\t\t\t\t\t\t\t\t\t\t    |";
    cout << endl
         << le << "|                                                                                                                   |" << endl;
    for (int i = 1; i <= 10; i++)
    {
        if (i == 1)
            cout << le << "|            \t  " << i << "       ";
        if (i == 5)
            cout << i << "                       ";
        if (i != 5 && i != 1)
            cout << i << "       ";
    }
    cout << " |";
    cout << endl;
    int t = 65;
    // InputCheckinData(c,info);
    for (int j = 1; j <= 100; j++)
    {
        if (j % 10 == 1)
        {
            cout << le << "|"
                 << "\t" << (char)t << " : ";
            t++;
        }
        if (getCheckinArray(c, v, j) == 1)
        {
            if (j % 10 == 0)
                cout << "\t[ x ]\t    |";
            else
                cout << "\t[ x ]";
        }
        else
        {
            if (j % 10 == 0)
                cout << "\t[   ]\t    |";
            else
                cout << "\t[   ]";
        }
        if (j % 10 == 5)
            cout << "\t\t";
        else if (j % 10 == 0)
            cout << endl;
    }
    cout << le << "|                                                                                                                   |" << endl;
    cout << le << "=====================================================================================================================\n";
    textcolor(4);
    cout << le << "--NOTE--\n"
         << le << "[   ] : Ghế trống.\n"
         << le << "[ x ] : Ghế đã được Checkin.\n\n";
    textcolor(3);
}
void Checkin:: InputSeat(Checkin *c, InfoFlight *info)
{
    while(true)
    {
        gotoXY(50, 40);
        system("pause");
        system("cls");
        textcolor(3);
        CheckinMap(c, info);
        gotoXY(40, 26);
        textcolor(7);
        
        if (row==65){
            cout<<"Hạng ghế của khách hàng là Thương gia";
            gotoXY(40,27);
            cout<<"Vui lòng chọn dãy ghế A";
        }
        else if (row==66)
        {
            cout<<"Hạng ghế của khách hàng là Phổ thông đặc biệt";
            gotoXY(40,27);
            cout<<"Vui lòng chọn dãy ghế B ,C";
        }
        else if (row==68)
        {
            cout<<"Hạng ghế của khách hàng là Phổ thông";
            gotoXY(40,27);
            cout<<"Vui lòng chọn dãy ghế D, E, F, G, H, I, J, K";
        }
        box(50, 32, 35, 2, 11, 1, Null, 0);
        gotoXY(52, 33);
        textcolor(3);
        cout << "Chọn ghế mà bạn muốn ngồi :  ";
        tempSeatRow = getch();
        if ((int)tempSeatRow >= 97 && (int)tempSeatRow < 107)
        tempSeatRow -= 32;
        if (((int)tempSeatRow >= 65 && (int)tempSeatRow < 75))
        {
            if ((int)tempSeatRow > maxrow || (int)tempSeatRow < row)
            {
                gotoXY(50, 37);
                textcolor(4);
                cout << "Dãy ghế này không thuộc về hạng ghế của bạn\n";
                continue;
            }
            gotoXY(80, 33);
            cout << char(tempSeatRow);
            cout << "-";
        }
        else
        {
            gotoXY(50, 37);
            textcolor(12);
            cout << "Dãy ghế mà bạn vừa nhập không hợp lệ!\n";
            textcolor(3);
            continue;
        }
        gotoXY(82, 33);
        cin >> tempSeatCol;
        if (tempSeatCol < 0 || tempSeatCol > 10)
        {
            gotoXY(50, 37);
            textcolor(4);
            cout << "Vị trí ghế không hợp lệ!\n";
            textcolor(3);
            continue;
        }
        // InputCheckinData(c,info,v);
        if (getCheckinArray(c, v, ((int)tempSeatRow - 65) * 10 + tempSeatCol) == 1)
        {
            textcolor(4);
            gotoXY(50, 37);
            cout << "Vị trí này đã được đặt rồi!\n";
            textcolor(3);
            continue;
        }
        gotoXY(50, 37);
        textcolor(2);
        cout << "Checkin thành công!\n";
        textcolor(3);
        gotoXY(50, 38);
        cout << "Chỗ ngồi của bạn là : " << char(tempSeatRow) << "-" << tempSeatCol << endl;
        cout << endl
            << endl;
        gotoXY(50, 40);
        system("pause");
        system("cls");
        break;
    }
}