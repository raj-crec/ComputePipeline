#include <Output.h>

using namespace ComputePipeline;

Output::~Output() {

  delete m_output;
  delete m_metadata;
}

void Output::SetOutput(void* output) { 
  
  if (m_output)
    delete m_output;

  m_output = output; 
}

void Output::SetMetaData(MetaData* mData) { 

  if (m_metadata)
    delete m_metadata;

  m_metadata = mData; 
}