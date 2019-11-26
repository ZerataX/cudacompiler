#pragma once

#include <iostream>
#include <map>
#include <sstream>

namespace cudaexecutor {

/** @enum loglevel
 *  @brief a level at which should be logged
 */
enum class loglevel {
  NONE,    /**< don't log at all */
  ERROR,   /**< an ERROR which should not be ignored */
  WARNING, /**< a WARNING which might be ignored */
  INFO,    /**< a INFO which can be ignored */
  DEBUG,   /**< verbose INFO which can be ignored */
  DEBUG1   /**< verbose DEBUG which can be ignored */
};

/*!
  \class logIt Logger.hpp
  \brief Class to log events at different levels
*/
class logIt
{
 public:
  //!
  //! \param level level at which the message is set
  //! \param current_level the current level of the executable
  //! \param file file where the logger was called
  //! \param line line where the logger was called
  logIt(loglevel level, loglevel current_level, const char *file,
        const int line)
      : _level{level}, _current_level{current_level} {
    _buffer << "LOGGER:[" << file << ":" << line << "]: ";
  }

  template <typename T> logIt &operator<<(T const &value) {
    _buffer << value;
    return *this;
  }

  ~logIt() {
    _buffer << std::endl;
    if (static_cast<int>(_level) <= static_cast<int>(_current_level))
      std::cerr << _buffer.str();
  }

 private:
  loglevel _level;
  loglevel _current_level;
  std::ostringstream _buffer;
}; // namespace cudaexecutor

//! set log level at compilation
#ifdef current_log_level
#define logger(level)                                                          \
  if (static_cast<int>(level) > static_cast<int>(current_log_level))           \
    ;                                                                          \
  else                                                                         \
    logIt(level, current_log_level, __FILE__, __LINE__)
#else
#define logger(level) logIt(level, loglevel::ERROR, __FILE__, __LINE__)
#endif

} // namespace cudaexecutor
