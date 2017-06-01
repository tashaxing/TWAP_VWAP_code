import csv

# global file path 
filePath = "../data/market_price.csv"

# read the csv file to get market data
def readData(filePath):
    marketDataTable = list()
    try:
    	fileIn = open(filePath, 'r')
    	reader = csv.reader(fileIn)
    	for row in reader:
    		marketDataTable.append(row)
    finally:
    	fileIn.close()
    
    return marketDataTable

# calculate vwap value
def calc_vwap(marketDataTable):
	n = len(marketDataTable) - 1
	total_sum = 0.0
	volume_sum = 0
	for i in range(1, n + 1):
		high_price = float(marketDataTable[i][9])
		low_price = float(marketDataTable[i][10])
		price = (high_price + low_price) / 2
		volume = int(marketDataTable[i][11])
		total_sum += price * volume
		volume_sum += volume

	return total_sum / volume_sum

# calculate vwap value
def calc_twap(marketDataTable):
	n = len(marketDataTable) - 1
	price_sum = 0.0
	for i in range(1, n + 1):
		high_price = float(marketDataTable[i][9])
		low_price = float(marketDataTable[i][10])
		price = (high_price + low_price) / 2
		price_sum += price

	return price_sum / n

if __name__ == "__main__":
	print "reading market data"
	marketDataTable = readData(filePath)
	print "calculating TWAP and VWAP"
	print "VWAP: ", calc_vwap(marketDataTable) 
	print "TWAP: ", calc_twap(marketDataTable) 