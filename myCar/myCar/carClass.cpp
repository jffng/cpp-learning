//
//  carClass.cpp
//  myCar
//
//  Created by Jeff Ong on 4/3/14.
//  Copyright (c) 2014 jong. All rights reserved.
//

#include <iostream>
#include <vector>
#include "carClass.h"

enum ColorName{
    BLACK,
    BLUE,
    RED,
    HOT_PINK
};

enum Style{
    HATCHBACK,
    SEDAN,
    SUV,
    CROSSOVER
};

class Wheel {
public:
    Wheel() : mTread(10), mRadius(1), mIsBare(false) {
        std::cout << "Base wheel constructor" << std::endl;
    }
    Wheel(const Wheel &otherWheel) : mTread(otherWheel.mTread) {
        std::cout << "Copy wheel constructor" << std::endl;
    }
    ~Wheel(){
        std::cout << "I'm wheel and I'm destructing" << std::endl;
    }
    
    bool isAlive() {
        if(mIsBare == false) { return true; }
        else { return false; }
    }
    
    void replace(int newTread){
        std::cout << "I'm in base replace" << std::endl;
        mTread = newTread;
        mIsBare = false;
    }
    
    void loseTread(){
        mTread--;
        std::cout << "Losing tread, mTread is now: " << mTread << std::endl;
    }
    
protected:
    bool mIsBare;
    int mTread;
    int mRadius;
};

class Car {
public:
    Car() : mYearMade(2014) {
        std::cout << "Constructing a base car" << std::endl;
    }
    Car( const Wheel & wheelType ) : mYearMade(2014), mWheels(wheelType)
    {
        std::cout << "Constructing a base car" << std::endl;
    }
    
    void drive(){
        std::cout << "Driving!" << std::endl;
        if(mWheels.isAlive())
        { mWheels.loseTread(); }
        else(mWheels.replace(0));
    }
    
protected:
    int mYearMade;
    Wheel mWheels;
};

class Mazda: public Car {
public:
    Mazda(const Wheel &toyoWheels) : Car(toyoWheels) {
        std::cout << "I'm in derived Mazda constructor" << std::endl;
    }
    ~Mazda() {
        std::cout << "I'm in derived Mazda destructor" << std::endl;
    }
};

class Ford: public Car {
public:
    Ford(const Wheel &fireStoneWheels) : Car(fireStoneWheels) {
        std::cout << "I'm in derived Ford constructor" << std::endl;
    }
    ~Ford() {
        std::cout << "I'm in derived Ford destructor" << std::endl;
    }
};

/*class Color {
public:
    Color()
    {
        std::cout << "The color is preset: " << mColor << std::endl;
        mColor = BLACK;
    }
    Color( const Color &other ) : r(other.r), g(other.g), b(other.b), a(other.a)
    {
        std::cout << "This is a custom color" << std::endl;
    }
    
private:
    float r, g, b, a;
    ColorName mColor;
};

class Appearance {
public:
    Appearance() : mStyle(){
        std::cout << "The apperance is null" << std::endl;
    }
    
    void setColor( Color &color) { mColor = color; }
    
private:
    Color mColor;
    Style mStyle;
};*/


int main(int argc, const char * argv[])
{
    std::cout << "Creating mMazda" << std::endl;
    Mazda* mMazda = new Mazda( Wheel() ) ;
    Ford* mFord = new Ford( Wheel() ) ;
    
    std::vector<Car*> mCarPointers;
    mCarPointers.push_back( mMazda );
    mCarPointers.push_back( mFord );
    
    for( auto carIt = mCarPointers.begin(); carIt != mCarPointers.end(); ++carIt){
        (*carIt)->drive();
        delete (*carIt);
    }
    
    return 0;
}