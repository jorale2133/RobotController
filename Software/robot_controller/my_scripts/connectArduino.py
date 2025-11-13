import serial
import time
import os

esp32 = serial.Serial('COM3', 115200, timeout=1)
time.sleep(2)

def init():
    print('Intructions:')
    print('(1) Manual')
    print('(2) Automatic')
    print("Enter option")

    try:
        mode = int(input('Input: '))
    except ValueError:
        print("Not a number")

    if(mode==1):
        print("Manual...")
        send_number(mode)
    if(mode==2):
        print("Automatic...")
        send_number(mode)

def send_number(num):
    data = str(num).encode('utf-8')
    esp32.write(data + b'\n')
    print(f"Sent to arduino: {num}")


##def read_position():
##    motorBase = int(input('Posición MotorBase: '))
##    motorLeft = int(input('Posición MotorLeft: '))
##    motorRight = int(input('Posición MotorRight: '))
##    motorGrip = int(input('Posición MotorGrip: '))

##    return [motorBase, motorLeft, motorRight, motorGrip]
    

while(True):
    init()
    os.system('cls')
