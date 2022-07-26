#pragma once

#include <iostream>
#include <string>
#include <Output.h>

using std::cout, std::endl;
using std::string;

namespace ComputePipeline {

  class DecompressData {

  public:
    bool Decompress(Output& inputData);
  protected:
    void* m_compressedData = nullptr;
    MetaData* m_metaData = nullptr;
    void* m_decompressedData = nullptr;
  private:
    virtual bool Decompress() = 0;
    virtual bool IsCorrectFormat() const = 0;
    virtual const string& GetDataHeader() const = 0;
  };
}