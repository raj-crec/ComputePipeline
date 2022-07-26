
#include <ItemLoaders/URLLoader.h>

using namespace ComputePipeline;

[[nodiscard]]
char* URLLoader::LoadItem(const string& uri) {

  if ((uri.find(URI_HTTP_PREFIX) == 0) || (uri.find(URI_HTTPS_PREFIX) == 0)) {

    std::cout << "Loading item from URL: " + uri << std::endl;

    // @todo: Implementation
    // @todo: A 'synchronous fetch' of the destination resource.
  }

  return nullptr;
}