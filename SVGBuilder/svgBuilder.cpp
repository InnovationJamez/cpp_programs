#include "svgBuilder.h"

void SVGBbulder::setVallues(int a, int b, int c, int d)
{
	this->a.x = a;
	this->a.y = b;
	this->b.x = c;
	this->b.y = d;
	SVGBbulder::addPath();
}

void SVGBbulder::setDim(int a, int b)

{
	this->mazeHeight = a;
	this->mazeWidth = a;
}

void SVGBbulder::lineDefineWidth()
{
	this->svgFile << "<line stroke='black' stroke-width='";
	this->svgFile << 1 / (this->mazeWidth*2+1);
	this->svgFile << "' \n";
}

void SVGBbulder::lineDefineHeight()
{
	this->svgFile << "<line stroke='black' stroke-width='";
	this->svgFile << 1 / (this->mazeHeight*2+1);
	this->svgFile << "' \n";
}

void SVGBbulder::startSVG()
{
	this->svgFile.open("svgTest.svg");
	this->svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	this->svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	this->svgFile << "<rect width='1' height='1' style='fill: white' />\n";
	
	double buffer = 1 / (this->mazeHeight * 2 + 1);

	SVGBbulder::lineDefineHeight();
	this->svgFile << "x1='0";
	this->svgFile << 0;
	this->svgFile << "' y1='";
	this->svgFile << buffer / 2;
	this->svgFile << "' x2='";
	this->svgFile << 1;
	this->svgFile << "' y2='";
	this->svgFile << buffer / 2;
	this->svgFile << "'/>\n";

	SVGBbulder::lineDefineWidth();
	this->svgFile << "x1='0";
	this->svgFile << 1-buffer/2;
	this->svgFile << "' y1='";
	this->svgFile << 0;
	this->svgFile << "' x2='";
	this->svgFile << 1-buffer/2;
	this->svgFile << "' y2='";
	this->svgFile << 1;
	this->svgFile << "'/>\n";

	SVGBbulder::lineDefineHeight();
	this->svgFile << "x1='0";
	this->svgFile << 1;
	this->svgFile << "' y1='";
	this->svgFile << 1-buffer/2;
	this->svgFile << "' x2='";
	this->svgFile << 0;
	this->svgFile << "' y2='";
	this->svgFile << 1-buffer/2;
	this->svgFile << "'/>\n";

	SVGBbulder::lineDefineWidth();
	this->svgFile << "x1='0";
	this->svgFile << buffer / 2;
	this->svgFile << "' y1='";
	this->svgFile << 1;
	this->svgFile << "' x2='";
	this->svgFile << buffer / 2;
	this->svgFile << "' y2='";
	this->svgFile << 0;
	this->svgFile << "'/>\n";
}

void SVGBbulder::addPath()
{
	double wallWidth = 0.995 / this->mazeWidth;
	double wallHeight = 0.995 / this->mazeHeight;
	this->a.x++;
	this->a.y++;
	this->b.x++;
	this->b.y++;
	double buffer = 0.005;

	if (this->a.y == this->b.y)
	{
		SVGBbulder::lineDefineWidth();
		this->svgFile << " x1='";
		this->svgFile << wallWidth * this->a.x + buffer;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * this->a.y + buffer;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * this->a.x + buffer;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * this->a.y - wallHeight + buffer;
		this->svgFile << "'/>\n";
	}
	else
	{
		SVGBbulder::lineDefineHeight();
		this->svgFile << " x1='";
		this->svgFile << wallWidth * this->a.x + buffer;
		this->svgFile << "' y1='";
		this->svgFile << wallHeight * this->a.y + buffer;
		this->svgFile << "' x2='";
		this->svgFile << wallWidth * this->a.x - wallWidth + buffer;
		this->svgFile << "' y2='";
		this->svgFile << wallHeight * this->a.y + buffer;
		this->svgFile << "'/>\n";
	}
}

void SVGBbulder::endSVG()
{
	this->svgFile << "</svg>\n";
	this->svgFile.close();
}


int main()
{
	SVGBbulder mazeOne;	
	mazeOne.setDim(4,4);
	mazeOne.startSVG();
	mazeOne.setVallues(0,0,1,0);
	mazeOne.setVallues(1,0,1,1);
	mazeOne.endSVG();
}