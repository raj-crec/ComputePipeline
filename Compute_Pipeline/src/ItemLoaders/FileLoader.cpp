
#include <filesystem>
#include <fstream>
#include <ItemLoaders/FileLoader.h>
#include <assert.h>

using namespace ComputePipeline;
using std::cout, std::endl;
namespace fs = std::filesystem;

using fs::path;
using std::ifstream, std::ios;

[[nodiscard]]
char* FileLoader::LoadItem(const string& uri) {

  if (uri.find(URI_FILE_PREFIX) != 0)
    return nullptr;

  path filePath = uri.substr(strlen(URI_FILE_PREFIX));

  cout << "Loading item from a file at: " << filePath << endl;

  if (fs::exists(filePath) && fs::is_regular_file(filePath) && !fs::is_empty(filePath)) {

    // open file 
    ifstream file(filePath, ios::in || ios::binary);
    if (!file.is_open())
      return nullptr;

    // size of the file in bytes.
    const uintmax_t size = fs::file_size(filePath);

    char* pContent = (char*)calloc(1,size);
    assert(pContent);

    file.seekg(0, ios::beg);
    file.read(pContent, size);

    // cout << "Read " << strlen(pContent) << " bytes." << endl;

    file.close();

    return pContent;
  }

  return nullptr;
}