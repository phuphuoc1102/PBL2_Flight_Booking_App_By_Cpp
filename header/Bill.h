#ifndef Bill_h
#define Bill_h
#include "LinkedList.h"
#include "Passenger.h"
#include "TicketPrice.h"
#include "NumberTicket.h"
#include "BookingData.h"
class Bill : public Login, public InfoFlight
{
private:
    Bill *employee;
    string nameEmployee;
public:
    Bill();
    ~Bill();
    void PrintBill(Login *data, InfoFlight *info, Passenger psg, TicketPrice *t, NumberTicket *num, BookingData *b, int indexFlight);
    void ProcessBill();
};
#endif