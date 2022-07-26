#pragma once

#include "DecompressData.h"

namespace ComputePipeline {

  class CFormat1 : public DecompressData {
  private:
    virtual bool Decompress();
    virtual bool IsCorrectFormat() const;
    virtual const string& GetDataHeader() const;
  };
}