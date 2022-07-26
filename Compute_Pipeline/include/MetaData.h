#pragma once

namespace ComputePipeline {

  // @todo: Add new compressed-file-types and image-file-types here.
  enum class DataType { 
    UNKNOWN,
    DECOMPRESSED_FORMAT1, 
    DECOMPRESSED_FORMAT2, 
    DECODED_IMAGE_FORMAT1, 
    DECODED_IMAGE_FORMAT2, 
    JSON_OBJECT 
  };

  // Thoughts around meta-data. 
  // This class can be inherited from to create meta-data classes required for each action-type.
  class MetaData {
  public:
    size_t m_size; // in bytes.
    DataType m_type = DataType::UNKNOWN; // can be set after a particular item has been processed by an action, to be used by the next action if required.
    bool m_processed = false;
  };
}