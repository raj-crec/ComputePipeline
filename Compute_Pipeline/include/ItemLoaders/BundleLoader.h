
#pragma once

#include "ItemLoader.h"

#define URI_BUNDLE_PREFIX "bundle://"

namespace ComputePipeline {

  class BundleLoader : public ItemLoader {

  public:
    virtual char* LoadItem(const string& uri);
  };
}