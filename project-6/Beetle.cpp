//
//  Beetle.cpp
//
//

#include "Beetle.h"

namespace cs31
{

Beetle::Beetle() : mBody(false),mTail(false), mLeg1(false), mLeg2(false), mLeg3(false), mLeg4(false), mHead(false), mEye1(false), mEye2(false), mAntenna1(false), mAntenna2(false), currentLeg(0), currentEye(0), currentAntenna(0)
{}

// convert a tossed die value into a BodyPart
Beetle::BodyPart Beetle::convertRollToBodyPart( int die ) const
{
    // if not matching, then return NOTVALID
    BodyPart part = BodyPart::NOTVALID;
    if (die == 6)
        part = BodyPart::BODY;
    if (die == 5)
        part = BodyPart::HEAD;
    if (die == 4)
        part = BodyPart::TAIL;
    if (die == 3)
        part = BodyPart::LEG;
    if (die == 2)
        part = BodyPart::ANTENNA;
    if (die == 1)
        part = BodyPart::EYE;
    return( part );
}

// build the Beetle's body
void Beetle::buildBody()
{
    mBody = true;
}

// has the Beetle's body been built?
bool Beetle::hasBody() const
{
    
    return( mBody);
}

// build the Beetle's tail but only if the body has already been built
void Beetle::buildTail()
{
  
    mTail = true;
}

// has the Beetle's tail been built?
bool Beetle::hasTail() const
{
    return(mTail);
}

// build the Beetle's leg but only if the body has already been built
void Beetle::buildLeg()
{
    currentLeg++;
    if (currentLeg == 1){
        mLeg1 = true;
    }
    if (currentLeg == 2){
        mLeg2 = true;
    }
    if (currentLeg == 3){
        mLeg3 = true;
    }
    if (currentLeg == 4){
        mLeg4 = true;
    }
    return;
    
}

// has the Beetle's leg been built?
bool Beetle::hasLeg1() const
{
    return(mLeg1);
}

bool Beetle::hasLeg2() const
{
    // for now...
    return(mLeg2);
}

bool Beetle::hasLeg3() const
{
    // for now...
    return(mLeg3);
}

bool Beetle::hasLeg4() const
{
    // for now...
    return(mLeg4);
}

// build the Beetle's head but only if the body has already been built
void Beetle::buildHead()
{
    mHead = true;
}

// has the Beetle's head been built?
bool Beetle::hasHead() const
{
    // for now...
    return(mHead);
}

// build the Beetle's eye but only if the head has already been built
void Beetle::buildEye()
{
    currentEye++;
    if (currentEye == 1){
        mEye1 = true;
    }
    if (currentEye == 2){
        mEye2 = true;
    }
}

// has the Beetle's eye been built?
bool Beetle::hasEye1() const
{
    // for now...
    return(mEye1);
}

bool Beetle::hasEye2() const
{
    // for now...
    return(mEye2);
}

// build the Beetle's antenna but only if the head has already been built
void Beetle::buildAntenna()
{
    // for now...
    currentAntenna++;
    if (currentAntenna == 1){
        mAntenna1 = true;
    }
    if (currentAntenna == 2){
        mAntenna2 = true;
    }
}

// has the Beetle's antenna been built?
bool Beetle::hasAntenna1() const
{
    // for now...
    return(mAntenna1);
}

bool Beetle::hasAntenna2() const
{
    // for now...
    return(mAntenna2);
}


// is this Beetle completely built out?
bool Beetle::isComplete() const
{
    if(!hasHead()){
        return(false);
    }
    if(!hasBody()){
        return(false);
    }
    if(!hasEye1()){
        return(false);
    }
    if(!hasEye2()){
        return(false);
    }
    if(!hasAntenna1()){
        return(false);
    }
    if(!hasAntenna2()){
        return(false);
    }
    if(!hasLeg1()){
        return(false);
    }
    if(!hasLeg2()){
        return(false);
    }
    if(!hasLeg3()){
        return(false);
    }
    if(!hasLeg4()){
        return(false);
    }
    if(!hasLeg4()){
        return(false);
    }
    return(true);
}


}


