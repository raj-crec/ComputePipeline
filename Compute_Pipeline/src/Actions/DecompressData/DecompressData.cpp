#include <Actions/DecompressData/DecompressData.h>

using namespace ComputePipeline;

bool DecompressData::Decompress(Output& inputData) {

  bool result = false;

  // Before de-compression
  m_compressedData = inputData.GetOutput();
  m_metaData = inputData.GetMetaData();

  if (!IsCorrectFormat())
    goto PostProcess;

  // Will modify m_decompressedData and m_metaData in the process.
  if (!Decompress())
    goto PostProcess;

  // After de-compression
  inputData.SetOutput(m_decompressedData);
  result = true;

  PostProcess:
  m_compressedData = nullptr;
  m_decompressedData = nullptr;
  m_metaData = nullptr;
  return result;
}