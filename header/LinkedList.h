#ifndef LinkedList_h
#define LinkedList_h
#include "../cpp/Login.cpp"
#include "../cpp/menu.cpp"
class LinkedList : public Login
{
    private:
        Login *head;
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(Login *a);
        void insertFirst(LinkedList &List,string username, string password);
        void printList();
        void deleteEmployee(int delNode);
        void InputUsername(LinkedList list);
        void InputPassword(LinkedList list);
};
void LoginToSystem();
#endif