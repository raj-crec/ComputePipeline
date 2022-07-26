#include <ActionHandlers/LoadItemHandler.h>
#include <Pipeline.h>
#include <assert.h>

using namespace ComputePipeline;
using std::cout, std::endl;

void LoadItemHandler::Handle(Pipeline* p, const string uri) {

  cout << "\nLoading item from storage ..." << endl;

  for (auto loader : m_loaders) {

    char* item = loader->LoadItem(uri);
    if (item != nullptr) {

      MetaData* meta = new MetaData();
      assert(meta != nullptr);

      meta->m_size = strlen(item);
      p->SetData(item, meta);

      break;
    }
  }
}