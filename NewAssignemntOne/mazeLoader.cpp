
#include "MazeLoader.h"

// Enter files names

void MazeLoader::enterBinName(std::string binFileName, 
	std::string svgFileName)

{
	this->svgFile.open(svgFileName.c_str());
	this->binFile.open(binFileName.c_str(), 
		std::ios::in | std::ios::binary);
}

// check file extemsion

bool MazeLoader::checkVal(int vallue)
{
	if(vallue > this->mazeWidth)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// check if file is open and valid

bool MazeLoader::checkFileOpen()
{
	if (this->binFile.is_open())
	{
		return true;

	}
	else
	{
		std::cout << "file did not open" << std::endl;
		return false;
	}
}


// check file size

bool MazeLoader::checkFileBinSize()
{
	this->binFile.seekg(0, std::ios::end);
	std::string tempString;
	this->fileSize = (int)this->binFile.tellg();
	if (this->fileSize <= 0)
	{
		std::cout << "file is empty" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

// start files

void MazeLoader::readLines()
{
	char ch;
	this->binFile.seekg(0, std::ios::beg);
	std::string tempString;
	std::string newTempString;
	while (this->binFile.tellg() < this->fileSize)
	{
		this->binFile.get(ch);
		tempString = ch + tempString;
		if (tempString.size() == 33)
		{
			newTempString = tempString.substr(1, tempString.size() - 2);
			this->binFileVector.push_back(newTempString);
			tempString.clear();
		}
	}
	this->binFile.close();
}

// binary to decimal

double MazeLoader::binToDecimal(std::string a)
{
	double tempInt = 0;
	for (int i = 0; i < (int)a.size(); ++i)
	{
		if (a[i] == '1')
		{
			tempInt += pow(2, i);
		}
	}
	return tempInt;
}

// Read binFileVector

void MazeLoader::readBinFileVector()
{
	this->mazeWidth = binToDecimal(this->binFileVector[0]);
	this->mazeHeight = binToDecimal(this->binFileVector[1]);
	this->noOfEdges = binToDecimal(this->binFileVector[2]);
	this->bufferWidth = 1 / (this->mazeWidth * 2 + 1);
	this->bufferHeight = 1 / (this->mazeHeight * 2 + 1);

	for (int i = 3; i < (int)(this->binFileVector.size() - 1); ++i)
	{
		if (i % 4 == 3)
		{
			this->a.x = binToDecimal(this->binFileVector[i]);
		}
		if (i % 4 == 0)
		{
			this->a.y = binToDecimal(this->binFileVector[i]);
		}
		if (i % 4 == 1)
		{
			this->b.x = binToDecimal(this->binFileVector[i]);
		}
		if (i % 4 == 2)
		{
			this->b.y = binToDecimal(this->binFileVector[i]);
			addEdge();
		}
	}
}

// Creating Edditing and closing SVG File 

void MazeLoader::beginSVG()
{
	this->svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	this->svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	this->svgFile << "<rect width='1' height='1' style='fill: white' />\n";
}

void MazeLoader::drawBorder()
{
	// Draw border
	lineDefineHeight();
	this->svgFile << "x1='";
	this->svgFile << 0;  
	this->svgFile << "' y1='";
	this->svgFile << this->bufferHeight / 2;
	this->svgFile << "' x2='";
	this->svgFile << 1;
	this->svgFile << "' y2='";
	this->svgFile << this->bufferHeight / 2;
	this->svgFile << "'/>\n";

	lineDefineWidth();
	this->svgFile << "x1='";
	this->svgFile << 1-this->bufferHeight/2;
	this->svgFile << "' y1='";
	this->svgFile << 0;
	this->svgFile << "' x2='";
	this->svgFile << 1-this->bufferHeight/2;
	this->svgFile << "' y2='";
	this->svgFile << 1;
	this->svgFile << "'/>\n";

	lineDefineHeight();
	this->svgFile << "x1='";
	this->svgFile << 1;
	this->svgFile << "' y1='";
	this->svgFile << 1-this->bufferHeight/2;
	this->svgFile << "' x2='";
	this->svgFile << 0;
	this->svgFile << "' y2='";
	this->svgFile << 1-this->bufferHeight/2;
	this->svgFile << "'/>\n";

	lineDefineHeight();
	this->svgFile << "x1='";
	this->svgFile << this->bufferHeight/2;
	this->svgFile << "' y1='";
	this->svgFile << 1;
	this->svgFile << "' x2='";
	this->svgFile << this->bufferHeight/2;
	this->svgFile << "' y2='";
	this->svgFile << 0;
	this->svgFile << "'/>\n";
}

// line define

void MazeLoader::lineDefineWidth()
{
	this->svgFile << "<line stroke= 'black' stroke-width='";
	this->svgFile << this->bufferWidth;
	this->svgFile << "' ";
}

void MazeLoader::lineDefineHeight()
{
	this->svgFile << "<line stroke= 'black' stroke-width='";
	this->svgFile << this->bufferHeight;
	this->svgFile << "' ";
}

// Add Edge

void MazeLoader::addEdge()
{
	double wallWidth = (1 - bufferWidth) / this->mazeWidth;
	double wallHeight = (1 - bufferHeight) / this->mazeHeight;
	this->a.x++;
	this->a.y++;
	this->b.x++;
	this->b.y++;

	if (this->a.y == this->b.y)
	{
		lineDefineWidth();
		this->svgFile << " x1='";
		this->svgFile << wallWidth * this->a.x + this->bufferWidth/2;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * this->a.y + this->bufferHeight / 2;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * this->a.x + this->bufferWidth / 2;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight*this->a.y-wallHeight+this->bufferHeight/2;
		this->svgFile << "'/>\n";
	}
	else
	{
		lineDefineHeight();
		this->svgFile << " x1='";
		this->svgFile << wallWidth * this->a.x + this->bufferWidth / 2;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * this->a.y + this->bufferHeight / 2;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth*this->a.x-wallWidth+this->bufferWidth / 2;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * this->a.y + this->bufferHeight / 2;
		this->svgFile << "'/>\n";
	}
}

// end svg

void MazeLoader::endSVG()
{
	this->svgFile << "</svg>\n";
	this->svgFile.close();
}

// main
    
int main(int argc, char*argv[])
{
	if(argc == 3)
	{
		std::string binFileName = argv[1];
		std::string svgFileName = argv[2];
		MazeLoader loaderOne;
		loaderOne.enterBinName(binFileName, svgFileName);
		loaderOne.beginSVG();
		loaderOne.checkFileBinSize();
		loaderOne.readLines();
		loaderOne.readBinFileVector();
		loaderOne.drawBorder();
		loaderOne.endSVG();
	}
	else
	{
		std::cout << "wrong number of com args" << std::endl;
	}
	return 0;
}
