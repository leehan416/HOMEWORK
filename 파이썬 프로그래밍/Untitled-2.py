from tkinter import *

root = Tk()


def onClick(event):
    text = inputTextField.get()
    t = ''
    b = False
    for i in text:
        if i.isalpha():
            t += i

    for i in range(len(t)):
        if t[i]  != t[len(t) - (i + 1)]:
            b = True

    if b:
        outLabel.config(text = "False")
    else :
        outLabel.config (text = "True")


root.title("title")

root.geometry("200x200")

root.resizable(False, False)

textLabel = Label(text = "asdf")

inputTextField = Entry(root)





button = Button(None, text= "tsdf")
outLabel = Label(text = "asdfasdf")
textLabel.pack()

button.bind('<Button-1>', onClick)


inputTextField.pack()
button.pack()
outLabel.pack()

root.mainloop()
