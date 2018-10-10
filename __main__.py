## Python code for Raspberry Pi. Threads used to keep track of multiple 'puzzles'. ##
## Only once all 'puzzles' are completed, the user makes the flower blossom. ##

from time import sleep
from gpiozero import Button, LED, Servo
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
from threading import Thread
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

beebutton = Button(26)

GPIO.setup(17,GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

sunbutton = Button(21)

servo = Servo(18)
GPIO.setup(24,GPIO.OUT)

shutdown = False #a variable to keep the treads running
solved_bee = False #a variable to keep track if the bee puzzle has been solved
solved_rain = False #a variable to keep track if the rain puzzle has been solved
solved_sun = False #a variable to keep track if the sun puzzle has been solved
count = 0 #to keep count of how many times the handle has been turned


def watch_bee():
    global shutdown, solved_bee #allows the global variables to be carried in and changed from within the function
    bb_on = False #starts the bounce handling
    while not shutdown:
        if beebutton.is_pressed and bb_on == False: #if button is pressed and hasn't been pressed before ('bb_on' variable = false)
            solved_bee = (solved_bee+1)%2
            ser.write('1')
            bb_on == True #button has been pressed so setting the 'bb_on' variable to true
        if not beebutton.is_pressed and bb_on == True: #if the button is not pressed and it's been pressed before ('bb_on' = true)
            bb_on == False #button has not been pressed so setting the 'bb_on' variable to false
    
def watch_rain():
    global shutdown, solved_rain, count, falling
    lg_on = False #same bounce handling as above
    while not shutdown:
        while count < 5 and not shutdown:
            if GPIO.input(17) == 1 and lg_on == False:
                lg_on = True
                count += 1
            if GPIO.input(17) == 0 and lg_on == True:
                lg_on = False
        solved_rain = (solved_rain+1)%2
        ser.write('2')
        count = 0

def watch_sun():
    global shutdown, solved_sun
    sb_on = False #same bounce handling as above
    while not shutdown:
        if sunbutton.is_pressed and sb_on == False:
            sb_on = True
            solved_sun = (solved_sun+1)%2
            ser.write('3')
        if not sunbutton.is_pressed and sb_on == True:
            sb = False
            
    
def flower(): #this is the function that makes the flower blossom
    servo.min() #flower opens
    GPIO.output(24,GPIO.HIGH) #LEDs on
    sleep(15) #pause for 15 seconds
    servo.max() #flower closes
    GPIO.output(24,GPIO.HIGH) #LEDs off

def reset(): #this is the function that resets all parts to 'off' state
    global solved_bee, solved_rain, solved_sun, count
    solved_bee = False
    solved_rain = False
    solved_sun = False
    count = 0
    ser.write('0') #sends a '0' to the arduino to turn off the LEDs
    servo.max()
    GPIO.output(24,GPIO.LOW)

    
thread1 = Thread(target = watch_bee, args = ())
thread2 = Thread(target = watch_rain, args = ())
thread3 = Thread(target = watch_sun, args = ())
thread1.start()
thread2.start()
thread3.start()

reset()    
try: #this interrupts the loop if Ctrl ^C is pressed in the Raspberry Pi terminal
    while True:
        if solved_bee and solved_rain and solved_sun:
            flower()
            sleep(5)
            reset()
except KeyboardInterrupt:
    shutdown = True
    thread1.join()
    thread2.join()
    thread3.join()
    reset()
