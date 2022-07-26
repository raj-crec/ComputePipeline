#include <assert.h>

#include "Actions/JSONConverter.h"

using namespace ComputePipeline;

void JSONConverter::ConvertJSON(Output& JsonData) {

  Object* ret = new Object();
  assert(ret != nullptr);

  //// For each <string, string> JSON string
  //ret->Set(key1, &val1);
  //ret->Set(key2, &val2);
 
  //// For each <string, object> JSON string
  //ret->Set(key1, &(JSONConverter::ConvertJSON(jsonString)));

  JsonData.GetMetaData()->m_type = DataType::JSON_OBJECT;
  JsonData.GetMetaData()->m_processed = true; // No more actions are applicable.
  JsonData.SetOutput(ret);
}

Object::~Object() {

  for (auto pair : pairs)
    delete pair.second;
}

void Object::Set(const string& key, const void* val) {

  assert((!key.empty()) && (val != nullptr));

  pairs[key] = val;
}



