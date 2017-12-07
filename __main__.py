from time import sleep
from gpiozero import Button, LED, Servo #check
import RPi.GPIO as GPIO #TW EDIT
GPIO.setmode(GPIO.BCM) #TW EDIT
from threading import Thread
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

beebutton = Button(26)

GPIO.setup(17,GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

sunbutton = Button(21)

servo = Servo(18)
GPIO.setup(24,GPIO.OUT)

shutdown = False
solved_bee = False
solved_rain = False
solved_sun = False
count = 0


def watch_bee():
    global shutdown, solved_bee
    bb_on = False
    while not shutdown:
        if beebutton.is_pressed and bb_on == False:
            solved_bee = (solved_bee+1)%2
            ser.write('1')
            bb_on == True
        if not beebutton.is_pressed and bb_on == True:
            bb_on == False
    
def watch_rain():
    global shutdown, solved_rain, count, falling
    lg_on = False
    while not shutdown:
        while count < 5 and not shutdown:
            if GPIO.input(17) == 1 and lg_on == False:
                lg_on = True
                count += 1
            if GPIO.input(17) == 1 and lg_on == True:
                lg_on = False
        solved_rain = (solved_rain+1)%2
        ser.write('2') #turns the rain and clouds on
        count = 0

def watch_sun():
    global shutdown, solved_sun
    sb_on == False
    while not shutdown:
        if sunbutton.is_pressed and sb_on == False:
            sb_on = True
            solved_sun = (solved_sun+1)%2
            ser.write('3')
        if not sunbutton.is_pressed and sb_on == True:
            sb = False
            
    
def flower():
    servo.min()
    GPIO.output(24,GPIO.HIGH)

def reset():
    global solved_bee, solved_rain, solved_sun, count
    solved_bee = False
    solved_rain = False
    solved_sun = False
    count = 0
    ser.write('0')
    servo.max()
    GPIO.output(24,GPIO.LOW)

    
thread1 = Thread(target = watch_bee, args = ())
thread2 = Thread(target = watch_rain, args = ())
thread3 = Thread(target = watch_sun, args = ())
thread1.start()
thread2.start()
thread3.start()

reset()    
try:
    while True:
        if solved_bee and solved_rain and solved_sun:
            flower()
            sleep(15)
            reset()
except KeyboardInterrupt:
    shutdown = True
    reset()
    GPIO.cleanup()
