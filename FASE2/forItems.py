from tkinter import PhotoImage, font, ttk 
import tkinter as tk 
from PIL import Image, ImageTk

ID = [1,2,3,4,5, 6, 7, 8, 9]
Names = ['Tom', 'Rob', 'Tim', 'Jim', 'Kim', 'Steph', 'Davis', 'Katt']
photo = ['/home/fdd/Descargas/imgs/1.jpeg', '/home/fdd/Descargas/imgs/2.jpeg', '/home/fdd/Descargas/imgs/3.jpeg', '/home/fdd/Descargas/imgs/4.jpeg', '/home/fdd/Descargas/imgs/5.jpeg', '/home/fdd/Descargas/imgs/6.jpeg', '/home/fdd/Descargas/imgs/7.jpeg', '/home/fdd/Descargas/imgs/8.jpeg', '/home/fdd/Descargas/imgs/9.jpeg']
  
window = tk.Tk() 

treev = ttk.Treeview(window, selectmode ='browse') 
treev.pack(side='left',expand=True, fill='both') 
  

verscrlbar = ttk.Scrollbar(window,  
                           orient ="vertical",  
                           command = treev.yview) 
  
verscrlbar.pack(side ='right', fill ='y')   
treev.configure(yscrollcommand = verscrlbar.set) 

S = ttk.Style(window)
S.configure('Treeview', rowheight=200)
treev["columns"] = ('1', '2', '3') 

treev['show'] = 'headings'
  
treev.column("1", minwidth=100, anchor ='c', stretch=0) 
treev.column("2", width = 90, anchor ='c') 
treev.column("3", width = 90, anchor ='c') 




treev.heading("1", text ="ID") 
treev.heading("2", text ="Names") 
treev.heading("3", text ="photo") 

# v = PhotoImage(file='/home/fdd/Descargas/imgs/1.png')
for i in range(len(photo)-1):
    # img = Image.open(photo[i])
    # tkimage = ImageTk.PhotoImage(img)
    

    
    treev.insert("", 'end', values =(ID[i], Names[i], 'hola'))
    i = i + 1
  
# for x, y, z in zip(ID, Names, photo):
#     img = Image.open(z)
#     tkimage = ImageTk.PhotoImage(img)

#     treev.insert("", 'end', values =(x, y, tk.Label(window, image=tkimage)))

window.mainloop()