#include "Vehicle.h"
#include "Customer.h"
#include "Booking.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdint>
#include <utility>

Vehicle testVehicleNumber()
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
   return vehicle;
}

Customer testCustomerName()
{
   std::string name;
   std::cout << "Enter customer name: " << std::endl;
   std::getline(std::cin, name);
   std::cout << "you entered: " << name << std::endl;
   Customer customer(name);
   assert(customer.getName() == name);
   return customer;
}

// Booking inputs... date, time, origin, destination
std::pair<Date, Date> testBookingDates()
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
   return std::make_pair(departureDate, arrivalDate);
}

void writeBookingToFile(const Booking& booking)
{
   std::cout << "Generating booking report..." << std::endl;
   std::string filename = "booking.txt";
   std::ofstream outFile(filename);
   outFile << "Customer: " << booking.getCustomer().getName() << "\n";
   outFile << "Vehicle #: " << booking.getVehicle().getNumber() << "\n";
   outFile << "Departure Date: " << booking.getDepartureDate();
   outFile << "Arrival Date: " << booking.getArrivalDate();
   outFile.close();
   std::cout << filename << std::endl;
}

// TODO: write test to read in the file output and check each line ***

// like the idea of getting all the dependencies for booking first, then passing all to booking container
//  refactor idea later: have file name be <customer name>-<departure date>-<arrival date>
Booking testBookingDetails(const Customer& customer,
                           const Vehicle& vehicle,
                           const Date& depart,
                           const Date& arrive)
{
   return Booking(customer, vehicle, depart, arrive);
}

// ----- Requirements ----- //
// Take in customer information
// Take in booking choices
// Show booking results
// Take in booking confirmation
// Show bill and print to file
// Improvements
//  have a container of available vehicles and perhaps drivers too to pull from if there are any available
//   if not can return there are no availabilities on that reservation date/time, please enter a different date/time
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

   Vehicle vehicle = testVehicleNumber();
   Customer customer = testCustomerName();
   std::pair<Date, Date> dates = testBookingDates();
   Booking booking = testBookingDetails(customer, vehicle, dates.first, dates.second);
   writeBookingToFile(booking);
}