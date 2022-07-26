#include <Actions/DecompressData/CompressedFormat1.h>

using namespace ComputePipeline;

bool CFormat1::Decompress() {

  cout << "De-Compressing as per C-Format-1" << endl;

  // @todo: Implement de-compression, perhaps in various stages.
  // Allocate for and populate m_decompressedData.

  m_metaData->m_type = DataType::DECOMPRESSED_FORMAT1;

  return true;
}

const string& CFormat1::GetDataHeader() const {

  cout << "Returning Header as per C-Format-1" << endl;

  // @todo: Read header based on C-Format-1, and allocate a new string buffer.

  return "";
}

bool CFormat1::IsCorrectFormat() const {

  const string& header = GetDataHeader();

  cout << "Checking Header as per C-Format-1" << endl;

  // Implement header-check as per C-Format-1

  return true;
}