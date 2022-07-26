
#pragma once

#include <iostream>
#include <string>

// #include<functional>

using std::string;

namespace ComputePipeline {

  class ItemLoader {

  public:

    // Keeping things simple for now. Only synchronous loading of the item.
    virtual char* LoadItem(const string& uri) = 0;
  };
}