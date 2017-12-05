from time import sleep
from gpiozero import Button, LED, Servo #check
import RPi.GPIO as GPIO #TW EDIT
GPIO.setmode(GPIO.BCM) #TW EDIT
from threading import Thread
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

beebutton = Button(26)
#beeled = LED(19)

#lightgate = Button(17)
lightgate = GPIO.setup(17,GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

sunbutton = Button(21)
#sunled = LED(20)

servo = Servo(18)

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
            ser.write('1') #turns the bee on
    
def watch_rain():
    global shutdown, solved_rain, count, falling
    while not shutdown:
        while count < 5:
            if lightgate.is_pressed:
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
            #print('sun is unsolved') #tom edit
    
def flower():
    while True:
        servo.min()
        sleep(1)
        servo.max()
        #want it to reset to min always
    print('flowers blossom')
    

def reset():
    global solved_bee, solved_rain, solved_sun, count, state, falling
    solved_bee = False
    solved_rain = False
    solved_sun = False
    count = 0
    state = 0
    #beeled.off()
    falling = False
    ser.write('1')
    ser.write('2')
    ser.write('3')

    
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
        sleep(15)
        reset()
