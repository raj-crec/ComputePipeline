#include <ActionHandlers/ImageHandler.h>
#include <Pipeline.h>

using namespace ComputePipeline;

void ImageHandler::Handle(Pipeline* p, const string uri) {

  ComputePipeline::Output& inData = p->GetData();
  if (inData.GetMetaData()->m_processed)
    return;

  cout << endl << "===================" << endl;
  cout << "Handling Image Data" << endl;
  cout << "===================" << endl;

  for (auto decoder : m_decoders) {
    if (decoder->Decode(inData))
      return;
  }
}