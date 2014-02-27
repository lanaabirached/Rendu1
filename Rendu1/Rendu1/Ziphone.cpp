//
//  Ziphone.cpp
//  Rendu1
//
//  Created by Lana macbook on 27/02/14.
//  Copyright (c) 2014 Lana macbook. All rights reserved.
//

#include "Ziphone.h"

Ziphone::Ziphone()
{
    x = 1;
    y = 1;
    z = 1;
    
    mass = 10;
}

Ziphone::Ziphone(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    
    mass = 10;
}

float Ziphone::getVolume()
{
    return x * y * z;
}

float Ziphone::getDensity()
{
    return mass/getVolume();
}

void Ziphone::setMass(float m)
{
    this->mass = m;
}

float Ziphone::getMass()
{
    return this->mass;
}

Ziphone Ziphone::operator+(Ziphone &z)
{
    Ziphone res;
    
    res.mass = this->mass + z.mass;
    
    return res;
}

Ziphone::~Ziphone()
{
}