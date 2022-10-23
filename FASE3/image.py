from tkinter import PhotoImage
import tkinter as tk
from PIL import Image, ImageTk

root = tk.Tk()
root.title("My window")
root.geometry('500x400')

frame = tk.Frame(root)
frame.pack(fill='both', expand=1)

def insertImage():
    btree_img = ImageTk.PhotoImage(Image.open('pic.jpeg'))
    lbl_btree_img = tk.Label(frame, image=btree_img)
    lbl_btree_img.btree_img = btree_img
    lbl_btree_img.place(x=20, y=20)

# btree_img = ImageTk.PhotoImage(Image.open('pic.jpeg'))
# lbl_btree_img = tk.Label(frame, image=btree_img)
# lbl_btree_img.pack()
insertImage()

root.mainloop()