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
state = 0
falling = False


def watch_bee():
    global shutdown, solved_bee
    while not shutdown:
        if beebutton.is_pressed:
            solved_bee = True
            print('bee is solved')
            ser.write('1')
    
def watch_rain():
    global shutdown, solved_rain, count, falling
    while not shutdown:
        while count < 5:
            if GPIO.input(17) == 1:
                print('pressing it boys')
                count += 1
        solved_rain = True
        print('rain is solved')
        falling = True
        ser.write('2') #turns the rain and clouds on
        print('falling rain business') #Tom edit

def watch_sun():
    global shutdown, solved_sun, state
    while not shutdown:
        if sunbutton.is_pressed:
            state = (state+1)%2
            ser.write('3')
        if state == 1:
            solved_sun = True
            print('sun is solved') # tom edit
        if state == 0:
            solved_sun = False
    
def flower():
    print('flowers blossom')
    servo.min()
    GPIO.output(24,GPIO.LOW)
    sleep(5)
    servo.max()
    GPIO.output(24,GPIO.HIGH)
    sleep(15)
    GPIO.output(24,GPIO.LOW)
    servo.min()
    #want it to reset to min always

def reset():
    global solved_bee, solved_rain, solved_sun, count, state, falling
    solved_bee = False
    solved_rain = False
    solved_sun = False
    count = 0
    state = 0
    falling = False
    ser.write('0')

    
thread1 = Thread(target = watch_bee, args = ())
thread2 = Thread(target = watch_rain, args = ())
thread3 = Thread(target = watch_sun, args = ())
thread1.start()
thread2.start()
thread3.start()

reset()    
while True:
    if solved_bee and solved_rain and solved_sun:
        flower()
        reset()
