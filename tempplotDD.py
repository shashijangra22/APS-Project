import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,100000,200000,300000,500000,600000,700000,2000000] 
y1 = [0.000063,0.000152,0.001885,0.03588,3.886,16.589,79.23,58.85,463.35,581.17,3393.91] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,100000,200000,300000,500000,600000,700000,2000000] 
y2 =  [0.000038,0.000061,0.000920,0.008507,0.1351,0.3136,0.5070,0.959,1.206,1.366,3.544]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 


# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Delete Comparison on random data set') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
