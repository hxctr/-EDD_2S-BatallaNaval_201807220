from ast import If

from json import load
from tkinter import Label, PhotoImage, ttk, simpledialog
import tkinter as tk
import tkinter.font as tkFont
from unicodedata import category
from PIL import Image, ImageTk
import os
import json

import btree
import Users
import items
import ALVTree

btree_object = btree.ArbolB()
users_object = Users.UsersList()
list_items = Users.ItemsList()
items_object = items.ListaArticulos()






def loadUsers():
    list_items.insertInfo(15)
    list_items.insertInfo(40)
    list_items.insertInfo(30)
    
    
    path_file = simpledialog.askstring("Ingrese la ruta del archivo .json: ", 'Ingrese la ruta', parent=root)
    
    if path_file is not None:
        print('la ruta es: ', path_file)
        op_file = open(path_file)
        data = json.load(op_file)

        for usuario in data ['usuarios']:
            users_object.insert(usuario['id'], usuario['nick'], usuario['password'], usuario['monedas'], usuario['edad'], list_items)
        
        for item in data['articulos']:
            items_object.insert(item['id'], item['categoria'], item['nombre'], item['precio'], item['src'])
        
        
        op_file.close()
    else:
        print('Ruta equivocada')
    
    
    
# loadUsers()
    
def login():
    
    entryUser = ety_user_login.get()
    entryPass = ety_pass_login.get()
    
    user_state = users_object.logUser(entryUser, entryPass)
    
    if user_state == 1:
        print('Admin user')
        change_to_admin()
    elif user_state == 2:
        print('Normal user')
        change_to_user()
    else:
        print('not found')
    print(entryUser, entryPass)

def getInUserTab():
    # change_to_store()
    
    for widget in user_frame.winfo_children():
        widget.destroy()
    
    lbl_heading_user = tk.Label(
    user_frame, text='Bienvenido '+ety_user_login.get(), font=font_large)
    lbl_heading_user.pack(pady=20)
    
    show_store = tk.Button(
    user_frame, font=font_small, text='Ir a la tienda', command= change_to_store)
    show_store.pack(pady=80)


def buy_item(entry_item, aver):
    
    btn_alv = tk.Button()
    btn_alv = tk.Button(tienda_frame)
    btn_alv["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_alv["font"] = ft
    btn_alv["fg"] = "#ffffff"
    btn_alv["justify"] = "center"
    btn_alv["text"] = "Mostrar arbol avl"
    btn_alv["relief"] = "raised"
    btn_alv.pack(pady=20)
    btn_alv["command"] = generate_img()
    
    avr = list()
    avr = aver
    avr.append(entry_item)
    # print(avr)
    #Here, I will insert into avl
    #ety_user_login.get()
    
    avr = list(map(int, avr))
    print(avr)
    alv_object = ALVTree.AVLTree()
    
    
    for i in range(len(avr)):
        print(i)
        info_object = ALVTree.Info(avr[i])
        alv_object.addToTree(info_object)
    alv_object.graphTree()        
    
    
    

def generate_img():
    pass

def mostrarTienda(articulos):
    
    aver = list()
    aver = articulos
    
    for widget in tienda_frame.winfo_children():
        widget.destroy()
    
    ety_name_item = tk . Entry(tienda_frame)
    ety_name_item["borderwidth"] = "1px"
    ft = tkFont.Font(family='Times', size=18)
    ety_name_item["font"] = ft
    ety_name_item["fg"] = "#000000"
    ety_name_item["justify"] = "center"
    ety_name_item.pack(padx=40)

    btn_buy_item = tk.Button()
    btn_buy_item = tk.Button(tienda_frame)
    btn_buy_item["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_buy_item["font"] = ft
    btn_buy_item["fg"] = "#ffffff"
    btn_buy_item["justify"] = "center"
    btn_buy_item["text"] = "Comprar articulo"
    btn_buy_item["relief"] = "raised"
    btn_buy_item.pack(pady=20)
    entry_item = ety_name_item.get()
    btn_buy_item["command"] = lambda: buy_item(ety_name_item.get(), aver)

    btn_rt_asc_frame = tk.Button()
    btn_rt_asc_frame = tk.Button(tienda_frame)
    btn_rt_asc_frame["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_rt_asc_frame["font"] = ft
    btn_rt_asc_frame["fg"] = "#ffffff"
    btn_rt_asc_frame["justify"] = "center"
    btn_rt_asc_frame["text"] = "Regresar desde tienda"
    btn_rt_asc_frame["relief"] = "raised"
    btn_rt_asc_frame.pack(pady=20)
    btn_rt_asc_frame["command"] = change_to_user
    
    
    
    
    #nuevo intento
    
    ids = items_object.sendIdsToPY()
    categoria = items_object.sendCategoriaToPY()
    precio = items_object.sendPrecioToPY()
    nombre = items_object.sendNombreToPY()
    #muestro tiendda
    treev = ttk.Treeview(tienda_frame, selectmode ='browse') 
    treev.pack(side='left',expand=True, fill='both') 

    verscrlbar = ttk.Scrollbar(tienda_frame,  
                           orient ="vertical",  
                           command = treev.yview) 
  
    verscrlbar.pack(side ='right', fill ='y')   
    treev.configure(yscrollcommand = verscrlbar.set) 
    # #///
    # horscrlbar = ttk.Scrollbar(treev,  
    #                        orient ="horizontal",  
    #                        command = treev.xview) 
  
    # horscrlbar.pack(side ='bottom', fill ='x')   
    # treev.configure(xscrollcommand = horscrlbar.set) 

  
    treev["columns"] = ('1', '2', '3', '4') 

    treev['show'] = 'headings'
  
    treev.column("1", width = 90, anchor ='c') 
    treev.column("2", width = 90, anchor ='c') 
    treev.column("3", width = 90, anchor ='c') 


    treev.heading("1", text ="ID") 
    treev.heading("2", text ="Categoria") 
    treev.heading("3", text ="Precio") 
    treev.heading("4", text ="Nombre") 

    

    for w, x, y, z in zip(ids, categoria, precio, nombre):    
        treev.insert("", 'end', values =(w, x, y, z))

    #finalizo tienda
    
    # login_frame.forget()
    # admin_frame.forget()
    # asc_frame.pack(fill='both', expand=1)
    
    # treev = ttk.Treeview(tienda_frame, selectmode ='browse') 
    # treev.pack(side='left',expand=True, fill='both') 

    # verscrlbar = ttk.Scrollbar(tienda_frame,  
    #                        orient ="vertical",  
    #                        command = treev.yview) 
  
    # verscrlbar.pack(side ='right', fill ='y')   
    # treev.configure(yscrollcommand = verscrlbar.set) 
  
    # treev["columns"] = ('1', '2') 

    # treev['show'] = 'headings'
  
    # treev.column("1", width = 90, anchor ='c') 
    # treev.column("2", width = 90, anchor ='c') 



    # treev.heading("1", text ="ID") 
    # treev.heading("2", text ="Nick") 
    
    # ID = [1,2,3,4,5, 6, 7, 8, 9]
    # Names = ['Tom', 'Rob', 'Tim', 'Jim', 'Kim', 'Steph', 'Davis', 'Katt']
    # photo = ['/home/fdd/Descargas/imgs/1.png', '/home/fdd/Descargas/imgs/2.jpeg', '/home/fdd/Descargas/imgs/3.jpeg', '/home/fdd/Descargas/imgs/4.jpeg', '/home/fdd/Descargas/imgs/5.jpeg', '/home/fdd/Descargas/imgs/6.jpeg', '/home/fdd/Descargas/imgs/7.jpeg', '/home/fdd/Descargas/imgs/8.jpeg', '/home/fdd/Descargas/imgs/9.jpeg']

    # listimgs = list()
    
    # for i in range(len(Names)):    
       
    #     btree_img = ImageTk.PhotoImage(Image.open(photo[i]))
    #     lbl_btree_img = tk.Label(tienda_frame, image=btree_img)
    #     lbl_btree_img.btree_img = btree_img
    #     lbl_btree_img.pack()
        
    #     listimgs.append(btree_img)
    #     treev.insert(parent='',index="end", image=listimgs[i], values=(ID[i], Names[i]) )
        
    #     treev.pack(expand=True, fill=tk.BOTH)
        # treev.insert(parent="",
        #             index="end",
        #             image=listimgs[i],
        #             values=(ID[i], Names[i]))
        # treev.pack(expand=True, fill=tk.BOTH)
    
    
    

    # for w, x in zip(ids, nicks):    
    #     treev.insert("", 'end', values =(w, x))

    #acaba nuevo intento

    # #aqui debe ir el treeview
    # ID = [1,2,3,4,5, 6, 7, 8, 9]
    # Names = ['Tom', 'Rob', 'Tim', 'Jim', 'Kim', 'Steph', 'Davis', 'Katt']
    # photo = ['/home/fdd/Descargas/imgs/1.png', '/home/fdd/Descargas/imgs/2.jpeg', '/home/fdd/Descargas/imgs/3.jpeg', '/home/fdd/Descargas/imgs/4.jpeg', '/home/fdd/Descargas/imgs/5.jpeg', '/home/fdd/Descargas/imgs/6.jpeg', '/home/fdd/Descargas/imgs/7.jpeg', '/home/fdd/Descargas/imgs/8.jpeg', '/home/fdd/Descargas/imgs/9.jpeg']
    # column_names = ('country_column', 'capital_city_column')
    
    # treev = ttk.Treeview(columns=column_names)

    # treev.heading('country_column', text='Id')
    # treev.heading('capital_city_column', text='Nick')

    # treev.column("0", width=100, anchor ='c', stretch=0) 
    # treev.column("1", width = 100, anchor ='c') 
    
    # listimgs = list()


    # S = ttk.Style(tienda_frame)
    # S.configure('Treeview', rowheight=400)    
    
    # for i in range(len(photo)-1):    
       
        
    #     btree_img = ImageTk.PhotoImage(Image.open(photo[i]))
    #     lbl_btree_img = tk.Label(tienda_frame)
    #     lbl_btree_img.btree_img = btree_img
    #     lbl_btree_img.pack()
        
    #     listimgs.append(btree_img)
        
    #     treev.insert(parent="",
    #                 index="end",
    #                 image=listimgs[i],
    #                 values=(ID[i], Names[i]))
    #     treev.pack(expand=True, fill=tk.BOTH)

def displayStore():
    # change_to_store()
    #Adding treeview
    for widget in store_frame.winfo_children():
        widget.destroy()
    
    
    
    btn_rt_asc_frame = tk.Button()
    btn_rt_asc_frame = tk.Button(store_frame)
    btn_rt_asc_frame["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_rt_asc_frame["font"] = ft
    btn_rt_asc_frame["fg"] = "#ffffff"
    btn_rt_asc_frame["justify"] = "center"
    btn_rt_asc_frame["text"] = "Regresar"
    btn_rt_asc_frame["relief"] = "raised"
    btn_rt_asc_frame.pack(pady=20)
    btn_rt_asc_frame["command"] = change_to_user
    
    
    
    ID = [1,2,3,4,5, 6, 7, 8, 9]
    Names = ['Tom', 'Rob', 'Tim', 'Jim', 'Kim', 'Steph', 'Davis', 'Katt']
    photo = ['/home/fdd/Descargas/imgs/1.png', '/home/fdd/Descargas/imgs/2.jpeg', '/home/fdd/Descargas/imgs/3.jpeg', '/home/fdd/Descargas/imgs/4.jpeg', '/home/fdd/Descargas/imgs/5.jpeg', '/home/fdd/Descargas/imgs/6.jpeg', '/home/fdd/Descargas/imgs/7.jpeg', '/home/fdd/Descargas/imgs/8.jpeg', '/home/fdd/Descargas/imgs/9.jpeg']
    column_names = ('country_column', 'capital_city_column')
    
    treev = ttk.Treeview(columns=column_names)

    treev.heading('country_column', text='Country')
    treev.heading('capital_city_column', text='Capital')

    treev.column("0", width=100, anchor ='c', stretch=0) 
    treev.column("1", width = 100, anchor ='c') 
    
    listimgs = list()


    S = ttk.Style(store_frame)
    S.configure('Treeview', rowheight=400)    
    treev.pack(side='left',expand=True, fill='both') 
    for i in range(len(photo)-1):    
       
        
        btree_img = ImageTk.PhotoImage(Image.open(photo[i]))
        lbl_btree_img = tk.Label(store_frame, image=btree_img)
        lbl_btree_img.btree_img = btree_img
        lbl_btree_img.pack()
        
        listimgs.append(btree_img)
        treev.insert(parent="",
                    index="end",
                    image=listimgs[i],
                    values=(ID[i], Names[i]))
        # treev.pack(expand=True, fill=tk.BOTH)
        
def getUsersAsc():
    
    for widget in asc_frame.winfo_children():
        widget.destroy()
    
    users_object.bubblesortUp()
    
    btn_rt_asc_frame = tk.Button()
    btn_rt_asc_frame = tk.Button(asc_frame)
    btn_rt_asc_frame["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_rt_asc_frame["font"] = ft
    btn_rt_asc_frame["fg"] = "#ffffff"
    btn_rt_asc_frame["justify"] = "center"
    btn_rt_asc_frame["text"] = "Regresar"
    btn_rt_asc_frame["relief"] = "raised"
    btn_rt_asc_frame.pack(pady=20)
    btn_rt_asc_frame["command"] = change_to_admin
    
    
    
    ids = users_object.sendIdsToPY()
    nicks = users_object.sendNicksToPY()
    age = users_object.sendAgesToPY()
    passw = users_object.sendPasswordsToPY()
    
    login_frame.forget()
    admin_frame.forget()
    asc_frame.pack(fill='both', expand=1)
    
    treev = ttk.Treeview(asc_frame, selectmode ='browse') 
    treev.pack(side='left',expand=True, fill='both') 

    verscrlbar = ttk.Scrollbar(asc_frame,  
                           orient ="vertical",  
                           command = treev.yview) 
  
    verscrlbar.pack(side ='right', fill ='y')   
    treev.configure(yscrollcommand = verscrlbar.set) 
    # #///
    # horscrlbar = ttk.Scrollbar(treev,  
    #                        orient ="horizontal",  
    #                        command = treev.xview) 
  
    # horscrlbar.pack(side ='bottom', fill ='x')   
    # treev.configure(xscrollcommand = horscrlbar.set) 

  
    treev["columns"] = ('1', '2', '3', '4') 

    treev['show'] = 'headings'
  
    treev.column("1", width = 90, anchor ='c') 
    treev.column("2", width = 90, anchor ='c') 
    treev.column("3", width = 90, anchor ='c') 


    treev.heading("1", text ="ID") 
    treev.heading("2", text ="Nick") 
    treev.heading("3", text ="Age") 
    treev.heading("4", text ="Password") 

    

    for w, x, y, z in zip(ids, nicks, age, passw):    
        treev.insert("", 'end', values =(w, x, y, z))

def getUsersDesc():
    
    for widget in desc_frame.winfo_children():
        widget.destroy()
    
    users_object.bubblesortDown()
    
    
    btn_rt_desc_frame = tk.Button()
    btn_rt_desc_frame = tk.Button(desc_frame)
    btn_rt_desc_frame["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_rt_desc_frame["font"] = ft
    btn_rt_desc_frame["fg"] = "#ffffff"
    btn_rt_desc_frame["justify"] = "center"
    btn_rt_desc_frame["text"] = "Regresar"
    btn_rt_desc_frame["relief"] = "raised"
    btn_rt_desc_frame.pack(pady=20)
    btn_rt_desc_frame["command"] = change_to_admin
    
    ids = users_object.sendIdsToPY()
    nicks = users_object.sendNicksToPY()
    age = users_object.sendAgesToPY()
    passw = users_object.sendPasswordsToPY()
    
    login_frame.forget()
    admin_frame.forget()
    asc_frame.forget()
    desc_frame.pack(fill='both', expand=1)
    
    treev = ttk.Treeview(desc_frame, selectmode ='browse') 
    treev.pack(side='left',expand=True, fill='both') 

    verscrlbar = ttk.Scrollbar(desc_frame,  
                           orient ="vertical",  
                           command = treev.yview) 
  
    verscrlbar.pack(side ='right', fill ='y')   
    treev.configure(yscrollcommand = verscrlbar.set) 

  
    treev["columns"] = ('1', '2', '3', '4') 

    treev['show'] = 'headings'
  
    treev.column("1", width = 90, anchor ='c') 
    treev.column("2", width = 90, anchor ='c') 
    treev.column("3", width = 90, anchor ='c') 

    

    treev.heading("1", text ="ID") 
    treev.heading("2", text ="Nick") 
    treev.heading("3", text ="Age") 
    treev.heading("4", text ="Password") 

    

    for w, x, y, z in zip(ids, nicks, age, passw):    
        treev.insert("", 'end', values =(w, x, y, z))   

def getBTree():
    
    
    
    # login_frame.forget()
    # admin_frame.forget()
    # asc_frame.forget()
    # desc_frame.forget()
    
    for widget in btree_frame.winfo_children():
        widget.destroy()
        
    login_frame.forget()
    asc_frame.forget()
    desc_frame.forget()
    admin_frame.forget()
    btree_frame.pack(fill='both', expand=1)
    
    btn_rt_btree_frame = tk.Button()
    btn_rt_btree_frame = tk.Button(btree_frame)
    btn_rt_btree_frame["cursor"] = "heart"
    ft = tkFont.Font(family='Times', size=18)
    btn_rt_btree_frame["font"] = ft
    btn_rt_btree_frame["fg"] = "#ffffff"
    btn_rt_btree_frame["justify"] = "center"
    btn_rt_btree_frame["text"] = "Regresar"
    btn_rt_btree_frame["relief"] = "raised"
    btn_rt_btree_frame.pack(pady=20)
    btn_rt_btree_frame["command"] = change_to_admin
    
    
    ids = users_object.sendIdsToPY()
    
    # print(ids)
    # for i in range(len(ids)):
    #     print(ids[i])
    #     btree_object.insertar(ids[i])
    
    for id in ids:
        
        btree_object.insertar(id)
    
    btree_graph = btree_object.Grafo()
    
    archivo = open('btree.dot', 'w')
    archivo.write(btree_graph)
    archivo.close()
    os.system('dot -Tjpg btree.dot -o btree.jpeg')
    
    # phto = PhotoImage('btree.jpeg')
    
    # lbld = Label(login_frame, image=phto)
    # lbld.image = phto
    # lbld.pack()
    
    btree_img = ImageTk.PhotoImage(Image.open('btree.jpeg'))
    lbl_btree_img = tk.Label(btree_frame, image=btree_img)
    lbl_btree_img.btree_img = btree_img
    lbl_btree_img.pack()
    
    
    
    

# getBTree()
    

# users_object.getLk(51)



# ---------------------
def center_window_on_screen():
    x_cord = int((screen_width/2) - (width/2))
    y_cord = int((screen_height/2) - (height/2))
    root.geometry("{}x{}+{}+{}".format(width, height, x_cord, y_cord))


def change_to_admin():
    login_frame.forget()
    asc_frame.forget()
    desc_frame.forget()
    btree_frame.forget()
    admin_frame.pack(fill='both', expand=1)

def change_to_btree():
    login_frame.forget()
    asc_frame.forget()
    desc_frame.forget()
    admin_frame.forget()
    btree_frame.pack(fill='both', expand=1)
    
def change_to_user():
    login_frame.forget()
    asc_frame.forget()
    desc_frame.forget()
    admin_frame.forget()
    btree_frame.forget()
    store_frame.forget()
    tienda_frame.forget()
    user_frame.pack(fill='both', expand=1)
    
    # getInUserTab()
    
def change_to_tienda():
    login_frame.forget()
    asc_frame.forget()
    desc_frame.forget()
    admin_frame.forget()
    btree_frame.forget()
    store_frame.forget()
    user_frame.forget()
    tienda_frame.pack(fill='both', expand=1)
    articulos = list()
    mostrarTienda(articulos)
    

def change_to_store():
    login_frame.forget()
    asc_frame.forget()
    desc_frame.forget()
    admin_frame.forget()
    btree_frame.forget()
    user_frame.forget()
    store_frame.pack(fill='both', expand=1)
    displayStore()
    
    

def change_to_login():
    login_frame.pack(fill='both', expand=1)
    user_frame.forget()
    admin_frame.forget()


# Now we get to the program itself:-
# Let's set up the window ...
root = tk.Tk()
root.title("My Work - Swapping frames")
root.configure(bg='lightyellow')
# Set the icon used for your program

width, height = 800, 700
screen_width = root.winfo_screenwidth()  # To get the width of the screen
screen_height = root.winfo_screenheight()  # To get the height of the screen
center_window_on_screen()  # To center the window


login_frame = tk.Frame(root)  # Login frame
admin_frame = tk.Frame(root)  # Admin fram
user_frame = tk.Frame(root)  #User frame
asc_frame = tk.Frame(root)
desc_frame = tk.Frame(root)
btree_frame = tk.Frame(root)
store_frame = tk.Frame(root)
tienda_frame = tk.Frame(root)

# btree_img = ImageTk.PhotoImage(Image.open('btree.jpg'))
# lbl_btree_img = tk.Label(login_frame, image=btree_img)
# lbl_btree_img.pack()
    




# Let's create the fonts that we need.
font_large = tkFont.Font(family='Georgia', size='24', weight='bold')
font_small = tkFont.Font(family='Georgia', size='12')


# Next, comes the heading for this frame.

# Center label in login
lbl_heading_login = tk.Label(login_frame)
ft = tkFont.Font(family='Times', size=28)
lbl_heading_login["font"] = ft
lbl_heading_login["fg"] = "#000000"
lbl_heading_login["justify"] = "center"
lbl_heading_login["text"] = "Iniciar Sesión"
lbl_heading_login.place(x=190, y=70, width=210, height=46)
lbl_heading_login.bind("<Button-1>", lambda e:loadUsers())

# User label
lbl_user_login = tk . Label(login_frame)
ft = tkFont . Font(family=' Times ', size=22)
lbl_user_login["font"] = ft
lbl_user_login["fg"] = "#000000"
lbl_user_login["justify"] = "center"
lbl_user_login["text"] = "Usuario"
lbl_user_login.place(x=120, y=190, width=106, height=30)

# Entry for user
ety_user_login = tk . Entry(login_frame)
ety_user_login["borderwidth"] = "1px"
ft = tkFont.Font(family='Times', size=18)
ety_user_login["font"] = ft
ety_user_login["fg"] = "#000000"
ety_user_login["justify"] = "center"
ety_user_login.place(x=250, y=190, width=252, height=31)

# Password label
lbl_pass_login = tk.Label(login_frame)
ft = tkFont.Font(family='Times', size=22)
lbl_pass_login["font"] = ft
lbl_pass_login["fg"] = "#000000"
lbl_pass_login["justify"] = "center"
lbl_pass_login["text"] = "Contraseña"
lbl_pass_login.place(x=80, y=270, width=153, height=30)

# Entry for password
bullet = "\u2022"
ety_pass_login = tk.Entry(login_frame)
ety_pass_login['show'] = bullet
ety_pass_login["borderwidth"] = "1px"
ft = tkFont.Font(family='Times', size=18)
ety_pass_login["font"] = ft
ety_pass_login["fg"] = "#333333"
ety_pass_login["justify"] = "center"
ety_pass_login . place(x=250, y=270, width=252, height=31)



def btn_log_login_command():

    entryuser = ety_user_login.get()
    entrypass = ety_pass_login.get()

    if entryuser == 'ADMIN' and entrypass =='123':
        print('si es admin')
    else:
        print('Aqui hacer la busqueda de usuario')
#         print(entryuser)
    print(entryuser, entrypass)

# button for login
btn_log_login = tk.Button(login_frame)
# btn_log_login["anchor"] = "nw"
btn_log_login["bg"] = "#000000"
btn_log_login["cursor"] = "heart"
ft = tkFont.Font(family='Times', size=18)
btn_log_login["font"] = ft
btn_log_login["fg"] = "#ffffff"
btn_log_login["justify"] = "center"
btn_log_login["text"] = "Ingresar"
btn_log_login["relief"] = "raised"
btn_log_login.place(x=230, y=360, width=151, height=34)
btn_log_login["command"] = login

# Command for log button




# And finally, the button to swap between the frames.
# btn_change_to_work = tk.Button(
#     login_frame, text='Change to work', font=font_small, command=change_to_admin)
# btn_change_to_work.pack(pady=20)

# The widgets needed for the work frame.
# These are only being used in this example
# to show that both frames are working as
# expected.

# First the image gets added.


# Next, we'll add a heading.
lbl_heading_work = tk.Label(
    admin_frame, text='This is the admin frame', font=font_large)
lbl_heading_work.pack(pady=20)

lbl_heading_btree = tk.Label(
    btree_frame, text='This is the btree', font=font_large)
lbl_heading_btree.pack(pady=20)

lbl_heading_store = tk.Label(
    store_frame, text='Tienda de articulos', font=font_large)
lbl_heading_store.pack(pady=20)

lbl_heading_user = tk.Label(
user_frame, text='Bienvenido usuario'+ety_user_login.get(), font=font_large)
lbl_heading_user.pack(pady=20)





#Admin buttons
btn_change_to_quiz = tk.Button(
    admin_frame, font=font_small, text='Cerrar sesion', command=change_to_login)
btn_change_to_quiz.pack(pady=20)

show_asc_users = tk.Button(
    admin_frame, font=font_small, text='Mostrar usuarios de forma ascendente', command= getUsersAsc)
show_asc_users.pack(pady=40)

show_desc_users = tk.Button(
    admin_frame, font=font_small, text='Mostrar usuarios de forma descendente', command= getUsersDesc)
show_desc_users.pack(pady=80)

show_btree = tk.Button(
    admin_frame, font=font_small, text='Mostrar Arbol B', command= getBTree)
show_btree.pack(pady=85)


#buttons for user interface
show_tienda = tk.Button(
    user_frame, font=font_small, text='Ir a la tienda', command=change_to_tienda)
show_tienda.pack(pady=85)

show_admn = tk.Button(
    user_frame, font=font_small, text='Cerrar Sesion', command=change_to_login)
show_admn.pack(pady=85)

# show_return_usuario = tk.Button(
#     tienda_frame, font=font_small, text='Regresar al usuario', command=change_to_user)
# show_return_usuario.pack(pady=85)




login_frame.pack(fill='both', expand=1)


root.mainloop()


