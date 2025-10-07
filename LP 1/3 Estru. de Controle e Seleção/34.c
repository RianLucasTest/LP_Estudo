#include <stdio.h>
#include <stdlib.h>
//34. Um determinado material radioativo perde metade de sua massa a cada 50 segundos. Dada a
//massa inicial, em gramas, fazer um algoritmo que determine o tempo necessário para que essa
//massa se torne menor do que 0,5 grama. Escreva a massa inicial, a massa final e o tempo
//calculado em horas, minutos e segundos (hh:mm:ss).

int main() {
    float mass, m_inicial;
    int cont, temp, sec, min, hr;
    sec = min = hr = cont = 0;

    printf("Insira a massa inicial do material(em gramas):\n");
    scanf("%f", &mass);
    m_inicial = mass;

    while(mass >= 0.5){
        mass = mass / 2;
        cont++;
    }
    
    sec = cont * 50;
    temp = sec / 60;
    sec = sec % 60;
    hr = temp / 60;
    min = temp % 60;

    printf("A massa inicial era: %.2f\nA massa final e: %.2f\nO tempo para alcancar essa massa foi de: %d:%d:%d\n", m_inicial, mass, hr, min, sec);


    system("PAUSE");
    return 0;
}