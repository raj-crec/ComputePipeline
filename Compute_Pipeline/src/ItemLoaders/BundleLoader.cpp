
#include <ItemLoaders/BundleLoader.h>

using namespace ComputePipeline;

[[nodiscard]]
char* BundleLoader::LoadItem(const string& uri) {

  if (uri.find(URI_BUNDLE_PREFIX) == 0) {

    std::cout << "Loading item from an application bundle at: " + uri << std::endl;

    // @todo: Implementation
    // @todo: Extract app bundle name and item name.
    // Load app bundle and read item from the same.
  }

  return nullptr;
}

