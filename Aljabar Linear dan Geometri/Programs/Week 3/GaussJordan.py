def GaussJordan(A,B):
    # Membuat matriks augmented
    for i in range(len(A)):
        A[i].append(B[i][0])
    # Membuat matriks segitiga atas
    for i in range(len(A)):
        for j in range(len(A)):
            if i != j:
                c = A[j][i]/A[i][i]
                for k in range(len(A)+1):
                    A[j][k] = A[j][k] - c*A[i][k]
    # Membuat matriks segitiga bawah
    for i in range(len(A)-1,-1,-1):
        for j in range(len(A)-1,-1,-1):
            if i != j:
                c = A[j][i]/A[i][i]
                for k in range(len(A)+1):
                    A[j][k] = A[j][k] - c*A[i][k]
    # Membuat matriks diagonal
    for i in range(len(A)):
        c = A[i][i]
        for j in range(len(A)+1):
            A[i][j] = A[i][j]/c
    # Membuat matriks solusi
    X = []
    for i in range(len(A)):
        X.append([A[i][len(A)]])
    return X

A = [[1,-2,2,-1,-1],[2,1,-2,-2,-2],[-1,2,-4,1,1],[3,1,1,-3,-3]]
B = [[1],[-2],[4],[6]]

x = GaussJordan(A,B)
print(x)