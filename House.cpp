//
//  House.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Brittany Factura on 10/5/15.
//  Copyright (c) 2015 RexWest. All rights reserved.
//

#include "House.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"
#include "Camera.h"

House::House(float size) : Drawable()
{
    this->size = size;
}

House::~House()
{
    //Delete any dynamically allocated memory/objects here
}

void House::draw(DrawData& data)
{

    // This data structure defines a simple house
    
//    int nVerts = 42;    // your vertex array needs to have this many entries
    
    // These are the x,y,z coordinates of the vertices of the triangles
    float vertices[] = {
        -4,-4,4, 4,-4,4, 4,4,4, -4,4,4,     // front face
        -4,-4,-4, -4,-4,4, -4,4,4, -4,4,-4, // left face
        4,-4,-4,-4,-4,-4, -4,4,-4, 4,4,-4,  // back face
        4,-4,4, 4,-4,-4, 4,4,-4, 4,4,4,     // right face
        4,4,4, 4,4,-4, -4,4,-4, -4,4,4,     // top face
        -4,-4,4, -4,-4,-4, 4,-4,-4, 4,-4,4, // bottom face
        
        -20,-4,20, 20,-4,20, 20,-4,-20, -20,-4,-20, // grass
        -4,4,4, 4,4,4, 0,8,4,                       // front attic wall
        4,4,4, 4,4,-4, 0,8,-4, 0,8,4,               // left slope
        -4,4,4, 0,8,4, 0,8,-4, -4,4,-4,             // right slope
        4,4,-4, -4,4,-4, 0,8,-4};                   // rear attic wall
    
    // These are the RGB colors corresponding to the vertices, in the same order
    float colors[] = {
        1,0,0, 1,0,0, 1,0,0, 1,0,0,  // front is red
        0,1,0, 0,1,0, 0,1,0, 0,1,0,  // left is green
        1,0,0, 1,0,0, 1,0,0, 1,0,0,  // back is red
        0,1,0, 0,1,0, 0,1,0, 0,1,0,  // right is green
        0,0,1, 0,0,1, 0,0,1, 0,0,1,  // top is blue
        0,0,1, 0,0,1, 0,0,1, 0,0,1,  // bottom is blue
        
        0,0.5,0, 0,0.5,0, 0,0.5,0, 0,0.5,0, // grass is dark green
        0,0,1, 0,0,1, 0,0,1,                // front attic wall is blue
        1,0,0, 1,0,0, 1,0,0, 1,0,0,         // left slope is green
        0,1,0, 0,1,0, 0,1,0, 0,1,0,         // right slope is red
        0,0,1, 0,0,1, 0,0,1,};              // rear attic wall is red
    
    // The index data stores the connectivity of the triangles;
    // index 0 refers to the first triangle defined above
    int indices[] = {
        0,2,3,    0,1,2,      // front face
        4,6,7,    4,5,6,      // left face
        8,10,11,  8,9,10,     // back face
        12,14,15, 12,13,14,   // right face
        16,18,19, 16,17,18,   // top face
        20,22,23, 20,21,22,   // bottom face
        
        24,26,27, 24,25,26,   // grass
        28,29,30,             // front attic wall
        31,33,34, 31,32,33,   // left slope
        35,37,38, 35,36,37,   // right slope
        39,40,41};            // rear attic wall
    
    material.apply();
    
    //Set the OpenGL Matrix mode to ModelView (used when drawing geometry)
    glMatrixMode(GL_MODELVIEW);
    
    //Push a save state onto the matrix stack, and multiply in the toWorld matrix
    glPushMatrix();
    glMultMatrixf(toWorld.ptr());
    
    //Make house!
    glBegin(GL_TRIANGLES);
    
    //    glColor3f(1, 0, 0);       //color at index 0
    //    glVertex3f(-4, -4, 4);    //color at index 0
    //    glColor3f(1, 0, 0);       //color at index 2
    //    glVertex3f(4, 4, 4);      //color at index 2
    //    glColor3f(1, 0, 0);       //color at index 3
    //    glVertex3f(-4, 4, 4);     //color at index 3

    for (int i = 0; i < 60; i++) {
        int index = 3 * indices[i];
        glColor3f(colors[index], colors[index+1], colors[index+2]);
        glVertex3f(vertices[index], vertices[index+1], vertices[index+2]);
    }
    
    glEnd();
    
    //Pop the save state off the matrix stack
    //This will undo the multiply we did earlier
    glPopMatrix();
}