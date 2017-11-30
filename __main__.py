from time import sleep
from gpiozero import Button, LED

beebutton = Button(pin_no)
beeled = LED(pin_no)

lightgate = Button(pin_no)

sunbutton = Button(pin_no)
sunled = LED(pin_no)
    

def watch_bee():
    global solved_bee
    while not shutdown:
        if beebutton_pressed:
            solved_bee = True
            beeled.on()
    close thread
    
def watch_rain():
    global solved_rain, count, falling
    while not shutdown:
        while count < 5:
            if lightgate_pressed:
                count += 1
        solved_rain = True
        falling = True
        while falling:
            falling_rain business
    close thread

def watch_sun():
    global solved_sun, state
    while not shutdown:
        if sunbutton_pressed:
            state = (state+1)%2
        if state = 1:
            sunled.on()
            solved_sun = True
        if state = 0:
            sunled.off()
            solved_sun = False
    close thread

def reset():
    global solved_bee, solved_rain, solved_sun, count, state, falling
    solved_bee = False
    solved_rain = False
    solved_sun = False
    count = 0
    state = 0
    beeled.off()
    falling = False


reset()
thread 1 = thread(watch_bee)
thread 2 = thread(watch_rain)
thread 3 = thread(watch_sun)

while True:
    if solved_bee and solved_rain and solved_sun:
        flower()
        sleep(15)
        reset()
