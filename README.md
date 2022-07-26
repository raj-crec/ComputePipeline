# ComputePipeline

This Compute Pipeline loads a single item synchronously at a time ( from a file, network URL or an app bundle ),
and process the same through the pipeline.

At each stage of the pipeline, it is possible to mark an item as processed, so that later stages of the pipeline ignore the same.
Here, we have done this for an image ( after it is decoded ), and for a JSON item ( after it is converted to a C++ object).
On the other hand, a compressed item is decompressed and then passed through the remaining stages of the pipeline ( until it is decoded or converted to a C++ object ). For this reason, the decompression stage is always the 2nd stage in the pipeline.
However, the pipeline is flexible enough to be setup as per the available handlers, and in any presumed order.

Building
--------
Please download the repo and open 'Compute_Pipeline' folder.
Generate CMake Cache and fire the build thereafter.

Testing
-------
Main.cpp acts as a testing tool, as well as a client demonstration.
Implementation has been done using Visual Studio 2019, and the build that has been tested has been configured using x64-Debug ( using CMake ).
Also, due to implementation limitations,
* Image Handler always processes an incoming item as an image, and marks it as processed.
  The item doesn't get processed by other handlers down the 'pipeline'.
* Compressed Data Handler always processes the incoming item as compressed data.
  However, the item does get processed by other handlers down the 'pipeline', as the compressed data handler never marks an item as 'processed'.
* Items that get loaded from an URL or an app-bundle never get processed, as no data gets loaded really.


TODO
----
1) Try-Catch usage ( basically, deal with exceptions ).
2) Deal with asynchronous loading and handling ( Concurrency )
3) Memory management ( cleanup of the pipeline, including all it's handlers )

Awaiting further discussions !
