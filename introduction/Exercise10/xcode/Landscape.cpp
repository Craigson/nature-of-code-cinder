/*
 *  Landscape.cpp
 *  Exercise10
 *
 *  Created by Nathan Koch on 1/1/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// header files
#include "cinder/app/AppBasic.h"
#include "cinder/Perlin.h"
#include "cinder/gl/Vbo.h"
#include "Landscape.h"

// namespaces
using namespace ci;
using namespace std;

Landscape::Landscape(int scl_, int w_, int h_) {
	scl = scl_;
    w = w_;
    h = h_;
    cols = w/scl;
    rows = h/scl;
    for (int i = 0; i < cols; i++) {
        vector<float> col;
        for (int j = 0; j < rows; j++) {
            col.push_back(0);
        }
        z.push_back(col);
    }
}

void Landscape::update( ) {
	float xoff = 0;
    for (int i = 0; i < cols; i++) {
        float yoff = 0;
        for (int j = 0; j < rows; j++) {
            z[i][j] = lmap(perlin.noise(xoff, yoff, zoff), 0.0f, 1.0f, -120.0f, 120.0f);
            yoff += 0.1;
        }
        xoff += 0.1;
    }
	zoff += 0.1;
}

void Landscape::draw( ) {
    gl::VboMesh mesh;
    
    gl::VboMesh::Layout layout;
    layout.setStaticIndices();
    layout.setStaticPositions();
    layout.setStaticColorsRGBA();
    
    int zSize = rows*cols;
    mesh = gl::VboMesh( zSize, zSize, layout, GL_QUADS );
    
    std::vector<uint32_t> indices;
    int i = 0;
    while(i < zSize) {
        indices.push_back(i);
        i++;
    }
    mesh.bufferIndices(indices);
    
    vector<Vec3f> positions;
    for (int x = 0; x < z.size() - 1; x++) {
        for (int y = 0; y < z[x].size() - 1; y++) {
            positions.push_back( Vec3f(0, 0, z[x][y]) );
            positions.push_back( Vec3f(0, 0, z[x+1][y]) );
            positions.push_back( Vec3f(scl, scl, z[x+1][y+1]) );
            positions.push_back( Vec3f(0, scl, z[x][y+1]) );
        }
    }
    mesh.bufferPositions(positions);
    
    gl::color(0.5, 0.5, 0);
    gl::translate(Vec3f(5.0f, 5.0f, 5.0f));
    gl::draw(mesh);
}
