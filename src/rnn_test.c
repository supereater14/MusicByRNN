/* predicts next character
 * given previous characters:
 * 1-hot encoding (so (256)-tensor)
 * goes via 16x256 tensor to size-16 memory
 * which also feeds into itself by 16x16 tensor,
 * and feeds out to C 256x16
 * which is then filtered through softmax
 * A => B => C => D
       ^ \
       \_|
 */    
#include <math.h>

#define NUM_CHARS 256
#define MEM_SIZE 16

double A[NUM_CHARS];
double B[MEM_SIZE];
double C[NUM_CHARS];
double D[NUM_CHARS];

double BA[MEM_SIZE][NUM_CHARS]; /*B from A*/
double BB[MEM_SIZE][MEM_SIZE]; /*B from B*/
double CB[NUM_CHARS][MEM_SIZE]; /*C from B*/

inline double sigmoid(double x) {
   return 1.0/(1.0+exp(-x));
}

void update_B() {
   int c, m, n;
   for(m=0; m!=MEM_SIZE; ++m) {
      B[m] = 0.0;
      for(n=0; n!=MEM_SIZE; ++n) {
         B[m] += BB[m][n]*B[n];
      }
      for(c=0; c!=NUM_CHARS; ++c) {
         B[m] += BA[m][c]*A[c];
      }
      B[m] = sigmoid(B[m]);
   }
}

void update_C() {
   int c, m;
   for(c=0; c!=NUM_CHARS; ++c) {
      C[c] = 0.0;
      for(m=0; m!=MEM_SIZE; ++m) {
         C[c] += CB[c][m]*B[m];
      }
      C[c] = exp(C[c]);
   }
}

void update_D() {
   int c;
   double sum=0.0;
   for(c=0; c!=NUM_CHARS; ++c) {
      sum += C[c];
   }
   for(c=0; c!=NUM_CHARS; ++c) {
      D[c] = C[c]/sum;
   }
}

int main(int argc, char** argv) {
   return 0;
}
