#pragma once

#include <string>
#include <vector>

#include "Device.hpp"
#include "util.hpp"

#include <cuda.h>
#include <cuda_runtime.h>

namespace cudaexecutor {

/*!
  \class Options Options.hpp
  \brief Options for compiling a Program
  \example options_construct.cpp
*/
class Options {
 public:
  //! empty Options constructor
  Options() {}
  //! construct Options with one Option
  //! \tparam T optiontype, e.g. FMAD
  //! \param t option
  template <typename T> Options(const T &t);
  //! construct Options with multiple Option
  //! \tparam T  optiontype, e.g. FMAD
  //! \tparam TS Option
  //! \param t  optiontype, e.g. FMAD
  //! \param ts Option
  template <typename T, typename... TS> Options(const T &t, const TS &... ts);
  //! insert Option
  //! \param op e.g. "--device-debug"
  void insert(const std::string &op);
  //! insert Option
  //! \param name e.g. "--fmad"
  //! \param value e.g. "false"
  void insert(const std::string &name, const std::string &value);
  //! insert Option
  //! \tparam T optiontype, e.g. FMAD
  //! \param t Option
  template <typename T> void insertOptions(const T &t);
  //! insert multiple Options with multiple Option
  //! \tparam T  optiontype, e.g. FMAD
  //! \tparam TS Option
  //! \param t  optiontype, e.g. FMAD
  //! \param ts Option
  template <typename T, typename... TS>
  void insertOptions(const T &t, const TS &... ts);
  //!
  //! \return c-style string array with all options
  const char **options() const;
  //!
  //! \return number of Options
  auto numOptions() const { return _options.size(); }

 private:
  std::vector<std::string> _options;
  mutable std::vector<const char *> _chOptions;
};

template <typename T> Options::Options(const T &t) { insertOptions(t); }

template <typename T, typename... TS>
Options::Options(const T &t, const TS &... ts) {
  insertOptions(t);
  insertOptions(ts...);
}

template <typename T> void Options::insertOptions(const T &t) {
  insert(t.name(), t.value());
}

template <typename T, typename... TS>
void Options::insertOptions(const T &t, const TS &... ts) {
  insert(t.name(), t.value());
  insertOptions(ts...);
}

namespace detail {

class BooleanOption {
  const bool _b;

 public:
  explicit BooleanOption(bool b) : _b{b} {}
  auto value() const { return (_b) ? "true" : "false"; }
};

} // namespace detail

namespace options {

class GpuArchitecture {
  const std::string arc;

 public:
  GpuArchitecture(int major, int minor)
      : arc(std::string("compute_") + std::to_string(major) +
            std::to_string(minor)) {}

  explicit GpuArchitecture(const cudaexecutor::Device &device)
      : GpuArchitecture(device.major(), device.minor()) {}

  auto name() const { return "--gpu-architecture"; }
  auto &value() const { return arc; }
};

class FMAD : public detail::BooleanOption {
 public:
  using detail::BooleanOption::BooleanOption;
  auto name() const { return "--fmad"; }
};

class Fast_Math : public detail::BooleanOption {
 public:
  using detail::BooleanOption::BooleanOption;
  auto name() const { return "--use_fast_math"; }
};

} // namespace options

} // namespace cudaexecutor

