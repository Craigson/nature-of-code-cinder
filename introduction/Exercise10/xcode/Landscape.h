/*
 *  Landscape.h
 *  Exercise10
 *
 *  Created by Nathan Koch on 1/1/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

typedef std::shared_ptr<class Landscape> LandscapeRef;

class Landscape {
	
  public:
	
	Landscape(int scl_, int w_, int h_);
	
	void update();
	void draw();
	
    int scl;
    int w, h;
    int rows, cols;
    float zoff = 0.0;
    ci::Perlin perlin;
    std::vector<std::vector<float> > z;
};
