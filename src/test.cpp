#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
//#include "../type/table.hpp"
#include "base/hexstring.hpp"
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
  const string hexprfix("0x");

  std::cout<<"double: "<<now<<std::endl;

  string n= numToHex(now);
  cout<<"string: "<<n<<endl;
  cout<<"time: "<<timeToHex(now)<<endl;
  string hx=timeToHex(now);
  auto a=HexToLL(hx);
  cout<<a<<endl;

  cout<<getTimeString()<<endl;

  long long nowstamp = std::chrono::duration_cast<std::chrono::milliseconds>
      (std::chrono::system_clock::duration::max()-std::chrono::system_clock::now().time_since_epoch()).count();
  std::cout<<"nowstamp: "<<nowstamp<<std::endl;
  string ns= numToHex(nowstamp);
  cout<<"string: "<<ns<<endl;


  cout<<nowstamp-now<<endl;
  return 0;


}
