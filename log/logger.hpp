#ifndef TOLLY_LOGGER_HPP_
#define TOLLY_LOGGER_HPP_

#include <boost/shared_array.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sinks/async_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <fstream>

namespace tolly {

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace attrs = boost::log::attributes;

enum sign_severity_level {
  normal,
  notification,
  warning,
  error,
  critical
};

void InitLog() {
  typedef sinks::asynchronous_sink<sinks::text_ostream_backend> TextSink;

  // init sink1
  boost::shared_ptr<sinks::text_ostream_backend> backend1 = boost::make_shared<sinks::text_ostream_backend>();
  backend1->add_stream(boost::shared_ptr<std::ostream>(new std::ofstream("sign.log")));
  boost::shared_ptr<TextSink> sink1(new TextSink(backend1));
  sink1->set_formatter (
   expr::format("[%1%]<%2%>(%3%): %4%")
   % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
   % expr::attr<sign_severity_level>("Severity")
   % expr::attr<attrs::current_thread_id::value_type >("ThreadID")
   % expr::smessage
   );
  sink1->set_filter(expr::attr<sign_severity_level>("Severity") >= warning);
  logging::core::get()->add_sink(sink1);

  // init sink2
  boost::shared_ptr<sinks::text_ostream_backend> backend2 = boost::make_shared<sinks::text_ostream_backend>();
  backend2->auto_flush(true);
  backend2->add_stream(boost::shared_ptr<std::ostream>(new std::ofstream("sign.csv")));
  boost::shared_ptr<TextSink> sink2(new TextSink(backend2));
  sink2->set_formatter (
   expr::format("%1%,%2%,%3%")
   % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
   % expr::attr<sign_severity_level>("Severity")
   % expr::smessage
   );
  sink2->set_filter(expr::attr<sign_severity_level>("Severity") == critical);
  logging::core::get()->add_sink(sink2);

  logging::add_common_attributes();
  logging::core::get()->add_global_attribute("ThreadID", attrs::current_thread_id());
}
BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::severity_logger_mt<sign_severity_level>)
} //namespace

#endif // TOLLY_LOGGER_HPP_
