#include "svgBuilder.h"

void SVGBbulder::setVallues()
{
	this->a.x = 0;
	this->a.y = 1;
	this->b.x = 1;
	this->b.y = 1;
	this->mazeHeight = 4;
	this->mazeWidth = 4;
}

void SVGBbulder::startSVG()
{
	this->svgFile.open("svgTest.svg");
	this->svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	this->svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	this->svgFile << "<rect width='1' height='1' style='fill: white' />\n";
}

void SVGBbulder::addEdge()
{

}

void SVGBbulder::endSVG()
{
	this->svgFile << "</svg>\n";
	this->svgFile.close();
}


int main()
{

}