
#include <iostream>
#include "hospital.h"
#include "doctor.h"
#include "menu.h"
//#include "table.h"

using namespace std;

int main()
{
    HospitalList H;
    createHospitalList(H);

    DoctorList D;
    createDoctorList(D);

    handleChoice(H, D);
    // vector<vector<string>> data;

	// // Adding rows incrementally
	// data.push_back(vector<string>{ "Cell11", "Cell12", "Cell13" });
	// data.push_back(vector<string>{ "Cell21", "Cell22", "Cell23" });
	// data.push_back(vector<string>{ "Cell31", "Cell32", "Cell33" });
	// string title = "RS Pinna\nID : 11\nJl. Suropati";

	// try {
	// 	printTable(3, 10, title, data);
	// } catch (const exception& e) {
	// 	cerr << "Error: " << e.what() << endl;
	// }

    return 0;
}
