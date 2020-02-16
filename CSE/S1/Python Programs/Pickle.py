#Pickling

import pickle

class_Name = raw_input("Enter the class name : ")
f=open("{0}.py".format(class_Name),"w")
f.write("class "+class_Name+":\n")
while(True):
    var_name=raw_input("Enter the variable name : ")
    var_value=input("Enter {0}'s value : ".format(var_name))
    if (type(var_value) == str):
        f.write("\t"+var_name+" = "+var_value+"\n")
    else:
        f.write("\t"+var_name+" = ")
        pickle.dump(var_value,f)
    op=raw_input("Do you want to add more (y/n) ? : ")
    if (op=='y' or op=='Y'):
        continue
    elif (op=='n' or op=="N"):
        break
    else:
        print("Invalid Input !")
f.close()


