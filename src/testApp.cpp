#include "testApp.h"
void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c) {

	ofVec3f normal = ((b - a).cross(c - a)).normalize();
        ofFloatColor color = ofFloatColor::fromHsb(ofRandom(0.1,0.15),1.0,1.0);
	mesh.addNormal(normal);
    mesh.addColor(color);
	mesh.addTexCoord(a);
    mesh.addVertex(a);
	
    mesh.addNormal(normal);
    mesh.addColor(color);
	mesh.addTexCoord(b);
	mesh.addVertex(b);
    
	mesh.addNormal(normal);
    mesh.addColor(color);
	mesh.addTexCoord(c);
	mesh.addVertex(c);
}

//--------------------------------------------------------------
void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d) {
	addFace(mesh, a, b, c);
	addFace(mesh, a, c, d);
}
//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    total = 0;
    int width = ofGetWidth();
    int height = ofGetHeight();
    int step = 40;
    mesh.setUsage(GL_DYNAMIC_DRAW);
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    for(int y = 0 ; y < height-step ;y+=step)
    {
        for (int x = 0; x < width-step; x+=step) {
            
            ofVec3f nw = ofVec3f( x, y , 0);
			ofVec3f ne = ofVec3f( x + step, y, 0);
			ofVec3f sw = ofVec3f( x, y + step, 0);
			ofVec3f se = ofVec3f( x + step, y + step, 0);
			
			addFace(mesh, nw, ne, se, sw);


        }
    }
    total = mesh.getNumVertices();
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0 ; i <  total; i+=3)
    {
        float col = (i/3.0f)/ofGetHeight();
        ofFloatColor color = mesh.getColors()[i];
        float row = (i/3.0f)/ofGetWidth();
        float alpha = ofSignedNoise(sin(i*1.0f/total),cos(row),ofGetElapsedTimef()*.6);

        color.a = alpha;
        mesh.setColor(i, color);
        mesh.setColor(i+1, color);
        mesh.setColor(i+2, color);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    mesh.drawFaces();
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