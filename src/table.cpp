#include "table.h"

using namespace std;

static string padString(const string& str, int width) {
	if (str.length() >= width)
		return str.substr(0, width);
	return str + string(width - str.length(), ' ');
}

static void printSeparator(int numCols, int cellWidth) {
    for (int col = 0; col < numCols + 1; ++col) {
		cout << "+" << string(cellWidth, '-');
	}
	cout << "+" << endl;
}

static void printTitle(const string& title, int numCols, int cellWidth) {
    int totalWidth = (cellWidth + 1) * (numCols + 1) + 1;

    // Split the title into lines by `\n`
    vector<string> lines;
    size_t start = 0;
    size_t end = title.find('\n');
    while (end != string::npos) {
        lines.push_back(title.substr(start, end - start));
        start = end + 1;
        end = title.find('\n', start);
    }
    lines.push_back(title.substr(start)); // Add the last line

    // Print the top border of the title
    cout << "+" << string(totalWidth - 2, '-') << "+" << endl;

    // Print each line of the title, center-aligned
    for (const auto& line : lines) {
        int paddingLeft = (totalWidth - 2 - line.length()) / 2;
        int paddingRight = totalWidth - 2 - paddingLeft - line.length();
        cout << "|" << string(paddingLeft, ' ') << line << string(paddingRight, ' ') << "|" << endl;
    }
}


void printTable(int cols, int width, const string& tableTitle, const vector<vector<string>>& data) {
	int rows = data.size();
	if (data.size() != rows || (rows > 0 && data[0].size() != cols)) {
		throw runtime_error("Data dimensions do not match the specified number of rows and columns.");
	}

	// Print the title
	printTitle(tableTitle, cols, width);

	// Print the content of the table
	for (int row = 0; row < rows; ++row) {
		printSeparator(cols, width);
		cout << "|" << padString(to_string(row + 1), width);
		for (int col = 0; col < cols; ++col) {
			cout << "|" << padString(data[row][col], width);
		}
		cout << "|" << endl;
	}
	printSeparator(cols, width);
}
