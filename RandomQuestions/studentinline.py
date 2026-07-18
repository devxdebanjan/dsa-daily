# Given an array A representing student heights. All students must form into several lines, arriving in the order they appear in the array.

# For the i-th student:

#     If there exists a line where all students in that line are taller than A[i], the student may join any such line.
#     If no such line exists, the student must start a new line.

# Compute the minimum number of lines that will be created.

# Write a function that, given a non-empty integer array A (length N), returns the minimum number of linesite a function that, given a non-empty integer array A (length N), returns the minimum number of lines

def studentLines(A):
    lines = 0
    lastmember = []

    for student in A:

        if(len(lastmember)==0):
            lines+=1
            lastmember.append(student)

        else:
            diff = 1e9
            for i in range(len(lastmember)):
                # print("here",lastmember[i],student )
                if(lastmember[i]>student):
                    if(diff>(lastmember[i]-student)):
                        indextemp = i
                        diff = lastmember[i]-student
                        
            if(diff==1e9):
                lines+=1
                lastmember.append(student)   
            else:
                lastmember[indextemp] = student
    return lines

print(studentLines([4,7,3,2,8,1]))            
