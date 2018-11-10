import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,100000] 
y1 = [0.000052,0.000215,0.006542,0.4430,64.909] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,100000,200000,300000,500000,600000,700000,2000000] 
y2 =  [0.000028,0.000042,0.000516,0.004879,0.0767,0.1778,0.2909,0.537,0.67,0.800,3.486]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 


# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Search Comparison on random data set') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
