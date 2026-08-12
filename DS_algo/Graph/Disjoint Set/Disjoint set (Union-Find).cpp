int find(int A[],int x)
{
       if(A[x] == x)
        return x;

        return A[x] = find(A, A[x]);
}
void unionSet(int A[],int X,int Z)
{
	int x = find(A, X);
	int y = find(A, Z);

	if(x == y)
	    return;

	A[x] = y;
}
