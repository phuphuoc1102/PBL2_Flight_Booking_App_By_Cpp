#ifndef NumberTicket_h
#define NumberTicket_h
#include "InfoFlight.h"
class NumberTicket : public InfoFlight {
  private:
  NumberTicket *num;
  int first;
  int last;
  long long ticketID[10][100];
  public:
  NumberTicket();
  ~NumberTicket();
  void InputNumberTicket(NumberTicket *&num);
  void setTicketID(int i,int j,int x);
  int getFirst(NumberTicket *num,int i);
  int getLast(NumberTicket *num,int i);
  int getTicketID(int i,int j);
};
#endif