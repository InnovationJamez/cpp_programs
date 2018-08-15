int main()
{
	int mazeWidth;
	int mazeHeight;
	int noOfEdges;
	fstream binFile("binFile",ios::binary | ios::in | ios::out | ios::trunc );
	if(!file.is_open())
	{
		cout << "file did not open";
	}else
	{
	ofstream svgFile;
	svgFile.open("generatedMaze.svg");
	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' ";
	svgFile << "xmlns='http://www.w3.org/2000/svg'>\n";
	svgFile << "<rect width='1' height='1' style='fill: white' />\n";
	
	string s;
	for(std::string line, int i = 1; getline(binFile, s); ++i)
	{
	if(i == 1)
	{ 
	}
	binFile.close();
	
	// first line width
	
	// second line height
	
	// third line number of edges
	
	// rest edges
	
	
	
	
	
	
	myFile << "</svg>\n";	
	
	}
		
	
}