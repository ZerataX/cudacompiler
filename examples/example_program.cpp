#include "../include/cudaexecutor/main.hpp"

using cudaexecutor::Program, cudaexecutor::ProgramArg, cudaexecutor::Kernel,
    cudaexecutor::Options, cudaexecutor::Device, cudaexecutor::load,
    cudaexecutor::type_of, cudaexecutor::to_comma_separated;

int main() {
  int *array = new int[5]{5, 3, 3, 2, 7};
  int data{8};
  try {
    Device device;
    Options options{cudaexecutor::options::GpuArchitecture(device),
                    cudaexecutor::options::FMAD(false)};
    Program program{"template<typename type, int size>\n"
                    "__global__ void my_kernel(type[] c, type val) {\n"
                    "    auto idx = threadIdx.x * size;\n"
                    "\n"
                    "    #pragma unroll(size)\n"
                    "    for (auto i = 0; i < size; i++) {\n"
                    "        c[idx] = val;\n"
                    "        idx++;\n"
                    "    }\n"
                    "}"};

    std::vector<ProgramArg> program_args;
    ProgramArg array_arg(&array, sizeof(int) * 5, true);
    ProgramArg data_arg(&data);
    program_args.push_back(array_arg);
    program_args.push_back(data_arg);

    dim3 grid(1);
    dim3 block(1);
    program.kernel("my_kernel")
                      // .instantiate(type_of(data), 5)
                      // .instantiate<float, std::integral_constant<int, 5>>()
                      .instantiate("int", "int 5")
                      .compile(options)
                      .configure(grid, block)
                      .launch(program_args);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::vector<int> vec(array, array + 5);
  std::cout << to_comma_separated(vec) << std::endl;

  delete[] array;

  return 0;
}
