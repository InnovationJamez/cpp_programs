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
	void setVallues();
	void startSVG();
	void addEdge();
	void endSVG();
}