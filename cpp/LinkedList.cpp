#include <bits/stdc++.h>
#include <conio.h>
#include "../header/LinkedList.h"
#include "../header/lib.h"
using namespace std;
LinkedList::LinkedList()
{
    head = NULL;
}
LinkedList::~LinkedList()
{
}
LinkedList::LinkedList(Login *a)
{
    head = a;
}
void LinkedList::insertFirst(LinkedList &List, string username, string password)
{
    cnt++;
    Login *tmp = new Login(username, password);
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
    head->setNumOfEmployee(cnt);
}
void LinkedList::printList()
{
    cout << "So nhan vien : " << head->getNumOfEmployee() << endl;
    Login *temp3 = head;
    if (head == NULL)
    {
        cout << "List empty" << endl;
    }
    else
    {
        int i = 1;
        while (temp3 != NULL)
        {
            cout << "Staff " << i << endl;
            cout << "User : ";
            cout << temp3->getUsername() << endl;
            cout << "Password : ";
            cout << temp3->getPassword() << endl;
            temp3 = temp3->next;
        }
    }
}
void LinkedList::deleteEmployee(int delNode)
{
    Login *temp1 = head, *temp2 = NULL;
    int len = 0;
    if (head == NULL)
    {
        cout << "List empty." << endl;
    }
    else
    {
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
            len++;
        }
        if (len < delNode)
        {
            cout << "Index out of range" << endl;
        }
        else
        {
            temp1 = head;
            if (delNode == 1)
            {
                head = head->next;
                delete temp1;
            }
            else
            {
                while (delNode-- > 1)
                {
                    temp2 = temp1;
                    temp1 = temp1->next;
                }
                temp2->next = temp1->next;
                delete temp1;
            }
        }
    }
    cnt--;
}
void LinkedList::InputPassword(LinkedList list)
{
    string pass;
    int kt = 0;
    textcolor(6);
    cout << "\n";
    cout << le1 << "Mật khẩu      : ";
    textcolor(3);
    char c = getch();
    while (c != 10 && c != 13)
    {
        if (c != 8)
        {
            cout << '*';
            pass += c;
            c = getch();
        }
        else if (pass.length() > 0)
        {
            cout << "\b \b";
            pass = pass.erase(pass.size() - 1);
            c = getch();
        }
        else
        {
            c = getch();
        }
    }

    cout << endl;
    int cntPass = 0;
    Login *temppw = head;
    while (cntPass < 30)
    {
        indexPassword++;
        if (indexPassword == indexUser)
        {
            if (pass == temppw->getPassword())
            {
                textcolor(10);
                cout << "\n";
                cout << le1 << "Đăng nhập thành công !\n"
                     << endl;
                textcolor(3);
                cout << le1 << "1.Tiếp tục.\n";
                cout << le1 << "0.Thoát.\n";
                cout << "\n";
                cout << le1 << "TRẢ LỜI: ";
                int lc;
                cin >> lc;
                if (lc == 1)
                {
                    dn = 1;
                    setIdEmployee(indexPassword);
                    posEmployee = getIdEmployee();
                    system("cls");
                    dn = 1;
                    kt++;
                    errorCount = 0;
                    break;
                }
                else if (lc == 0)
                {
                    dn = 0;
                    textcolor(12);
                    cout << "\n";
                    cout << le1 << "Cảm ơn!";
                    exit(0);
                }
                else
                {
                    textcolor(14);
                    cout << le1 << "Lựa chọn không hợp lệ!";
                    textcolor(3);
                    exit(0);
                }
                break;
            }
            else
            {
                errorCount++;
                if (errorCount >= 3)
                {
                    textcolor(12);
                    cout << "\n";
                    cout << le1 << "Tài khoản đã bị khóa vì nhập sai mật khẩu vượt quá số lần quy định !\n";
                    exit(0);
                }
                textcolor(12);
                cout << "\n";
                cout << le1 << "Đăng nhập thất bại !\n\n";
                textcolor(3);
                tmp1 = 0;
                cout << le1 << "1.Thử lại.\n";
                cout << le1 << "0.Thoát.\n\n";
                cout << le1 << "TRẢ LỜI: ";
                int lc;
                cin >> lc;
                if (lc == 1)
                {
                    tmp1 = 0;
                    indexUser = 0;
                    indexPassword = 0;
                    system("cls");
                    InputUsername(list);
                }
                else if (lc == 0)
                {
                    textcolor(12);
                    cout << "\n";
                    cout << le1 << "Cảm ơn!";
                    exit(0);
                }
                else
                {
                    textcolor(14);
                    cout << le1 << "Lựa chọn không hợp lệ!";
                    textcolor(3);
                    exit(0);
                }
            }
        }
        temppw = temppw->next;
        cntPass++;
        if (kt != 0)
            return;
    }
    if (kt != 0)
        return;
}
void LinkedList::InputUsername(LinkedList list)
{
    system("cls");
    box(50, 3, 50, 6, 11, 1, Title, 0);
    textcolor(6);
    cout << le1 << "Tên đăng nhập : ";
    textcolor(3);
    string user_name, tmpUsername;
    fflush(stdin);
    getline(cin, user_name);
    tmpUsername = user_name;
    checkLogin = 0;
    for (int q = 0; q < tmpUsername.length(); q++)
    {
        if ((int)tmpUsername[q] == 32)
        {
            gotoXY(40, 12);
            textcolor(12);
            cout << "\n";
            cout << le1 << "Tên đăng nhập không được có khoảng trắng, vui lòng nhập lại!\n";
            textcolor(3);
            gotoXY(50, 14);
            system("pause");
            checkLogin++;
            tmp1 = 0;
            check = 0;
            InputUsername(list);
            break;
        }
    }
    if (tmpUsername.length() == 0)
    {
        gotoXY(40, 12);
        textcolor(12);
        cout << "\n";
        cout << le1 << "Bạn phải nhập tên đăng nhập !\n";
        textcolor(3);
        gotoXY(50, 15);
        system("pause");
        InputUsername(list);
        return;
    }
    Lowercase(tmpUsername);
    Login *temp = head;
    tmp1 = 0;
    int cntLogin = 0;
    while (cntLogin < 30)
    {
        string tmpGetUsername = temp->getUsername();
        Lowercase(tmpGetUsername);
        indexUser++;
        if (tmpUsername == tmpGetUsername)
        {
            tmpUsername = temp->getUsername();
            InputPassword(list);
            break;
        }
        else
        {
            if (checkLogin == 0)
            {
                tmp1++;
            }
        }
        temp = temp->next;
        cntLogin++;
    }
    if (tmp1 == 30 && checkLogin == 0 && check == 1)
    {
        tmp1 = 0;
        textcolor(12);
        cout << "\n";
        cout << le1 << "Tên đăng nhập không hợp lệ !\n\n";
        textcolor(3);
        cout << le1 << "1.Thử lại.\n";
        cout << le1 << "0.Thoát.\n\n";
        cout << le1 << "TRẢ LỜI: ";
        int lc;
        cin >> lc;
        if (lc == 1)
        {
            indexUser = 0;
            indexPassword = 0;
            system("cls");
            InputUsername(list);
        }

        else if (lc == 0)
        {
            textcolor(12);
            cout << "\n";
            cout << le1 << "Cảm ơn!";
            exit(0);
        }
        else
        {
            textcolor(14);
            cout << le1 << "Lựa chọn không hợp lệ!";
            textcolor(3);
            exit(0);
        }
    }
}
void LoginToSystem()
{
    Login *a;
    LinkedList list(a);
    int i = 0;
    ifstream input("../database/LoginData.txt");
    string user, pass;
    while (!input.eof())
    {
        input >> user;
        input >> pass;
        list.insertFirst(list, user, pass);
        i++;
    }
    list.InputUsername(list);
}