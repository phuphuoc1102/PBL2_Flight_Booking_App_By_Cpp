#ifndef BookingData_h
#define BookingData_h
#include "Passenger.h"
#include "NumberTicket.h"
class BookingData :   public Passenger,public NumberTicket{
      private:
      BookingData *b;
      long long ticketid;
      public:
      BookingData();
      ~BookingData();
      void InputBookingData(BookingData *&b,InfoFlight *info,int v);
      long long get_ticketid(BookingData *b,int i);
      string GetName(BookingData *b,int i);
      string GetDateofbirth(BookingData *b,int i);
      string GetSex(BookingData *b,int i);
      string GetIDcard(BookingData *b,int i);
      string GetPhonenumber(BookingData *b,int i);
};
#endif