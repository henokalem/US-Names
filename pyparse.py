import pandas
import matplotlib.pyplot as plt


fileNames  = open('inputFile.txt', 'r')

for fileName in fileNames:
    data = pandas.read_csv(fileName[:-1], sep=",", header = None)
    data.columns = ["First Name", "Gender", "Count"]

data['Count'] = data['Count'].apply(pandas.to_numeric)

popularNames = data.sort_values(by='Count', ascending=0).head(10)

popularNamesList = []
index = []

for i in popularNames['Count']:
    popularNamesList.append(i)

for j in popularNames['First Name']:
    index.append(j)

numIndex = range(len(popularNamesList))
print(numIndex)

plt.bar(numIndex,popularNamesList)
plt.xlabel('Most Popular First Names')
plt.ylabel('Count')
plt.title('US Name Popularity')
plt.xticks(numIndex, index)

plt.show()




#print(data.head(40));


#data = pandas.read_csv('namesData/yob1880.txt', sep=",", header = None)

#data.columns = ["First Name", "Gender", "Count"]

#print(data.head(5))
