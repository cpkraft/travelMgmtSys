#pragma once

#include <cstdint>

class Vehicle
{
   public:
      Vehicle() { number = 0; }
      Vehicle(uint32_t num) { number = num; }
      uint32_t getNumber() { return number; }

      Vehicle& operator=(const Vehicle& vehicle)
      {
         if (this == &vehicle) return *this; // self-assignement check
         number = vehicle.number;
         return *this; // return the existing obj so we can chain this operator
      }

   private:
      uint32_t number;
};