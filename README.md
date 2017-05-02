# Parallel-computing-to-multiply-large-matrices
Parallel computing to multiply large matrices using OpenMP library of C language for faster multiplication and extensive use of compluter hardware. <br />
We First show the multiplication of two large matrices without using OpenMP , that is the ususal multiplication algorithm which takes O(n^3) on any processor for a n x n matrix.  Use "withoutMP.c" for this purpose.<br />
Then , the same matrix is multiplied by using openMP directive "<omp.h>" which uses the concept of multithreading and uses all the cores of the processor. With a dual core or a Quad core processor , Time is considerably reduced, Whereas for a single core processor, time taken is increased, as threading takes time. Also, Time to multiply smaller matrices is more when openMP is used. This is because, Time taken for multiplying is overcome by the time taken for multithreading.

