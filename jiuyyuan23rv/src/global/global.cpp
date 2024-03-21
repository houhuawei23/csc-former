#include "global.hpp"

#include <iostream>
#include <string>

Configuration::Configuration() : _os(&std::cerr), _log_level(DEBUG) {
}

Configuration::~Configuration() {
}

std::ostream &Configuration::os() {
  return *_os;
}

LogLevel Configuration::logLevel() {
  return this->_log_level;
}

const std::string &Configuration::inputFilename() {
  return _input_filename;
}

void Configuration::setInputFilename(const std::string &filename) {
  _input_filename = filename;
}

void Configuration::setOstream(std::ostream &os) {
  _os = &os;
};

void Configuration::setLogLevel(LogLevel log_level) {
  this->_log_level = log_level;
}

Logger::Logger() : _log_level(DEBUG) {
}

Logger::Logger(LogLevel log_level) : _log_level(log_level) {
}

Logger::~Logger() {
}

Configuration configuration = Configuration();
Logger debug = Logger(DEBUG);
Logger info = Logger(INFO);
Logger warn = Logger(WARN);
Logger error = Logger(ERROR);
Logger fatal = Logger(FATAL);
