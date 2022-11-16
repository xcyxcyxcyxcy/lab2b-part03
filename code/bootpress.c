#include "pico/stdlib.h"
#include <stdio.h>
#include "stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pio.h"
#include <math.h>
#include "neopixel.h"  


#define QTPY_BOOT_PIN 21
void record(bool arr[],int seconds)
{
    stdio_init_all();                                           //Initialization functions
    int cnt=0;
    neopixel_set_rgb(0x00ff00ff);
    while(true)
    {   
        if(!(gpio_get(QTPY_BOOT_PIN))){
            arr[cnt]=true;
            
            sleep_ms(5);
        }
        else{                                                   // If BOOT button is not pressed
        arr[cnt]=false;
        sleep_ms(5);
        }
        cnt=cnt+1;
        if(cnt>=((seconds*1000)-2))
        {
            cnt=0;
            neopixel_set_rgb(0x00000000);
            break;
        }
    }
}


void play(bool arr[], int seconds, char color)
{
  stdio_init_all();                                            
    uint32_t light_color;

    switch(color){
            case 'r':
                light_color = 0x00ff0000;
                break;
            case 'g':
                light_color = 0x0000ff00;
                break;
            case 'b':
                light_color = 0x000000ff;
                break;
                default : 
                light_color = 0x000000ff;
    
    }

    for(int j=0;j<=seconds*1000;j=j+1)                             
            {
                if(arr[j]==true)
                {
                     neopixel_set_rgb(light_color);
                    sleep_ms(5);
                }

                else
                {
                    neopixel_set_rgb(0x00000000);
                    sleep_ms(5);
                }
            }

neopixel_set_rgb(0x00000000);
}


void loopplay(bool arr[], int seconds, char color)
{
  stdio_init_all();                                            
    uint32_t light_color;
    char c = 0;
    switch(color){
            case 'r':
                light_color = 0x00ff0000;
                break;
            case 'g':
                light_color = 0x0000ff00;
                break;
            case 'b':
                light_color = 0x000000ff;
                break;
                default : 
                light_color = 0x000000ff;
    
    }
    int x = 0;

    for(int x=0;x<2;x=x+1)     
    { 
    for(int j=0;j<=seconds*1000;j=j+1)                             
            {
            
                if(arr[j]==true)
                {
                     neopixel_set_rgb(light_color);
                    sleep_ms(5);
                }

                else
                {
                    neopixel_set_rgb(0x00000000);
                    sleep_ms(5);
                }
            }
        
    }

neopixel_set_rgb(0x00000000);
}