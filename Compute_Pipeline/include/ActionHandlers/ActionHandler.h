#pragma once

#include <string>
#include <iostream>

using std::string;

namespace ComputePipeline {

  class Pipeline;

  class ActionHandler {

  public:
    virtual void Handle(Pipeline* p, const string uri = "") = 0;
  };
}