import matplotlib.pyplot as plt
f=open("//Users//mohit//Desktop//elapse.txt","r")
s=f.readlines()


res=[]
for elem in s:
    res.append(float(elem.replace("\n","")))





x=[0,30,40]
plt.bar(x,res)

plt.xlabel("priorities")
plt.ylabel("execution time")
plt.show()

