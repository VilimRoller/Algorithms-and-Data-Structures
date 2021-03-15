import matplotlib.pyplot as plt

fileName = "Uniform distribution benchmark results_BigObj.txt"
numberOfSortingAlgorithms = 7
windowTitle = "Sorting algorithms benchmark"
plotTitle = "Sorting algorithms execution time"
objectType = "~1,6 KB objects"
xAxisLabel = "Number of vector elements"
yAxisLabel = "Execution time [us]"

def getPlotTitle(DistributionType):
    return plotTitle + " for " + DistributionType + " for " + objectType

def openDataFile(nameOfFile):
    file = open(nameOfFile, "r")
    return file

def getNameOfDistribution(DataFile):
    return DataFile.readline().split()[2] + " distribution"

def getXAxisData(DataFile):
    StringList = DataFile.readline().split()[4:]
    FloatList = [float(i) for i in StringList]
    return FloatList

def skipLines(DataFile, NumberOfLines):
    for _ in range(NumberOfLines):
        line = DataFile.readline()

def getAlgorithmName(DataFile):
    dataLine = DataFile.readline().split()
    return dataLine[2] + " " + dataLine[3]

def getAlgorithmMeasuredTimes(DataFile):
    StringList = DataFile.readline().split()[3:]
    FloatList = [float(i) for i in StringList]
    return FloatList

def fillAlgorithmData(AlgoNames, AlgoTimes, NumberOfAlgos, DataFile):
    for algorithm in range(NumberOfAlgos):
        AlgoNames.append(getAlgorithmName(DataFile))
        skipLines(DataFile, 6)
        AlgoTimes.append(getAlgorithmMeasuredTimes(DataFile))
        skipLines(DataFile, 1)

def setPlotWindow():
    fig = plt.figure(windowTitle, figsize=(15, 10))
    fig.suptitle(getPlotTitle(nameOfDistribution))
    ax = fig.add_subplot(1, 1, 1)
    setAxisLabels(ax)
    return fig, ax

def setAxisLabels(ax):
    ax.set_xlabel(xAxisLabel)
    ax.set_ylabel(yAxisLabel)

def plotAllAlgorithms(ax, xAxis, AlgorithmMeasuredTimes, AlgorithmNames, numberOfSortingAlgorithms):
    for algoIndex in range(numberOfSortingAlgorithms):
        ax.plot(xAxis, AlgorithmMeasuredTimes[algoIndex], label=AlgorithmNames[algoIndex])

def showPlotWindow(ax):
    ax.legend()
    plt.show()

DataFile = openDataFile(fileName)
AlgorithmNames = []
AlgorithmMeasuredTimes = []

nameOfDistribution = getNameOfDistribution(DataFile)
xAxis = getXAxisData(DataFile)
skipLines(DataFile, 2)
fillAlgorithmData(AlgorithmNames, AlgorithmMeasuredTimes, numberOfSortingAlgorithms, DataFile)

fig, ax = setPlotWindow()

plotAllAlgorithms(ax, xAxis, AlgorithmMeasuredTimes, AlgorithmNames, numberOfSortingAlgorithms)

showPlotWindow(ax)

DataFile.close()