#include <string>

class Customer
{
   public:
      Customer(std::string customerName) { name = customerName; };
   
   private:
      std::string name;
};