#pragma once

#include "ActionHandler.h"
#include <Actions/DecodeImage/DecodeImage.h>
#include <vector>

using std::vector;

namespace ComputePipeline {

  class ImageHandler : public ActionHandler {

  public:
    virtual void Handle(Pipeline* p, const string uri = "");
    void Insert(DecodeImage* decoder) { m_decoders.push_back(decoder); }
  private:
    vector<DecodeImage*> m_decoders;
  };
}