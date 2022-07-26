# CMakeList.txt : CMake project for Compute_Pipeline, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Compute_Pipeline" VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source to this project's executable.
add_executable (Compute_Pipeline "src/Pipeline.cpp" "include/Pipeline.h" "src/Main.cpp" "include/ItemLoaders/ItemLoader.h"  "include/ItemLoaders/FileLoader.h" "include/ItemLoaders/URLLoader.h" "include/ItemLoaders/BundleLoader.h" "src/ItemLoaders/BundleLoader.cpp" "src/ItemLoaders/FileLoader.cpp" "src/ItemLoaders/URLLoader.cpp"  "src/Actions/DecodeImage/DecodeImage.cpp" "src/Actions/DecompressData/CompressedFormat1.cpp" "src/Actions/JSONConverter.cpp" "include/Actions/DecompressData/DecompressData.h" "include/Actions/JSONConverter.h" "include/Actions/DecodeImage/DecodeImage.h"  "include/ActionHandlers/ActionHandler.h" "include/ActionHandlers/LoadItemHandler.h" "include/ActionHandlers/CompressedDataHandler.h" "include/ActionHandlers/JSONHandler.h" "src/ActionHandlers/ImageHandler.cpp" "src/ActionHandlers/CompressedDataHandler.cpp" "src/ActionHandlers/JSONHandler.cpp" "src/ActionHandlers/LoadItemHandler.cpp" "include/Actions/DecompressData/CompressedFormat1.h" "include/Actions/DecompressData/CompressedFormat2.h" "src/Actions/DecompressData/CompressedFormat2.CPP" "src/Actions/DecompressData/DecompressData.cpp" "include/Actions/DecodeImage/ImageFormat1.h" "include/Actions/DecodeImage/ImageFormat2.h" "src/Actions/DecodeImage/ImageFormat1.cpp" "src/Actions/DecodeImage/ImageFormat2.cpp" "include/MetaData.h" "src/Output.cpp" "include/Output.h" )

# TODO: Add tests and install targets if needed.
