#include <Actions/DecodeImage/DecodeImage.h>

using namespace ComputePipeline;

bool DecodeImage::Decode(Output& imageData) {

  bool result = false;

  // Before de-compression
  m_encodedImage = imageData.GetOutput();
  m_metaData = imageData.GetMetaData();

  if (!IsCorrectFormat())
    goto PostProcess;

  // Will modify m_encodedImage and m_metaData in the process.
  if (!Decode())
    goto PostProcess;

  // After de-compression
  imageData.SetOutput(m_decodedImage);
  result = true;

PostProcess:
  m_encodedImage = nullptr;
  m_decodedImage = nullptr;
  m_metaData = nullptr;
  return result;
}