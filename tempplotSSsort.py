import matplotlib.pyplot as plt 

# line 1 points 
x1 =[50,100,1000,10000,100000]
y1 = [0.000060,0.000077,0.00722,0.451,67.59] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 =[50,100,1000,10000,100000,300000,500000,1000000,2000000]
y2 =  [0.000033,0.000042,0.000191,0.00347,0.0333,0.1125,0.204,0.410,0.894]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 



# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Search Comparison on sorted data set') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
