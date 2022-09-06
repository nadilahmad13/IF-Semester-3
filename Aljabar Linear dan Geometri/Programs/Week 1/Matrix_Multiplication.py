def Matrix_Multiplication(A,B):
    C = []
    for i in range(len(A)):
        C.append([])
        for j in range(len(B[0])):
            C[i].append(0)
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]
    return C

# Matrix Input
B = [[1,2,4],[2,6,0]]
A = [[4,1,4,3],[0,-1,3,1],[2,7,5,2]]

# Call Function
C = Matrix_Multiplication(B,A)

# Final Output
for i in range(len(C)):
    for j in range(len(C[0])):
        print(C[i][j], end = ' ')
    print()