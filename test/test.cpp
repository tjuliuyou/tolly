#include <iostream>

#include "../type/table.hpp"

#include "logger.hpp"

using namespace std;
using namespace tolly;
int main()
{
    InitLog();
    InitLog();
    src::severity_logger_mt<sign_severity_level>& lg = my_logger::get();
    BOOST_LOG_SEV(lg, normal) << "A trace severity message";
    BOOST_LOG_SEV(lg, debug) << "A debug severity message";
   // BOOST_LOG_SEV(lg, info) << "An informational severity message";
    BOOST_LOG_SEV(lg, warning) << "A warning severity message";
    BOOST_LOG_SEV(lg, error) << "An error severity message";
    BOOST_LOG_SEV(lg, critical) << "A fatal severity message";
    //BOOST_LOG_SEV(lg, report) << "A report severity message";
    logging::core::get()->remove_all_sinks();
    return 0;
}
