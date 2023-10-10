#include <stdio.h>
#include <stdlib.h>
int main() {
      int i, n;
      printf("nhap gia tri: ");
      scanf("%d",&n);
      int mang[n];
      for(i=0;i<n;i++){
            printf("mang[%d] = ", i);
            scanf("%d",&mang[i]);
      }
      float tong=0, trungBinh=0;
      int dem=0;
      for(i=0;i<n;i++){
            if(mang[i]%3==0){
                  tong+=mang[i];
                  dem++;
            }
      }
      trungBinh = tong/dem;
      printf("Trung binh tong cac so chia het cho 3 trong mang la %.2f", trungBinh);
      return 0;
}
