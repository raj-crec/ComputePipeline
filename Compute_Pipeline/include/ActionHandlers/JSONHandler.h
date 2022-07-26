#pragma once

#include "ActionHandler.h"
#include <Actions/JSONConverter.h>

namespace ComputePipeline {

  class JSONHandler : public ActionHandler {

  public:
    virtual void Handle(Pipeline* p, const string uri = "");
  private:
    bool IsJsonData(const Output& data);
  };
}