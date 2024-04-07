#ifndef __GLOBAL_HPP__
#define __GLOBAL_HPP__

#include <memory>
#include <string>
#include <iostream>

using LogLevel = enum LogLevel : size_t { DEBUG, INFO, WARN, ERROR, FATAL };

class Configuration {
protected:
  std::string _input_filename;
  std::string _output_filename;
  std::ostream *_os;
  LogLevel _log_level;

public:
  Configuration();
  ~Configuration();
  /// @brief manage filename
  const std::string &inputFilename();
  void setInputFilename(const std::string &filename);
  const std::string &outputFilename() {
    return _output_filename;
  }
  void setOutputFilename(const std::string &filename) {
    _output_filename = filename;
  }
  /// @brief manage ostream
  std::ostream &os();
  void setOstream(std::ostream &os);
  /// @brief manage loglevel
  LogLevel logLevel();
  void setLogLevel(LogLevel log_level);
};

class Logger {
private:
  LogLevel _log_level;

public:
  Logger();
  Logger(LogLevel log_level);
  ~Logger();
  template <typename T>
  Logger &operator<<(const T &msg);
};

extern Configuration configuration;
extern Logger debug;
extern Logger info;
extern Logger warn;
extern Logger error;
extern Logger fatal;

template <typename T>
Logger &Logger::operator<<(const T &msg) {
  if (this->_log_level >= configuration.logLevel()) configuration.os() << msg;
  return *this;
};

#endif
