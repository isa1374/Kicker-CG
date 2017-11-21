//
//  Plane.h
//  KickerFP
//
//  Created by Karla on 20/11/17.
//  Copyright © 2017 Isa. All rights reserved.
//

#ifndef Plane_h
#define Plane_h

class Plane{
public:
    Plane(int w, int h);
    ~Plane();
    void display(int stepSize, float *color);
private:
    int m_w, m_h;
    float specularMat0[3], shine;
};

#endif /* Plane_h */
