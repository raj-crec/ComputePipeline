// Compute_Pipeline.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>
#include <string>

#include <Output.h>
#include <ActionHandlers/ActionHandler.h>
#include <ActionHandlers/LoadItemHandler.h>

using std::vector;
using std::string;

namespace ComputePipeline {

  class Pipeline {

  public:
    Pipeline(LoadItemHandler* handler);
    void Insert(ActionHandler* handler);
    void Submit(const string& uri);
    void SetData(void* output, MetaData* metaData = nullptr); // deletes previous output as well as meta-data.
    Output& GetData() { return m_data; }

  private:
    vector<ActionHandler* > m_actionHandlers;
    Output m_data;  // To store output/meta-data at the end of each stage.
  };
}
