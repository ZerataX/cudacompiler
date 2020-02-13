#pragma once

#include "JNIHandle.hpp"
#include <cuda.h>
#include <memory>
#include <vector>

namespace yacx {
class KernelArg;
class KernelArgMatrixPadding;

namespace detail {
class DataCopy {
 public:
  //! A constructor
  //! \param kernelArg KernelArg, which should be copied from/to host to/from
  //! device
  DataCopy() {}
  //! copy data from host to device
  virtual void copyDataHtoD(KernelArg *kernelArg) = 0;
  //! copy data from device to host
  virtual void copyDataDtoH(KernelArg *kernelArg) = 0;
};

class DataCopyKernelArg : public DataCopy {
 public:
  DataCopyKernelArg() {}
  void copyDataHtoD(KernelArg *kernelArg) override;
  void copyDataDtoH(KernelArg *kernelArg) override;
};

class DataCopyKernelArgMatrixPadding : public DataCopy {
 public:
  //! A constructor
  /*!
   * \param elementSize size of each element of the matrix in bytes
   * \param paddingValue value to fill up additional rows and columns
   * \param src_rows number of rows of current matrix without padding
   * \param src_columns number of columns of currentmatrix without padding
   * \param dst_rows number of rows for new matrix with padding
   * \param dst_columns number of columns for new matrix with padding
   */
  DataCopyKernelArgMatrixPadding(int elementSize, unsigned int paddingValue,
                                 int src_rows, int src_columns, int dst_rows,
                                 int dst_columns)
      : m_paddingValue(paddingValue), m_elementSize(elementSize),
        m_src_rows(src_rows), m_src_columns(src_columns), m_dst_rows(dst_rows),
        m_dst_columns(dst_columns) {}
  void copyDataHtoD(KernelArg *kernelArg) override;
  void copyDataDtoH(KernelArg *kernelArg) override;

 private:
  const int m_elementSize;
  const int m_paddingValue;
  const int m_src_rows;
  const int m_src_columns;
  const int m_dst_rows;
  const int m_dst_columns;
};
} // namespace detail

/*!
  \class ProgramArg ProgramArg.hpp
  \brief Class to help launch Kernel with given arguments
  Arguments are automatically uploaded and downloaded.
  \example docs/kernel_args.cpp
    Will execute the Kernel with <code>add(1, 2, 3, 4, result)</code>;
    and the result will be downloaded from device to host
*/

class KernelArg : JNIHandle {
  friend class KernelArgs;
  friend class detail::DataCopyKernelArg;
  friend class detail::DataCopyKernelArgMatrixPadding;

 public:
  //! A constructor
  /*!
   *
   * \param data pointer to argument for kernel function
   * \param size size of argument in bytes
   * \param download copy the results from device to host after kernel execution
   * \param copy copy the results to the device
   * \param upload allocate the argument on the device (not necessary for basic
   * types, e.g. int)
   */
  KernelArg(void *data, size_t size, bool download = false, bool copy = true,
            bool upload = true);
  //! A constructor for basic types, e.g. int
  //! \param data pointer to argument for kernel function
  explicit KernelArg(void *data) : KernelArg{data, 0, false, false, false} {};
  //!
  //! \return pointer to host data
  const void *content() const;
  //!
  //! \return pointer to device data
  CUdeviceptr deviceptr() { return m_ddata; }
  //! uploads data to device
  //! \return time to upload to device
  float upload();
  //! downloads data to host
  //! \return time to download from device
  float download() { return download(const_cast<void *>(m_hdata)); }
  //! downloads data to host
  //! \param pointer to host memory
  //! \return time to download from device
  float download(void *hdata);
  const size_t size() const { return m_size; }
  bool isDownload() const { return m_download; }
  void setDownload(bool download) { m_download = download; }
  bool isCopy() const { return m_copy; }
  void setCopy(bool copy) { m_copy = copy; }

 protected:
  const void *m_hdata;
  CUdeviceptr m_ddata;
  std::shared_ptr<detail::DataCopy> m_dataCopy;

 private:
  const size_t m_size;
  bool m_download;
  bool m_copy;
  const bool m_upload;
  static std::shared_ptr<detail::DataCopyKernelArg> dataCopyKernelArg;
};

class KernelArgMatrixPadding : public KernelArg {
 public:
  //! A constructor
  /*!
   *
   * \param data pointer to argument for kernel function
   * \param size size of argument in bytes
   * \param download copy the results from device to host after kernel execution
   * types, e.g. int)
   * \param elementSize size of each element of the matrix in bytes
   * \param paddingValue value to fill up additional rows and columns
   * \param src_rows number of rows of current matrix without padding
   * \param src_columns number of columns of currentmatrix without padding
   * \param dst_rows number of rows for new matrix with padding
   * \param dst_columns number of columns for new matrix with padding
   */
  KernelArgMatrixPadding(void *data, size_t size, bool download,
                         int elementSize, unsigned int paddingValue,
                         int src_rows, int src_columns, int dst_rows,
                         int dst_columns);
};

class KernelArgs {
 public:
  KernelArgs(std::vector<KernelArg> args);
  float upload();
  float download();
  float download(void *hdata);
  const void **content();
  size_t size() const;
  size_t maxOutputSize() const;

 private:
  std::vector<KernelArg> m_args;
  mutable std::vector<const void *> m_voArgs;
};
} // namespace yacx