#pragma once

#include "DecodeImage.h"

namespace ComputePipeline {

  class ImageFormat1 : public DecodeImage {
  private:
    virtual bool Decode();
    virtual bool IsCorrectFormat() const;
    virtual const string& GetImageHeader() const;
  };
}