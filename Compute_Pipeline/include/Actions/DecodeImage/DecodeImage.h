#pragma once

#include <iostream>
#include <string>
#include <Output.h>

using std::cout, std::endl;
using std::string;

namespace ComputePipeline {

  class DecodeImage {

  public:
    bool Decode(Output& imageData);
  protected:
    void* m_encodedImage = nullptr;
    MetaData* m_metaData = nullptr;
    void* m_decodedImage = nullptr;
  private:
    virtual bool Decode() = 0;
    virtual bool IsCorrectFormat() const = 0;
    virtual const string& GetImageHeader() const = 0;
  };
}