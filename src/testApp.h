#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    ofVbo vbo;
	vector<ofVec3f> pos;//[GRID_WIDTH*GRID_HEIGHT*LENGTH];
	vector<ofVec3f> normal;//[GRID_WIDTH*GRID_HEIGHT*LENGTH];
	vector<ofFloatColor> color;//[GRID_WIDTH*GRID_HEIGHT*LENGTH];
	ofVec3f center;
	int total;
    int WIDTH;
    int HEIGHT;
	int space;
};
