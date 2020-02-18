#pragma once

#include "../../include/yacx/JNIHandle.hpp"
#include "../../include/yacx/KernelArgs.hpp"

#include <memory>

namespace jni {
class KernelArgJNI : yacx::JNIHandle {
  friend class KernelArgJNISlice;

 public:
  KernelArgJNI(std::shared_ptr<void> hdata, yacx::KernelArg *kernelArg)
      : m_hdata(hdata), m_kernelArg(kernelArg){};
  KernelArgJNI(void *data, size_t size, bool download, bool copy, bool upload);
  ~KernelArgJNI();
  yacx::KernelArg *kernelArgPtr() { return m_kernelArg; }
  virtual void *getHostData() const { return m_hdata.get(); }
  std::shared_ptr<void> getHostDataSharedPointer() { return m_hdata; }

 private:
  std::shared_ptr<void> m_hdata;
  yacx::KernelArg *m_kernelArg;
};

class KernelArgJNISlice : public KernelArgJNI {
 public:
  KernelArgJNISlice(size_t start, size_t end, KernelArgJNI *arg);
  void *getHostData() const override {
    return reinterpret_cast<char *>(m_hdata.get()) + m_offset;
  }

 private:
  size_t m_offset;
};
} // namespace jni
