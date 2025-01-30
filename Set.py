import itertools
def insertele(lst):
	no=int(input("Enter no you want to insert "))
	if (no not in lst):
		lst.append(no)
		print(no ," is added ")
		print(lst)
	else:
		print("No is already present")

def delete(lst):
	no=int(input("Enter no you want to delete "))
	lst.remove(no)
	print(no," is removed ")
	print(lst)

def contains(lst):
	
	no=int(input("Enter no you want to check "))
	
	if(no not in lst):
		print(no," is not present")
	else:
		print(no ," is present")
		
def uni(lst):
	list2=[]
	m=int(input("Enter no of students in second set"))
	for j in range(m):
		el=int(input("Enter student Roll no "))
		list2.append(el)
	print(list2)
	
	print("Union of two set is as follows: ")
	list3=[]
	list3.append(lst)
	list3.append(list2)
	print(list3)
	
def intersection(lst):
	list2=[]
	m=int(input("Enter no of students in second set"))
	for j in range(m):
		el=int(input("Enter student Roll no "))
		list2.append(el)
	print(list2)
	print("Intersection is:")
	
	inter=[]
	
	for i in list2:
		if(i in lst):
			inter.append(i)
	print(inter)
			
def printsublist(lst):
	sublists=[]
	for r in range(len(lst) + 1):
		sublists.extend(itertools.combinations(lst,r))
	return [list(sublist) for sublist in sublists]
	
def check_subset(lst):
    
    subset = []
    n = int(input("Enter the size of the subset: "))
    for _ in range(n):
        ele = int(input("Enter an element of the subset: "))
        subset.append(ele)
    
   
    if all(ele in lst for ele in subset):
        print("The given set is a subset.")
    else:
        print("The given set is not a subset.")

			
def main():

	count=8
	lst=[]
	n=int(input("Enter no of students "))
	for i in range(n):
		ele=int(input("Enter student Roll no "))
		lst.append(ele)
	print(lst)
	print("1.Add element")
	print("2.Remove element")
	print("3.Check given elemnt is present in list")
	print("4.print size")
	print("5.Print Union of two sets")
	print("6.Print Intersection of Two Sets")
	print("7.Print Power Set")
	print("8.Check given set is subset of of existing list")
	while(count!=0):
		wish=input("do you want to continue? (yes/no)")
		if(wish=="yes"):
			ch=int(input("Enter choice"))
			if(ch==1):
				insertele(lst)
				count-=1
				
			elif(ch==2):
				delete(lst)
				count-=1
				
			elif(ch==3):
				contains(lst)
				count-=1
			elif(ch==4):
				print("size= ",n)
				count-=1
			elif(ch==5):
				uni(lst)
				count-=1
			elif(ch==6):
				intersection(lst)
				count-=1
			elif(ch==7):
				print(printsublist(lst))
				count-=1
			elif(ch==8):
				check_subset(lst)
				count-=1
				
			else:
				print("Invalid choice")
		else:
			break
main()

		
			