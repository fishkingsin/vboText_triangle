#include "testApp.h"
void addFace(vector<ofVec3f> &pos,vector<ofFloatColor> &color,vector<ofVec3f> &normal, ofVec3f a, ofVec3f b, ofVec3f c) {
    
	ofVec3f _normal = ((b - a).cross(c - a)).normalize();
    ofFloatColor _color = ofFloatColor::fromHsb(ofRandom(0.1,0.15),1.0,1.0);
    pos.push_back(a);
    pos.push_back(b);
    pos.push_back(c);
    
    color.push_back(_color);
    color.push_back(_color);
    color.push_back(_color);
    
    normal.push_back(_normal);
    normal.push_back(_normal);
    normal.push_back(_normal);
    //	mesh.addNormal(normal);
    //    mesh.addColor(color);
    //	mesh.addTexCoord(a);
    //    mesh.addVertex(a);
    //
    //    mesh.addNormal(normal);
    //    mesh.addColor(color);
    //	mesh.addTexCoord(b);
    //	mesh.addVertex(b);
    //
    //	mesh.addNormal(normal);
    //    mesh.addColor(color);
    //	mesh.addTexCoord(c);
    //	mesh.addVertex(c);
}

//--------------------------------------------------------------
void addFace(vector<ofVec3f> &pos,vector<ofFloatColor> &color,vector<ofVec3f> &normal, ofVec3f a, ofVec3f b, ofVec3f c, ofVec3f d) {
	addFace(pos,color,normal, a, b, c);
	addFace(pos,color,normal, a, c, d);
}
//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    total = 0;
    int width = ofGetWidth();
    int height = ofGetHeight();
    int step = 40;
    
    WIDTH = width*1.0/step;
    HEIGHT = height*1.0/step;
    
    
    for(int y = 0 ; y < height-step ;y+=step)
    {
        for (int x = 0; x < width-step; x+=step) {
            
            ofVec3f nw = ofVec3f( x, y , 0);
			ofVec3f ne = ofVec3f( x + step, y, 0);
			ofVec3f sw = ofVec3f( x, y + step, 0);
			ofVec3f se = ofVec3f( x + step, y + step, 0);
			
            
            
            addFace(pos,color,normal,nw,ne,se,sw);
            total+=6;
            
        }
    }
    vbo.setVertexData(pos.data(), total, GL_DYNAMIC_DRAW);
    
	vbo.setColorData(color.data(), total, GL_DYNAMIC_DRAW);
	vbo.setNormalData(normal.data(), total, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255);
	
    
    
	vbo.bind();
	vbo.updateVertexData(pos.data(), total);
	vbo.updateColorData(color.data(), total);
	vbo.updateNormalData(normal.data(), total);
    
    //	int step = 40;
    //
    //
    //
    //    int width = ofGetWidth();
    //    int height = ofGetHeight();
    
    //    vbo.draw(GL_TRIANGLE_FAN, 0,total);
    
    for(int y = 0 ; y < HEIGHT ;y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
			for(int k = 0 ; k<2 ; k++)
            {
                
                int index = ((y*HEIGHT+x) * 3 )* k*3;
                vbo.draw(GL_TRIANGLE_FAN, index,3);
                
            }
		}
	}
    
	vbo.unbind();
	
	ofPopMatrix();
    
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