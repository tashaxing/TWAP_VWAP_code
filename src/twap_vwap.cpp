#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <time.h>

// global file path 
const std::string kFilePath = "../data/market_price.csv";

// read the csv file to get market data
void readData(const std::string &filePath, std::vector<std::vector<std::string>> &marketDataTable)
{
	std::ifstream inFile(filePath);
	std::string lineStr;
	// read csv line by line
	while (std::getline(inFile, lineStr))
	{
		std::stringstream ss(lineStr);
		std::string str;
		std::vector<std::string> lineArray;
		// read one line separated by comma
		while (std::getline(ss, str, ','))
			lineArray.push_back(str);
		marketDataTable.push_back(lineArray);
	}
}

// calculate twap value
double calc_twap(std::vector<std::vector<std::string>> &marketDataTable)
{
	
	return 0.0;
}

// calculate vwap value
double calc_vwap(std::vector<std::vector<std::string>> &marketDataTable)
{
	return 0.0;
}

int main()
{
	std::vector<std::vector<std::string>> marketDataTable;
	readData(kFilePath, marketDataTable);

	return 0;
}