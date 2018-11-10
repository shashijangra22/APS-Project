import matplotlib.pyplot as plt 

# line 1 points 
x1 = [50,100,1000,10000,100000,300000,500000,1000000,2000000] 
y1 = [0.000112,0.000069,0.000585,0.00599,0.036,0.112,0.184,0.365,0.790] 
# plotting the line 1 points 
plt.plot(x1, y1, label = "Binomial Heap") 

# line 2 points 
x2 = [50,100,1000,10000,100000,300000,500000,1000000,2000000]  
y2 =  [0.000072,0.000107,0.000471,0.00953,0.0815,0.2599,0.459,0.946,1.976]
# plotting the line 2 points 
plt.plot(x2, y2, label = "AVL tree") 



# naming the x axis 
plt.xlabel('Input Size (n)') 
# naming the y axis 
plt.ylabel('Time Taken in sec') 
# giving a title to my graph 
plt.title('Insert Comparison on sorted data set') 

# show a legend on the plot 
plt.legend() 

# function to show the plot 
plt.show() 
