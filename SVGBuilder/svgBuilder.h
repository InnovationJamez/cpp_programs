#include<iostream>
#include<vector>
#include<random>
#include<fstream>

struct coords
{
	int x, y;
};

class SVGBbulder
{
private:
	coords a;
	coords b;
	double mazeWidth;
	double mazeHeight;
	std::ofstream svgFile;
public:
	void setVallues(int a, int b, int c, int d);
	void startSVG();
	void lineDefineWidth();
	void lineDefineHeight();
	void addPath();
	void endSVG();
	void setDim(int a, int b);
};

