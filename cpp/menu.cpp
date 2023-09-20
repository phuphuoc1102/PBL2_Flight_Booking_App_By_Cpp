#include <bits/stdc++.h>
#include "../header/mylib.h"
#include <conio.h>
#include <string.h>
using namespace std;
int row, col, maxrow, maxcol;
int xx = 60, yy = 10, choose = 0;
int idx = 1;
int id = 0;
int amountOfTicket[10] = {};
int cntCheckinPassenger[10] = {};
int position[10][100] = {};
int checkSeatClass = 0;
int posID = 0;
void box(int xx, int yy, int w, int h, int t_color, int b_color, char content[][200], int idx);
void boxes(int xx, int yy, int w, int h, int t_color, int b_color, char content[][200], int count);
void menu(char content[][200], int count);
void thanh_sang(int xx, int yy, int w, int h, int b_color, char content[][200], int idx);
int arrChoose[10];
long long tmpTotalMoney[10] = {};
int checkProcess = 0;
int cnt = 0, countticket = 0;
int countLoginToSystem = 0;
int full = 0;
int sumOfTicket[16] = {}, ThuongGia[16] ={}, PhoThong[16] = {}, PhoThongDB[16] = {};
char tempSeatRow;
int tempSeatCol;
char Title[][200] = {
    "\n\n\t\t\t\t\t\t\t\t     ITF Airlines"};
char Null[][200] = {""};
char Notify[][200] = {
    "\n\n\t\t\t\t\t\t\t     THÔNG BÁO !!"};
char FindFlight[][200] = {
    "\n\n\t\t\t\t\t\t\t     TÌM CHUYẾN BAY"};
char SummaryFunc[][200] = {
    "\n\n\t\t\t\t\t\t\t TỔNG KẾT DOANH THU"};
char CheckinSuccessFully[][200] = {
    "\n\n\t\t\t\t\t\t\t CHECKIN THÀNH CÔNG"};
char checkin[][200] = {
    "\n\n\t\t\t\t\t\t\t\t        CHECKIN"};
char Cash[][200] = {
    "\n\n\t\t\t\t\t\t\t     THANH TOÁN "};

char Book[][200] = {
    "\n\n\t\t\t\t\t\t\t\t\t\t\t ĐẶT VÉ"};
char TicketOption[][200] =
    {"Hạng phổ thông",
     "Hạng phổ thông đặc biệt",
     "Hạng thương gia"};
char Option[][200] = {
    "\t  Đặt vé",
    "\t  Checkin",
    "\t  Tổng kết",
    "\t  Đăng xuất",
    "\t  Thoát"};
char Options[][200] = {
    "Thử lại.",
    "Thoát."};
char inputPassengerInfo[][200] =
    {
        "\n\n\t\t\t\t\t\t     NHẬP THÔNG TIN HÀNH KHÁCH"};
char PassengerInfo[][200] =
    {
        "\n\n\t\t\t\t\t        \tTHÔNG TIN HÀNH KHÁCH"};
char PassengerNameInput[][200] =
    {
        "Họ và tên : "};
char PassengerDateOfBirthInput[][200] =
    {
        "Ngày sinh : "};
char Day[][200] =
    {
        "Ngày (dd) : "};
char Month[][200] =
    {
        "Tháng (mm) : "};
char Year[][200] =
    {
        "Năm (yyyy) : "};
char PassengerSexInput[][200] =
    {
        "Giới tính : "};
char PassengerIDCardInput[][200] =
    {
        "Số căn cước công dân : "};
char PassengerPhoneNumberInput[][200] =
    {
        "Số điện thoại : "};
char Answer[][200] =
    {
        "TRẢ LỜI : "};
char Count[][200] =
    {
        "SỐ LƯỢNG : "};
char checkinFunction[][200] =
    {
        "Nhập mã số vé của bạn : "};
char SummaryChar[][200] =
    {
        "  Mã Hành Trình  |  Tổng số lượng vé  |  Số vé đã bán  |  Số vé chưa bán  |  Số vé đã checkin  |  Số vé chưa checkin  |  Tổng doanh thu  "};
string le = "\t\t\t\t\t";
void print(int idx, char content[][200])
{
    cout << content[idx];
}
int k = 0;
int **checkArr;
int tmpidx = 0, pol = 0;
int nu = 0;
int d, m, y;
int n = 0;
int a[3], b[3];
string dkh, dd, nkh;
int in = 0, pos;
string le3 = "\t\t\t\t\t";
int flightChoose = 0;
int posEmployee = 0, indexUser = 0, tmp1 = 0, indexPassword = 0, checkLogin = 0, dn = 0, j = 0, i = 0, errorCount = 0, check = 1;
string le1 = "\t\t\t\t\t\t  ";
int checkinArr[10][200];
int CheckArr[10][200];
int getChoose(int choose)
{
    return choose;
}
void menu(char content[][200], int count)
{
    ShowCur(0);
    int w = 30;
    int h = 2;
    int t_color = 11;
    int b_color = 1;
    int b_color_sang = 75;
    for (int i = 0; i < count; i++)
    {
        boxes(xx, yy, w, h, t_color, b_color, content, count);
    }
    int xp = xx;
    int yp = yy; // toạ độ thanh sáng
    bool kt = true;
    int xcu = xp, ycu = yp;
    while (true)
    {

        // in
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, content, (ycu - yy) / 2);
            xcu = xp;
            ycu = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, content, (yp - yy) / 2);
            kt = false;
        }
        // ddieeu khien di chuyen
        if (_kbhit())
        {
            char c = _getch();
            if (c == 72)
            {
                kt = true;
                if (yp != yy)
                    yp -= 2;
                else
                    yp = yy + h * (count - 1);
            }
            else if (c == 80)
            {
                kt = true;
                if (yp != yy + h * (count - 1))
                    yp += 2;
                else
                    yp = yy;
            }
            else if (c == 13)
            {
                textcolor(3);
                choose = (yp - yy) / 2 + 1;
                system("cls");
                return;
            }
        }
    }
}
void thanh_sang(int xx, int yy, int w, int h, int b_color, char content[][200], int idx)
{
    textcolor(b_color);
    for (int i = yy + 1; i <= yy + h - 1; i++)
    {
        for (int j = xx + 1; j <= xx + w - 1; j++)
        {
            gotoXY(j, i);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(xx + 1, yy + 1);
    print(idx, content);
}
void box(int xx, int yy, int w, int h, int t_color, int b_color, char content[][200], int idx)
{
    textcolor(b_color);
    for (int i = yy + 1; i <= yy + h - 1; i++)
    {
        for (int j = xx + 1; j <= xx + w - 1; j++)
        {
            gotoXY(j, i);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(xx + 1, yy + 1);
    print(idx, content);
    textcolor(3);
    SetColor(t_color);

    if (h == 1 || w <= 1)
        return;
    for (int i = xx; i <= xx + w; i++)
    {
        gotoXY(i, yy);
        cout << "─";
        gotoXY(i, yy + h);
        cout << "─";
    }
    for (int i = yy; i <= yy + h; i++)
    {
        gotoXY(xx, i);
        cout << "│";
        gotoXY(xx + w, i);
        cout << "│";
    }
    gotoXY(xx, yy);
    cout << "┌";
    gotoXY(xx + w, yy);
    cout << "┐";
    gotoXY(xx, yy + h);
    cout << "└";
    gotoXY(xx + w, yy + h);
    cout << "┘";
    gotoXY(xx, yy + h);
    cout << endl;
}
void boxes(int xx, int yy, int w, int h, int t_color, int b_color, char content[][200], int count)
{
    for (int i = 0; i < count; i++)
    {
        box(xx, yy + i * 2, w, h, 11, 1, content, i);
        if (i != 0)
        {
            gotoXY(xx, yy + i * 2);
            cout << "├";
            gotoXY(xx + w, yy + i * 2);
            cout << "┤";
        }
    }
}