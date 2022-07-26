#pragma once

#include "ActionHandler.h"
#include <ItemLoaders/ItemLoader.h>
#include <vector>

using std::vector;

namespace ComputePipeline {

  class LoadItemHandler : public ActionHandler {

  public:
    virtual void Handle(Pipeline* p, const string uri = "");
    void Insert(ItemLoader* loader) { m_loaders.push_back(loader); }
  private:
    vector<ItemLoader*> m_loaders;
  };
}