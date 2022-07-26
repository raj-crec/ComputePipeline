#pragma once

#include <string>
#include <map>
#include <Output.h>

using std::string;
using std::map;

namespace ComputePipeline {

  class Object {

  public:
    ~Object();
    void Set(const string& key, const void* val);

  private:
    map<string, const void*> pairs;
  };

  class JSONConverter {
  public:
    static void ConvertJSON(Output& JsonData);
  };
}