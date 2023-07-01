import matplotlib.pyplot as plt

xAxisLabel = "Number of vector elements"
yAxisLabel = "Execution time [us]"

def getPlotTitle(distributionType, plotTitle):
    return plotTitle + " for " + distributionType + " using type: " + objectType

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
    StringList = DataFile.readline().split()[2:]
    FloatList = [float(i) for i in StringList]
    return FloatList

def fillAlgorithmData(AlgoNames, AlgoTimes, NumberOfAlgos, DataFile):
    for algorithm in range(NumberOfAlgos):
        AlgoNames.append(getAlgorithmName(DataFile))
        skipLines(DataFile, 6)
        AlgoTimes.append(getAlgorithmMeasuredTimes(DataFile))
        skipLines(DataFile, 2)

def setPlotWindow(distributionName, windowTitle, plotTitle):
    fig = plt.figure(windowTitle, figsize=(15, 10))
    fig.suptitle(getPlotTitle(distributionName, plotTitle))
    ax = fig.add_subplot(1, 1, 1)
    setAxisLabels(ax)
    return fig, ax

def setAxisLabels(ax):
    ax.set_xlabel(xAxisLabel)
    ax.set_ylabel(yAxisLabel)

def plotAllAlgorithms(ax, xAxis, AlgorithmMeasuredTimes, AlgorithmNames, numberOfAlgorithms):
    for algoIndex in range(numberOfAlgorithms):
        ax.plot(xAxis, AlgorithmMeasuredTimes[algoIndex], label=AlgorithmNames[algoIndex])

def plotResults(filePath, numberOfAlgorithms, windowTitle, plotTitle, objectType):
    DataFile = openDataFile(filePath)
    AlgorithmNames = []
    AlgorithmMeasuredTimes = []

    distributionName = getNameOfDistribution(DataFile)
    xAxis = getXAxisData(DataFile)
    skipLines(DataFile, 2)

    fillAlgorithmData(AlgorithmNames, AlgorithmMeasuredTimes, numberOfAlgorithms, DataFile)

    fig, ax = setPlotWindow(distributionName, windowTitle, plotTitle)
    plotAllAlgorithms(ax, xAxis, AlgorithmMeasuredTimes, AlgorithmNames, numberOfAlgorithms)
    ax.legend()
    DataFile.close()

searchResultFilePath = "AlgorithmsAndDataStructures/Search Algorithms Benchmark.txt"
numberOfSearchAlgorithms = 4
searchWindowTitle = "Search algorithms benchmark"
searchPlotTitle = "Search algorithms execution time"
objectType = "int"

sortResultFilePath = "AlgorithmsAndDataStructures/Uniform distribution benchmark results.txt"
numberOfSortAlgorithms = 7
sortWindowTitle = "Sort algorithms benchmark"
sortPlotTitle = "Sort algorithms execution time"


plotResults(searchResultFilePath, numberOfSearchAlgorithms, searchWindowTitle, searchPlotTitle, objectType)
plotResults(sortResultFilePath, numberOfSortAlgorithms, sortWindowTitle, sortPlotTitle, objectType)

plt.show()