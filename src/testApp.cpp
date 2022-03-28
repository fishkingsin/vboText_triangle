#include "testApp.h"
void addFace(vector<ofVec3f> &pos,vector<ofFloatColor> &color,vector<ofVec3f> &normal, ofVec3f a, ofVec3f b, ofVec3f c) {
    
	ofVec3f _normal = ((b - a).cross(c - a)).normalize();
    ofFloatColor _color = ofFloatColor::fromHsb(ofRandom(0.5,0.9),1.0,1.0);
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
    ofSetFullscreen(true);
    total = 0;
    int width = ofGetWidth();
    int height = ofGetHeight();
    int step = 80;
    
    WIDTH = width*1.0/step;
    HEIGHT = height*1.0/step;
    
    
    int row = 0;
    int col = 0;
    int space = 5;
    for(int y = 0 ; y < height ;y+=step)
    {
        row++;
        for (int x = 0; x < width; x+=step)
        {
            
            
            ofVec3f nw = ofVec3f( x + space, y + space , 0);
			ofVec3f ne = ofVec3f( x + step - space, y + space, 0);
			ofVec3f sw = ofVec3f( x + space, y + step - space, 0);
			ofVec3f se = ofVec3f( x + step - space, y + step - space, 0);
            if((col%2==0 && row%2==1) || (col%2==1 && row%2==0))
            {
                nw = nw.getRotated(90,ofVec3f( x+step*0.5, y + step*0.5, 0), ofVec3f(0,0,1));
                ne = ne.getRotated(90,ofVec3f( x+step*0.5, y + step*0.5, 0), ofVec3f(0,0,1));
                sw = sw.getRotated(90,ofVec3f( x+step*0.5, y + step*0.5, 0), ofVec3f(0,0,1));
                se = se.getRotated(90,ofVec3f( x+step*0.5, y + step*0.5, 0), ofVec3f(0,0,1));
            }
            addFace(pos,color,normal,nw,ne,se,sw);
            total+=6;
            col++ ;
        }
    }
    vbo.setVertexData(pos.data(), total, GL_DYNAMIC_DRAW);
    
	vbo.setColorData(color.data(), total, GL_DYNAMIC_DRAW);
	vbo.setNormalData(normal.data(), total, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void testApp::update(){
    
    float count = 0;
    float count2 = 0;
    for(int i = 0 ; i< total ;i+=3)
    {
        float a = sin((count-=1.1)+ofGetElapsedTimef());
        float a2 = cos((count2+=0.07));//+ofGetElapsedTimef());
        color[i].a = a;//*a2;
        color[i+1].a = a*a2;
        color[i+2].a = a*a2;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofPushMatrix();
	ofEnableAlphaBlending();
	ofSetColor(255, 255, 255);
	
    
    
	vbo.bind();
	vbo.updateVertexData(pos.data(), total);
	vbo.updateColorData(color.data(), total);
	vbo.updateNormalData(normal.data(), total);
    
    
    for(int i = 0 ; i< total ;i+=3)
    {
        vbo.draw(GL_TRIANGLE_FAN, i,3);
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
