#pragma once

#include "ActionHandler.h"
#include <Actions/DecompressData/DecompressData.h>
#include <vector>

using std::vector;

namespace ComputePipeline {

  class CompressedDataHandler : public ActionHandler {

  public:
    virtual void Handle(Pipeline* p, const string uri = "");
    void Insert(DecompressData* decompressor) { m_decompressors.push_back(decompressor); }
  private:
    vector<DecompressData*> m_decompressors;
  };
}