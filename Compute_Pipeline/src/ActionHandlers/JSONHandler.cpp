#include <ActionHandlers/JSONHandler.h>
#include <Pipeline.h>

using namespace ComputePipeline;
using std::cout, std::endl;

void JSONHandler::Handle(Pipeline* p, const string uri) {

  ComputePipeline::Output& inData = p->GetData();
  if (inData.GetMetaData()->m_processed)
    return;

  cout << endl << "===================" << endl;
  cout << "Handling JSON Data" << endl;
  cout << "===================" << endl;

  if (IsJsonData(inData))
    JSONConverter::ConvertJSON(inData);
}

bool JSONHandler::IsJsonData(const Output& data) {

  // @todo: Use a third-party library perhaps ??

  return true;
}