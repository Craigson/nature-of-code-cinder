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
    // Every cell is an individual quad
    // (could use quad_strip here, but produces funny results, investigate this)
    for( int x = 0; x < z.size() - 1; x++ )
    {
		for( int y = 0; y < z[x].size() - 1; y++ )
		{
			
			// one quad at a time
			// each quad's color is determined by the height value at each vertex
			// (clean this part up)
			
			// There are more efficient ways to do this, but perhaps the easiest to explain
			
			glPushMatrix();
			gl::translate( Vec3f( ( x * scl ) - ( w / 2 ), ( y * scl ) - ( h / 2 ), -160 ) );
			
			// draw the quad
			gl::color( .6, .6, .6 );
			gl::begin( GL_QUADS );
			gl::vertex( 0, 0, z[x][y] );
			gl::vertex( scl, 0, z[x+1][y] );
			gl::vertex( scl, scl, z[x+1][y+1] );
			gl::vertex( 0, scl, z[x][y+1] );
			gl::end();
			
			// draw the outlines
			gl::color( 0, 0, 0 );
			gl::begin( GL_LINES );
			gl::vertex( 0, 0, z[x][y] );				// side 1
			gl::vertex( scl, 0, z[x+1][y] );
			gl::vertex( scl, 0, z[x+1][y] );		// side 2
			gl::vertex( scl, scl, z[x+1][y+1] );
			gl::vertex( scl, scl, z[x+1][y+1] );	// side 3
			gl::vertex( 0, scl, z[x][y+1] );
			gl::vertex( 0, scl, z[x][y+1] );		// line 4
			gl::vertex( 0, 0, z[x][y] );
			gl::end();
			
			glPopMatrix();
		}
    }
}
