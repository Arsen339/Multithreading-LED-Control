#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// блок глобальных переменных
// режим работы
int mode = 1;
// состояние светодиодов
int LED = 3;
// время задержки
int stop = 1;

int dec2bin(int num)
{
// функция для перевода десятичных чисел в двоичные
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}



void *myThreadFun(void *vargp)
// второй поток
{



    int *myid = (int *)vargp;
    
    // выбор режимов работы
    while (1 > 0){
        if (mode == 1){
    	    sleep(stop);
    	    if (LED > 15){
    	        LED = 0;
    	    }
    	    LED = LED + 1;
    	   
    	   switch(LED){
    	   // вариант вывода состояния светодиодов путем кейсов
    	   case 0:
    	   printf("0000\n");
    	   fflush(stdout);
    	   break;
    	   case 1:
    	   printf("0001\n");
    	   fflush(stdout);
    	   break;
    	   case 2:
    	   printf("0010\n");
    	   break;
    	   case 3:
    	   printf("0011\n");
    	   fflush(stdout);
    	   break;
    	   case 4:
    	   printf("0100\n");
    	   fflush(stdout);
    	   break;
    	   case 5:
    	   printf("0101\n");
    	   break;
    	   case 6:
    	   printf("0110\n");
    	   fflush(stdout);
    	   break;
    	   case 7:
    	   printf("0111\n");
    	   fflush(stdout);
    	   break;
    	   case 8:
    	   printf("1000\n");
    	   fflush(stdout);
    	   break;
    	   case 9:
    	   printf("1001\n");
    	   fflush(stdout);
    	   break;
    	   case 10:
    	   printf("1010\n");
    	   fflush(stdout);
    	   break;
    	   case 11:
    	   printf("1011\n");
    	   fflush(stdout);
    	   break;
    	   case 12:
    	   printf("1100\n");
    	   fflush(stdout);
    	   break;
    	   case 13:
    	   printf("1101\n");
    	   fflush(stdout);
    	   break;
    	   case 14:
    	   printf("1110\n");
    	   fflush(stdout);
    	   break;
    	   case 15:
    	   printf("1111\n");
    	   fflush(stdout);
    	   break;
    	   default:
    	   printf("0000\n");
    	   fflush(stdout);
    	   
    	   
    	   
    	   
    	   
    	   }
    	  
    	   
        }
        else if (mode == 0){
        // вариант вывода состояния светодиодов путем перевода в двоичную СС
    	    sleep(stop);
    	    if (LED ==0){
    	        LED = 15;
    	    }
    	    LED = LED - 1;
    	   
    	    printf("%d\n", dec2bin(LED));
    	    fflush(stdout);
    	  
    	   
        }
        
         else if (mode == 2){
    	    sleep(stop);
  	    while (1>0){
    	        printf("0000\n");
    	        sleep(stop);
    	        fflush(stdout);
    	  }
    	   
        }
        
        
        
    }


}

  

int main()

{

    int i;
    // id потока
    pthread_t tid;


    // Создадим поток:

    pthread_create(&tid, NULL, myThreadFun, (void *)&tid);

  
   while (1>0){
   fflush(stdin);
   scanf("%d", &mode);
   
   // считывание длины задержки из файла
   char *file = "file.txt";
   FILE *f = fopen(file, "r");
   fscanf(f, "%d", &stop);
   fclose(f);
    
        }

    pthread_exit(NULL);

    return 0;

}
