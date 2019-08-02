//
// Created by lehoej on 9/14/2018.
//

#include "../HeaderFiles/GrowingTree.h"

// fill board generate & start point
GrowingTree::GrowingTree(int* x, int* y, std::string* binFileName, std::string* solution)
:width(*x), height(*y), binFileName(*binFileName), solutionFileName(*solution){
    fillBoard();
    setLocation();
    setVisited();
}

// de-constructor deallocate the memory taken up by the object
GrowingTree::~GrowingTree() {
    delete mapTree;
	delete board;
}

// growing tree loop
void GrowingTree::buildLoop() {
	while(mapTree->size()>0) {
        selectPiece();
        carvePath();
		setVisited();
	}
}

// generate random number
void GrowingTree::generateRandom(int max){
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dis(0, (max-1));
    this->randNum = dis(gen);
}

// set location
void GrowingTree::setLocation(){
    generateRandom(this->height);
    position.yPos = this->randNum;
    generateRandom(this->width);
    position.xPos = this->randNum;
}

// createBoard
void GrowingTree::fillBoard(){
    for(int row = 0;row<width; row++) {
        std::vector<disposition>tempVec;
        for(int col = 0; col<height; col++){
            disposition state;
            tempVec.push_back(state);
        }
        board->push_back(tempVec);
    }
}



// check surounding cells
DIRECTION GrowingTree::neighborChk(){
    std::vector<DIRECTION> choice;
    if(checkNorth()){
        choice.push_back(NORTH);
        choice.push_back(NORTH);
    }if(checkSouth()){
        choice.push_back(SOUTH);
        choice.push_back(SOUTH);
    }if(checkEast()){
        choice.push_back(EAST);
        choice.push_back(EAST);
    }if(checkWest()){
        choice.push_back(WEST);
        choice.push_back(WEST);
	}
	if(choice.empty()) {
		return EMPTY;
	}else{
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(choice), std::end(choice), rng);
        generateRandom(choice.size());
        return choice[this->randNum];
    }
}

// carve path
void GrowingTree::carvePath(){
    DIRECTION choice = neighborChk();
    switch(choice){
        case NORTH:
            moveNorth();
            addLocation();
            break;
        case SOUTH:
            moveSouth();
            addLocation();
            break;
        case EAST:
            moveEast();
            addLocation();
            break;
        case WEST:            
			moveWest();
            addLocation();
            break;
        case EMPTY:
            backTrack();
            break;
        default:
            std::cout << "there has been an error" << std::endl;
            break;
    }
}

// select the newest piece from the map
void GrowingTree::selectPiece(){
	int val = mapTree->size()-1;
	this->position = (*mapTree)[val];
}

// add location to the map
void GrowingTree::addLocation(){
    (*mapTree).push_back(this->position);
}
    
// pop one location off the top of the stack
void GrowingTree::backTrack(){
	(*mapTree).pop_back();
}

// make soluction to maze // SOLUTION // SOLUTION

// mark east
bool GrowingTree::markEast(){
	bool result = false;	
	if((*board)[this->position.xPos][this->position.yPos].binVal & 0b000010 && this->position.xPos != this->width-1){
		result = ((*board)[this->position.xPos + 1][this->position.yPos].binVal & 0b100000)? false:true;
	}
	return result;	
}

// mark south
bool GrowingTree::markSouth(){
	bool result = false;
	if((*board)[this->position.xPos][this->position.yPos].binVal & 0b001000 && this->position.yPos != this->height-1){
		result = ((*board)[this->position.xPos][this->position.yPos + 1].binVal & 0b100000)? false:true;
	}
	return result;
}

// mark west
bool GrowingTree::markWest(){
	bool result = false;
	if((*board)[this->position.xPos][this->position.yPos].binVal & 0b000100 && this->position.xPos != 0){
		result = ((*board)[this->position.xPos - 1][this->position.yPos].binVal & 0b100000)? false:true;
	}
	return result;
}

// mark north
bool GrowingTree::markNorth(){
	bool result = false;
	if((*board)[this->position.xPos][this->position.yPos].binVal & 0b010000 && this->position.yPos != 0){
		result = ((*board)[this->position.xPos][this->position.yPos - 1].binVal & 0b100000)? false:true;
	}
	return result;
}

void GrowingTree::solverMain(){
	this->solutionFile.open("SolutionFiles/" + solutionFileName, std::ofstream::out | std::ofstream::trunc);
	this->position = {0,0};
	markVisited();
	addPiece();
	int xGoal = width-1;
	int yGoal = height-1;
	std::string answer;
	
	while (this->position.xPos != xGoal ||  this->position.yPos != yGoal)
	{   
		this->position = this->locationList[this->locationList.size()-1];
		// check right/east
		if(markEast()){
			this->position.xPos++;
			markVisited();
			addPiece();
		}
		// check south/down
		else if(markSouth())
		{
			this->position.yPos++;
			markVisited();
			addPiece();
		}
		// check left/west 
		else if(markWest()){
			this->position.xPos--;
			markVisited();
			addPiece();
		}
		// check north/up
		else if(markNorth()){
			this->position.yPos--;
			markVisited();
			addPiece();

		}else{
			removePiece();
			this->position = this->locationList[this->locationList.size()-1];
		}
	} // while loop
	
	for(int i = 0; i < (int)this->locationList.size(); i++){
		this->solutionFile << this->locationList[i].xPos;
		this->solutionFile << "\n";
		this->solutionFile << this->locationList[i].yPos;
		this->solutionFile << "\n";
	}
	
	this->solutionFile.close();
} // solver main

// M N S W E V
//
//      N
//   W     E
//      S

// set the fifth bit to zero as the solver visites the cell 
void GrowingTree::markVisited(){
	(*board)[this->position.xPos][this->position.yPos].binVal |= 0b100000;
}

// addlocation to the list of locations
void GrowingTree::addPiece(){
	this->locationList.push_back(position);
}

// remove location from the list of locations
void GrowingTree::removePiece(){
	this->locationList.pop_back();
}


// binary file stuff


void GrowingTree::openBinFile(){
    (*binFile).open("MazeFiles/" + binFileName, std::ios::in | std::ios::out | std::ios::trunc);
}

// convert a base ten number to binary
void GrowingTree::intToBin(){
    binNum = "";
    while (num > 0)
    {
        binNum = binNum + (num % 2 == 1 ? '1' : '0');
        num = num / 2;
    }
    while(binNum.length() < 32)
    {
        binNum = binNum + '0';
    }
}

// iterate through the vector<vector<cell>> and find where the walls are
void GrowingTree::connectionChecker(){
    edgeNo = 0;
    for(int i = 0; i<width;i++){
        for(int j = 0; j<(height-1); j++){
            if((*board)[i][j].binVal & 0b01000){
                edgeNo++;
                position.yPos = j;
                position.xPos = i;
                southWall();
            }
        }
    }
    for(int j = 0; j<height; j++){
        for(int i = 0; i<(width-1);i++){
            if((*board)[i][j].binVal & 0b0010){
                edgeNo++;
                position.yPos = j;
                position.xPos = i;
                eastWall();
            }
        }
    }

}

// store binary number in bin file
void GrowingTree::addToBinFile(){
    for (int counter = 0; counter <= (int)binNum.size(); counter++) {
        binFile->put(binNum[counter]);
    }
}

// add number of edges to third spot in wallList
void GrowingTree::addEdgeNum(){
    num = width;
    intToBin();
    addToBinFile();
    num = height;
    intToBin();
    addToBinFile();
    num = edgeNo;
    intToBin();
    addToBinFile();
}

// add values for edges
void GrowingTree::addEdges(){
    for (int i : (*numberList)) {
        num = i;
        intToBin();
        addToBinFile();
    }
}

// deallocate memory taken up by the binFile fstream object
void GrowingTree::deleteBinFile(){
    binFile->close();
    delete binFile;
    delete numberList;
}

// add numbers to wall container
void GrowingTree::addToWallList(){
    (*numberList).push_back(num);
}

// GrowingTree::south edge
void GrowingTree::southWall(){
    num = position.xPos;
    addToWallList();
    num = position.yPos;
    addToWallList();
    num = position.xPos;
    addToWallList();
    num = position.yPos+1;
    addToWallList();
}

// east edge
void GrowingTree::eastWall(){
    num = position.xPos;
    addToWallList();
    num = position.yPos;
    addToWallList();
    num = position.xPos+1;
    addToWallList();
    num = position.yPos;
    addToWallList();
}

void GrowingTree::binaryMain(){
    openBinFile();
    connectionChecker();
    addEdgeNum();
    addEdges();
    deleteBinFile();
}
