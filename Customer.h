#include <string>

class Customer
{
   public:
      Customer(std::string customerName) { name = customerName; };
      std::string getName() { return name; }
   
   private:
      std::string name;
};