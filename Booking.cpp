#include "Booking.h"

// DEPRICATED: kept around for old tests - TODO: update old tests
Booking::Booking(Date depDate, Date arrDate)
{
   customer = Customer("No Name"); // invalid name
   vehicle = Vehicle(0); // invalid vehicle
   departureDate = depDate;
   arrivalDate = arrDate;
}

Booking::Booking(Customer theCustomer,
         Vehicle theVehicle,
         Date depDate,
         Date arrDate)
{
   customer = theCustomer;
   vehicle = theVehicle;
   departureDate = depDate;
   arrivalDate = arrDate;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
   out << date.month << "." << date.day << "." << date.year << std::endl;
   return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
   std::cout << "Enter Month (e.g. 03): " << std::endl;
   in >> date.month;
   std::cout << "Enter Day (e.g. 12): " << std::endl;
   in >> date.day;
   std::cout << "Enter Year (e.g. 2023): " << std::endl;
   in >> date.year;
   return in;
}