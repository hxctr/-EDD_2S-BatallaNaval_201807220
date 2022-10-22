from tkinter import *
from PIL import ImageTk, Image
from tkinter import ttk

ID = [1,2,3,4,5, 6, 7, 8, 9]
Names = ['Tom', 'Rob', 'Tim', 'Jim', 'Kim', 'Steph', 'Davis', 'Katt']
photo = ['/home/fdd/Descargas/imgs/1.jpeg', '/home/fdd/Descargas/imgs/2.jpeg', '/home/fdd/Descargas/imgs/3.jpeg', '/home/fdd/Descargas/imgs/4.jpeg', '/home/fdd/Descargas/imgs/5.jpeg', '/home/fdd/Descargas/imgs/6.jpeg', '/home/fdd/Descargas/imgs/7.jpeg', '/home/fdd/Descargas/imgs/8.jpeg', '/home/fdd/Descargas/imgs/9.jpeg']



win = Tk()
win.geometry("700x500")
treev = ttk.Treeview(win, selectmode ='browse') 
treev.pack(side='left',expand=True, fill='both') 

verscrlbar = ttk.Scrollbar(win,  
                           orient ="vertical",  
                           command = treev.yview) 
  
verscrlbar.pack(side ='right', fill ='y')   
treev.configure(yscrollcommand = verscrlbar.set) 

  
treev["columns"] = ('1', '2', '3') 

treev['show'] = 'headings'
  
treev.column("1", width = 90, anchor ='c') 
treev.column("2", width = 90, anchor ='c') 
treev.column("3", width = 90, anchor ='c') 


treev.heading("1", text ="ID") 
treev.heading("2", text ="Names") 
treev.heading("3", text ="photo") 




frame = Frame(win, width=600, height=400)
frame.pack()
frame.place(anchor='center', relx=0.5, rely=0.5)

img = ImageTk.PhotoImage(Image.open('/home/fdd/Descargas/imgs/9.jpeg'))



imagen = Image.open('/home/fdd/Descargas/imgs/7.jpeg')
imagen = ImageTk.PhotoImage(imagen)


label = Label(frame, image = imagen)
label.pack()

for i in range(len(photo)-1):
    # img = Image.open(photo[i])
    # tkimage = ImageTk.PhotoImage(img)
    

    
    treev.insert("", 'end', values =(ID[i], Names[i], 'hola'), image=imagen)
    i = i + 1
win.mainloop()