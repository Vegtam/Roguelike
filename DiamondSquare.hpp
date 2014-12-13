/*
Copyright (c) 2009, Travis Archer
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
in the documentation and/or other materials provided with the distribution.

Neither the name of Morningside College nor the names of its contributors may be used to endorse or promote products derived 
from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/***************************************************************
*Fractal Terrain Generator
*created by Travis Archer
*
*This program creates a Fractal Terrain, using the
*	Diamond-Square technique described by Gavin S. P. Miller.
*
*1.0 initalizes variables (there are many)
*2.0 the map is created, this is the interesting part
*3.0 the map is outputted to a bitmap file. It should be noted
*	that the map is only a series of numbers before this step.
*	This step finds the flood level, and creates colors
*	accordingly. This part may be as interesting as 2.0 to some
*4.0 a webpage is created, displaying the bitmap
****************************************************************/
#ifndef DIAMONDSQUARE_HPP
#define	DIAMONDSQUARE_HPP
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

class DiamondSquare {
public:
    DiamondSquare();
    DiamondSquare(const DiamondSquare& orig) ;
    virtual ~DiamondSquare();  
    static const unsigned hgrid = 65;
    static const unsigned vgrid = 65;
    float map[hgrid][vgrid];//make the empty array
    float min, max;       
   
    
    void generateMap();
    void printMap(int type);  
    
    
    
private:
    void makeBlankMap();
    
    void fillMap();
    float random(float max);
   
    struct color{
	//v[0]=red, v[1]=green, v[2]=blue
	unsigned char v[3];
	
	color(unsigned char r, unsigned char g, unsigned char b){
		v[0]=r;
		v[1]=g;
		v[2]=b;
	}
    };
    
    color lerp(color c1, color c2, float value);

};

#endif	/* DIAMONDSQUARE_HPP */

