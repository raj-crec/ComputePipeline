
#pragma once

#include "ItemLoader.h"

#define URI_FILE_PREFIX "file://"

namespace ComputePipeline {

  class FileLoader : public ItemLoader {

  public:
    virtual char* LoadItem(const string& uri);
  };
}