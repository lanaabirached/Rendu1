//
//  ziphone.h
//  Rendu1
//
//  Created by Lana macbook on 27/02/14.
//  Copyright (c) 2014 Lana macbook. All rights reserved.
//

#ifndef Rendu1_ziphone_h
#define Rendu1_ziphone_h

class Ziphone {

private:
    
    float x, y, z;
    
    float mass;
    
public:
    
    int color;
    
    // constructor
    Ziphone();
    Ziphone(float x, float y, float z);
    
    // getters
    float getVolume();
    float getDensity();
    float getMass();
    
    // setters
    void setMass(float m);
    
    // operators
    Ziphone operator+(Ziphone& z);
    
    // destructors
    ~Ziphone();
};

#endif
