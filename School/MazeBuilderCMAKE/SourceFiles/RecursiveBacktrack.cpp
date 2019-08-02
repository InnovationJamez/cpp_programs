//
// Created by lehoej on 9/16/2018.
//

#include "../HeaderFiles/RecursiveBacktrack.h"

//constructor
RecursiveBacktrack::RecursiveBacktrack(int* x, int* y, std::string* binFileName, std::string* solution) : 
    GrowingTree(x,y,binFileName, solution){
    addLocation();
    buildLoop();
}

// select newest piece from the map
void RecursiveBacktrack::selectPiece(){
    this->position = mapStack->top();
}

// adding location to the top of the map
void RecursiveBacktrack::addLocation(){
    mapStack->push(this->position);
}

// pop one location off the top of the stack
void RecursiveBacktrack::backTrack(){
    mapStack->pop();
}

// growing tree loop
void RecursiveBacktrack::buildLoop(){
    while(!mapStack->empty()){
        selectPiece();
        carvePath();
    }
}

// carve path
void RecursiveBacktrack::carvePath(){
    DIRECTION choice = neighborChk();
    switch(choice){
        case NORTH:
            moveNorth();
            addLocation();
			setVisited();
            break;
        case SOUTH:
            moveSouth();
            addLocation();
			setVisited();
            break;
        case EAST:
            moveEast();
            addLocation();
			setVisited();
            break;
        case WEST:
            moveWest();
            addLocation();
			setVisited();
            break;
        case EMPTY:
            backTrack();
            break;
        default:
            std::cout << "there has been an error" << std::endl;
            break;
    }
}

RecursiveBacktrack::~RecursiveBacktrack(){
    delete mapStack;
}
