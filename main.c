#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct dugum{
   char data;
   struct dugum *next;
};
typedef struct dugum node;

node *front=NULL;

int boyut_kontrol=0; //boyut kontrol dizi boyutuna eklenecek degeri hesaba katar
int matris_kontrolu=0; // bu matris varsa dizi islemlerinden kucuk degiskilkleri oldugunu kontrol edicek

char dizi_tipi[20]; //boyutu belirlenen dizi tipinin ne oldugunu belirtir

int donus_tipi_kontrol=0;
char donus_tipi[20];

char dongu_icin_baslik[100];

int sayac_ptr=0;
int kontrol_ptr=0;

int sayac_int=0;
char dizi_bellek_int[100];

int sayac_double=0;
char dizi_bellek_double[100];

int sayac_float=0;
char dizi_bellek_float[100];

int sayac_char=0;
char dizi_bellek_char[100];

int sayac_long=0;
char dizi_bellek_long[100];

int sayac_short=0;
char dizi_bellek_short[100];

int sayac_byte=0;
char dizi_bellek_byte[100];

int sayac_bool=0;
char dizi_bellek_bool[100];

char bigo_tutucu[100][100]; //tum big o lari tutucak
int fonk_sayisi=0;  // big o sayilarini vericek   not : index tutucak

char genel_big[100][100]; //fonksiyonlarin genel big olarini vericek

char bigo[100][100]; // anlik fonk icin hesaplana n big o yu tutucak
int anlik_sayisi=0;    // bigo index i tutucak


int do_araligi=0;
int do_miktar_bul=0;
char do_big[100];
int gelen_Do_mu=0;
int do_eklendi_mi=0;

int while_miktar_bul=0;
char while_big[100];
int while_Eklendi_mi=0;
int gelen_while_mi=0;
char while_Degiskeni[100];

char degeler_for[100][100];
int degerler_for_sayisi=0;   //bunlar benim for degelerimi tutucak
int adim_sayisi=0;
int gelen_for_mu=0;
int parantez_for_sayisi=0;

int pp=-1; // bu bize en son pop mu push mu edildigini soyleyecek
int pop_sayisi=0;

char rec[100]; // recursiv i ayri ttutucak

int l=0; // c dili olup olmadigini kontrol eder

int recursive=0;









int bos_mu()
{
    if(front==NULL)
    {
        return 1;
    }
    return 0;
}
void push(char data)
{
    if(front==NULL)
    {
        front=(node *)malloc(sizeof(front));
        front->data=data;
        front->next=NULL;
    }
    else
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->data=data;
        temp->next=front;
        front=temp;
    }

}

void pop()
{
    if(front==NULL)
    {
        printf("stuck bos\n");
    }
    else
    {
        front=front->next;
    }

}

void dolas()
{
    node *iter=front;
    if(iter==NULL)
    {
        printf("Stuck bos...\n");
        return;
    }
    while(iter!=NULL)
    {
        printf("%c ",iter->data);
        iter=iter->next;
    }
    printf("\n");
}

int eleman_sayisi() //suslu parantez sayisi dondurur
{
    if(front==NULL)
    {
        return 0;
    }
      int i=0;
      node *iter=front;
      while(iter!=NULL)
      {
          i++;
          iter=iter->next;
      }

    return i;
}

void bosluk_kaldir(char *String)
{
    int i=0,y=0;

    for(i=0,y=0;String[i]!='\0';i++,y++)
    {
        String[y]=String[i];

        if(String[i]==' ')
           y--;
    }
    String[y]='\0';
}

void bas_bosluk_kaldir(char *String)
{
    int i=0,y=0;
    for(i=0,y=0;String[i]!='\0';i++,y++)
    {
        String[y]=String[i];

        if(String[i]==' ')
           y--;
        if(String[i]!=' ')
        {
            i++;
            y++;
            break;
        }
    }
    for(;String[i]!='\0';i++,y++)
    {
        String[y]=String[i];
    }
    String[y]='\0';
}

void dosya_bos_mu()
{
     FILE *dosyaptr=fopen("kod.txt","r");

    if (dosyaptr!=NULL)
    {
      fseek (dosyaptr, 0, SEEK_END); //dosya sonuna gidliyor
      int size = ftell(dosyaptr); //dosya boyutunu aliniyor

        if (size==0)
        {
          printf("Dosya icerigi bostur islem yapilamaz !!!\n");
          fclose(dosyaptr);
          exit(0);
        }
    }
    fclose(dosyaptr);
}


void oku(char kod[8000])
{
     FILE *dosyaptr=fopen("kod.txt","r");



    if(dosyaptr==NULL)
    {
        printf("Dosya acilirken bir hata olustu...\n");
        return ;
    }

    char temp[100];
    char metin[8000]="";


    char *ptr;
     while(!feof(dosyaptr))
     {
         fgets(temp,100,dosyaptr);
         if(l==0)
         {
             if((ptr=strstr(temp,"stdio.h")!=NULL))
             {
                 l=1;
             }
         }
         strcat(metin,temp);
     }
     fclose(dosyaptr);

   strcpy(kod,metin);

}

void dongu_kontrolu(char taslak[100])
{
    char *ptr_1; //amacı istenilen degerlerin olup olmadigini dondurmek
    // rekürsiv yapi kontrolu
    int sayi=0;

    char bosluksuz[100];
    strcpy(bosluksuz,taslak);
    bosluk_kaldir(bosluksuz);

    if(do_miktar_bul==1)
    {
        char t[100];
        strcpy(t,taslak);
        bas_bosluk_kaldir(t);
        //artis miktarini bulmaliyim
        if((ptr_1=strstr(t,"for"))==NULL)
        {
            if((ptr_1=strstr(t,"+"))!=NULL)
            {
                strcpy(do_big,"n");
                if((ptr_1=strstr(t,"while"))!=NULL)
                    do_miktar_bul=0;

            }
            else if((ptr_1=strstr(t,"-"))!=NULL)
            {
                strcpy(do_big,"n");
                if((ptr_1=strstr(t,"while"))!=NULL)
                    do_miktar_bul=0;

            }
            else if((ptr_1=strstr(t,"*"))!=NULL)
            {
                strcpy(do_big,"log'n");
               if((ptr_1=strstr(t,"while"))!=NULL)
                    do_miktar_bul=0;
            }
            else if((ptr_1=strstr(t,"/"))!=NULL)
            {
                strcpy(do_big,"log'n");
                if((ptr_1=strstr(t,"while"))!=NULL)
                    do_miktar_bul=0;
            }
        }
       // printf("do_big=%s\n",do_big);
    }
    if(while_miktar_bul==1)
    {
          char t[100];
          strcpy(t,taslak);
          bas_bosluk_kaldir(t);

          if(ptr_1=strstr(t,"for")==NULL)
          {
           if(ptr_1=strstr(t,while_Degiskeni)!=NULL)
           {
            if((ptr_1=strstr(t,"+"))!=NULL)
            {
                 int byldum=0;
                if((ptr_1=strstr(t,"="))!=NULL)
                {



                         if(t[0]==while_Degiskeni[0] && t[1]==while_Degiskeni[1])
                                byldum=1;
                          else
                            byldum=-1;

                }
                if(byldum!=-1){
                strcpy(while_big,"n");
                while_miktar_bul=0;
                }

            }
            else if((ptr_1=strstr(t,"-"))!=NULL)
            {
                int byldum=0;
                if((ptr_1=strstr(t,"="))!=NULL)
                {



                         if(t[0]==while_Degiskeni[0] && t[1]==while_Degiskeni[1])
                                byldum=1;
                          else
                            byldum=-1;

                }
                if(byldum!=-1){
                strcpy(while_big,"n");
                while_miktar_bul=0;
                }

            }
            else if((ptr_1=strstr(t,"*"))!=NULL)
            {
                int byldum=0;
                if((ptr_1=strstr(t,"="))!=NULL)
                {



                         if(t[0]==while_Degiskeni[0] && t[1]==while_Degiskeni[1])
                                byldum=1;
                          else
                            byldum=-1;

                }
                if(byldum!=-1){
                strcpy(while_big,"log'n");
                while_miktar_bul=0;
                }
            }
            else if((ptr_1=strstr(t,"/"))!=NULL)
            {
               int byldum=0;
                if((ptr_1=strstr(t,"="))!=NULL)
                {



                         if(t[0]==while_Degiskeni[0] && t[1]==while_Degiskeni[1])
                                byldum=1;
                          else
                            byldum=-1;

                }
                if(byldum!=-1){
                strcpy(while_big,"log'n");
                while_miktar_bul=0;
                }
            }

           }
          }
    }

    if((ptr_1=strstr(taslak,dongu_icin_baslik))!=NULL) //biz rekursiv bir yapının icerisindeyiz
    {
        ptr_1++;
        recursive++;
         if((ptr_1=strstr(ptr_1,dongu_icin_baslik))!=NULL) // bir tane daha var bu bize 2^n i verir
         {
             recursive++;
             //printf("Recursivden geldim Bu bize 2^n verir...\n");
             strcpy(rec,"2^n");

         }
         else if(recursive>1)
         {
             recursive++;
            // printf("Recursivden geldim Bu bize 2^n verir...\n");
             strcpy(rec,"2^n");

         }
         else
         {
             ptr_1=strstr(taslak,"(");
             ptr_1++;

             if(ptr_1=strstr(taslak,"+"))
             {
                // printf("Recursivden geldim Bu biz n verir ...\n");
                 strcpy(rec,"n");

             }
             else if(ptr_1=strstr(taslak,"-"))
             {
                // printf("Recursivden geldim Bu biz n verir ...\n");
                 strcpy(rec,"n");

             }
             else if(ptr_1=strstr(taslak,"*"))
             {
                // printf("Recursivden geldim Bu biz log(n) verir ...\n");
                 strcpy(rec,"log'n");

             }
             else if(ptr_1=strstr(taslak,"/"))
             {
                 //printf("Recursivden geldim Bu biz log(n) verir ...\n");
                 strcpy(rec,"log'n");
             }

         }

    }

    if((ptr_1=strstr(bosluksuz,"for("))!=NULL)
    {

        // gelen_for_mu=1; simdilik
         int z=0; // anlik sayiisiin artip artmadigini kontrol edicek

         ptr_1=strstr(bosluksuz,";");
         ptr_1=strstr(ptr_1,";");   //artis miktarina geldim
         ptr_1++;
         char miktar[100];
         strcpy(miktar,ptr_1);


         if(pp==0)
         {
             char kopya[100];
             strcpy(kopya,"");

             if(eleman_sayisi()>=2 && pop_sayisi>0)
             {


                     strcpy(kopya,bigo[anlik_sayisi-pop_sayisi]);
                     anlik_sayisi+=pop_sayisi;                       //onceden eklenecek varsa ekliyor
                     z++;
                     strcpy(bigo[anlik_sayisi],kopya);

             }

             if(z==0)
             anlik_sayisi++;

             if((ptr_1=strstr(miktar,"+"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"n");
                 if(gelen_Do_mu==1 && strlen(do_big)!=0){
                    strcat(bigo[anlik_sayisi],do_big);
                    do_eklendi_mi=1;
                 }
                 if(gelen_while_mi==1 && strlen(while_big)!=0){
                    strcat(bigo[anlik_sayisi],while_big);
                    while_Eklendi_mi=1;
                 }
                 strcat(degeler_for[degerler_for_sayisi],"n");
                 degerler_for_sayisi++;
             }
             else if((ptr_1=strstr(miktar,"-"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"n");
                 if(gelen_Do_mu==1 && strlen(do_big)!=0){
                    strcat(bigo[anlik_sayisi],do_big);
                    do_eklendi_mi=1;
                 }
                 if(gelen_while_mi==1 && strlen(while_big)!=0){
                    strcat(bigo[anlik_sayisi],while_big);
                    while_Eklendi_mi=1;
                 }
                 strcat(degeler_for[degerler_for_sayisi],"n");
                 degerler_for_sayisi++;
             }
             else if((ptr_1=strstr(miktar,"/"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"log'n");
                 if(gelen_Do_mu==1 && strlen(do_big)!=0){
                    strcat(bigo[anlik_sayisi],do_big);
                    do_eklendi_mi=1;
                 }
                 if(gelen_while_mi==1 && strlen(while_big)!=0){
                    strcat(bigo[anlik_sayisi],while_big);
                    while_Eklendi_mi=1;
                 }
                 strcat(degeler_for[degerler_for_sayisi],"log'n");
                 degerler_for_sayisi++;
             }
             else if((ptr_1=strstr(miktar,"*"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"log'n");
                 if(gelen_Do_mu==1 && strlen(do_big)!=0){  //amacı do eklemek
                    strcat(bigo[anlik_sayisi],do_big);
                    do_eklendi_mi=1;
                 }
                 if(gelen_while_mi==1 && strlen(while_big)!=0){
                    strcat(bigo[anlik_sayisi],while_big);
                    while_Eklendi_mi=1;
                 }
                 strcat(degeler_for[degerler_for_sayisi],"log'n");
                 degerler_for_sayisi++;
             }

             pp=-1;
             pop_sayisi=0; //islemi yaptik 0 la
         }
         else
         {

             if((ptr_1=strstr(miktar,"+"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"n");
                 if(degerler_for_sayisi==0)
                 {
                     if(gelen_Do_mu==1 && strlen(do_big)!=0){  //amacı do eklemek
                        strcat(bigo[anlik_sayisi],do_big);
                        do_eklendi_mi=1;
                     }
                     if(gelen_while_mi==1 && strlen(while_big)!=0){
                        strcat(bigo[anlik_sayisi],while_big);
                        while_Eklendi_mi=1;
                    }
                 }
                 strcat(degeler_for[degerler_for_sayisi],"n");
                 degerler_for_sayisi++;
             }
             else if((ptr_1=strstr(miktar,"-"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"n");
                 if(degerler_for_sayisi==0)
                 {
                     if(gelen_Do_mu==1 && strlen(do_big)!=0){  //amacı do eklemek
                        strcat(bigo[anlik_sayisi],do_big);
                        do_eklendi_mi=1;
                     }
                     if(gelen_while_mi==1 && strlen(while_big)!=0){
                        strcat(bigo[anlik_sayisi],while_big);
                        while_Eklendi_mi=1;
                    }
                 }
                 strcat(degeler_for[degerler_for_sayisi],"n");
                 degerler_for_sayisi++;
             }
             else if((ptr_1=strstr(miktar,"/"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"log'n");
                 if(degerler_for_sayisi==0)
                 {
                     if(gelen_Do_mu==1 && strlen(do_big)!=0){  //amacı do eklemek
                        strcat(bigo[anlik_sayisi],do_big);
                        do_eklendi_mi=1;
                     }
                     if(gelen_while_mi==1 && strlen(while_big)!=0){
                        strcat(bigo[anlik_sayisi],while_big);
                        while_Eklendi_mi=1;
                    }
                 }
                 strcat(degeler_for[degerler_for_sayisi],"log'n");
                 degerler_for_sayisi++;
             }
             else if((ptr_1=strstr(miktar,"*"))!=NULL)
             {
                 strcat(bigo[anlik_sayisi],"log'n");
                 if(degerler_for_sayisi==0)
                 {
                     if(gelen_Do_mu==1 && strlen(do_big)!=0){  //amacı do eklemek
                        strcat(bigo[anlik_sayisi],do_big);
                      //  printf("Eklenen do big = %s\n",do_big);
                        do_eklendi_mi=1;
                     }
                     if(gelen_while_mi==1 && strlen(while_big)!=0){
                        strcat(bigo[anlik_sayisi],while_big);
                        while_Eklendi_mi=1;
                    }
                 }
                 strcat(degeler_for[degerler_for_sayisi],"log'n");
                 degerler_for_sayisi++;
             }
             pp=-1;


         }



    }
    else if((ptr_1=strstr(bosluksuz,"do{"))!=NULL)
    {


       do_miktar_bul=1;
       gelen_Do_mu=1;

    }

    else if((ptr_1=strstr(bosluksuz,"while("))!=NULL)
    {
        char *k; //do while ayrimi
        if((k=strstr(bosluksuz,";"))==NULL)
        {
            //printf("Girmem lazim\n");

            while_miktar_bul=1;
            gelen_while_mi=1;
            ptr_1=strstr(bosluksuz,"(");
            ptr_1++;
            char o[100];
            strcpy(o,ptr_1);
            bas_bosluk_kaldir(o);
            int i=0;
            while(1)
            {
                if(o[i]==' ' || o[i]=='<' || o[i]=='>' || o[i]=='=' || o[i]=='!')
                    break;

                while_Degiskeni[i]=o[i];
                i++;
            }
            while_Degiskeni[i]='\0';
           // printf("While_Degiskeni=%s\n",while_Degiskeni);
        }
    }



}

void dongu_icin_baslik_kontrolu(char taslak[100])
{
    char deneme[100];
    strcpy(deneme,taslak);
    bas_bosluk_kaldir(deneme);
    char *bosluk_ptr;

     bosluk_ptr=strstr(deneme," ");
     bosluk_ptr++;
   //  printf("Bosluk_ptr =%s\n",bosluk_ptr);
     if(bosluk_ptr[0]==' ')      //burdaki amac bosluktan sonra gelen namei bulmak;
        bosluk_ptr++;

     strcpy(deneme,bosluk_ptr);
    // printf("deneme=%s\n",deneme);
     bosluk_kaldir(deneme);
    // printf("Bosluk_kaldir=%s\n",deneme);

     int i=0;
     for(i=0; deneme[i]!='(' ; i++)
     {
         dongu_icin_baslik[i]=deneme[i];
     }
     dongu_icin_baslik[i]='\0';

    // printf("Baslik bulundu =%s\n",dongu_icin_baslik);
}


void zaman_karmasikligi()
{
    FILE *dosyaptr=fopen("kod.txt","r");
    if(dosyaptr==NULL)
    {
        printf("Dosya acilamadi.\n");
        return;
    }
    char temp[100];
    char *parentez_kontrolu;
     char *parantez_kapat_kontrolu;

     int baslik=0; //baslik bulunup bulunmadigini kontrol edicek
     int yapildi_mi=0;

    while(!feof(dosyaptr))
    {
        fgets(temp,100,dosyaptr);
        //printf("%s",temp);

         if(temp[0]=='#' || temp[0]=='\n')
         {
             continue;
         }

         if(baslik==0)
         {
             //printf("Baslik kontrolune girebildim mi\n");
            // printf("temp = %s\n",temp);
             baslik=1;
             dongu_icin_baslik_kontrolu(temp);


             if((parentez_kontrolu=strstr(temp,"{"))!=NULL)    //ekstra parantez olusa kacirmamak icin
             {
                push('{');

               // printf("{ prantez eklendi...\n");

             }
             continue;
         }

         if((parentez_kontrolu=strstr(temp,"{"))!=NULL)
         {
             //if(gelen_for_mu==1)
               // parantez_for_sayisi++;

               // gelen_for_mu=0;

             push('{');

            // printf("{ prantez eklendi...\n");

         }

         if(bos_mu()==1)
         {
             continue;
         }

         if((parantez_kapat_kontrolu=strstr(temp,"}"))!=NULL)
         {
             pop();
             pp=0;
             pop_sayisi++;

            // if(parantez_for_sayisi!=0)
             //   parantez_for_sayisi--;
            // printf("} parantez kapatildi...\n");

         }

         if(bos_mu()==1)
         {
             // fonksiyon btti
             baslik=0;
             recursive=0;

            // printf("\n%s",bigo);
             for(int i=0; i<=anlik_sayisi ; i++)
             {
                 if(strcmp(bigo[i],"")==0)
                    continue;
               //  printf("i nin degeri = %d\n",i);
                 strcat(bigo_tutucu[fonk_sayisi],bigo[i]);
                 if(i!=anlik_sayisi)
                 strcat(bigo_tutucu[fonk_sayisi],"+");
                                      // bu  ana tutucuya ekler
                 yapildi_mi=1;

             }


             for(int i=0; i<=anlik_sayisi ; i++)
             {
                 strcpy(bigo[i],"");
             }
             anlik_sayisi=0;
             // 0 lama islemi getceklesti

             if(do_eklendi_mi==0 && gelen_Do_mu==1)
             {
                 if(strcmp(bigo_tutucu[fonk_sayisi],"")!=0)
                 strcat(bigo_tutucu[fonk_sayisi],"+");
                 strcat(bigo_tutucu[fonk_sayisi],do_big);
                 if(yapildi_mi!=1)
                    yapildi_mi=1;

             }

             if(while_Eklendi_mi==0 && gelen_while_mi==1)
             {
                // printf("Girmem la\n");
                // printf("While_big=%s\n",while_big);
                 if(strcmp(bigo_tutucu[fonk_sayisi],"")!=0)
                 strcat(bigo_tutucu[fonk_sayisi],"+");
                 strcat(bigo_tutucu[fonk_sayisi],while_big);
                 if(yapildi_mi!=1)
                    yapildi_mi=1;

             }


             if(strlen(rec)!=0) // ayni fonkta recursive yapi da var onu da eklemeliyim
             {

                 //printf("Merhabalar olamam gerekn yerdeyim\n");
                 char k[100];
                 strcpy(k,rec);
                 strcat(k,"(");
                 strcat(k,bigo_tutucu[fonk_sayisi]);     //donusum islemleri
                 strcat(k,")");

                 strcpy(bigo_tutucu[fonk_sayisi],k);
                 if(yapildi_mi!=1)
                    yapildi_mi=1;

             }
             if(yapildi_mi==0)
             {
                 strcpy(bigo_tutucu[fonk_sayisi],"1");
                 fonk_sayisi++;
             }

             if(yapildi_mi==1)
             {
                 yapildi_mi=0;
                 fonk_sayisi++;     //fonksiyon sayisini duzgun arttirmak icin
             }

           /* printf("Degerler for sayisi=%d\n",degerler_for_sayisi);
             for(int i=0; i<degerler_for_sayisi; i++)
             {
                 printf("%s\n",degeler_for[i]);
             }*/


             strcpy(rec,"");

             strcpy(do_big,"");
             do_araligi=0;
             do_eklendi_mi=0;
             do_miktar_bul=0;                   // 0 lama yeri
             gelen_Do_mu=0;

             while_miktar_bul=0;
             strcpy(while_big,"");
             strcpy(while_Degiskeni,"");
             while_Eklendi_mi=0;
             gelen_while_mi=0;


             continue;
         }

         //buraya yapılacak islemler gelicek

         dongu_kontrolu(temp);


    }
    fclose(dosyaptr);

}

void kimlik_belirleme(char *taslak)
{
    char *tutucu;
    int m=0; // bu bana pointerda istisnai olaylarin sonrasını vericek
    //printf("Taslak=%s\n",taslak);

         if(strcmp(donus_tipi,"int")==0 && donus_tipi_kontrol==0)
         {
             donus_tipi_kontrol=1;
             sayac_int++;
            // printf("donus tipim int oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"float")==0 && donus_tipi_kontrol==0)
         {
             donus_tipi_kontrol=1;
             sayac_float++;
            // printf("donus tipim float oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"char")==0 && donus_tipi_kontrol==0)
         {
             donus_tipi_kontrol=1;
             sayac_char++;
            // printf("donus tipim char oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"double")==0 && donus_tipi_kontrol==0)
         {
              donus_tipi_kontrol=1;
              sayac_double++;
             // printf("donus tipim double oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"long")==0 && donus_tipi_kontrol==0)
         {
              donus_tipi_kontrol=1;
              sayac_long++;
             // printf("donus tipim long oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"short")==0 && donus_tipi_kontrol==0)
         {
              donus_tipi_kontrol=1;
              sayac_short++;
             // printf("donus tipim short oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"byte")==0 && donus_tipi_kontrol==0)
         {
              donus_tipi_kontrol=1;
              sayac_byte++;
            //  printf("donus tipim byte oldugunda artti\n");
         }
         else if(strcmp(donus_tipi,"bool")==0 && donus_tipi_kontrol==0)
         {
              donus_tipi_kontrol=1;
              sayac_bool++;
            //  printf("donus tipim byte oldugunda artti\n");
         }

     if((tutucu=strstr(taslak,"*"))!=NULL)
     {

         char *ptr_ozel;

         int t=0; //kontrol amacli
         char k[100];   //basta  tanımlama yapilmadan esttir kullanilip deger atilabailir bu istisnayi yok edicez
         //sayac_ptr++;
        // m++;

        /*  */
          if((ptr_ozel=strstr(taslak,"="))!=NULL)
          {
              strcpy(k,taslak);
              bas_bosluk_kaldir(k);
              for(int i=0; taslak[i]!='=';i++)  //yildiz esttir solunda mi
              {
                  if(taslak[i]=='*')
                  {
                      if(k[0]=='i' && k[1]=='n')
                      {
                            t=1;
                      }
                      else if(k[0]=='f' && k[1]=='l')
                      {
                          t=1;
                      }
                      else if(k[0]=='d' && k[1]=='o')
                      {
                          t=1;
                      }
                      else if(k[0]=='c' && k[1]=='h')
                      {
                            t=1;
                      }
                      else if(k[0]=='l' && k[1]=='o')
                      {
                            t=1;
                      }
                      else if(k[0]=='s' && k[1]=='h')
                      {
                            t=1;
                      }
                      else if(k[0]=='b' && k[1]=='y')
                      {
                            t=1;
                      }
                      else if(k[0]=='b' && k[1]=='o')
                      {
                            t=1;
                      }

                      if(t==1)
                      {
                          sayac_ptr++;
                          m++; //islem yapildi
                         // printf("Pointer tespit edildi.\n");

                      }
                  }
              }

          }
          else
          {
               strcpy(k,taslak);
              bas_bosluk_kaldir(k);
                      if(k[0]=='i' && k[1]=='n')
                      {
                            t=1;
                      }
                      else if(k[0]=='f' && k[1]=='l')
                      {
                          t=1;
                      }
                      else if(k[0]=='d' && k[1]=='o')
                      {
                          t=1;
                      }
                      else if(k[0]=='c' && k[1]=='h')
                      {
                            t=1;
                      }
                      else if(k[0]=='l' && k[1]=='o')
                      {
                            t=1;
                      }
                      else if(k[0]=='s' && k[1]=='h')
                      {
                            t=1;
                      }
                      else if(k[0]=='b' && k[1]=='y')
                      {
                            t=1;
                      }
                      else if(k[0]=='b' && k[1]=='o')
                      {
                            t=1;
                      }

                      if(t==1)
                      {
                          sayac_ptr++;
                          m++; //islem yapildi
                         // printf("Pointer tespit edildi.\n");

                      }

          }

         /* if((ptr_ozel=strstr(taslak,"="))!=NULL && g==1)
          {
              ptr_ozel++;
              if(ptr_ozel=strstr(ptr_ozel,"*"))     //butası pointer istisnalarını yok ediyor çarpmadan ayırıyor
              {                                      //burada carmalari ayirt ediyor
                  sayac_ptr--;
                  m--;
                  g=0;
              }

              for(int i=0; taslak[i]!='=' ; i++)
              {
                  if(taslak[i]=='*')
                  {
                      sayac_ptr++;
                       m++;
                       g=0;
                  }
              }
          }*/




     }
     if((tutucu=strstr(taslak,"["))!=NULL && m==0 )
     {
        // printf("Dizi Tespit edildi.\n");
         char *check; //tutucu parentezi dondurdu bana ayrıyetten degisken tipini tutucak ... lazım
         //dizi tipi belirleme
         if((check=strstr(taslak,"int "))!=NULL)
         {

             strcpy(dizi_tipi,"int");
         }
         else if((check=strstr(taslak,"float "))!=NULL)
         {
             strcpy(dizi_tipi,"float");
         }
         else if((check=strstr(taslak,"double "))!=NULL)
         {
             strcpy(dizi_tipi,"double");
         }
         else if((check=strstr(taslak,"char "))!=NULL)
         {
             strcpy(dizi_tipi,"char");
         }
         else if((check=strstr(taslak,"long "))!=NULL)
         {
             strcpy(dizi_tipi,"long");
         }
         else if((check=strstr(taslak,"short "))!=NULL)
         {
             strcpy(dizi_tipi,"short");
         }
         else if((check=strstr(taslak,"byte "))!=NULL)
         {
             strcpy(dizi_tipi,"byte");
         }
         else if((check=strstr(taslak,"bool "))!=NULL)
         {
             strcpy(dizi_tipi,"bool");
         }
         else
         {
             strcpy(dizi_tipi,"");
         }

         if(tutucu[1]==']')
         {
            boyut_kontrol=1;
            tutucu++;
         }
         else
         {
             tutucu++; //sayi kismina geldik
             if(strcmp(dizi_tipi,"int")==0)
             {
                 if((atoi(tutucu))!=0)     //eger [a] tarzı bir sey olamamisa
                 sayac_int+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_int);

                     dizi_bellek_int[i++]=tutucu[0];
                     dizi_bellek_int[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"float")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_float+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_float);

                     dizi_bellek_float[i++]=tutucu[0];
                     dizi_bellek_float[i]='\0';

                 }
             }
             else if(strcmp(dizi_tipi,"double")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_double+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_double);

                     dizi_bellek_double[i++]=tutucu[0];
                     dizi_bellek_double[i]='\0';

                 }
             }
             else if(strcmp(dizi_tipi,"char")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_char+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_char);

                     dizi_bellek_char[i++]=tutucu[0];
                     dizi_bellek_char[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"long")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_long+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_long);

                     dizi_bellek_long[i++]=tutucu[0];
                     dizi_bellek_long[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"short")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_short+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_short);

                     dizi_bellek_short[i++]=tutucu[0];
                     dizi_bellek_short[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"byte")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_byte+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_byte);

                     dizi_bellek_byte[i++]=tutucu[0];
                     dizi_bellek_byte[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"bool")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_bool+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_bool);

                     dizi_bellek_bool[i++]=tutucu[0];
                     dizi_bellek_bool[i]='\0';
                 }
             }
         }

         if((tutucu=strstr(tutucu,"["))!=NULL)// bu da matris mi degil mi onu kontrol edicek
         {
            // printf("Matris tepit edildi\n");
             if(boyut_kontrol==1)
                matris_kontrolu=1; //boyut kontrolune giricekse ayri kontrol de yapmaliyiz
             tutucu++;
             if(strcmp(dizi_tipi,"int")==0)
             {
                 if((atoi(tutucu))!=0)     //eger [a] tarzı bir sey olamamisa
                 sayac_int+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_int);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_int[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_int[i++]=tutucu[0];
                     dizi_bellek_int[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"float")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_float+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_float);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_float[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_float[i++]=tutucu[0];
                     dizi_bellek_float[i]='\0';

                 }
             }
             else if(strcmp(dizi_tipi,"double")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_double+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_double);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_double[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_double[i++]=tutucu[0];
                     dizi_bellek_double[i]='\0';

                 }
             }
             else if(strcmp(dizi_tipi,"char")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_char+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_char);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_char[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_char[i++]=tutucu[0];
                     dizi_bellek_char[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"long")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_long+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_long);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_long[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_long[i++]=tutucu[0];
                     dizi_bellek_long[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"short")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_short+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_short);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_short[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_short[i++]=tutucu[0];
                     dizi_bellek_short[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"byte")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_byte+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_byte);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_byte[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_byte[i++]=tutucu[0];
                     dizi_bellek_byte[i]='\0';
                 }
             }
             else if(strcmp(dizi_tipi,"bool")==0)
             {
                 if((atoi(tutucu))!=0)
                 sayac_bool+=atoi(tutucu);
                 else
                 {
                     int i=strlen(dizi_bellek_bool);
                     if(boyut_kontrol!=1) //o zaman yildiz koy
                     dizi_bellek_bool[i++]='*'; //bu bana matris oldugunu bildiricek
                     dizi_bellek_bool[i++]=tutucu[0];
                     dizi_bellek_bool[i]='\0';
                 }
             }

         }


     }
     else if((tutucu=strstr(taslak,"int "))!=NULL && m==0)
     {

        // printf("integer tespit edildi\n");
         sayac_int++;      //kendi degerini ekledik
        // printf("taslak=%s\n",taslak);


         if(boyut_kontrol==1)
         {
             boyut_kontrol=0; //amac degeri 0 lamak

             //tipini ogrenip benim 4m 8n gibi bunlari kaydetmem lazim

             if(strcmp(dizi_tipi,"int")==0)
             {
                 int i=strlen(dizi_bellek_int);
                     if(matris_kontrolu==1)
                     dizi_bellek_int[i++]='*';
                     dizi_bellek_int[i++]=tutucu[4];
                     dizi_bellek_int[i]='\0';

             }
             else if(strcmp(dizi_tipi,"float")==0)
             {
                int i=strlen(dizi_bellek_float);
                     if(matris_kontrolu==1)
                     dizi_bellek_float[i++]='*';
                     dizi_bellek_float[i++]=tutucu[4];
                     dizi_bellek_float[i]='\0';
             }
             else if(strcmp(dizi_tipi,"double")==0)
             {
                 int i=strlen(dizi_bellek_double);
                     if(matris_kontrolu==1)
                     dizi_bellek_double[i++]='*';
                     dizi_bellek_double[i++]=tutucu[4];
                     dizi_bellek_double[i]='\0';
             }
             else if(strcmp(dizi_tipi,"char")==0)
             {
                 int i=strlen(dizi_bellek_char);
                     if(matris_kontrolu==1)
                     dizi_bellek_char[i++]='*';
                     dizi_bellek_char[i++]=tutucu[4];
                     dizi_bellek_char[i]='\0';
             }
             else if(strcmp(dizi_tipi,"long")==0)
             {
                 int i=strlen(dizi_bellek_long);
                     if(matris_kontrolu==1)
                     dizi_bellek_long[i++]='*';
                     dizi_bellek_long[i++]=tutucu[4];
                     dizi_bellek_long[i]='\0';
             }
             else if(strcmp(dizi_tipi,"short")==0)
             {
                 int i=strlen(dizi_bellek_short);
                     if(matris_kontrolu==1)
                     dizi_bellek_short[i++]='*';
                     dizi_bellek_short[i++]=tutucu[4];
                     dizi_bellek_short[i]='\0';
             }
             else if(strcmp(dizi_tipi,"byte")==0)
             {
                 int i=strlen(dizi_bellek_byte);
                     if(matris_kontrolu==1)
                     dizi_bellek_byte[i++]='*';
                     dizi_bellek_byte[i++]=tutucu[4];
                     dizi_bellek_byte[i]='\0';
             }
             else if(strcmp(dizi_tipi,"bool")==0)
             {
                 int i=strlen(dizi_bellek_bool);
                     if(matris_kontrolu==1)
                     dizi_bellek_bool[i++]='*';
                     dizi_bellek_bool[i++]=tutucu[4];
                     dizi_bellek_bool[i]='\0';
             }

              matris_kontrolu=0;
         }
     }
     else if((tutucu=strstr(taslak,"float "))!=NULL && m==0)
     {
        //printf("float tespit edildi\n");
         sayac_float++;      //kendi degerini ekledik


     }
     else if((tutucu=strstr(taslak,"char "))!=NULL && m==0)
     {
       // printf("char tespit edildi\n");
         sayac_char++;      //kendi degerini ekledik


     }
     else if((tutucu=strstr(taslak,"double "))!=NULL && m==0)
     {
        // printf("double tespit edildi\n");
         sayac_double++;      //kendi degerini ekledik

     }
     else if((tutucu=strstr(taslak,"long "))!=NULL && m==0)
     {
        // printf("long tespit edildi\n");
         sayac_long++;      //kendi degerini ekledik

     }
     else if((tutucu=strstr(taslak,"short "))!=NULL && m==0)
     {
        // printf("short tespit edildi\n");
         sayac_short++;      //kendi degerini ekledik

     }
     else if((tutucu=strstr(taslak,"byte "))!=NULL && m==0)
     {
        // printf("byte tespit edildi\n");
         sayac_byte++;      //kendi degerini ekledik

     }
     else if((tutucu=strstr(taslak,"bool "))!=NULL && m==0)
     {
        // printf("bool tespit edildi\n");
         sayac_bool++;      //kendi degerini ekledik

     }

     m=0;
}
void govde_kontrolu(char *temp)
{
    //tanımlamala bakıcaz
    char *kesici;
    char taslak[100];
    char kesilen[100];
    char bas[100]="";
    char *ptr;
    int c=-1; //amacı neydik onu hatırlatacak
    int bb=0; //basligi burdan mi belirledik onu soylicek

    strcpy(kesilen,temp);

    //bazen suslu parantez baslgin yaninda olailiyor bu durum bizim donus tipini kacirmamaize sebep olur
    //bu durumu engellemek adina istisnayi yakalamak adına eksta kontrolmu yapıyorum
    char baslik_tutmak[100];
    char *p;  //parantez olmalı
    char *s;  //suslu parantez olmalı
    strcpy(baslik_tutmak,temp);
    bas_bosluk_kaldir(baslik_tutmak);

     if((s=strstr(baslik_tutmak,"{"))!=NULL)
     {
            if((p=strstr(baslik_tutmak,"("))!=NULL)
            {
                baslik_kontrolu(baslik_tutmak);
                return;
                //iki kosul saglaniyorsa baslik bulmamiz lazım


            }

     }



   if(ptr=strstr(kesilen,"(")==NULL){
         //burdaki eşittir null ın amacı yan yana yanımlanamanın fonksiyon atamalarından farkını belirlemek
    if((ptr=strstr(kesilen,"int "))!=NULL)
    {
       strcpy(bas,"int ");
       c=0;
    }
    else if((ptr=strstr(kesilen,"float "))!=NULL)
    {
        strcpy(bas,"float ");
        c=1;
    }
    else if((ptr=strstr(kesilen,"double "))!=NULL)
    {
        strcpy(bas,"double ");
        c=2;
    }
    else if((ptr=strstr(kesilen,"char "))!=NULL)
    {
        strcpy(bas,"char ");
        c=3;
    }
    else if((ptr=strstr(kesilen,"long "))!=NULL)
    {
        strcpy(bas,"long ");
        c=4;
    }
    else if((ptr=strstr(kesilen,"short "))!=NULL)
    {
        strcpy(bas,"short ");
        c=5;
    }
    else if((ptr=strstr(kesilen,"byte "))!=NULL)
    {
        strcpy(bas,"byte ");
        c=6;
    }
    else if((ptr=strstr(kesilen,"bool "))!=NULL)
    {
        strcpy(bas,"bool ");
        c=7;
    }
   }

     // burdaki amac dizi[]={1,2,3} gibi ciktşlari tespit etmek ve onlar icin ayri bir islem uygulamak
     // zaten eger baslisk belirlenmisstir simdi bizim koseli parantez olup olmadigina bakmamiz lazım
     char *kpptr; //koseli parantez olup olmadigii dondurucek pointer
     char *spptr; //bize koseli parantenzeden sonra suslu parantez olup olmadigin dondurucek pointer
     if((kpptr=strstr(kesilen,"["))!=NULL) //isteline durum gerceklesmistir
     {
         kpptr++;
       if(kpptr[0]==']')
       {
         if((spptr=strstr(kesilen,"{"))!=NULL)
         {
            // printf("Tespit edildi\n");
            char ekstra[100]; //bu bizim gelen degerin dizi degilde standart degisken gibi tutmamizi saglayak
            spptr++;
            strcpy(ekstra,spptr);
           // printf("Ekstra =%s\n",ekstra);
            kesici = strtok(ekstra,","); //geleni virgule gore ayır

           //  int k=1;
         while(kesici!=NULL)
         {
            // printf("%d-)%s\n",k,kesici);
            // k++;
             if(c==0)
              {
                  strcpy(bas,"int ");
              }
              else if(c==1)
              {
                  strcpy(bas,"float ");
              }
              else if(c==2)
              {
                  strcpy(bas,"double ");
              }
              else if(c==3)
              {
                  strcpy(bas,"char ");
              }
              else if(c==4)
              {
                  strcpy(bas,"long ");
              }
              else if(c==5)
              {
                  strcpy(bas,"short ");
              }
              else if(c==6)
              {
                  strcpy(bas,"byte ");
              }
              else if(c==7)
              {
                  strcpy(bas,"bool ");
              }
               strcpy(taslak,kesici);
               strcat(bas,taslak);

               kimlik_belirleme(bas);
                kesici=strtok(NULL,",");
         }
         strcpy(bas,"");

         return;

         }

      }

      else if(kpptr[0]>48 && kpptr[0]<58)
      {
          kimlik_belirleme(kesilen);
          return;
      }



     }




    kesici = strtok(kesilen,","); //virgule gore ayir

    int i=0;  //kesilen str sayisi icin
    while(kesici!=NULL)
    {
        if(i<1)
        {
            strcpy(taslak,kesici); //amacim kesicinin konumunu kaybetmemesi
            kimlik_belirleme(taslak);
           // printf("%s\n",taslak);
        }
        i++;
        if(i>1)
        {
             strcat(bas,kesici);
              kimlik_belirleme(bas);
            //  printf("%s\n",bas);
              if(c==0)
              {
                  strcpy(bas,"int ");
              }
              else if(c==1)
              {
                  strcpy(bas,"float ");
              }
              else if(c==2)
              {
                  strcpy(bas,"double ");
              }
              else if(c==3)
              {
                  strcpy(bas,"char ");
              }
              else if(c==4)
              {
                  strcpy(bas,"long ");
              }
              else if(c==5)
              {
                  strcpy(bas,"short ");
              }
              else if(c==6)
              {
                  strcpy(bas,"byte ");
              }
              else if(c==7)
              {
                  strcpy(bas,"bool ");
              }

        }

        kesici=strtok(NULL,",");
    }
       strcpy(bas,"");
       bb=0;

}

void baslik_kontrolu(char *temp)
{
    char taslak[100];

    strcpy(taslak,temp);

    bas_bosluk_kaldir(taslak);

    //donus tipi belirlenmesi
    if(taslak[0]=='v' && taslak[1]=='o')
    {
        strcpy(donus_tipi,"void");
       // printf("Void oldum\n");
    }
    else if(taslak[0]=='i' && taslak[1]=='n')
    {
        strcpy(donus_tipi,"int");
        //printf("int oldum\n");
    }
    else if(taslak[0]=='f' && taslak[1]=='l')
    {
        strcpy(donus_tipi,"float");
       // printf("float oldum\n");
    }
    else if(taslak[0]=='d' && taslak[1]=='o')
    {
        strcpy(donus_tipi,"double");
        //printf("DOUBLE OLDUM\n");
    }
    else if(taslak[0]=='c' && taslak[1]=='h')
    {
        strcpy(donus_tipi,"char");
       // printf("char oldum\n");
    }
    else if(taslak[0]=='l' && taslak[1]=='o')
    {
        strcpy(donus_tipi,"long");
    }
    else if(taslak[0]=='s' && taslak[1]=='h')
    {
        strcpy(donus_tipi,"short");
    }
    else if(taslak[0]=='b' && taslak[1]=='y')
    {
        strcpy(donus_tipi,"byte");
    }
    else if(taslak[0]=='b' && taslak[1]=='o')
    {
        strcpy(donus_tipi,"bool");
    }
    //donus tipi belirlendi

   // printf("donus_tipi=%s\n",donus_tipi);

    temp++; //amac donus tipi takılmasın...

    temp=strstr(temp,"("); //parenteze kadar gel

    temp++; //amac parentezden kurtulmak

    //simdi parametreli ayiracagiz
    char *kesici;

    char kesilen[100];

    strcpy(kesilen,temp);

    kesici = strtok(kesilen,","); //virgule gore ayir

    while(kesici!=NULL)
    {
        strcpy(taslak,kesici); //amacim kesicinin konumunu kaybetmemesi

       kimlik_belirleme(taslak);


        kesici=strtok(NULL,",");
    }


}

void yer_karmasikligi()
{
     FILE *dosyaptr=fopen("kod.txt","r");
     if(dosyaptr==NULL)
     {
         printf("Dosya acilamadi.\n");
         return;
     }


     char temp[100];
     char *parentez_kontrolu;
     char *parantez_kapat_kontrolu;


     while(!feof(dosyaptr))
     {

          fgets(temp,100,dosyaptr);
           //printf("temp = %s",temp);

          if(temp[0]=='#' || temp[0]=='\n')
          {
             // printf("xxx\n");
              continue;
          }
         // printf("Continu sorgunusu gectim\n");
          parentez_kontrolu=strstr(temp,"{");
          if(parentez_kontrolu!=NULL)
          {
              push('{');
             // printf("{ eklendi...\n");

          }

          if(bos_mu()==1)
          {
             // printf("Bosmu da miyim\n");
                  baslik_kontrolu(temp);

          }
          else
          {
              parantez_kapat_kontrolu=strstr(temp,"}");
              if(parantez_kapat_kontrolu!=NULL)
              {
                  pop();
                  //printf("} cikarildi...\n");
              }
              if(bos_mu()==1)
              {
                  //printf("Bosaldim\n");
                  donus_tipi_kontrol=0;
                  strcpy(donus_tipi,"");
              }

              govde_kontrolu(temp);

          }

     }

     fclose(dosyaptr);

}

void time_result()
{
    printf("Zaman karmasikliklari...\n");
   // printf("Fonskyin sayisi = %d\n",fonk_sayisi);
    for(int i=0; i<fonk_sayisi;i++)
    {
        printf("O(%s)\n",bigo_tutucu[i]);
    }

}

void space_result()
{
    printf("Yer Karmasikligi =  ");

    int q=0; //burda o (n) icerikce mi bakacagiz

     if(strlen(dizi_bellek_int)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_int); i++)
         {

             printf("4%c",dizi_bellek_int[i]);
             int j=i+1;
             if(dizi_bellek_int[j]=='*')
             {
                 printf("%c",dizi_bellek_int[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_float)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_float); i++)
         {
             printf("4%c",dizi_bellek_float[i]);
             int j=i+1;
             if(dizi_bellek_float[j]=='*')
             {
                 printf("%c",dizi_bellek_float[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_double)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_double); i++)
         {
             printf("8%c",dizi_bellek_double[i]);
             int j=i+1;
             if(dizi_bellek_double[j]=='*')
             {
                 printf("%c",dizi_bellek_double[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_long)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_long); i++)
         {
             printf("4%c",dizi_bellek_long[i]);
             int j=i+1;
             if(dizi_bellek_long[j]=='*')
             {
                 printf("%c",dizi_bellek_long[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_short)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_short); i++)
         {
             printf("2%c",dizi_bellek_short[i]);
             int j=i+1;
             if(dizi_bellek_short[j]=='*')
             {
                 printf("%c",dizi_bellek_short[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_byte)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_byte); i++)
         {
             printf("%c",dizi_bellek_byte[i]);
             int j=i+1;
             if(dizi_bellek_byte[j]=='*')
             {
                 printf("%c",dizi_bellek_byte[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_char)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_char); i++)
         {
             printf("%c",dizi_bellek_char[i]);
             int j=i+1;
             if(dizi_bellek_char[j]=='*')
             {
                 printf("%c",dizi_bellek_char[++j]);
                 i=j;
                 q=-1;

             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }
     if(strlen(dizi_bellek_bool)!=0)
     {
         for(int i=0; i<strlen(dizi_bellek_bool); i++)
         {
             printf("%c",dizi_bellek_bool[i]);
             int j=i+1;
             if(dizi_bellek_bool[j]=='*')
             {
                 printf("%c",dizi_bellek_bool[++j]);
                 i=j;
                 q=-1;
             }
             printf(" + ");
         }
         if(q!=-1)
         q=1;
     }

    //printf("Sayac_int=%d\n",sayac_int);
   int toplam=(sayac_char)+(sayac_double*8)+(sayac_float*4)+(sayac_int*4)+(sayac_ptr*8)+(sayac_byte)+(sayac_short*2)+(sayac_long*4)+(sayac_bool);
   printf("%d  ",toplam);

   if(q==1)
   {
       printf("  Big O cinsinden ifade edersek = O(n)\n");
   }
   else if(q==0)
   {
       printf("  Big O cinsinden ifade edersek = O(1)\n");
   }
   else if(q==-1)
   {
       printf("  Big O cinsinden ifade edersek = O(n^2)\n");
   }


}

void gecen_sure_hesabi()
{
    int parantezzz=0;
    int icerde_miyiz=0;
    int ilk_yazilicak=0;
    int son_yazilicak=0;
    FILE *dosyaptr=fopen("kod.txt","r");
    FILE *dosyaptr2=fopen("derlenecek.c","w");
    FILE *dosyaptr3=fopen("kod_kontrol.txt","w");

    char txt[100];
    char *p;
    char *pr;
   if(dosyaptr==NULL ||dosyaptr3==NULL)
   {
       printf("Dosya acilirken bir hata olustu!\n");
       return ;
   }

   //her seyden once bizim time.h kutuphanesini dahil etmemiz lazım
   fprintf(dosyaptr3,"#include <time.h>\n");
   fprintf(dosyaptr2,"#include <time.h>\n");


   while(!feof(dosyaptr))
   {
       fgets(txt,100,dosyaptr);
       if((pr=strstr(txt,"{"))!=NULL)
       {
          push('{');
        //  printf("{ parantez eklendi...\n");
       }
       if((pr=strstr(txt,"}"))!=NULL)
       {
          pop();
         // printf("} parantez cikarildi...\n");
       }
       if((p=strstr(txt,dongu_icin_baslik))!=NULL)
       {
           icerde_miyiz=1;
       }
       if((p=strstr(txt,"return"))!=NULL && son_yazilicak==0 &&icerde_miyiz==1)
       {
           fprintf(dosyaptr3,"bitir_t = clock();\n");
           fprintf(dosyaptr3,"printf(\"Calismaya baslama suresi: %%d \\n\", basla_t);\n");
           fprintf(dosyaptr3,"printf(\"Calismanin bitisi suresi: %%d \\n\", bitir_t);\n");
           fprintf(dosyaptr3,"printf(\"Kod calistiginde gecen sure (saniye): %%f \\n\", (double)(bitir_t - basla_t) / CLOCKS_PER_SEC );\n");

           fprintf(dosyaptr2,"bitir_t = clock();\n");
           fprintf(dosyaptr2,"printf(\"Calismaya baslama suresi: %%d \\n\", basla_t);\n");
           fprintf(dosyaptr2,"printf(\"Calismanin bitisi suresi: %%d \\n\", bitir_t);\n");
           fprintf(dosyaptr2,"printf(\"Kod calistiginde gecen sure (saniye): %%f \\n\", (double)(bitir_t - basla_t) / CLOCKS_PER_SEC );\n");
           son_yazilicak=1;
       }
       fprintf(dosyaptr3,"%s",txt);
       fprintf(dosyaptr2,"%s",txt);
       if(icerde_miyiz==1 && ilk_yazilicak==0 && eleman_sayisi()>0)
       {
           fprintf(dosyaptr3,"clock_t basla_t, bitir_t;\nbasla_t = clock();\n");
           fprintf(dosyaptr2,"clock_t basla_t, bitir_t;\nbasla_t = clock();\n");
           ilk_yazilicak=1;
       }
       //printf("%s",txt);
   }

   printf("\nMetin belgesinde yer alan kodun calistirildiginda gecen surenin hesaplanabilmesi icin\n");
   printf("Lutfen derlenecek c isimli dosyayi derleyiniz \n");
   printf("Bu dosyada gerekli islemler gerceklesicektir...\n");
   printf("Tesekkur ederiz...\n");
   fclose(dosyaptr3);
   fclose(dosyaptr);
   fclose(dosyaptr2);

}

int main()
{
     dosya_bos_mu();

     char kod[8000];
     oku(kod);
     printf("%s",kod);

     printf("\n-----------------------------------------------------------------\n");
     if(l==1)
     {
       printf("\nDosyadan okunan kod metni tam olarak bir C  kodudur.\n");

     }
      else if(l==0)
     {
        printf("Dosyadan okunan kod metni tam olarak bir C kodu degildir.\n");
     }


      yer_karmasikligi();
      printf("\n-----------------------------------------------------------------\n");
      space_result();
      zaman_karmasikligi();
      printf("\n-----------------------------------------------------------------\n");
     time_result();
     printf("\n-----------------------------------------------------------------\n");

    printf("*************************************************************************\n");
     gecen_sure_hesabi();
    printf("\n**************************************************************************\n");


    return 0;
}
