#include <Actions/DecodeImage/ImageFormat1.h>

using namespace ComputePipeline;

bool ImageFormat1::Decode() {

  cout << "Decoding as per image-format-1" << endl;

  // @todo: Implement decoding, perhaps in various stages.
  // Allocate for and populate m_decodedImage.

  m_metaData->m_type = DataType::DECODED_IMAGE_FORMAT1;
  m_metaData->m_processed = true; // No more actions are applicable.

  return true;
}

const string& ImageFormat1::GetImageHeader() const {

  cout << "Returning Header as per image-format-1" << endl;

  // @todo: Read header based on image-Format-1, and allocate a new string buffer.

  return "";
}

bool ImageFormat1::IsCorrectFormat() const {

  const string& header = GetImageHeader();

  cout << "Checking Header as per image-Format-1" << endl;

  // Implement header-check as per image-Format-1

  return true;
}