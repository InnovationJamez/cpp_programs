#include<iostream>
#include<math.h>

// get initial vallues
void getVallues(int* dpwPtr, int* wdPtr, int* cpwPtr, float* dpaPtr);

// takes wafer diameter, and dies per wafer
// returns die area
float calcDieArea(int* wdPtr, int* dpwPtr);

// takes die area and defents per area
// returns yeild
float calcYield(float da, float* dpaPtr);

// takes cost per wafer, dies per wafer, yield
// returns cost per die
float calcPrice(int* cpwPtr, int* dpwPtr, float yield);


int main(int argc, char *argv[]){

	// given vallues
	int dpw; // dies per wafer
	int* dpwPtr = &dpw;

	int wd; // wafer diameter
	int* wdPtr = &wd;

	int cpw; // cost per wafer
	int* cpwPtr = &cpw;

	float dpa; // defects per unit area
	float* dpaPtr = &dpa;

	// calculated vallues
	float yield; // yield
	float cpd; // cost per die
	float da; // area of each die

	// set vallues
	getVallues(dpwPtr, wdPtr, cpwPtr, dpaPtr);

	// calc die area
	da = calcDieArea(wdPtr, dpwPtr);

	// calc field
	yield = calcYield(da, dpaPtr);

	// calc cost per die
	cpd = calcPrice(cpwPtr, dpwPtr, yield);

	// write all the calculations
	std::cout << "\nCalculated Vallues\n" << std::endl;
	std::cout << "Die area: " << da << std::endl;
	std::cout << "Yield: " << yield << std::endl;
	std::cout << "Cost per Wafer: " << cpd << std::endl;

	return 0;

}

// get initial vallues
void getVallues(int* dpwPtr, int* wdPtr, int* cpwPtr, float* dpaPtr){

	std::cout << "\nInput vallues\n" << std::endl;

	std::cout << "Dies per wafer: ";
	std::cin >> *dpwPtr;
	std::cout << "\n";

	std::cout << "Wafer diameter: ";
	std::cin >> *wdPtr;
	std::cout << "\n";

	std::cout << "Cost per wafer: ";
	std::cin >> *cpwPtr;
	std::cout << "\n";

	std::cout << "Damage per wafer area: ";
	std::cin >> *dpaPtr;
	std::cout << "\n";
}

// takes wafer diameter, and dies per wafer
// returns die area
float calcDieArea(int* wdPtr, int* dpwPtr){
	float da, wa, r;

	// calculate radias
	r = (float)*wdPtr / 2;

	// calc wafer area
	wa = M_PI * pow(r, 2);

	// calc area of each die
	da = wa / (float)*dpwPtr;

	return da;
}

// takes die area and defents per area
// returns yeild
float calcYield(float da, float* dpaPtr){
	float y;

	y = 1 / pow(1 + da * ((*dpaPtr) / 2), 2);

	return y;
}

// takes cost per wafer, dies per wafer, yield
// returns cost per die
float calcPrice(int* cpwPtr, int* dpwPtr, float yield){
	float p;

	p = ((float)*cpwPtr) / (((float)*dpwPtr) * yield);

	return p;
}

