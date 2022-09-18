#include "Vehicle.h"
#include "Customer.h"
#include "Booking.h"

#include <iostream>
#include <cassert>
#include <cstdint>

void testVehicleNumber()
{
   uint32_t num = 101;
   std::cout << "Enter vehicle number: " << std::endl;
   // Note: can't use cin >> b/c there's a mix of number and string inputs, so getline is used.
   //  It is advised not to mix operator >> with getline.
   //  Alternatively, trying to just use std::cin.ignore() after the operator >> to eat the \n which cin >> ignores
   std::cin >> num;
   std::cin.ignore(); // must eat the \n
   std::cout << "you entered: " << num << std::endl;
   Vehicle vehicle(num);
   assert(vehicle.getNumber() == num);
}

void testCustomerName()
{
   std::string name;
   std::cout << "Enter customer name: " << std::endl;
   std::getline(std::cin, name);
   std::cout << "you entered: " << name << std::endl;
   Customer customer(name);
   assert(customer.getName() == name);
}

// Booking inputs... date, time, origin, destination
void testBookingDates()
{
   Date departureDate;
   std::cout << "Enter date of departure (e.g. 03..16..2023)... " << std::endl;
   std::cin >> departureDate;
   std::cin.ignore(); // must eat the \n
   std::cout << "you entered: " << departureDate << std::endl;

   Date arrivalDate;
   std::cout << "Enter date of arrival (e.g. 03..16..2023)... " << std::endl;
   std::cin >> arrivalDate;
   std::cin.ignore(); // must eat the \n
   std::cout << "you entered: " << arrivalDate << std::endl;

   Booking booking(departureDate, arrivalDate);
   assert(booking.getDepartureDate() == departureDate);
   assert(booking.getArrivalDate() == arrivalDate);
}

// ----- Requirements ----- //
// Take in customer information
// Take in booking choices
// Show booking results
// Take in booking confirmation
// Show bill and print to file
main()
{
   // TODO: make sure to pass dependencies
   // Make sure classes follow SOLID design
   // Single Responsiblitiy
   // Open-Closed
   // Liskov Substitution
   // Interface Segregation
   // Dependency Inversion
   std::cout << "----- TMS: program start -----\n" << std::endl;

   testVehicleNumber();
   testCustomerName();
   testBookingDates();
}