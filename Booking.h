#pragma once

#include <cstdint>
#include <iostream>
#include <tuple>

#include "Customer.h"
#include "Vehicle.h"

struct Date
{
   Date() { year = 0; month = 0; day = 0; }
   Date(uint32_t y, uint32_t m, uint32_t d) { year = y; month = m; day = d; }
   uint32_t year;
   uint32_t month;
   uint32_t day;

   Date& operator=(const Date& date)
   {
      if (this == &date) return *this; // self-assignement check
      year = date.year;
      month = date.month;
      day = date.day;
      return *this; // return the existing obj so we can chain this operator
   }

   bool operator==(const Date& rhs) const
   {
      return std::tie(year, month, day) == std::tie(rhs.year, rhs.month, rhs.day);
   }
};

// Date stream overloads
std::ostream& operator<<(std::ostream& out, const Date& date);
std::istream& operator>>(std::istream& in, Date& date);

class Booking
{
   public:
      Booking(Date depDate, Date arrDate);  // DEPRICATED: kept around for old tests - TODO: update old tests
      Booking(Customer theCustomer,
              Vehicle theVehicle,
              Date depDate,
              Date arrDate);
      Date getDepartureDate() { return departureDate; }
      Date getArrivalDate() { return arrivalDate; }

   private:
      Customer customer;
      Vehicle vehicle;
      Date departureDate;
      Date arrivalDate;
};