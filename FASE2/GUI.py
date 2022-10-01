from ast import If
from json import load
import tkinter as tk
import tkinter.font as tkFont
from PIL import Image, ImageTk
import os


# ---------------------
def center_window_on_screen():
    x_cord = int((screen_width/2) - (width/2))
    y_cord = int((screen_height/2) - (height/2))
    root.geometry("{}x{}+{}+{}".format(width, height, x_cord, y_cord))


def change_to_work():
    login_frame.forget()
    work_frame.pack(fill='both', expand=1)


def change_to_quiz():
    login_frame.pack(fill='both', expand=1)
    work_frame.forget()


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
work_frame = tk.Frame(root)  # User fram

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
btn_log_login["command"] = btn_log_login_command

# Command for log button




# And finally, the button to swap between the frames.
btn_change_to_work = tk.Button(
    login_frame, text='Change to work', font=font_small, command=change_to_work)
btn_change_to_work.pack(pady=20)

# The widgets needed for the work frame.
# These are only being used in this example
# to show that both frames are working as
# expected.

# First the image gets added.


# Next, we'll add a heading.
lbl_heading_work = tk.Label(
    work_frame, text='This is the WORK frame', font=font_large)
lbl_heading_work.pack(pady=20)

# Finally, we need the button to
# swap back to the quiz frame.
btn_change_to_quiz = tk.Button(
    work_frame, font=font_small, text='Change to quiz', command=change_to_quiz)
btn_change_to_quiz.pack(pady=20)

# Only the quiz frame needs to be shown
# when the program starts.  The work frame
# will only appear when the Change button
# is clicked.
login_frame.pack(fill='both', expand=1)

img_list=[]
path = "C:\Users\hctr\Desktop\screenshots" # my folder
n_row = 0
n_col = 0
index = 0
x = tk.IntVar()
for f in os.listdir(path):
    img_list.append(ImageTk.PhotoImage(Image.open(os.path.join(path,f))))
    n_col +=1
    index +=1
    if n_col > 9:
        n_row +=1
        n_col = 1
    radio_button = Radiobutton(C, image=img_list[index-1], indicatoron=0, bd=2, variable = x, value = index)
    radio_button.grid(row=n_row, column = n_col)

root.mainloop()


# class App:
#     def __init__(self, root):
#         # setting title
#         root.title("batalla naval")
#         # setting window size
#         width = 600
#         height = 500
#         screenwidth = root.winfo_screenwidth()
#         screenheight = root.winfo_screenheight()
#         alignstr = '%dx%d+%d+%d' % (width, height,
#                                     (screenwidth - width) / 2, (screenheight - height) / 2)
#         root.geometry(alignstr)
#         root.resizable(width=False, height=False)

#         txtfl_pass = tk.Entry(root)
#         txtfl_pass["borderwidth"] = "1px"
#         ft = tkFont.Font(family='Times', size=18)
#         txtfl_pass["font"] = ft
#         txtfl_pass["fg"] = "#333333"
#         txtfl_pass["justify"] = "center"
#         txtfl_pass["text"] = "Entry"
#         txtfl_pass.place(x=250, y=180, width=252, height=31)

#         self.txtfl_user = tk.Entry(root)
#         self.txtfl_user["borderwidth"] = "1px"
#         self.ft = tkFont.Font(family='Times', size=18)
#         self.txtfl_user["font"] = ft
#         self.txtfl_user["fg"] = "#333333"
#         self.txtfl_user["justify"] = "center"
#         # txtfl_user["text"] = "Entry"
#         self.txtfl_user.place(x=250, y=120, width=252, height=31)

#         GButton_892 = tk.Button(root)
#         GButton_892["bg"] = "#f0f0f0"
#         GButton_892["cursor"] = "pirate"
#         ft = tkFont.Font(family='Times', size=18)
#         GButton_892["font"] = ft
#         GButton_892["fg"] = "#000000"
#         GButton_892["justify"] = "center"
#         GButton_892["text"] = "Ingresar"
#         GButton_892.place(x=230, y=280, width=139, height=30)
#         GButton_892["command"] = self.GButton_892_command

#         GLabel_822 = tk.Label(root)
#         ft = tkFont.Font(family='Times', size=22)
#         GLabel_822["font"] = ft
#         GLabel_822["fg"] = "#333333"
#         GLabel_822["justify"] = "center"
#         GLabel_822["text"] = "Usuario"
#         GLabel_822.place(x=80, y=120, width=106, height=30)

#         GLabel_500 = tk.Label(root)
#         ft = tkFont.Font(family='Times', size=22)
#         GLabel_500["font"] = ft
#         GLabel_500["fg"] = "#333333"
#         GLabel_500["justify"] = "center"
#         GLabel_500["text"] = "Contraseña"
#         GLabel_500.place(x=80, y=180, width=153, height=30)

#     def GButton_892_command(self):

#         entryuser = self.txtfl_user.get()
#         print(entryuser)


# if __name__ == "__main__":
#     root = tk.Tk()
#     app = App(root)
#     root.mainloop()
