#include "Vehicle.h"
#include "Customer.h"

#include <iostream>

void testVehicle(Vehicle& vehicle)
{
   std::cout << "Vehicle: Pass" << std::endl;
   // TODO
}

void testCustomer(Customer& customer)
{
   std::cout << "Customer: Pass" << std::endl;
   // TODO
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
   std::cout << "TMS: program start" << std::endl;

   Vehicle vehicle;
   testVehicle(vehicle);

   std::string name;

   std::cout << "Enter name: " << std::endl;
   std::getline(std::cin, name);
   std::cout << "you entered: " << name << std::endl;
   Customer customer(name);
   testCustomer(customer);
}