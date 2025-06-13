import tkinter 
#from tkinter import tkinter.simpledialog

root = tkinter.Tk()

root.title("Miku WiFi and Bluetooth Controller")
root.configure(background=None)

#label 1
tkinter.Label(root, text="Hastune Miku is here to help you configure your WiFi and Bluetooth more easely !").pack()
tkinter.Label(root, text="Make sense since she litteraly lives here").pack()

#Main Miku image
image = tkinter.PhotoImage(file="MIKU.png")
tkinter.Label(root, image=image).pack()

#Text 
#tkinter.simpledialog.askstring(root, prompt="prompt")

root.mainloop()


