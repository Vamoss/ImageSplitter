#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
#define N 200
	
	ofImage image;
	ofImage imageToSave;

	image.loadImage("image.jpg");

	unsigned char subRegion[ N * N * 3  ];  // R G B   
	unsigned char * videoPixels = image.getPixels();  

	int mainPixelPos, subPixlPos, width, height, xIn, yIn, xOut, yOut;
	string outputName;

	width = image.width;
	height = image.height;

	for (yIn = 0; yIn < height-N; yIn += N)
	{
		for (xIn = 0; xIn < width-N; xIn += N)
		{
			for (yOut = 0; yOut < N; yOut++){  

				for (xOut = 0; xOut < N; xOut++)
				{  

					mainPixelPos = ((xOut+xIn) * width + (yOut+yIn)) * 3;  
					subPixlPos = (xOut * N + yOut) * 3;  
					
					subRegion[subPixlPos]		= videoPixels[mainPixelPos];   // R  
					subRegion[subPixlPos + 1]	= videoPixels[mainPixelPos + 1];  // G  
					subRegion[subPixlPos + 2]	= videoPixels[mainPixelPos + 2];  // B  
				}
			}

			outputName = "image_" + ofToString(xIn) + "_" + ofToString(yIn) + ".jpg";

			imageToSave.setFromPixels(subRegion, N, N, OF_IMAGE_COLOR);
			imageToSave.saveImage(outputName, OF_IMAGE_QUALITY_BEST);
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}