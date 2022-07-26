#include <Actions/DecodeImage/ImageFormat2.h>

using namespace ComputePipeline;

bool ImageFormat2::Decode() {

  cout << "Decoding as per image-format-2" << endl;

  // @todo: Implement decoding, perhaps in various stages.
  // Allocate for and populate m_decodedImage.

  m_metaData->m_type = DataType::DECODED_IMAGE_FORMAT2;
  m_metaData->m_processed = true; // No more actions are applicable.

  return true;
}

const string& ImageFormat2::GetImageHeader() const {

  cout << "Returning Header as per image-format-2" << endl;

  // @todo: Read header based on image-Format-2, and allocate a new string buffer.

  return "";
}

bool ImageFormat2::IsCorrectFormat() const {

  const string& header = GetImageHeader();

  cout << "Checking Header as per image-Format-2" << endl;

  // Implement header-check as per image-Format-2

  return false;
}