#include <Actions/DecompressData/CompressedFormat2.h>

using namespace ComputePipeline;

bool CFormat2::Decompress() {

  cout << "De-Compressing as per C-Format-2" << endl;

  // @todo: Implement de-compression, perhaps in various stages.
  // Allocate for and populate m_decompressedData.
 
  m_metaData->m_type = DataType::DECOMPRESSED_FORMAT2;

  return true;
}

const string& CFormat2::GetDataHeader() const {

  cout << "Returning Header as per C-Format-2" << endl;

  // @todo: Read header based on C-Format-2, and allocate a new string buffer.

  return "";
}

bool CFormat2::IsCorrectFormat() const {

  const string header = GetDataHeader();

  cout << "Checking Header as per C-Format-2" << endl;

  // Implement header-check as per C-Format-2

  return false;
}