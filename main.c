#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "prints.h"

bool bissexto(int ano){
    if(ano % 400 == 0){
        return true;
    }else{
        if(ano % 4 == 0 && ano % 100 != 0)
            return true;
        else
            return false;
    }
}

int main(){
    srand(time(0));
    time_t curr_time;
    struct tm *times_legais;

    time(&curr_time);
    times_legais = localtime(&curr_time);

    int ano_atual = times_legais->tm_year + 1900;
    int mes_atual = times_legais->tm_mon + 1;
    int dia = times_legais->tm_mday;
    int idade_Tin = mes_atual - 11 < 0 ? (ano_atual - 2019) - 1 : (ano_atual - 2019);
    idade_Tin = mes_atual == 0 && dia == 0 ? idade_Tin + 1 : idade_Tin;

    if(mes_atual == 11 && dia == 27){
        text();
        cake(rand() % 3);
        num(idade_Tin);
    }else{
        int mes_falta = 11 - mes_atual;
        int dia_falta = 27 - dia;

        if(mes_falta == 0 && dia_falta < 0){
            mes_falta += 11;
        }
        if(mes_falta < 0){
            mes_falta += 12;
        }

        if(dia_falta < 0){
            if(mes_atual == 1 || mes_atual == 3 || mes_atual == 5 || mes_atual == 7 || mes_atual == 8 || mes_atual == 10 || mes_atual == 12){
                dia_falta += 31;
            }else if (mes_atual == 4 || mes_atual == 6 || mes_atual == 9 || mes_atual == 11){
                dia_falta += 30;
            }else{
                if(bissexto(ano_atual))
                    dia_falta += 29;
                else
                    dia_falta += 28;
            }
        }

        printf("Ainda não!\n");
        cat(rand() % 5);
        if(mes_falta == 0)
            printf("Volte daqui a %d dia(s).\n", dia_falta);
        else
            printf("Volte daqui a %d mes(es) e %d dia(s).\n", mes_falta, dia_falta);
        printf("Não se esqueça do bolo e dos presentes. Não deixe o Tin de patas vazias!\n");
    }
    return 0;
}
