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

// calculate vwap value
double calc_vwap(std::vector<std::vector<std::string>> &marketDataTable)
{
	int n = marketDataTable.size() - 1; // skip the first title line
	double total_sum = 0.0;
	int volume_sum = 0;
	for (int i = 1; i <= n; i++)
	{
		// get the price and volume according to table structure
		double high_price = atof(marketDataTable[i][9].c_str());
		double low_price = atof(marketDataTable[i][10].c_str());
		double price = (high_price + low_price) / 2;
		int volume = atoi(marketDataTable[i][11].c_str());
		// compute total sum and volume sum
		total_sum += price * volume;
		volume_sum += volume;
	}

	return total_sum / volume_sum;
}

// calculate twap value
double calc_twap(std::vector<std::vector<std::string>> &marketDataTable)
{
	int n = marketDataTable.size() - 1; // skip the first title line
	double price_sum = 0.0;
	for (int i = 1; i <= n; i++)
	{
		// get the price and volume according to table structure
		double high_price = atof(marketDataTable[i][9].c_str());
		double low_price = atof(marketDataTable[i][10].c_str());
		double price = (high_price + low_price) / 2;
		// compute price sum and time sum
		// here use the 1 min K-line data, so total time is n minutes
		price_sum += price;
	}

	return price_sum / n;
}

int main()
{
	std::vector<std::vector<std::string>> marketDataTable;
	std::cout << "reading market data" << std::endl;
	readData(kFilePath, marketDataTable);
	std::cout << "calculating TWAP and VWAP" << std::endl;
	std::cout << "VWAP: " << calc_twap(marketDataTable) << std::endl;
	std::cout << "TWAP: " << calc_vwap(marketDataTable) << std::endl;

	return 0;
}