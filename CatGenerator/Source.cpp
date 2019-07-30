#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

std::string drawRect(float x, float y, float w, float h, std::string c){
	std::string temp = "<rect x=\""+ std::to_string(x) + 
	"\" y=\""+ std::to_string(y) + 
	"\" width=\""+ std::to_string(w) + 
	"\" height=\""+ std::to_string(h) + 
	"\" stroke=\"" + c + "\"" + 
	" fill=\"" + c + "\"" + 
	"/>\n";
	return temp;
}

std::string drawCircle(float x, float y, float r, std::string c){

	std::string temp = "<circle cx=\"" + std::to_string(x) + 
	"\" cy=\"" + std::to_string(y) + "\" r=\"" + 
	std::to_string(r) + 
	"\" stroke=\"" + c + "\"" + 
	" fill=\"" + c + "\"" + 
	"/>\n";
	return temp;
} //  "\ + std::to_string +  "\

std::string DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, std::string c){
	std::string temp = "<polygon points=\"" + std::to_string(x1) + 
	"," + std::to_string(y1) + 
	" "+ std::to_string(x2) + 
	"," + std::to_string(y2) + 
	" "  + std::to_string(x3) + 
	"," + std::to_string(y3) + 
	"\" stroke=\"" + c + "\"" + 
	" fill=\"" + c + "\"" + 
	"/>\n";

	return temp;
}

std::string DrawOval(float cx, float cy, float rx, float ry, std::string c){
	std::string temp = "<ellipse cx=\"" + std::to_string(cx) + 
	"\" cy=\"" + std::to_string(cy) + 
	"\" rx=\"" + std::to_string(rx) + 
	"\" ry=\"" + std::to_string(ry) + 
	"\" stroke=\"" + c + "\"" + 
	" fill=\"" + c + "\"" + 
	" />\n";

	return temp;
}

std::string DrawCurve(float x1, float y1, float po, float r, float x2, float y2, float width, std::string c){
	std::string temp = "<path d=\"M " + std::to_string(x1) +  
	" " + std::to_string(y1) + 
	" q " + std::to_string(po) + 
	" " + std::to_string(r) + 
	" " + std::to_string(x2) + 
	" " + std::to_string(y2) + "\" stroke=\"" + 
	c + "\" stroke-width=\"" + 
	std::to_string(width) + "\" fill=\"none\" />\n";
	return temp;
}

std::string GetRbg(){
	std::string temp = "rgb(" + std::to_string(rand() % 255) + 
	", " + std::to_string(rand() % 255) + 
	", " + std::to_string(rand() % 255) + ")";

	return temp;
}

void drawCat(std::string* catString){
	srand(time(NULL));
	std::string bodyColor = GetRbg();
	std::string eyeColor = GetRbg();
	std::string mouthColor = GetRbg();
	std::string collarColor = GetRbg();
	std::string chestColor = GetRbg();
	std::string innerEarColor = GetRbg();

	// begining
	(*catString) += "<svg viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\">\n";

	// left ear
	(*catString) += DrawTriangle(15, 5, 25, 15, 15, 25, bodyColor);
	(*catString) += DrawTriangle(14.5, 5, 20, 20, 10, 30, collarColor);

	// right ear
	(*catString) += DrawTriangle(65, 5, 55, 15, 65, 25, bodyColor);
	(*catString) += DrawTriangle(65.5, 5, 65, 25, 60, 20, collarColor);

	// body
	(*catString) += drawCircle(40, 40, 35, bodyColor);
	(*catString) += drawRect(5, 40, 70, 45, bodyColor);

	// collar
	(*catString) += drawRect(5, 45, 70, 2, collarColor);

	// feet
	(*catString) += drawCircle(10, 91, 5, chestColor);
	(*catString) += drawCircle(25, 91, 5, chestColor);
	(*catString) += drawCircle(55, 91, 5, chestColor);
	(*catString) += drawCircle(70, 91, 5, chestColor);

	// legs
	(*catString) += drawRect(5, 76, 10, 15, bodyColor);
	(*catString) += drawRect(20, 76, 10, 15, bodyColor);
	(*catString) += drawRect(50, 76, 10, 15, bodyColor);
	(*catString) += drawRect(65, 76, 10, 15, bodyColor);

	// tail
	(*catString) += drawCircle(90, 55, 5, chestColor);
	(*catString) += drawRect(76, 65, 15, 10, bodyColor);
	(*catString) += drawCircle(90, 70, 5, bodyColor);
	(*catString) += drawRect(85, 55, 10, 15, bodyColor);

	// chest
	(*catString) += drawRect(16, 65, 33, 20, chestColor);
	(*catString) += DrawOval(32.5, 65, 16.5, 12, chestColor);

	// eyes
	(*catString) += DrawOval(28, 18, 4, 3, mouthColor);
	(*catString) += DrawOval(52, 18, 4, 3, mouthColor);

	// muzzle
	(*catString) += DrawOval(40, 33, 15, 10, chestColor);

	// mouth
	(*catString) += DrawCurve(40, 30, 8, 10, 15, 0, 3, mouthColor);
	(*catString) += drawCircle(40, 28, 2, mouthColor);
	(*catString) += DrawCurve(25, 30, 6, 10, 15, 0, 3, mouthColor);

	(*catString) += drawCircle(25, 30, 1, mouthColor);
	(*catString) += drawCircle(55, 30, 1, mouthColor);

	// bowtie
	(*catString) += DrawTriangle(37.5, 46, 25, 40, 25, 50, collarColor);
	(*catString) += DrawTriangle(37.5, 46, 50, 40, 50, 50, collarColor);
	(*catString) += DrawOval(37.5, 46, 3, 2, collarColor);

	// end
	(*catString) += "</svg>";
}



int main(){

	std::string fileName = "cat.svg";
	std::string filePath = "files/" + fileName;
	std::fstream catFile;
	catFile.open(filePath, std::fstream::out | std::fstream::trunc);

	std::string catString; 

	drawCat(&catString);

	if(catFile.is_open()){
		catFile << catString;
	}
	else{
		std::cout << "file did not open" << std::endl;
	}

	catFile.close();

	return 0;
}