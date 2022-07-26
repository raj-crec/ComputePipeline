#pragma once

#include <MetaData.h>

// Coz the requirement mentioned about an Output Object !

namespace ComputePipeline {

  class Output {

  public:

    void* GetOutput() const { return m_output; }
    MetaData* GetMetaData() const { return m_metadata; }
    void SetOutput(void* output);
    void SetMetaData(MetaData* mData);

    ~Output();

  private:
    void* m_output = nullptr;
    MetaData* m_metadata = nullptr;
  };
}