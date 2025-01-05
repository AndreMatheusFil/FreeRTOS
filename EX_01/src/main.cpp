/******************************************************************
Exemplo para criação de tasks
Esse exemplo é como criar tarefas no FreeRTOS

******************************************************************/

#include <Arduino.h>
/* Biblioteca FreeRTOS */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED 2

/* Variaveis para o handle das tasks */
TaskHandle_t task1Handle = NULL;
TaskHandle_t task2Handle = NULL;

/* Prótotipos das tasks */


// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}