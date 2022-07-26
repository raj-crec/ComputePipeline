
#pragma once

#include "ItemLoader.h"

#define URI_HTTP_PREFIX "http://"
#define URI_HTTPS_PREFIX "https://"

namespace ComputePipeline {

  class URLLoader : public ItemLoader {

  public:
    virtual char* LoadItem(const string& uri);
  };
}