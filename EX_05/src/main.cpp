/******************************************************************
Exemplo para tasks em núcleos diferentes
Esse exemplo é como fazer tarefas em núcleos diferentes no FreeRTOS

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
  
  xTaskCreatePinnedToCore(vTask1,"TASK1",configMINIMAL_STACK_SIZE,(void*)LED,1,&task1Handle,APP_CPU_NUM);
  xTaskCreatePinnedToCore(vTask2,"TASK2",configMINIMAL_STACK_SIZE+1024,NULL,2,&task2Handle,PRO_CPU_NUM);
}

void loop() {
  vTaskDelay(1000);
}

void vTask1(void *pvParameters)
{
  int pin = (int)pvParameters;
  pinMode(pin,OUTPUT);
  while (1)
  {
    digitalWrite(pin,!digitalRead(pin));
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