import serial
import tkinter as tk
from time import sleep

ser = serial.Serial('/dev/tty.usbmodem141301', 9600)


root = tk.Tk()

root.geometry("180x180")
root.resizable(0, 0)

def motion(event):
    x, y = event.x, event.y
    pos = 'X{}Y{}'.format(x, y)
    print(pos)
    ser.write(pos.encode())
    sleep(0.01)

root.bind('<Motion>', motion)
root.mainloop()