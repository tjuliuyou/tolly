#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
//#include "../type/table.hpp"
#include "../base/hexstring.hpp"
//#include "logger.hpp"

using namespace std;
using namespace tolly;
int main()
{
//    InitLog();
//    InitLog();
//    src::severity_logger_mt<sign_severity_level>& lg = my_logger::get();
//    BOOST_LOG_SEV(lg, normal) << "A trace severity message";
//    BOOST_LOG_SEV(lg, debug) << "A debug severity message";
//   // BOOST_LOG_SEV(lg, info) << "An informational severity message";
//    BOOST_LOG_SEV(lg, warning) << "A warning severity message";
//    BOOST_LOG_SEV(lg, error) << "An error severity message";
//    BOOST_LOG_SEV(lg, critical) << "A fatal severity message";
//    //BOOST_LOG_SEV(lg, report) << "A report severity message";
//    logging::core::get()->remove_all_sinks();
//    return 0;

  long long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

  std::cout<<"double: "<<now<<std::endl;

  string n= numToHex(now);

  cout<<"string: "<<n<<endl;

  int a = 1;
  std::cout<<"int: "<<a<<std::endl;
   n= numToHex(a);
   cout<<"string: "<<n<<endl;
   cout<<std::hex<<a<<endl;

  return 0;


}
