# Changelog
## yacx v0.4.1 (2019-12-13)
### Documentation
- created a [classDiagram](docs/diagram/classDiagram.pdf)
- a [Code of Conduct](./CODE_OF_CONDUCT.md)
- a [Contribution Guideline](./CONTRIBUTING.md)

### Changes
- renamed (see [#78](https://github.com/ZerataX/yacx/issues/78))
  - Headers.{length=>numHeaders}
  - Options.{options=>content}
  - KernelArgs.m_{chArgs=>voArgs}
- cleaned up repo
  - fixed workflows for pull requests
  - issue templates
  - updated README.md 
  
## yacx v0.4 (2019-12-07)
### Changes
- rename project from **cudaexecutor**/**cudacompiler** to **yacx** - *yet another cudaexecutor*

## cudaexecutor v0.3 (2019-12-07)
### Features
- KernelTime: measure time of kernel execution as well as uploading and downloading of KernelArgs
- fully featured JNI
- lots of java and scala examples
- build and execute script for java/scala: [cudaexecutor.sh](https://github.com/ZerataX/yacx/blob/0.3/cudaexecutor.sh)

### Changes
- KernelArgs refactor
  - moved KernelArg uploading into KernelArgs

## cudaexecutor v0.2 (2019-12-03)
### Features
- c++ bindings
  - get devices
  - template kernels
  - logging and exception for debugging
  - nvrtc option class
- mostly replicated as a JNI

### Changes
- Classes renamed
  - ProgramArg => KernelArg
  - Program => Source
  - Kernel => Kernel, Program
  
## cudaexecutor v0.1 (2019-11-22)
### Features
- c++ bindings
  - execute abitrary cuda kernels
