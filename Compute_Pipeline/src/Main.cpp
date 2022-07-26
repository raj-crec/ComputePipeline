// main.cpp : Defines the entry point for the application.
// Demonstrates the client/test code for the compute-pipeline, as per the requirement of the given assignment.
// The pipeline is flexible enough to be set up as per client's requirements, based on the required action handlers.
// Each action handler, in turn, is flexible enough to support the desired image formats/compressed data formats/load destination types.

// Item-Loaders and Load-Item-Handler
#include <ItemLoaders/FileLoader.h>
#include <ItemLoaders/URLLoader.h>
#include <ItemLoaders/BundleLoader.h>
#include <ActionHandlers/LoadItemHandler.h>

// Image-Decoders and Image-Handler
#include <Actions/DecodeImage/ImageFormat1.h>
#include <Actions/DecodeImage/ImageFormat2.h>
#include <ActionHandlers/ImageHandler.h>

// Data-Decompressors and Compressed-Data-Handler
#include <Actions/DecompressData/CompressedFormat1.h>
#include <Actions/DecompressData/CompressedFormat2.h>
#include <ActionHandlers/CompressedDataHandler.h>

// JSON Handler
#include <ActionHandlers/JSONHandler.h>

#include <Pipeline.h>
#include <assert.h>

using namespace std;
using namespace ComputePipeline;

LoadItemHandler* SetUpLoadItemHandler() {

	// Create ItemLoaders.
	FileLoader* fLoader = new FileLoader();
	assert(fLoader);

	URLLoader* uLoader = new URLLoader();
	assert(uLoader);

	BundleLoader* bLoader = new BundleLoader();
	assert(bLoader);

	// Flexibility to add item-loaders based on your need and order-preference.
	LoadItemHandler* loadItemAction = new LoadItemHandler();
	assert(loadItemAction);

	loadItemAction->Insert(fLoader);
	loadItemAction->Insert(uLoader);
	loadItemAction->Insert(bLoader);

	return loadItemAction;
}

ImageHandler* SetUpImageHander() {

	// Create image decoders
	ImageFormat1* imf1Decoder = new ImageFormat1();
	assert(imf1Decoder);

	ImageFormat2* imf2Decoder = new ImageFormat2();
	assert(imf2Decoder);

	// Flexibility to add image-decoders based on your need and order-preference.
	ImageHandler* decodeImageAction = new ImageHandler();
	assert(decodeImageAction);

	decodeImageAction->Insert(imf1Decoder);
	decodeImageAction->Insert(imf2Decoder);

	return decodeImageAction;
}

CompressedDataHandler* SetUpCompressedDataHandler() {

	// Create data-decompressors
	CFormat1* cmf1Decompressor = new CFormat1();
	assert(cmf1Decompressor);

	CFormat2* cmf2Decompressor = new CFormat2();
	assert(cmf2Decompressor);

	// Flexibility to add data-decompressors based on your need and order-preference.
	CompressedDataHandler* decompressDataAction = new CompressedDataHandler();
	assert(decompressDataAction);

	decompressDataAction->Insert(cmf1Decompressor);
	decompressDataAction->Insert(cmf2Decompressor);

	return decompressDataAction;
}

JSONHandler* SetUpJSONHandler() {

	JSONHandler* jsonHandler = new JSONHandler();
	assert(jsonHandler);

	return jsonHandler;
}

int main()
{

	// Create the compute pipeline with the desired action handlers.
	// As per the given assignment in this case.
	Pipeline p(SetUpLoadItemHandler()); // Has to be the first action, always !
	p.Insert(SetUpCompressedDataHandler());
	p.Insert(SetUpImageHander());
	p.Insert(SetUpJSONHandler());
  

  // Submit actions to the pipeline.

  // Submit action with an image file ( to be decoded ).
	// Any no. of image formats can be supported through the 'DecodeImage' hierarchy.
	p.Submit("file://C:\\Users\\rajab\\Documents\\C++\\IMG.LY\\Test\\test.jpg");

	// Submit action with a compressed file ( to be decompressed ).
	// Any no. of compression formats can be supported through the 'DecompressData' hierarchy.
	p.Submit("file://C:\\Users\\rajab\\Documents\\C++\\IMG.LY\\Test\\test.zip");

	// Submit action with a json file ( to be converted to a C++ object ).
	p.Submit("file://C:\\Users\\rajab\\Documents\\C++\\IMG.LY\\Test\\test.json");

	// @todo: TEST NETWORK FILE PATHS.

	// URL Examples
  p.Submit("http://www.test-url.com/test.jpg");
	p.Submit("https://www.test-url.com/test.zip");
	p.Submit("https://www.test-url.com/test.json");

	// App Bundle Examples
	p.Submit("bundle://<local-or-network-path-to-bundle>/test.aab/test.jpg");
	p.Submit("bundle://<local-or-network-path-to-bundle>/test.aab/test.zip");
	p.Submit("bundle://<local-or-network-path-to-bundle>/test.aab/test.json");

	// @todo: Finally, need to clean-up the pipeline.

	return 0;
}