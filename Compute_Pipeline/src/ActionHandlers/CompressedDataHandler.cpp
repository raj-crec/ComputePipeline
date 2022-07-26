#include <ActionHandlers/CompressedDataHandler.h>
#include <Pipeline.h>

using namespace ComputePipeline;

void CompressedDataHandler::Handle(Pipeline* p, const string uri) {

  ComputePipeline::Output& inData = p->GetData();
  if (inData.GetMetaData()->m_processed)
    return;

  cout << endl << "========================" << endl;
  cout << "Handling Compressed Data" << endl;
  cout << "========================" << endl;

  for (auto handler : m_decompressors) {
    if (handler->Decompress(p->GetData()))
      return;
  }
}