#include <stdio.h>
#include <stdlib.h>
#include<string.h>
  typedef struct hastabilgi{
int no;
char ad[40];
int yas;
char hastalik[60];
 }hasta;
void kayitsil(FILE* fptr)
{
    hasta bilgi={0,"",0,""};
    int numara;
    printf("silmek istediginiz hastanin numarasini girin ");
    scanf("%d",&numara);
    fseek(fptr,(numara-1)*sizeof(hasta),SEEK_SET);
      fread(&bilgi,sizeof(hasta),1,fptr);
    if(bilgi.no==numara)
    {
       fseek(fptr,(numara-1)*sizeof(hasta),SEEK_SET);
       fwrite(&bilgi,sizeof(hasta),1,fptr);

    }
    else
    {
        printf("%d nolu hasta bulunmamaktadir",numara);
    }
}
void hastaduzenleme(FILE*fptr)
{
    int numara;
    char guncel;
    hasta bilgi={0,"",0,""};
    printf("duzenleyeceginiz hastanin numarasini girin");
    scanf("%d",&numara);
     fseek(fptr,(numara-1)*sizeof(hasta),SEEK_SET);
 fread(&bilgi,sizeof(hasta),1,fptr);
 if(bilgi.no==0)
 {
     printf("%d numarali hasta bulunmamaktadir",numara);

 }
 else
 {
    fprintf(fptr,"%d%s%d%s",bilgi.no,bilgi.ad,bilgi.yas,bilgi.hastalik);
       printf("yeni hastal�g� giriniz");
       gets(guncel);
       strcmp(bilgi.hastalik,guncel);
        fseek(fptr, (numara - 1) * sizeof(hasta), SEEK_SET);
        fwrite(&bilgi, sizeof(hasta), 1, fptr);

 }
}
void kayitlistele(FILE*fptr)
{
     hasta bilgi={0,"",0,""};
     while(!feof(fptr))
     {
          fread(&bilgi,sizeof(hasta),1,fptr);
          if(bilgi.no!=0)
          {
                printf("%d%s%d%s",bilgi.no,bilgi.ad,bilgi.yas,bilgi.hastalik);
          }
     }
}
int main()
{
    int secim;
    FILE *dosya;
    if((dosya=fopen("hastabilgi.txt","r+"))==NULL)
    {
        printf("dosya acilamadi");
    }
    else
    {

int i,n;
printf("kac hasta girisi yapicaksiniz");
scanf("%d",&n);
   for (i = 0; i < n; i++) {
        hasta bilgi;
        printf("Hasta bilgilerini giriniz:\n");
        scanf("%d %s %d %s", &bilgi.no, bilgi.ad, &bilgi.yas, bilgi.hastalik);
        fprintf(dosya, "%d %s %d %s\n", bilgi.no, bilgi.ad, bilgi.yas, bilgi.hastalik);
    }

    printf("yapmak istediginiz islemi seciniz");
    printf("1-hasta kaydi silme");
    printf("2-hasta kaydi d�zenleme");
    printf("3-hasta kaydini listeleme");
    printf("4-cikis");
    scanf("%d",&secim);
    switch(secim)
    {
        case 1:kayitsil(dosya); break;
        case 2:hastaduzenleme(dosya); break;
        case 3: kayitlistele(dosya); break;
        case 4: exit(0);
        default: printf("yanl�s secim yapt�n�z");
    }
    fclose(dosya);
    }
    return 0;
}
