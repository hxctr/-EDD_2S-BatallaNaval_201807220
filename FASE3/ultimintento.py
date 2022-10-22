import tkinter as tk
from tkinter import ttk, PhotoImage
from PIL import ImageTk, Image

ID = [1,2,3,4,5, 6, 7, 8, 9]
Names = ['Tom', 'Rob', 'Tim', 'Jim', 'Kim', 'Steph', 'Davis', 'Katt']
photo = ['/home/fdd/Descargas/imgs/1.png', '/home/fdd/Descargas/imgs/2.jpeg', '/home/fdd/Descargas/imgs/3.jpeg', '/home/fdd/Descargas/imgs/4.jpeg', '/home/fdd/Descargas/imgs/5.jpeg', '/home/fdd/Descargas/imgs/6.jpeg', '/home/fdd/Descargas/imgs/7.jpeg', '/home/fdd/Descargas/imgs/8.jpeg', '/home/fdd/Descargas/imgs/9.jpeg']



root = tk.Tk()
# imgenes = PhotoImage(file="/home/fdd/Descargas/imgs/1.png")
root.geometry('700x500')
column_names = ('country_column', 'capital_city_column')

treev = ttk.Treeview(columns=column_names)

treev.heading('country_column', text='Country')
treev.heading('capital_city_column', text='Capital')

treev.column("0", width=100, anchor ='c', stretch=0) 
treev.column("1", width = 100, anchor ='c') 

listimgs = list()


S = ttk.Style(root)
S.configure('Treeview', rowheight=400)

for i in range(len(photo)):    
    
    i = i +1
print(listimgs)




for i in range(len(photo)-1):    
    # imagen2 = ImageTk.PhotoImage(Image.open(photo[i]))
    imagen2 = ImageTk.PhotoImage(Image.open(photo[i]))
    listimgs.append(imagen2)
    treev.insert(parent="",
                 index="end",
                 image=listimgs[i],
                 values=(ID[i], Names[i]))
    treev.pack(expand=True, fill=tk.BOTH)
    i = i + 1
    


root.mainloop()