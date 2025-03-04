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
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

  xTaskCreate(vTask1,"TASK1",configMINIMAL_STACK_SIZE,NULL,1,&task1Handle);
  xTaskCreate(vTask2,"TASK2",configMINIMAL_STACK_SIZE+1024,NULL,2,&task2Handle);
}

void loop() {
  vTaskDelay(1000);
}

void vTask1(void *pvParameters)
{
  pinMode(LED,OUTPUT);
  while (1)
  {
    digitalWrite(LED,!digitalRead(LED));
    vTaskDelay(pdMS_TO_TICKS(200));
  }
  
}
void vTask2(void *pvParameters)
{
  int cont = 0;
  while (1)
  {
    Serial.println("Task 2:" + String(cont++));
    vTaskDelay(1000);
  }
  
}