#include "hardware/pio.h"                                                               //Standard RP2040 library
#include "pico/stdlib.h"                                                                //Standard C library
#include <stdio.h>                                                                      //Standard C library
#include "stdlib.h"                                                                     //Standard C library
#include "hardware/gpio.h"                                                              //Standard RP2040 library
#include "hardware/structs/sio.h"                                                       //Standard RP2040 library
#include "bootpress.h"                                                             
#include "data_transfer.h"   
#include "neopixel.h"    

                                                  

#define QTPY_BOOT_PIN 21

typedef          uint32_t   VALUE;
typedef volatile uint32_t* ADDRESS;


VALUE register_read(ADDRESS  address) {
    return *address;                                    //Reading and returing the register value
}
void register_write(ADDRESS address, VALUE value) {
    *address = value;                                   //Writing value to register
}


int main(){
 
    stdio_init_all();     
    gpio_init(21);
    gpio_set_dir(21, GPIO_IN);
    neopixel_init();                                                              //Standard Library Initialization
    char operation;                                                                     //REPL operatoin Variable Declaration
    char color;                                                                         //Neopixel Color Variable Declaration
    bool recording[5001] ={0};                                                          //5sec recording of BOOT button storage Variable Declaration
    while (!stdio_usb_connected()) {
      printf(".");
      sleep_ms(500);
    }
    while(true){
        printf("\nPlease select operation mode");                                                            
        sleep_ms(10);
        scanf(" %c",&operation);                                                        //Reading Character from Terminal, to perform the particular Action
        switch(operation){                                                              //Switch Case for execution of requested operation
            case 'r':                                                                  //Record or Acquire Mode Case
                sleep_ms(10);
                printf("Recording in Progress\n");
                record(recording,3);                                                   //Calling Record Function, you can trace this to button_capture.c
                printf("\nRecord Ended\n");
                break;
            case 'p':                                                                  //Play Mode Case
                printf("Replay mode\n");
                sleep_ms(10);
                printf(" Which Color do you want:\n");
                scanf(" %c",&color);                                                 
                printf("Replay in Progress:\n");
                play(recording,3,color);                               
                printf("Replay Ended:\n");
                break;
            case 's':                                                                  //Save Mode Case
                printf("Save Changes\n");
                sleep_ms(10);
                encode(recording);                                                     
                sleep_ms(20);
                printf("Recording Saved\n");
                break;
            case 'l':
                printf("loop recording\n");
                sleep_ms(10);
                printf(" Which Color do you want:\n");
                scanf(" %c",&color);                                                 
                printf("loop in Progress:\n");
                loopplay(recording,3,color);                               
                printf("Replay Ended:\n");
                break;
            case 'u':                                                                  
                printf("Upload Mode Entered\n");
                char upload[1000];
                sleep_ms(10);
                printf("Upload Mode Entered, Paste the Recording\n");
                scanf(" %s",&upload);                                                  //Taking Input of the recording
                printf("%s",upload);
                decode(recording,upload);                                             
                printf("Upload Mode Entered, Recording Uploaded\n");
                break;
            case 'i':
                printf("\nplease type in yourself\n");
                char sequenceString[1000];
	             while (!stdio_usb_connected()){
		             sleep_ms(10);
	                }
	                scanf("%s", &sequenceString);
                    printf("%s",sequenceString);
                    for(int i=0; i<200; i++){
		        sleep_ms(10);
		        if(sequenceString[i] == '1'){
			    neopixel_set_rgb(0x00FF00FF);
    
			    sleep_ms(100);
		        } else{
			        neopixel_set_rgb(0x00000000);
			
			    sleep_ms(100);
			        }
		        }
	        neopixel_set_rgb(0x00FF00FF);
	        sleep_ms(10);

                    break;
            default:
                printf("Invalid Commmand\n");
        

        }
        sleep_ms(10);

    }
    return 0;
}