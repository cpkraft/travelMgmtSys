#pragma once

#include <string>

class Customer
{
   public:
      Customer() { name = "No Name"; }
      Customer(std::string customerName) { name = customerName; };
      std::string getName() { return name; }

      Customer& operator=(const Customer& customer)
      {
         if (this == &customer) return *this; // self-assignement check
         name = customer.name;
         return *this; // return the existing obj so we can chain this operator
      }
   
   private:
      std::string name;
};