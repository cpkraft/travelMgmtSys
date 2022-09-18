#include <cstdint>

class Vehicle
{
   public:
      Vehicle(uint32_t num){ number = num; }
      uint32_t getNumber() { return number; }

   private:
      uint32_t number;
};