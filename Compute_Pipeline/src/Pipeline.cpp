// Compute_Pipeline.cpp : 
//

#include <Pipeline.h>
#include <Output.h>
#include <assert.h>

using namespace ComputePipeline;
using std::cout, std::endl;

Pipeline::Pipeline(LoadItemHandler* handler) {
  m_actionHandlers.push_back(handler);
}

void Pipeline::Insert(ActionHandler* handler) {
  m_actionHandlers.push_back(handler);
}

void Pipeline::Submit(const string& uri) {

  assert(!m_actionHandlers.empty());
  
  if (uri.empty())
    return;

  m_actionHandlers[0]->Handle(this, uri);  // First action is always a load-action.

  if (m_data.GetOutput() == nullptr) {

    cout << "No data could be loaded for processing." << endl;
    return;
  }

  for (auto i = m_actionHandlers.begin() + 1; i != m_actionHandlers.end(); ++i)
    (*i)->Handle(this);

  cout << "\nProcessing done ..." << endl;
}

void Pipeline::SetData(void* output, MetaData* metaData) {

  m_data.SetOutput(output);
  m_data.SetMetaData(metaData);
}

