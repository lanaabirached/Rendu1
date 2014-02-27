//
//  main.cpp
//  Rendu1
//
//  Created by Lana macbook on 26/02/14.
//  Copyright (c) 2014 Lana macbook. All rights reserved.
//

#include <iostream>

#include "Ziphone.h"

using namespace std;

int main(int argc, const char * argv[])
{

    Ziphone Vinney = Ziphone(1, 42, 5);
    Ziphone Antoni = Ziphone();
    
    Ziphone Valou = Vinney + Antoni;
    
    cout << Vinney.getMass() << " + " << Antoni.getMass() << " = " << Valou.getMass() << endl;
    
    return 0;
}

