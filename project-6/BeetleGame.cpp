//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"
#include "Die.h"

#include <iostream>
using namespace::std;
namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
string BeetleGame::display( string msg ) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    string result = drawing.draw() + "\n" + msg;
    return( result );
}


// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::humanRoll( int amount )
{
    if (amount == 0){
        mHumanDie.roll();
    }
    else if (amount != 0){
        mHumanDie.setValue(amount);
    }

}

    // if the amount is zero, roll the Human's die
    // otherwise, cheat by forcing the amount into the Human's die


// TODO return the value of the Human's die
int BeetleGame::getHumanDie( ) const
{
    // for now...
    return(mHumanDie.getValue());
}

// TODO convert the Human's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Human's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::humanPlay( )
{
    if ((getHumanDie() == 6) && (!mHuman.hasBody())){
        mHuman.convertRollToBodyPart(6);
        mHuman.buildBody();
        return(true);
        
    }
    if (getHumanDie() == 5 && mHuman.hasBody() && (!mHuman.hasHead())){
        mHuman.convertRollToBodyPart(5);
        mHuman.buildHead();
        return(true);
    }
    if (getHumanDie() == 4 && mHuman.hasBody() && (!mHuman.hasTail())){
        mHuman.convertRollToBodyPart(4);
        mHuman.buildTail();
        return(true);
    }
    if (getHumanDie() == 3 && mHuman.hasBody() && (!mHuman.hasLeg1())){
        mHuman.convertRollToBodyPart(3);
        mHuman.buildLeg();
        return(true);
    }
    if (getHumanDie() == 3 && mHuman.hasBody() && (!mHuman.hasLeg2())){
        mHuman.convertRollToBodyPart(3);
        mHuman.buildLeg();
        return(true);
    }
    if (getHumanDie() == 3 && mHuman.hasBody() && (!mHuman.hasLeg3())){
        mHuman.convertRollToBodyPart(3);
        mHuman.buildLeg();
        return(true);
    }
    if (getHumanDie() == 3 && mHuman.hasBody() && (!mHuman.hasLeg4())){
        mHuman.convertRollToBodyPart(3);
        mHuman.buildLeg();
        return(true);
    }
    if (getHumanDie() == 2 && mHuman.hasHead() && mHuman.hasBody() && (!mHuman.hasAntenna1())){
        mHuman.convertRollToBodyPart(2);
        mHuman.buildAntenna();
        return(true);
    }
    if (getHumanDie() == 2 && mHuman.hasHead() && mHuman.hasBody() && (!mHuman.hasAntenna2())){
        mHuman.convertRollToBodyPart(2);
        mHuman.buildAntenna();
        return(true);
    }
    if (getHumanDie() == 1 && mHuman.hasHead() && mHuman.hasBody() && (!mHuman.hasEye1())){
        mHuman.convertRollToBodyPart(1);
        mHuman.buildEye();
        return(true);
    }
    if (getHumanDie() == 1 && mHuman.hasHead() && mHuman.hasBody() && (!mHuman.hasEye2())){
        mHuman.convertRollToBodyPart(1);
        mHuman.buildEye();
        return(true);
    }
    bool result = false;//if none of these come back to be true then it wil return false.
    return( result );
}

// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::computerRoll( int amount )
{
    if (amount == 0){
        mComputerDie.roll();
    }
    else if (amount != 0){
        mComputerDie.setValue(amount);
    }
}

// TODO return the value of the Computer's die
int BeetleGame::getComputerDie( ) const
{
    // for now...
    return( mComputerDie.getValue());
}

// TODO convert the Computer's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Computer's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::computerPlay( )
{
    if ((getComputerDie() == 6) && (!mComputer.hasBody())){
        mComputer.convertRollToBodyPart(6);
        mComputer.buildBody();
        return(true);
        
    }
    if (getComputerDie() == 5 && mComputer.hasBody() && (!mComputer.hasHead())){
        mComputer.convertRollToBodyPart(5);
        mComputer.buildHead();
        return(true);
    }
    if (getComputerDie() == 4 && mComputer.hasBody() && (!mComputer.hasTail())){
        mComputer.convertRollToBodyPart(4);
        mComputer.buildTail();
        return(true);
    }
    if (getComputerDie() == 3 && mComputer.hasBody() && (!mComputer.hasLeg1())){
        mComputer.convertRollToBodyPart(3);
        mComputer.buildLeg();
        return(true);
    }
    if (getComputerDie() == 3 && mComputer.hasBody() && (!mComputer.hasLeg2())){
        mComputer.convertRollToBodyPart(3);
        mComputer.buildLeg();
        return(true);
    }
    if (getComputerDie() == 3 && mComputer.hasBody() && (!mComputer.hasLeg3())){
        mComputer.convertRollToBodyPart(3);
        mComputer.buildLeg();
        return(true);
    }
    if (getComputerDie() == 3 && mComputer.hasBody() && (!mComputer.hasLeg4())){
        mComputer.convertRollToBodyPart(3);
        mComputer.buildLeg();
        return(true);
    }
    if (getComputerDie() == 2 && mComputer.hasHead() && mComputer.hasBody() && (!mComputer.hasAntenna1())){
        mComputer.convertRollToBodyPart(2);
        mComputer.buildAntenna();
        return(true);
    }
    if (getComputerDie() == 2 && mComputer.hasHead() && mComputer.hasBody() && (!mComputer.hasAntenna2())){
        mComputer.convertRollToBodyPart(2);
        mComputer.buildAntenna();
        return(true);
    }
    if (getComputerDie() == 1 && mComputer.hasHead() && mComputer.hasBody() && (!mComputer.hasEye1())){
        mComputer.convertRollToBodyPart(1);
        mComputer.buildEye();
        return(true);
    }
    if (getComputerDie() == 1 && mComputer.hasHead() && mComputer.hasBody() && (!mComputer.hasEye2())){
        mComputer.convertRollToBodyPart(1);
        mComputer.buildEye();
        return(true);
    }
    bool result = false;//if none of these come back to be true then it wil return false.
    return( result );
}

// TODO what is the current state of the game
BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const
{    
    if(mHuman.isComplete() == true){
        return( GameOutcome::HUMANWONGAME );
    }
    else if(mComputer.isComplete() == true){
        return( GameOutcome::COMPUTERWONGAME );
    }
    else
        return(GameOutcome::GAMENOTOVER);
}

std::string  BeetleGame::stringifyGameOutcome( ) const
{
    std::string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// TODO has the game ended with a winner?
bool BeetleGame::gameIsOver() const
{
    if(mHuman.isComplete() == true){
        return(true);
    }
    if(mComputer.isComplete() == true){
        return(true);
    }
    return(false);
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}


