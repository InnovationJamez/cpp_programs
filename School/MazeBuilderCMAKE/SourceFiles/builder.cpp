#include "../HeaderFiles/GrowingTree.h"
#include "../HeaderFiles/MazeLoader.h"
#include "../HeaderFiles/PrimAlgorithm.h"
#include "../HeaderFiles/RecursiveBacktrack.h"
#include<chrono>

enum OPTIONS {
  gg = 32,
  gp = 16,
  gr = 8,
  sv = 4,
  sb = 2,
  pm = 1  
};

void BuildGrowingTree(int* width, int* height, std::string* binFileName, std::string* solutionName ,int choice);

void BuildPrim(int* width, int* height, std::string* binFileName, std::string* solutionName ,int choice);

void BuildRecersive(int* width, int* height, std::string* binFileName, std::string* solutionName ,int choice);

void LoadMaze(std::string* binFileName, std::string* svgFileName);

int main(int argc, char* argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    
    int height = 4, width = 4;
    std::string binFileName = "null";
    std::string SVGFileName = "null";
    std::string solutionName = "null";
    int choice;
    std::string tempString;
    for(int i = 0; i < argc; i++){
        tempString = argv[i];
        
        if(tempString == "--gg" || tempString=="-gg"){
            width = std::stoi(argv[i+1]);
            height = std::stoi(argv[i+2]);
            choice |= gg;
        }
        if(tempString == "--gp" || tempString=="-gp"){
            width = std::stoi(argv[i+1]);
            height = std::stoi(argv[i+2]); 
            choice |= gp;          
        }
        if(tempString == "--gr" || tempString=="-gr"){
            width = std::stoi(argv[i+1]);
            height = std::stoi(argv[i+2]);
            choice |= gr;            
        }
        if(tempString == "--sv" || tempString=="-sv"){
            SVGFileName = argv[i+1]; 
            choice |= sv;           
        }
        if(tempString == "--sb" || tempString=="-sb"){
            binFileName = argv[i+1]; 
            choice |= sb;
        }
        if(tempString == "--pm" || tempString=="-pm"){
            solutionName = argv[i+1];
            choice |= pm;
        }
        
    }

    if(choice & gg){
        BuildGrowingTree(&width, &height, &binFileName, &solutionName, choice);
    }
    
    if(choice & gp){
        BuildPrim(&width, &height, &binFileName, &solutionName, choice);
    }
    
    if(choice & gr){
        BuildRecersive(&width, &height, &binFileName, &solutionName, choice);
    }
    
    if(choice & sv){
        MazeLoader(&binFileName, &SVGFileName, &solutionName);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << std::endl;

    return 0;
}// end of main

void BuildGrowingTree(int* width, int* height, std::string* binFileName, std::string* solutionName ,int choice){
    GrowingTree treeObj(width, height, binFileName, solutionName);
    treeObj.addLocation();
    treeObj.buildLoop();
    if(choice & sb){
        treeObj.binaryMain();
    }
    if(choice & pm){
        treeObj.solverMain();
    }		
}

void BuildPrim(int* width, int* height, std::string* binFileName, std::string* solutionName ,int choice){
    PrimAlgorithm primObj(width, height, binFileName, solutionName);
    if(choice & sb){
        primObj.binaryMain();
    }
    if(choice & pm){
        primObj.solverMain();
    }
    
}

void BuildRecersive(int* width, int* height, std::string* binFileName, std::string* solutionName ,int choice){
    RecursiveBacktrack recObj(width, height, binFileName, solutionName);
    if(choice & sb){
        recObj.binaryMain();
    }
    if(choice & pm){
        recObj.solverMain();
    }
    
}
